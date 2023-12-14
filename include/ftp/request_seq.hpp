#ifndef FTP_REQUEST_SEQ_HPP
#define FTP_REQUEST_SEQ_HPP

#pragma once

#include <ftp/command.hpp>
#include <string>

namespace ftp {

class request_seq
{
public:
  struct config
  {
    bool ignore_preliminary = true;
    bool cancel_on_connection_lost = true;
  };

  request_seq();
  request_seq(cmd c);
  request_seq(cmd c, std::string_view arg);

  const config& get_config() const noexcept;
  config& get_config() noexcept;

  std::string_view payload() const noexcept;

  void push(cmd c, std::string_view arg);

private:
  void add_cmd(cmd c, std::string_view arg = {});

  std::string payload_;
  config cfg_;
  int commands_ = 0;
  bool has_preliminary_ = false;
};

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/impl/request_seq.cpp>
#endif  // FTP_HEADER_ONLY

#endif  // !FTP_REQUEST_SEQ_HPP
