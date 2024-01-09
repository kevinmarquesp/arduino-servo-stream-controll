#pragma once
#include <Arduino.h>
#include "../types/types.h"

namespace string {
  void clean_input_string(String&);
  u8 count_character(String&, char);
}  //namespace string
