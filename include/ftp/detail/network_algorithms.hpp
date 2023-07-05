#ifndef _NETWORKING_ALGORITHMS_HPP_
#define _NETWORKING_ALGORITHMS_HPP_

#include <boost/asio/ip/tcp.hpp>
#include <ftp/error_code.hpp>
#include <ftp/handshake_params.hpp>

namespace ftp {

namespace detail {

using boost::asio::ip::tcp;

inline void connect_interface(
    tcp::socket& socket,
    const tcp::resolver::results_type& endpoints,
    const handshake_params& params,
    error_code& ec
);

inline void handshake_interface(tcp::socket& socket, const handshake_params& params, error_code& ec);

}  // namespace detail

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/impl/networking_algorithms.cpp>
#endif  // FTP_HEADER_ONLY

#endif  // !_NETWORKING_ALGORITHMS_HPP_
