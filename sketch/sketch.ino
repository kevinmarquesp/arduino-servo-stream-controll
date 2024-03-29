#include <LinkedList.h>
#include <ParallelServo.h>
#include "src/HashMap/HashMap.h"
#include "src/types/types.h" 
#include "src/commands/commands.h"
#include "src/string/string.h" 

#define print(c) Serial.print(c)
#define println(c) Serial.println(c)

#define BAUD_RATE 115200
#define START_DELAY_MS 500

llps_t servos_list;
HashMap<String, lambda_command_t> shell_hm;

extern String read_serial_user_input_string(void);
extern void display_command_arity(String, u8, String);
extern void display_command_dosent_exist_error(String, u8);
extern void add_new_command(HashMap<String, lambda_command_t>&, String, lambda_command_t);

void setup(void) {
  Serial.begin(BAUD_RATE);

  add_new_command(shell_hm, "b begin", commands::begin);
  add_new_command(shell_hm, "wa write_all", commands::write_all);
  add_new_command(shell_hm, "gp get_pos", commands::get_pos);

  delay(START_DELAY_MS);
}

void loop(void) {
  String user_input = read_serial_user_input_string();
  u8 first_space_idx = user_input.indexOf(' ');
  u8 user_input_len = user_input.length();

  String command = user_input.substring(0, first_space_idx);
  String argv = user_input.substring(first_space_idx + 1, user_input_len);
  u8 argc = string::count_character(user_input, ' ');

  if (user_input.length() == 0) {
    println("err : command not specified");
    return;
  }

  status_t<lambda_command_t> get_status = shell_hm.get(command);

  if (!get_status.is_ok) {
    display_command_dosent_exist_error(command, argc);
    return;
  }

  display_command_arity(command, argc, argv);
  get_status.acc(servos_list, argc, argv);
}
