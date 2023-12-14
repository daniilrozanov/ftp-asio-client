#ifndef FTP_REQUEST_SEQ_CPP
#define FTP_REQUEST_SEQ_CPP

#include "ftp/command.hpp"
#include <string_view>
#pragma once

#include <ftp/request_seq.hpp>

namespace ftp {

request_seq::request_seq() {}

request_seq::request_seq(cmd c) { add_cmd(c); }

request_seq::request_seq(cmd c, std::string_view arg) { add_cmd(c, arg); }

std::string_view request_seq::payload() const noexcept { return payload_; }

const request_seq::config& request_seq::get_config() const noexcept { return cfg_; }

request_seq::config& request_seq::get_config() noexcept { return cfg_; }

void request_seq::push(cmd c, std::string_view arg) { add_cmd(c, arg); }

void request_seq::add_cmd(cmd c, std::string_view arg)
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

#endif  // !FTP_REQUEST_SEQ_CPP
