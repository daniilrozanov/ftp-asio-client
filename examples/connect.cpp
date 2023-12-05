#include "ftp/handshake_params.hpp"
#include <ftp/details/connection_base.hpp>

int main()
{
  boost::asio::io_context ioc;
  ftp::detail::connection_base conn(ioc.get_executor());
  boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("192.168.1.66"), 21);
  ftp::handshake_params params("ftpuser", "ftpuser");
  conn.connect(ep, params);
  return 0;
}
