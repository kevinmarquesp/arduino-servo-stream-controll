#include <LinkedList.h>
#include <ParallelServo.h>

#include "src/commands/commands.h"

test(BeginCommand, commands_begin_fills_servos_list) {
  // Arrange
  LinkedList<ParallelServo*> servos_list;
  String args = "5:0:180 6:0:180 7:0:180"; // Sample arguments for one servo
  u8 argc = 3;

  // Act
  commands::begin(servos_list, argc, args);

  // Assert
  assertEqual(servos_list.size(), 3); // Check if the servos_list is not empty after calling the function
}

test(BeginCommand, commands_begin_clears_list_when_already_filled) {
  // Arrange
  LinkedList<ParallelServo*> servos_list;
  commands::begin(servos_list, 1, "5:0:180"); // Adding a dummy servo to the list
  commands::begin(servos_list, 0, ""); // Call the function to clear the list
  
  // Assert
  assertEqual(servos_list.size(), 0); // Check if the list is empty after calling the function
}

test(BeginCommand, commands_begin_ignores_ignored_arguments) {
  // Arrange
  LinkedList<ParallelServo*> servos_list;
  String args = "5:0:180 @6:0:180 7:0:180"; // Ignored argument
  u8 argc = 3;

  // Act
  commands::begin(servos_list, argc, args);

  // Assert
  assertEqual(servos_list.size(), 2); // Check if the list size remains unchanged
}

test(BeginCommand, commands_begin_overwrites_filled_list_with_new_servos) {
  // Arrange
  LinkedList<ParallelServo*> servos_list;
  commands::begin(servos_list, 2, "5:0:180 6:0:180"); // Adding a dummy servo to the list

  // Act
  commands::begin(servos_list, 1, "5:0:180"); // Sample arguments for one servo

  // Assert
  assertEqual(servos_list.size(), 1); // Check if the list size is correct after adding a servo
  // Additional assertions can be made to ensure the correct servo data is stored in the list
}