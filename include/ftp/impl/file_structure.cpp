#ifndef FTP_FILE_STRUCTURE_CPP
#define FTP_FILE_STRUCTURE_CPP

#pragma once

#include <ftp/file_structure.hpp>

namespace ftp {

std::string_view to_string(file_struct s)
{
  using namespace std::string_view_literals;
  switch (s)
  {
  case file_struct::file: return "F"sv;
  case file_struct::record: return "R"sv;
  case file_struct::page: return "P"sv;
  }
  return "<unknown>"sv;
}

}  // namespace ftp

#endif  // !FTP_FILE_STRUCTURE_CPP
