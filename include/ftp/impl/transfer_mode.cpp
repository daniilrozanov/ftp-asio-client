#ifndef FTP_TRANSFER_MODE_CPP
#define FTP_TRANSFER_MODE_CPP

#pragma once

#include <ftp/transfer_mode.hpp>

namespace ftp {

std::string_view to_string(transfer_mode m)
{
  using namespace std::string_view_literals;
  switch (m)
  {
  case transfer_mode::stream: return "S"sv;
  case transfer_mode::block: return "B"sv;
  case transfer_mode::compressed: return "C"sv;
  }
  return "<unknown>"sv;
}

}  // namespace ftp

#endif  // !FTP_TRANSFER_MODE_CPP
