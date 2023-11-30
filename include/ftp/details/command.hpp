#ifndef FTP_COMMAND_HPP
#define FTP_COMMAND_HPP

#include <string_view>

namespace ftp {

namespace detail {

using namespace std::string_view_literals;

class command
{
public:
  static constexpr std::string_view user = "USER"sv;

  static constexpr std::string_view pass = "PASS"sv;

  static constexpr std::string_view acct = "ACCT"sv;

  static constexpr std::string_view cwd = "CWD"sv;

  static constexpr std::string_view cdup = "CDUP"sv;

  static constexpr std::string_view smnt = "SMNT"sv;

  static constexpr std::string_view quit = "QUIT"sv;

  static constexpr std::string_view rein = "REIN"sv;

  static constexpr std::string_view port = "PORT"sv;

  static constexpr std::string_view pasv = "PASV"sv;

  static constexpr std::string_view type = "TYPE"sv;

  static constexpr std::string_view stru = "STRU"sv;

  static constexpr std::string_view mode = "MODE"sv;

  static constexpr std::string_view retr = "RETR"sv;

  static constexpr std::string_view stor = "STOR"sv;

  static constexpr std::string_view stou = "STOU"sv;

  static constexpr std::string_view appe = "APPE"sv;

  static constexpr std::string_view allo = "ALLO"sv;

  static constexpr std::string_view rest = "REST"sv;

  static constexpr std::string_view rnfr = "RNFR"sv;

  static constexpr std::string_view rnto = "RNTO"sv;

  static constexpr std::string_view abor = "ABOR"sv;

  static constexpr std::string_view dele = "DELE"sv;

  static constexpr std::string_view rmd = "RMD"sv;

  static constexpr std::string_view mkd = "MKD"sv;

  static constexpr std::string_view pwd = "PWD"sv;

  static constexpr std::string_view list = "LIST"sv;

  static constexpr std::string_view site = "SITE"sv;

  static constexpr std::string_view syst = "SYST"sv;

  static constexpr std::string_view stat = "STAT"sv;

  static constexpr std::string_view help = "HELP"sv;

  static constexpr std::string_view noop = "NOOP"sv;
};

}  // namespace detail

}  // namespace ftp

#endif  // !FTP_COMMAND_HPP
