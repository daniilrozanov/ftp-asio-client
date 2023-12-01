#ifndef FTP_RESPONCE_CPP
#define FTP_RESPONCE_CPP

#include "ftp/status.hpp"
#include <ftp/response.hpp>

namespace ftp {

response::response(const response& other) = default;

response::response(response&& other) = default;

response::response(unsigned s, const std::string& message) : s_(int_to_status(s)), message_(message) {}

response::response(const enum status s, const std::string& message) : s_(s), message_(message) {}

response::response(unsigned s, std::string&& message) : s_(int_to_status(s)), message_(message) {}

response::response(const enum status s, std::string&& message) : s_(s), message_(message) {}

status response::status() const noexcept { return s_; }

status_class response::status_class() const noexcept { return to_status_class(s_); }

status_group response::status_group() const noexcept { return to_status_group(s_); }

const std::string& response::message() const noexcept { return message_; }

bool response::has_error() const noexcept
{
  if (s_ == status::unknown || to_status_class(s_) == status_class::permanent_negative_completion ||
      to_status_class(s_) == status_class::transient_negative_completion)
    return true;
  return false;
  ;
}

}  // namespace ftp

#endif  // !FTP_RESPONCE_CPP
