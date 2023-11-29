#ifndef FTP_CONNECTION_HPP
#define FTP_CONNECTION_HPP

#include <boost/asio/connect.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>

#include <ftp/details/boost_asio_alias.hpp>
#include <ftp/handshake_params.hpp>

#include <iostream>

namespace ftp {

class connection
{
public:
  connection(net::io_context& ioc) : ioc_(ioc), control_(ioc), data_(ioc){};
  void connect(const net::ip::tcp::endpoint& ep, const handshake_params& params)
  {
    std::string user_password_commands;
    control_.connect(ep);
    net::read_until(control_, net::dynamic_buffer(control_input_buffer_), "\r\n");
    std::cout << control_input_buffer_ << std::endl;
    control_input_buffer_.erase();
    net::write(control_, net::buffer("USER " + params.username() + "\r\n"));
    net::read_until(control_, net::dynamic_buffer(control_input_buffer_), "\r\n");
    std::cout << control_input_buffer_ << std::endl;
    control_input_buffer_.erase();
    net::write(control_, net::buffer("PASS " + params.password() + "\r\n"));
    net::read_until(control_, net::dynamic_buffer(control_input_buffer_), "\r\n");
    std::cout << control_input_buffer_ << std::endl;
  }

private:
  net::io_context& ioc_;
  net::ip::tcp::socket control_;
  net::ip::tcp::socket data_;
  std::string control_input_buffer_;
};

}  // namespace ftp

#endif  // !FTP_CONNECTION_HPP
