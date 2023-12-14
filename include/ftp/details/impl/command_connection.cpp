#ifndef FTP_COMMAND_CONNECTION_CPP
#define FTP_COMMAND_CONNECTION_CPP

#pragma once

#include <ftp/details/command_connection.hpp>

namespace ftp {

namespace detail {

using boost::system::error_code;

template <typename T>
void command_connection<T>::connect(const net::ip::tcp::endpoint& ep, response& r)
{
  con_.connect(ep);
  receive(r);
}

template <typename T>
void command_connection<T>::connect(const net::ip::tcp::endpoint& ep, response& r, error_code& er)
{
  er = con_.connect(ep, er);
  if (er)
    return;
  receive(r, er);
}

template <typename T>
void command_connection<T>::send(const request& r)
{
  net::write(con_, net::buffer(r.payload()));
}

template <typename T>
void command_connection<T>::send(const request& r, error_code& er)
{
  net::write(con_, net::buffer(r.payload()), er);
}

template <typename T>
void command_connection<T>::receive(response& r)
{
  r.clear();
  net::read_until(con_, net::dynamic_buffer(r.data_), "\r\n");
  r.build_self();
}

template <typename T>
void command_connection<T>::receive(response& r, error_code& er)
{
  r.clear();
  net::read_until(con_, net::dynamic_buffer(r.data_), "\r\n");
  r.build_self();
}

}  // namespace detail

}  // namespace ftp

#endif  // !FTP_CONNECTION_BASE_CPP
