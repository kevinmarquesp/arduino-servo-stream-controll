#pragma once
#include <LinkedList.h>
#include <ParallelServo.h>

#define u8 uint8_t

using llps_t = LinkedList<ParallelServo>;
using lambda_command_t = void (*)(llps_t&, u8, String);

template <typename T>
class status_t {
public:
  bool is_ok;
  T acc;
};
