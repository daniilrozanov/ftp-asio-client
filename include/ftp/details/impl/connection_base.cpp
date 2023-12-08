#ifndef FTP_CONNECTION_BASE_CPP
#define FTP_CONNECTION_BASE_CPP

#pragma once

#include <ftp/details/connection_base.hpp>

namespace ftp {

namespace detail {

template <typename T>
void connection_base<T>::connect(const net::ip::tcp::endpoint& ep, response& r)
{
  control_.connect(ep);
  read_into_response(r);
}

template <typename T>
void connection_base<T>::execute(const request& r, response& resp)
{
  net::write(control_, net::buffer(r.payload()));
  read_into_response(resp);
}
template <typename T>
void connection_base<T>::read_into_response(response& r)
{
  r.clear();
  net::read_until(control_, net::dynamic_buffer(r.data_), "\r\n");
  r.build_self();
}

}  // namespace detail

}  // namespace ftp

#endif  // !FTP_CONNECTION_BASE_CPP
