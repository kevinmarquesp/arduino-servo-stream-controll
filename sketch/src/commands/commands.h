#pragma once
#include <Arduino.h>
#include <LinkedList.h>
#include <ParallelServo.h>
#include "../types/types.h"

namespace commands {
  void begin(llps_t&, u8, String);
  void attach(llps_t&, u8, String);
  void write_all(llps_t&, u8, String);
}  //namespace commands
