#ifndef FTP_FILE_STRUCTURE_HPP
#define FTP_FILE_STRUCTURE_HPP

#include <string_view>

namespace ftp {

enum class file_struct
{
  file,
  record,
  page
};

std::string_view to_string(file_struct s);

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/impl/file_structure.cpp>
#endif  // FTP_HEADER_ONLY

#endif  // !FTP_FILE_STRUCTURE_HPP
