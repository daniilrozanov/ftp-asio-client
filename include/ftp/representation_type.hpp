#ifndef FTP_REPRESENTATION_TYPE_HPP
#define FTP_REPRESENTATION_TYPE_HPP

#include <string_view>

namespace ftp {

enum class representation_type
{
  ascii_non_print,
  ascii_telnet,
  ascii_carriage,
  ebcdic_non_print,
  ebcdic_telnet,
  ebcdic_carriage,
  image,
  local_byte
};

std::string_view to_string(representation_type t);

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/impl/representation_type.cpp>
#endif  // FTP_HEADER_ONLY

#endif  // !FTP_REPRESENTATION_TYPE_HPP
