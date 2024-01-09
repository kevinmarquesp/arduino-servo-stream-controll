#pragma once
#include <LinkedList.h>
#include <ParallelServo.h>

#define u8 uint8_t

template <typename T>
class status_t {
public:
  bool is_ok;
  T acc;
};

using command_lambda_t = void (*)(LinkedList<ParallelServo>&, u8, String);
