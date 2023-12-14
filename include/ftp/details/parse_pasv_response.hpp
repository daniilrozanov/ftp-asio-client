#ifndef FTP_PARSE_PASV_RESPONSE_HPP
#define FTP_PARSE_PASV_RESPONSE_HPP

#include <boost/asio/ip/tcp.hpp>

#include <ftp/details/boost_asio_alias.hpp>

namespace ftp {

namespace detail {

net::ip::tcp::endpoint parse_pasv_response(const char* s);

net::ip::tcp::endpoint parse_pasv_response(const char* s, boost::system::error_code& er);

}  // namespace detail

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/details/impl/parse_pasv_response.cpp>
#endif  // DEBUG

#endif  // !FTP_PARSE_PASV_RESPONSE_HPP
