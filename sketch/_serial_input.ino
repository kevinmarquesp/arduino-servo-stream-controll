#include "src/string/string.h"

inline String read_serial_user_input_string(void) {
  while (!Serial.available())
    continue;

  String user_input = Serial.readStringUntil('\n');
  string::sanitize(user_input);

  return user_input;
}
