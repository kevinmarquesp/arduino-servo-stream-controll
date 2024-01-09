#pragma once

#define u8 uint8_t

template <typename T>
class status_t {
public:
  bool is_ok;
  T acc;
};
