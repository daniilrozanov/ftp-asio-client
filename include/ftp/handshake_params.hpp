#ifndef FTP_HANDSHAKE_PARAMS_HPP
#define FTP_HANDSHAKE_PARAMS_HPP

#include <string>

namespace ftp {

class handshake_params
{
public:
  handshake_params(const std::string& username, const std::string& password, const std::string& account = {})
      : username_(username), password_(password), account_(account)
  {
  }
  handshake_params(std::string&& username, std::string&& password, std::string&& account = {})
      : username_(username), password_(password), account_(account)
  {
  }
  const std::string& username() const noexcept { return username_; }
  const std::string& password() const noexcept { return password_; }
  const std::string& account() const noexcept { return account_; }

private:
  std::string username_;
  std::string password_;
  std::string account_;
};

}  // namespace ftp

#endif  // !FTP_HANDSHAKE_PARAMS_HPP
