#ifndef FTP_REPRESENTATION_TYPE_CPP
#define FTP_REPRESENTATION_TYPE_CPP

#pragma once

#include <ftp/representation_type.hpp>

namespace ftp {

std::string_view to_string(representation_type t)
{
  using namespace std::string_view_literals;
  switch (t)
  {
  case representation_type::ascii_non_print: return "A"sv;
  case representation_type::ascii_telnet: return "A T"sv;
  case representation_type::ascii_carriage: return "A C"sv;
  case representation_type::ebcdic_non_print: return "E"sv;
  case representation_type::ebcdic_telnet: return "E T"sv;
  case representation_type::ebcdic_carriage: return "E C"sv;
  case representation_type::image: return "I"sv;
  case representation_type::local_byte: return "L"sv;
  }
  return "<unknown>"sv;
}

}  // namespace ftp

#endif  // !FTP_REPRESENTATION_TYPE_CPP
