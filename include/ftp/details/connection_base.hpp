#ifndef FTP_CONNECTION_HPP
#define FTP_CONNECTION_HPP

#include <boost/asio/connect.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>

#include <ftp/details/boost_asio_alias.hpp>
#include <ftp/details/command.hpp>
#include <ftp/handshake_params.hpp>
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
  void connect(const net::ip::tcp::endpoint& ep, const handshake_params& params)
  {
    std::string null_buffer;
    response r;
    control_.connect(ep);
    net::read_until(control_, net::dynamic_buffer(null_buffer), "\r\n");
    execute("USER " + params.username(), r);
    execute("PASS " + params.password(), r);
  }

  void execute(const std::string& request, response& resp)
  {
    net::write(control_, net::buffer(request + "\r\n"));
    resp.clear();
    net::read_until(control_, net::dynamic_buffer(resp.data_), "\r\n");
    resp.build_self();
  }

private:
  net::any_io_executor ex_;
  net::ip::tcp::socket control_;
  net::ip::tcp::socket data_;
};

}  // namespace detail

}  // namespace ftp

#endif  // !FTP_CONNECTION_HPP
