#include <LinkedList.h>
#include <ParallelServo.h>
#include "src/HashMap/HashMap.h"
#include "src/string/string.h" 
#include "src/types/types.h" 

#define print(c) Serial.print(c)
#define println(c) Serial.println(c)

#define BAUD_RATE 115200
#define START_DELAY_MS 500

LinkedList<ParallelServo> servos_list;
HashMap<String, void (*)(void)> shell_hm;

extern String read_serial_user_input_string(void);

void setup(void) {
  Serial.begin(BAUD_RATE);

  shell_hm.add("ping", [](void){ println("pong"); });

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

  status_t<void (*)(void)> get_status = shell_hm.get(command);

  if (!get_status.is_ok) {
    print("err : the command `");
    print(command);
    println("` doesn't exist");

    return;
  }

  get_status.acc();
}
