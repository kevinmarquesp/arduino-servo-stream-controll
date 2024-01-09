#pragma once
#include <Arduino.h>

namespace string {
  void clean_input_string(String& user_input);
  uint8_t count_character(String& user_input, char target_char);
}  //namespace string
