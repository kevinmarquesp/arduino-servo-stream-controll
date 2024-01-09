#pragma once
#include <Arduino.h>
#include <LinkedList.h>
#include "../types/types.h"

template <typename K, typename V>
class HashMap {
private:
  LinkedList<K>* _keys_list;
  LinkedList<V>* _vals_list;

public:
  inline HashMap(void) : _keys_list(new LinkedList<K>()), _vals_list(new LinkedList<V>()) {}
  inline ~HashMap(void) {}

  void add(K key, V val) {
    _keys_list->add(key);
    _vals_list->add(val);
  }

  status_t<V> get(K key) {
    for (u8 i = 0; i < _keys_list->size(); ++i)
      if (_keys_list->get(i) == key)
        return {true, _vals_list->get(i)};

    return {false};
  }
};
