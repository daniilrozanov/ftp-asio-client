#ifndef _CONNECTION_HPP_
#define _CONNECTION_HPP_

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <ftp/error_code.hpp>
#include <ftp/handshake_params.hpp>

namespace ftp {
namespace asio = boost::asio;

using boost::asio::ip::tcp;

class connection
{
  asio::io_context& ioc_;
  tcp::socket cmd_socket_;

public:
  connection(asio::io_context& ioc) : ioc_(ioc), cmd_socket_(ioc_){};

  void connect(const tcp::resolver::results_type& endpoints, const handshake_params& params);

  void connect(const tcp::resolver::results_type& endpoint, const handshake_params& params, error_code& ec);

  void execute(const std::string& command);
};
}  // namespace ftp

#endif  // !_CONNECTION_HPP_
