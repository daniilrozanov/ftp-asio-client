#ifndef FTP_STATUS_HPP
#define FTP_STATUS_HPP

#pragma once

namespace ftp {

enum class status : unsigned
{
  unknown = 0,
  // Positive Preliminary reply
  positive_preliminary = 100,
  restart_marker_reply = 110,
  service_ready_in_some_minutes = 120,
  data_conn_open_transfer_starting = 125,
  file_status_ok_opening_data_conn = 150,
  // Positive Completion reply
  positive_completion = 200,
  command_not_implemented_superfluous = 202,
  system_status = 211,
  directory_status = 212,
  file_status = 213,
  help_message = 214,
  system_type = 215,
  ready_for_new_users = 220,
  closing_control_conn = 221,
  data_conn_opened = 225,
  data_conn_closed_file_action_ok = 226,
  entering_pasv_mode = 227,
  entering_long_pasv_mode = 228,
  entering_extenden_pasv_mode = 229,
  user_logged_in = 230,
  user_logged_in_by_security_data_exchange = 232,
  client_security_mechanism_ok = 234,
  client_security_data_ok = 235,
  file_action_ok = 250,
  pathname_created = 257,
  // Positive Intermediate reply
  positive_intermediate = 300,
  user_name_ok_need_password = 331,
  need_account = 332,
  need_security_data = 334,
  need_more_security_data = 335,
  username_ok_need_password = 336,
  file_action_pending_further_info = 350,
  // Transient Negative Completion reply
  transient_negative_completion = 400,
  service_not_available = 421,
  data_conn_open_error = 425,
  conn_closed_tranfer_aborted = 426,
  invalid_login_info = 430,
  resource_unavailable = 431,
  host_unavailable = 434,
  file_action_not_taken = 450,
  action_aborted = 451,
  action_not_taken = 452,
  // Permanent Negative Completion reply
  permanent_negative_completion = 500,
  syntax_error_in_parameters_or_arguments = 501,
  command_not_implemented = 502,
  bad_sequence_of_commands = 503,
  command_not_implemented_for_that_parameter = 504,
  not_logged_in = 530,
  need_account_for_storing_files = 532,
  command_protection_level_denied_for_policy = 533,
  request_denied_for_policy = 534,
  failed_security_check = 535,
  data_protection_level_not_supported_by_security = 536,
  command_protection_level_not_supported_by_security = 537,
  action_not_taken_file_unavailable = 550,
  action_aborted_page_type_unknown = 551,
  file_action_aborted_exceeded_storage_allocation = 552,
  action_not_taken_file_name_not_allowed = 553
};

enum class status_class : unsigned
{
  unknown = 0,
  positive_preliminary = 1,
  positive_completion = 2,
  positive_intermediate = 3,
  transient_negative_completion = 4,
  permanent_negative_completion = 5,
};

enum class status_group : unsigned
{
  unknown = 10,
  syntax = 0,
  information = 1,
  connections = 2,
  authentication_and_accounting = 3,
  unspecified = 4,
  filesystem = 5

};

status int_to_status(unsigned i) noexcept;

status_class to_status_class(unsigned s) noexcept;

status_class to_status_class(status s) noexcept;

status_group to_status_group(unsigned s) noexcept;

status_group to_status_group(status s) noexcept;

}  // namespace ftp

#ifdef FTP_HEADER_ONLY
#include <ftp/impl/status.cpp>
#endif

#endif  // !FTP_STATUS_HPP
