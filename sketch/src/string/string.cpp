#include "string.h"

inline void strip_inner_character(String& user_input, char strip_target) {
  for (u8 i = 1; i < user_input.length(); ++i) {
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

u8 string::count_character(String& user_input, char target_char) {
  u8 counter = 0;

  for (u8 i = 0; i < user_input.length(); ++i)
    if (user_input.charAt(i) == target_char)
      ++counter;

  return counter;
}
