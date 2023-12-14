#ifndef FTP_DATA_CONNECTION_HPP
#define FTP_DATA_CONNECTION_HPP

#include <boost/asio/connect.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>

#include <ftp/details/transfer_parameters.hpp>

#include <ftp/command.hpp>
#include <ftp/details/boost_asio_alias.hpp>
#include <ftp/request.hpp>
#include <ftp/response.hpp>
#include <ftp/status.hpp>

namespace ftp {

namespace detail {

using boost::system::error_code;

template <typename Executor>
class data_connection
{
public:
  using executor_type = Executor;
  data_connection(executor_type ex) : con_(ex){};
  data_connection(net::io_context& ioc) : con_(ioc.get_executor()){};

  void connect(const net::ip::tcp::endpoint& ep);

  void connect(const net::ip::tcp::endpoint& ep, error_code& er);

  template <typename CompletionToken>
  auto async_connect(const net::ip::tcp::endpoint& ep, CompletionToken&& token)
  {
  }

  void reconnect();

  void reconnect(error_code& er);

  template <typename CompletionToken>
  auto async_reconnect(CompletionToken&& token)
  {
  }

  template <typename Container>
  void send(const Container& data, transfer_params t_params = {})
  {
    switch (t_params.mode)
    {
    case transfer_mode::stream:
      net::write(con_, data);
      con_.close();
      return;
    case transfer_mode::block: return;
    case transfer_mode::compressed: return;
    }
  }

  template <typename Container>
  void send(const Container& data, error_code& er, transfer_params t_params = {})
  {
  }

  template <typename Container, typename CompletionToken>
  auto async_send(const Container& data, transfer_params t_params, CompletionToken&& token)
  {
  }

  template <typename Container>
  void receive(Container& data, transfer_params t_params = {})
  {
    switch (t_params.mode)
    {
    case transfer_mode::stream: net::read(con_, net::dynamic_buffer(data)); return;
    case transfer_mode::block: return;
    case transfer_mode::compressed: return;
    }
  }

  template <typename Container>
  void receive(Container& data, error_code& er, transfer_params t_params)
  {
  }

  template <typename Container, typename CompletionToken>
  auto async_receive(Container& data, transfer_params t_params, CompletionToken&& token)
  {
  }

private:
  net::ip::tcp::socket con_;
  net::ip::tcp::endpoint ep_;
};

}  // namespace detail

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/details/impl/data_connection.cpp>
#endif  // FTP_HEADER_ONLY

#endif  // !FTP_DATA_CONNECTION_HPP
