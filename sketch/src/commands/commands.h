#pragma once
#include <Arduino.h>
#include <LinkedList.h>
#include <ParallelServo.h>
#include "../types/types.h"

namespace commands {
  void attach(LinkedList<ParallelServo>&, u8, String);
}  //namespace commands
