#ifndef FTP_IMPL_STATUS_CPP
#define FTP_IMPL_STATUS_CPP

#pragma once

#include <ftp/status.hpp>

namespace ftp {

constexpr status int_to_status(unsigned i) noexcept
{
  switch (static_cast<status>(i))
  {
  case status::positive_preliminary:
  case status::restart_marker_reply:
  case status::service_ready_in_some_minutes:
  case status::data_conn_open_transfer_starting:
  case status::file_status_ok_opening_data_conn:
  case status::positive_completion:
  case status::command_not_implemented_superfluous:
  case status::system_status:
  case status::directory_status:
  case status::file_status:
  case status::help_message:
  case status::system_type:
  case status::ready_for_new_users:
  case status::closing_control_conn:
  case status::data_conn_opened:
  case status::data_conn_closed_file_action_ok:
  case status::entering_pasv_mode:
  case status::entering_long_pasv_mode:
  case status::entering_extenden_pasv_mode:
  case status::user_logged_in:
  case status::user_logged_in_by_security_data_exchange:
  case status::client_security_mechanism_ok:
  case status::client_security_data_ok:
  case status::file_action_ok:
  case status::pathname_created:
  case status::positive_intermediate:
  case status::user_name_ok_need_password:
  case status::need_account:
  case status::need_security_data:
  case status::need_more_security_data:
  case status::username_ok_need_password:
  case status::file_action_pending_further_info:
  case status::transient_negative_completion:
  case status::service_not_available:
  case status::data_conn_open_error:
  case status::conn_closed_tranfer_aborted:
  case status::invalid_login_info:
  case status::resource_unavailable:
  case status::host_unavailable:
  case status::file_action_not_taken:
  case status::action_aborted:
  case status::action_not_taken:
  case status::permanent_negative_completion:
  case status::syntax_error_in_parameters_or_arguments:
  case status::command_not_implemented:
  case status::bad_sequence_of_commands:
  case status::command_not_implemented_for_that_parameter:
  case status::not_logged_in:
  case status::need_account_for_storing_files:
  case status::command_protection_level_denied_for_policy:
  case status::request_denied_for_policy:
  case status::failed_security_check:
  case status::data_protection_level_not_supported_by_security:
  case status::command_protection_level_not_supported_by_security:
  case status::action_not_taken_file_unavailable:
  case status::action_aborted_page_type_unknown:
  case status::file_action_aborted_exceeded_storage_allocation:
  case status::action_not_taken_file_name_not_allowed: return static_cast<status>(i);
  default: break;
  }
  return status::unknown;
}

constexpr status_class to_status_class(status s) noexcept
{
  switch (static_cast<unsigned>(s) / 100)
  {
  case 1: return status_class::positive_preliminary;
  case 2: return status_class::positive_completion;
  case 3: return status_class::positive_intermediate;
  case 4: return status_class::transient_negative_completion;
  case 5: return status_class::permanent_negative_completion;
  default: break;
  }
  return status_class::unknown;
}

constexpr status_class to_status_class(unsigned s) noexcept { return to_status_class(int_to_status(s)); }

constexpr status_group to_status_group(status s) noexcept
{
  if (s == status::unknown)
    return status_group::unknown;
  switch ((static_cast<unsigned>(s) % 100) / 10)
  {
  case 0: return status_group::syntax;
  case 1: return status_group::information;
  case 2: return status_group::connections;
  case 3: return status_group::authentication_and_accounting;
  case 4: return status_group::unspecified;
  case 5: return status_group::filesystem;
  default: break;
  }
  return status_group::unknown;
}

constexpr status_group to_status_group(unsigned s) noexcept { return to_status_group(int_to_status(s)); }

}  // namespace ftp

#endif
