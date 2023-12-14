kjkjkj#ifndef FTP_PARSE_PASV_RESPONSE_CPP
#define FTP_PARSE_PASV_RESPONSE_CPP

#pragma once

#include <ftp/details/parse_pasv_response.hpp>

namespace ftp {

namespace detail {

net::ip::tcp::endpoint parse_pasv_response(const char* s)
{
  using std::to_string;
  using namespace net::ip;
  unsigned char h1, h2, h3, h4, p2;
  unsigned short p1;
  sscanf(s, "Entering Passive Mode (%hhu,%hhu,%hhu,%hhu,%hu,%hhu).", &h1, &h2, &h3, &h4, &p1, &p2);
  auto a = make_address(to_string(h1) + '.' + to_string(h2) + '.' + to_string(h3) + '.' + to_string(h4));
  return tcp::endpoint(a, (p1 << 8) + p2);
}

net::ip::tcp::endpoint parse_pasv_response(const char* s, boost::system::error_code& er)
{
  using std::to_string;
  using namespace net::ip;
  unsigned char h1, h2, h3, h4, p2;
  unsigned short p1;
  if (sscanf(s, "Entering Passive Mode (%hhu,%hhu,%hhu,%hhu,%hu,%hhu).", &h1, &h2, &h3, &h4, &p1, &p2) != 6)
  {
    return {};
  }
  auto a = make_address(to_string(h1) + '.' + to_string(h2) + '.' + to_string(h3) + '.' + to_string(h4), er);
  if (er)
    return {};
  return tcp::endpoint(a, (p1 << 8) + p2);
}
}  // namespace detail

}  // namespace ftp

#endif  // !FTP_PARSE_PASV_RESPONSE_CPP
