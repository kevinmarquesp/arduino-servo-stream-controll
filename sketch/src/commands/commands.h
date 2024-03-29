#pragma once
#include <Arduino.h>
#include <LinkedList.h>
#include <ParallelServo.h>
#include "../types/types.h"

namespace commands {
  void begin(llps_t&, u8, String);
  void write_all(llps_t&, u8, String);
  void get_pos(llps_t&, u8, String);
}  //namespace commands
