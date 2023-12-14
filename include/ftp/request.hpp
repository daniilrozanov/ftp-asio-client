#ifndef FTP_REQUEST_HPP
#define FTP_REQUEST_HPP

#include <ftp/command.hpp>

#include <string>

namespace ftp {

class request
{
public:
  request() noexcept;
  request(cmd c) noexcept;
  request(cmd c, const std::string& arg);

  cmd get_cmd() const noexcept;
  const std::string& get_arg() const noexcept;
  std::string payload() const;

private:
  cmd c_;
  std::string arg_;
};

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/impl/request.cpp>
#endif  // FTP_HEADER_ONLY

#endif  // !FTP_REQUEST_HPP
