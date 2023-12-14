#ifndef FTP_SESSION_HPP
#define FTP_SESSION_HPP

#include <ftp/details/command_connection.hpp>
#include <ftp/details/data_connection.hpp>
#include <ftp/details/transfer_parameters.hpp>

#include <ftp/handshake_params.hpp>

namespace ftp {

namespace detail {

template <typename Executor>
class session
{
public:
  using executor_type = Executor;
  session() = delete;
  session(executor_type ex) : command_con_(ex), data_con_(ex) {}
  session(net::io_context& ioc) : command_con_(ioc.get_executor()), data_con_(ioc.get_executor()) {}

  void connect(const net::ip::tcp::endpoint& ep, const handshake_params& params);

  void connect(
      const net::ip::tcp::endpoint& ep,
      const handshake_params& params,
      boost::system::error_code& er
  );

  template <typename CompletionToken>
  auto async_connect(
      const net::ip::tcp::endpoint& ep,
      const handshake_params& params,
      CompletionToken&& token
  )
  {
  }

  void execute(const request& req, response& resp);

  void execute(const request& req, response& resp, boost::system::error_code& er);

  void set_active_state(boost::system::error_code& er);

  void set_passive_state(const net::ip::tcp::endpoint& ep, boost::system::error_code& er);

  template <typename CompletionToken>
  auto async_execute(const request& req, response& resp, CompletionToken&& token)
  {
  }

  template <typename Data>
  void send_data(Data&& data)
  {
  }

  template <typename Data, typename CompletionToken>
  auto async_send_data(Data&& data, CompletionToken&& token)
  {
  }

private:
  command_connection<executor_type> command_con_;
  data_connection<executor_type> data_con_;
  transfer_params t_params_;
};

}  // namespace detail

}  // namespace ftp

#endif  // !FTP_SESSION_HPP
