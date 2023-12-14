#ifndef FTP_COMMAND_CONNECTION_HPP
#define FTP_COMMAND_CONNECTION_HPP

#include <boost/asio/compose.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>

#include <ftp/command.hpp>
#include <ftp/details/boost_asio_alias.hpp>
#include <ftp/request.hpp>
#include <ftp/response.hpp>
#include <ftp/status.hpp>

#include <functional>
#include <utility>

namespace ftp {

namespace detail {

template <typename Executor>
class command_connection
{
public:
  using executor_type = Executor;
  command_connection(executor_type ex) : con_(ex.get_executor()){};
  command_connection(net::io_context& ioc) : con_(ioc.get_executor()){};

  void connect(const net::ip::tcp::endpoint& ep, response& r);

  void connect(const net::ip::tcp::endpoint& ep, response& r, boost::system::error_code& er);

  template <typename CompletionToken>
  auto async_connect(const net::ip::tcp::endpoint& ep, response& r, CompletionToken&& token)
  {
    // return net::async_compose<CompletionToken, void(error_code)>();
  }

  void send(const request& r);

  void send(const request& r, boost::system::error_code& er);

  template <typename CompletionToken>
  auto async_send(const request& r, CompletionToken&& token)
  {
  }

  void receive(response& r);

  void receive(response& r, boost::system::error_code& er);

  template <typename CompletionToken>
  auto async_receive(response& r, CompletionToken&& token)
  {
  }

  template <typename Invokable>
  void execute(const request& r, response& resp, Invokable&& preliminary_handler)
  {
    send(r);
    do
    {
      receive(resp);
      if (resp.status_class() == status_class::positive_preliminary)
        std::invoke(std::forward<Invokable>(preliminary_handler), resp);
    } while (resp.status_class() == status_class::positive_preliminary);
  }

  template <typename Invokable>
  void execute(
      const request& r,
      response& resp,
      boost::system::error_code& er,
      Invokable&& preliminary_handler
  )
  {
    send(r, er);
    if (er)
      return;
    do
    {
      receive(resp, er);
      if (resp.status_class() == status_class::positive_preliminary)
        std::invoke(std::forward<Invokable>(preliminary_handler), resp);
    } while (resp.status_class() == status_class::positive_preliminary && !er);
  }

private:
  net::ip::tcp::socket con_;
};

}  // namespace detail

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/details/impl/command_connection.cpp>
#endif  // FTP_HEADER_ONLY

#endif  // !FTP_COMMAND_CONNECTION_HPP
