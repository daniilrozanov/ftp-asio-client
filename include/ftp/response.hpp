#ifndef FTP_RESPONSE_HPP
#define FTP_RESPONSE_HPP

#pragma once

#include <ftp/status.hpp>
#include <string>
#include <string_view>

namespace ftp {

namespace detail {
template <typename Executor>
class command_connection;
}

class response
{
public:
  response();
  response(const status s, const std::string& message);
  response(unsigned s, const std::string& message);
  response(const status s, std::string&& message);
  response(unsigned s, std::string&& message);
  response(const response& other);
  response(response&& other);

  status status() const noexcept;
  status_class status_class() const noexcept;
  status_group status_group() const noexcept;
  const std::string_view message() const noexcept;
  bool has_error() const noexcept;

  template <typename U>
  friend class detail::command_connection;

private:
  void clear();
  bool build_self();

  enum status s_;
  std::string_view message_;
  std::string data_;
};

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/impl/response.cpp>
#endif  // DEBUG

#endif  // !FTP_RESPONSE_HPP
