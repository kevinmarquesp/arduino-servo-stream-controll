#pragma once
#include <Arduino.h>
#include <LinkedList.h>
#include "../types/types.h"

template <typename K, typename V>
class HashMap {
private:
  LinkedList<K> _keys_list;
  LinkedList<V> _vals_list;

public:
  inline HashMap(void) : _keys_list(nullptr), _vals_list(nullptr) {}
  inline ~HashMap(void) {}

  void add(K, V);
  status_t<V> get(K);
};
