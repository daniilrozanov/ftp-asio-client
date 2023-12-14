#ifndef FTP_TRANSFER_PARAMETERS_HPP
#define FTP_TRANSFER_PARAMETERS_HPP

#include <ftp/file_structure.hpp>
#include <ftp/representation_type.hpp>
#include <ftp/transfer_mode.hpp>

namespace ftp {

namespace detail {

struct transfer_params
{
  transfer_mode mode = transfer_mode::stream;
  file_struct f_struct = file_struct::file;
  representation_type repr_type = representation_type::ascii_non_print;
};

}  // namespace detail

}  // namespace ftp

#endif  // !FTP_TRANSFER_PARAMETERS_HPP
