#ifndef FTP_RESPONSE_HPP
#define FTP_RESPONSE_HPP

#include <ftp/status.hpp>
#include <string>

namespace ftp {

class response
{
  response(const status s, const std::string& message);
  response(unsigned s, const std::string& message);
  response(const status s, std::string&& message);
  response(unsigned s, std::string&& message);
  response(const response& other);
  response(response&& other);

  status status() const noexcept;
  status_class status_class() const noexcept;
  status_group status_group() const noexcept;
  const std::string& message() const noexcept;
  bool has_error() const noexcept;

private:
  const enum status s_;
  const std::string message_;
};

}  // namespace ftp

#endif  // !FTP_RESPONCE_HPP
