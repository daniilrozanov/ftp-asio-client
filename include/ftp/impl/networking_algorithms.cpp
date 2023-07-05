#ifndef _NETWORKING_ALGORITHMS_CPP_
#define _NETWORKING_ALGORITHMS_CPP_

#pragma once

#include <boost/asio/connect.hpp>
#include <ftp/detail/network_algorithms.hpp>
#include <ftp/handshake_params.hpp>

namespace asio = boost::asio;

inline void ftp::detail::connect_interface(
    tcp::socket& socket,
    const tcp::resolver::results_type& endpoints,
    const handshake_params& params,
    error_code& ec
)
{
  asio::connect(socket, endpoints, ec);
  if (ec)
  {
    return;
  }
}

inline void ftp::detail::handshake_interface(
    tcp::socket& socket,
    const handshake_params& params,
    error_code& ec
)
{
}

#endif
