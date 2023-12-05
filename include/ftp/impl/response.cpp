#ifndef FTP_RESPONCE_CPP
#define FTP_RESPONCE_CPP

#pragma once

#include <ftp/response.hpp>
#include <ftp/status.hpp>

#include <cctype>
#include <string_view>

namespace ftp {

response::response() : s_(status::unknown), message_(), data_() {}

response::response(const response& other) = default;

response::response(response&& other) = default;

response::response(unsigned s, const std::string& message) : s_(int_to_status(s)), message_(message) {}

response::response(const enum status s, const std::string& message) : s_(s), message_(message) {}

response::response(unsigned s, std::string&& message) : s_(int_to_status(s)), message_(message) {}

response::response(const enum status s, std::string&& message) : s_(s), message_(message) {}

status response::status() const noexcept { return s_; }

status_class response::status_class() const noexcept { return to_status_class(s_); }

status_group response::status_group() const noexcept { return to_status_group(s_); }

const std::string_view response::message() const noexcept { return message_; }

bool response::has_error() const noexcept
{
  if (s_ == status::unknown || to_status_class(s_) == status_class::permanent_negative_completion ||
      to_status_class(s_) == status_class::transient_negative_completion)
    return true;
  return false;
  ;
}

bool response::build_self()
{
  if (data_.length() < 3)
    return false;
  if (!std::isdigit(data_[0]) || !std::isdigit(data_[1]) || !std::isdigit(data_[2]))
    return false;
  s_ = int_to_status(std::atoi(data_.c_str()));
  message_ = {data_.data() + 4, data_.size() - 6};
  return true;
}

void response::clear()
{
  s_ = status::unknown;
  message_ = {};
  data_.clear();
}

}  // namespace ftp

#endif  // !FTP_RESPONCE_CPP
