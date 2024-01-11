#include "../string/string.h"
#include "commands.h"

#define ARGS_DLMTR ' '
#define IGNORE_CHAR '@'
#define SUB_ARGS_DLMTR ':'

#define print(c) Serial.print(c)
#define println(c) Serial.println(c)
#define throw_when(cond) if (cond) { println("!err : wrong usage"); return; }

class BeginData {
public:
  bool ignore;
  u8 pin, min, max;
};

void commands::begin(llps_t& servos_list, u8 argc, String argv) {
  throw_when(argc == 0 || servos_list.size() > 0);

  LinkedList<String> args_list = string::split(argv, ARGS_DLMTR);
  LinkedList<BeginData> begin_data_list;

  for (u8 i = 0; i < args_list.size(); ++i) {  //parse arguments
    String curr_arg = args_list.get(i);

    if (curr_arg.charAt(0) == IGNORE_CHAR) {
      begin_data_list.add({ true, NULL, NULL, NULL });
      continue;
    }

    LinkedList<String> servos_config_list = string::split(curr_arg, SUB_ARGS_DLMTR);
    throw_when(servos_config_list.size() != 3);

    u8 pin = servos_config_list.get(0).toInt();
    u8 min = servos_config_list.get(1).toInt();
    u8 max = servos_config_list.get(2).toInt();

    throw_when(min < 0 || min > 180 || max < 0 || max > 180 || max < min);
    begin_data_list.add({ false, pin, min, max });
  }

  for (u8 i = 0; i < begin_data_list.size(); ++i) {  //apply changes
    BeginData curr_data = begin_data_list.get(i);

    if (curr_data.ignore)
      continue;

    ParallelServo* new_servo = new ParallelServo;

    new_servo->begin(curr_data.pin, curr_data.min, curr_data.max);
    servos_list.add(new_servo);
  }
}

void commands::write_all(llps_t& servos_list, u8 argc, String argv) {
  throw_when(argc == 0 || servos_list.size() == 0);

  LinkedList<String> args_list = string::split(argv, ARGS_DLMTR);

  for (u8 i = 0; i < args_list.size(); ++i) {
    if (i == servos_list.size())
      break;

    String str_deg = args_list.get(i);

    if (str_deg.charAt(0) == IGNORE_CHAR)
      continue;

    u8 deg = str_deg.toInt();

    servos_list.get(i)->move(deg, 0, true);
  }
}

void commands::get_pos(llps_t& servos_list, u8 argc, String argv) {
  throw_when(servos_list.size() == 0);

  String pos_buff = "";

  for (u8 i = 0; i < servos_list.size(); ++i) {
    pos_buff.concat(servos_list.get(i)->getPos());
    pos_buff.concat(' ');
  }

  string::clean_input_string(pos_buff);
  println(pos_buff);
}
