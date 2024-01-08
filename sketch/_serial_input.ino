inline void clean_input_string(String& user_input) {
  user_input.trim();
  user_input.toLowerCase();
}

inline String read_serial_user_input_string(void) {
  while (!Serial.available())
    continue;

  String user_input = Serial.readStringUntil('\n');
  clean_input_string(user_input);

  return user_input;
}
