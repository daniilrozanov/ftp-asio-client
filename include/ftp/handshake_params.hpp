#ifndef FTP_HANDSHAKE_PARAMS_HPP
#define FTP_HANDSHAKE_PARAMS_HPP

#include <string>

namespace ftp {

class handshake_params
{
public:
  handshake_params(const std::string& username, const std::string& password)
      : username_(username), password_(password)
  {
  }
  handshake_params(std::string&& username, std::string&& password) : username_(username), password_(password)
  {
  }
  const std::string& username() const noexcept { return username_; }
  const std::string& password() const noexcept { return password_; }

private:
  std::string username_;
  std::string password_;
};

}  // namespace ftp

#endif  // !FTP_HANDSHAKE_PARAMS_HPP
