#include <StringSplitter.h>
#include "commands.h"

#define print(c) Serial.print(c)
#define println(c) Serial.println(c)

void commands::attach(LinkedList<ParallelServo>& servos_list, u8 argc, String argv) {
  if (argc == 0) {
    println("err : arguments are required, zero specifyed...");
    return;
  }

  if (servos_list.size() == 0) {
    println("err : there is no servos yet, use the `create/1` command for that");
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
