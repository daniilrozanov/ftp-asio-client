#ifndef FTP_REQUEST_CPP
#define FTP_REQUEST_CPP

#include "ftp/command.hpp"
#include <string_view>
#pragma once

#include <ftp/request.hpp>

namespace ftp {

request::request() {}

request::request(cmd c) { add_cmd(c); }

request::request(cmd c, std::string_view arg) { add_cmd(c, arg); }

std::string_view request::payload() const noexcept { return payload_; }

const request::config& request::get_config() const noexcept { return cfg_; }

request::config& request::get_config() noexcept { return cfg_; }

void request::push(cmd c, std::string_view arg) { add_cmd(c, arg); }

void request::add_cmd(cmd c, std::string_view arg)
{
  payload_.append(to_string(c));
  if (!arg.empty())
  {
    payload_.append(" ");
    payload_.append(arg);
  }
  payload_.append("\r\n");
  ++commands_;
  if (has_preliminary_reply(c))
    has_preliminary_ = true;
}

}  // namespace ftp

#endif  // !FTP_REQUEST_CPP
