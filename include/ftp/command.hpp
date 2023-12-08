#ifndef FTP_COMMAND_HPP
#define FTP_COMMAND_HPP

#include <string_view>

namespace ftp {

enum class cmd_group
{
  unknown = 0,
  login,
  logout,
  transfer_parameters,
  file_action,
  informational,
  miscellaneous
};

enum class cmd
{
  unknown = 0,
  // login
  user,
  pass,
  acct,
  cwd,
  cdup,
  smnt,
  // logout
  quit,
  rein,
  // transfer parameters
  port,
  pasv,
  type,
  stru,
  mode,
  // file action commands
  retr,
  stor,
  stou,
  appe,
  allo,
  rest,
  rnfr,
  rnto,
  abor,
  dele,
  rmd,
  mkd,
  pwd,
  list,
  nlst,
  // informational commands
  syst,
  stat,
  help,
  // miscellaneous commands
  site,
  noop
};

constexpr std::string_view to_string(cmd c);

constexpr cmd string_to_cmd(std::string_view c);

constexpr cmd_group group_of_cmd(cmd c);

constexpr bool has_preliminary_reply(cmd c);

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/impl/command.cpp>
#endif  // FTP_HEADER_ONLY
#endif  // !FTP_COMMAND_HPP
