#include "ftp/handshake_params.hpp"
#include <ftp/connection.hpp>

int main()
{
  boost::asio::io_context ioc;
  ftp::connection conn(ioc);
  boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("192.168.1.66"), 21);
  ftp::handshake_params params("ftpuser", "ftpuser");
  conn.connect(ep, params);
  return 0;
}
