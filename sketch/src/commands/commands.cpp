#include <StringSplitter.h>
#include "commands.h"

#define print(c) Serial.print(c)
#define println(c) Serial.println(c)
#define throw_when(cond) if (cond) { println("!err : wrong usage"); return; }

void commands::begin(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  throw_when(argc == 0 || servos_list.size() > 0);

  const char dlmtr = ':';  //each sub-arg will be separated by this delimeter
  StringSplitter* args = new StringSplitter(argv, ' ', argc);
  u8 items_count = args->getItemCount();

  for (u8 i = 0; i < items_count; ++i) {
    String arg = args->getItemAtIndex(i);

    StringSplitter* cases = new StringSplitter(arg, dlmtr, 3);
    throw_when(cases->getItemCount() != 3);

    u8 pin = cases->getItemAtIndex(0).toInt();
    u8 min = cases->getItemAtIndex(1).toInt();
    u8 max = cases->getItemAtIndex(2).toInt();

    ParallelServo new_servo;

    new_servo.begin(pin, min, max);
    servos_list.add(new_servo);

    delete cases;
  }

  delete args;
}

void commands::attach(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  throw_when(argc == 0 || servos_list.size() == 0);

  StringSplitter* args = new StringSplitter(argv, ' ', argc);
  u8 items_count = args->getItemCount();

  for (u8 i = 0; i < items_count; ++i) {
    if (i == servos_list.size())
      break;

    u8 pin = args->getItemAtIndex(i).toInt();
    servos_list.get(i).attach(pin);
  }

  delete args;
}

void commands::write_all(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  throw_when(argc == 0 || servos_list.size() == 0);

  const char ignore_char = '@';  //ignores arguments that starts with this char
  StringSplitter* args = new StringSplitter(argv, ' ', argc);
  u8 items_count = args->getItemCount();

  for (u8 i = 0; i < items_count; ++i) {
    if (i == servos_list.size())
      break;

    String str_deg = args->getItemAtIndex(i);

    if (str_deg.charAt(0) == ignore_char)
      continue;

    u8 deg = str_deg.toInt();

    servos_list.get(i).write(deg);
  }

  delete args;
}
