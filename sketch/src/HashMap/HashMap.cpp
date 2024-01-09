#include "HashMap.h"

template <typename K, typename V>
void HashMap::add(K key, V val) {
  if (_keys_list == nullptr || _vals_list == nullptr) {
    _keys_list = new LinkedList<K>();
    _vals_list = new LinkedList<V>();
  }

  _keys_list->add(key);
  _vals_list->add(val);
}

template <typename K, typename V>
status_t<V> HashMap::get(K key) {
  for (u8 i = 0; i < _keys_list->size(); ++i)
    if (_keys_list->get(i) == key)
      return {true, _vals_list->get(i)};

  return {false};
}
