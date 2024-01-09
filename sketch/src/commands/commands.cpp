#include <StringSplitter.h>
#include "commands.h"

#define print(c) Serial.print(c)
#define println(c) Serial.println(c)

void commands::begin(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  if (argc == 0) {
    println("err : arguments are required, zero specifyed...");
    return;
  }

  if (servos_list.size() > 0) {
    println("warn : it will clean the current list and create a new one");
    servos_list.clear();
  }

  const char dlmtr = ':';  //each sub-arg will be separated by this delimeter
  StringSplitter* args = new StringSplitter(argv, ' ', argc);
  u8 items_count = args->getItemCount();

  for (u8 i = 0; i < items_count; ++i) {
    String arg = args->getItemAtIndex(i);

    StringSplitter* cases = new StringSplitter(arg, dlmtr, 3);

    if (cases->getItemCount() != 3) {
      println("err : invalid argument set, should be `pin:min:max`");
      return;
    }

    u8 pin = cases->getItemAtIndex(0).toInt();
    u8 min = cases->getItemAtIndex(1).toInt();
    u8 max = cases->getItemAtIndex(2).toInt();

    ParallelServo new_servo;

    new_servo.begin(pin, min, max);
    servos_list.add(new_servo);
  }
}

void commands::attach(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  if (argc == 0) {
    println("err : arguments are required, zero specifyed...");
    return;
  }

  if (servos_list.size() == 0) {
    println("err : there is no servos yet, use the `begin/*` command for that");
    return;
  }

  StringSplitter* args = new StringSplitter(argv, ' ', argc);
  u8 items_count = args->getItemCount();

  for (u8 i = 0; i < items_count; ++i) {
    if (i == servos_list.size())
      break;

    u8 pin = args->getItemAtIndex(i).toInt();
    servos_list.get(i).attach(pin);
  }
}

void commands::write_all(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  if (argc == 0) {
    println("err : arguments are required, zero specifyed...");
    return;
  }

  if (servos_list.size() == 0) {
    println("err : there is no servos yet, use the `begin/*` command for that");
    return;
  }

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
}
