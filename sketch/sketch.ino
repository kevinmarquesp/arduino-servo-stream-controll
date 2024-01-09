#include "src/string/string.h" 
#include "src/types/types.h" 

#define print(c) Serial.print(c)
#define println(c) Serial.println(c)

#define BAUD_RATE 115200
#define START_DELAY_MS 500

extern String read_serial_user_input_string(void);

void setup(void) {
  Serial.begin(BAUD_RATE);

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

  print(command);
  print("/");
  print(argc);
  print(" -> ");
  println(argv);
}
