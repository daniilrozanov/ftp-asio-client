#ifndef FTP_COMMAND_CPP
#define FTP_COMMAND_CPP

#pragma once

#include <ftp/command.hpp>

namespace ftp {

constexpr std::string_view to_string(cmd c)
{
  using namespace std::string_view_literals;
  switch (c)
  {
  case cmd::unknown: return "<unknown>"sv;
  case cmd::user: return "USER"sv;
  case cmd::pass: return "PASS"sv;
  case cmd::acct: return "ACCT"sv;
  case cmd::cwd: return "CWD"sv;
  case cmd::cdup: return "CDUP"sv;
  case cmd::smnt: return "SMNT"sv;
  case cmd::quit: return "QUIT"sv;
  case cmd::rein: return "REIN"sv;
  case cmd::port: return "PORT"sv;
  case cmd::pasv: return "PASV"sv;
  case cmd::type: return "TYPE"sv;
  case cmd::stru: return "STRU"sv;
  case cmd::mode: return "MODE"sv;
  case cmd::retr: return "RETR"sv;
  case cmd::stor: return "STOR"sv;
  case cmd::stou: return "STOU"sv;
  case cmd::appe: return "APPE"sv;
  case cmd::allo: return "ALLO"sv;
  case cmd::rest: return "REST"sv;
  case cmd::rnfr: return "RNFR"sv;
  case cmd::rnto: return "RNTO"sv;
  case cmd::abor: return "ABOR"sv;
  case cmd::dele: return "DELE"sv;
  case cmd::rmd: return "RMD"sv;
  case cmd::mkd: return "MKD"sv;
  case cmd::pwd: return "PWD"sv;
  case cmd::list: return "LIST"sv;
  case cmd::nlst: return "NLST"sv;
  case cmd::site: return "SITE"sv;
  case cmd::syst: return "SYST"sv;
  case cmd::stat: return "STAT"sv;
  case cmd::help: return "HELP"sv;
  case cmd::noop: return "NOOP"sv;
  }
  return "";
}

constexpr cmd string_to_cmd(std::string_view c)
{
  using namespace std::string_view_literals;
  return cmd::unknown;
}

constexpr cmd_group group_of_cmd(cmd c)
{
  switch (c)
  {
  case cmd::user:
  case cmd::pass:
  case cmd::acct:
  case cmd::cwd:
  case cmd::cdup:
  case cmd::smnt: return cmd_group::login;

  case cmd::quit:
  case cmd::rein: return cmd_group::logout;

  case cmd::port:
  case cmd::pasv:
  case cmd::type:
  case cmd::stru:
  case cmd::mode: return cmd_group::transfer_parameters;

  case cmd::retr:
  case cmd::stor:
  case cmd::stou:
  case cmd::appe:
  case cmd::allo:
  case cmd::rest:
  case cmd::rnfr:
  case cmd::rnto:
  case cmd::abor:
  case cmd::dele:
  case cmd::rmd:
  case cmd::mkd:
  case cmd::pwd:
  case cmd::list:
  case cmd::nlst: return cmd_group::file_action;

  case cmd::syst:
  case cmd::stat:
  case cmd::help: return cmd_group::informational;

  case cmd::site:
  case cmd::noop: return cmd_group::miscellaneous;

  case cmd::unknown: return cmd_group::unknown;
  }
}

constexpr bool has_preliminary_reply(cmd c)
{
  switch (c)
  {
  case cmd::rein:
  case cmd::stor:
  case cmd::stou:
  case cmd::list:
  case cmd::retr:
  case cmd::nlst:
  case cmd::appe: return true;
  default: break;
  }
  return false;
}

}  // namespace ftp

#endif  // !FTP_COMMAND_CPP
