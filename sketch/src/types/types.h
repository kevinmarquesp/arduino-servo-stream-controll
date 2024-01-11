#pragma once
#include <LinkedList.h>
#include <ParallelServo.h>

#define u8 uint8_t

using lambda_command_t = void (*)(LinkedList<ParallelServo>&, u8, String);

template <typename T>
class status_t {
public:
  bool is_ok;
  T acc;
};
