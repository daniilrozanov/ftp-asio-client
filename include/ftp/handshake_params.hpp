#ifndef _HANDSHAKE_PARAMS_HPP_
#define _HANDSHAKE_PARAMS_HPP_

#include <string>

namespace ftp {
class handshake_params
{
  std::string host_;
  std::string username_;
  std::string password_;
  int port;
};
}  // namespace ftp

#endif  // !_HANDSHAKE_PARAMS_HPP_
