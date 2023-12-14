#ifndef FTP_REQUEST_CPP
#define FTP_REQUEST_CPP

#include "ftp/command.hpp"
#pragma once

#include <ftp/request.hpp>

namespace ftp {

request::request() noexcept : c_(cmd::noop) {}
request::request(cmd c) noexcept : c_(c) {}
request::request(cmd c, const std::string& arg) : c_(c), arg_(arg) {}

cmd request::get_cmd() const noexcept { return c_; }
const std::string& request::get_arg() const noexcept { return arg_; }
std::string request::payload() const
{
  std::string payload;
  payload.append(to_string(c_));
  if (!arg_.empty())
  {
    payload.append(" ");
    payload.append(arg_);
  }
  payload.append("\r\n");
  return payload;
}

}  // namespace ftp

#endif  // !FTP_REQUEST_CPP
