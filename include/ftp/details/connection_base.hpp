#ifndef FTP_CONNECTION_HPP
#define FTP_CONNECTION_HPP

#include "ftp/request.hpp"
#include <boost/asio/connect.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>

#include <ftp/command.hpp>
#include <ftp/details/boost_asio_alias.hpp>
#include <ftp/handshake_params.hpp>
#include <ftp/request.hpp>
#include <ftp/response.hpp>

namespace ftp {

namespace detail {

template <typename Executor>
class connection_base
{
public:
  using executor_type = Executor;
  connection_base(Executor ex) : ex_(ex), control_(ex), data_(ex){};
  connection_base(net::io_context& ioc) : ex_(ioc.get_executor()), control_(ioc), data_(ioc){};

  void connect(const net::ip::tcp::endpoint& ep, response& r);

  void execute(const request& r, response& resp);

protected:
  void read_into_response(response& r);

private:
  net::any_io_executor ex_;
  net::ip::tcp::socket control_;
  net::ip::tcp::socket data_;
};

}  // namespace detail

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/details/impl/connection_base.cpp>
#endif  // FTP_HEADER_ONLY

#endif  // !FTP_CONNECTION_HPP
