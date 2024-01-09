#include "string.h"

inline void strip_inner_character(String& user_input, char strip_target) {
  for (uint8_t i = 1; i < user_input.length(); ++i) {
    char past = user_input.charAt(i - 1);
    char curr = user_input.charAt(i);

    if (curr != strip_target || past != curr)
      continue;

    user_input.remove(i, 1);
    --i;
  }
}

void string::clean_input_string(String& user_input) {
  user_input.trim();
  user_input.toLowerCase();
  strip_inner_character(user_input, ' ');
}
