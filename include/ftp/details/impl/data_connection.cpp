#ifndef FTP_DATA_CONNECTION_CPP
#define FTP_DATA_CONNECTION_CPP

#pragma once

#include <ftp/details/data_connection.hpp>

namespace ftp {

namespace detail {

template <typename T>
void data_connection<T>::connect(const net::ip::tcp::endpoint& ep)
{
  if (con_.is_open())
    con_.close();
  con_.connect(ep);
}

template <typename T>
void data_connection<T>::connect(const net::ip::tcp::endpoint& ep, error_code& er)
{
  ep_ = ep;
  if (con_.is_open())
    er = con_.close(er);
  if (er)
    return;
  er = con_.connect(ep, er);
}

template <typename T>
void data_connection<T>::reconnect()
{
  connect(ep_);
}

template <typename T>
void data_connection<T>::reconnect(error_code& er)
{
  connect(ep_, er);
}

}  // namespace detail

}  // namespace ftp

#endif  // !FTP_DATA_CONNECTION_CPP
