#include <LinkedList.h>
#include "src/HashMap/HashMap.h"
#include "src/types/types.h" 
#include "src/string/string.h" 

using shell_hashmap_t = HashMap<String, lambda_command_t>;

inline void add_new_command(shell_hashmap_t& shell_hm, String command_names, lambda_command_t command_function) {
  string::sanitize(command_names);
  LinkedList<String> command_names_list = string::split(command_names, ' ');

  for (u8 i = 0; i < command_names_list.size(); ++i) {
    String command_name = command_names_list.get(i);
    shell_hm.add(command_name, command_function);
  }
}
