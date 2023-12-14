#ifndef FTP_DEFAULTS_HPP
#define FTP_DEFAULTS_HPP

#include <string_view>

namespace ftp {

using namespace std::string_view_literals;

constexpr const int default_server_command_port = 21;

constexpr const std::string_view default_server_command_port_sv = "21"sv;

constexpr const int default_server_data_port = 20;

constexpr const std::string_view default_server_data_port_sv = "20"sv;

}  // namespace ftp

#endif  // !FTP_DEFAULTS_HPP
