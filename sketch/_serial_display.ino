#include "src/types/types.h" 

#define print(c) Serial.print(c)
#define println(c) Serial.println(c)

inline void display_command_arity(String command, u8 argc, String argv) {
  print(command);
  print("/");
  print(argc);
  print(" -> ");
  println(argv.length() <= 0 ? "NULL" : argv);
}

inline void display_command_dosent_exist_error(String command, u8 argc) {
  print("err : the command `");
  print(command);
  print("/");
  print(argc);
  println("` doesn't exist");
}
