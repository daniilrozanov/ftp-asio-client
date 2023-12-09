#ifndef FTP_TRANSFER_MODE_HPP
#define FTP_TRANSFER_MODE_HPP

#pragma once

#include <string_view>
namespace ftp {

enum class transfer_mode
{
  stream,
  block,
  compressed
};

std::string_view to_string(transfer_mode m);

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/impl/transfer_mode.cpp>
#endif  // FTP_HEADER_ONLY

#endif  // !FTP_TRANSFER_MODE_HPP
