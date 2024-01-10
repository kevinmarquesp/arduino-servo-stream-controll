#include "../string/string.h"
#include "commands.h"

#define print(c) Serial.print(c)
#define println(c) Serial.println(c)
#define throw_when(cond) if (cond) { println("!err : wrong usage"); return; }

void commands::begin(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  throw_when(argc == 0 || servos_list.size() > 0);

  const char config_dlmtr = ':';  //each sub-arg will be separated by this delimeter

  LinkedList<String> args_list = string::split(argv, ' ');

  for (u8 i = 0; i < args_list.size(); ++i) {
    String curr_arg = args_list.get(i);

    LinkedList<String> servos_config_list = string::split(curr_arg, config_dlmtr);
    throw_when(servos_config_list.size() != 3);

    u8 pin = servos_config_list.get(0).toInt();
    u8 min = servos_config_list.get(1).toInt();
    u8 max = servos_config_list.get(2).toInt();

    ParallelServo new_servo;

    new_servo.begin(pin, min, max);
    servos_list.add(new_servo);
  }
}

void commands::attach(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  throw_when(argc == 0 || servos_list.size() == 0);

  LinkedList<String> args_list = string::split(argv, ' ');

  for (u8 i = 0; i < args_list.size(); ++i) {
    if (i == servos_list.size())
      break;

    u8 pin = args_list.get(i).toInt();
    servos_list.get(i).attach(pin);
  }
}

void commands::write_all(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  throw_when(argc == 0 || servos_list.size() == 0);

  const char ignore_char = '@';  //ignores arguments that starts with this char
  LinkedList<String> args_list = string::split(argv, ' ');

  for (u8 i = 0; i < args_list.size(); ++i) {
    if (i == servos_list.size())
      break;

    String str_deg = args_list.get(i);

    if (str_deg.charAt(0) == ignore_char)
      continue;

    u8 deg = str_deg.toInt();

    servos_list.get(i).write(deg);
  }
}
