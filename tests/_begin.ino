#include <LinkedList.h>
#include <ParallelServo.h>

test(test_suit, assert_true) {
  assertTrue(true);
}

// TODO: figure out how this test units will include the local `src/` loca sketch library

/*******************************************************************************
test(commands_begin_fills_servos_list) {
  // Arrange
  LinkedList<ParallelServo*> servos_list;
  String args = "3 0 180"; // Sample arguments for one servo
  u8 argc = 3;

  // Act
  commands::begin(servos_list, argc, args);

  // Assert
  assertTrue(servos_list.size() > 0); // Check if the servos_list is not empty after calling the function
}

test(commands_begin_clears_list_when_already_filled) {
  // Arrange
  LinkedList<ParallelServo*> servos_list;
  servos_list.add(new ParallelServo()); // Adding a dummy servo to the list
  commands::begin(servos_list, 0, ""); // Call the function to clear the list
  
  // Assert
  assertEqual(servos_list.size(), 0); // Check if the list is empty after calling the function
}

test(commands_begin_adds_new_servos_to_empty_list) {
  // Arrange
  LinkedList<ParallelServo*> servos_list;
  String args = "3, 0, 180"; // Sample arguments for one servo
  u8 argc = 1;

  // Act
  commands::begin(servos_list, argc, args);

  // Assert
  assert_equal(servos_list.size(), 1); // Check if the list size is correct after adding a servo
}

test(commands_begin_adds_new_servos_to_non_empty_list) {
  // Arrange
  LinkedList<ParallelServo*> servos_list;
  servos_list.add(new ParallelServo()); // Adding a dummy servo to the list
  String args = "3, 0, 180"; // Sample arguments for one servo
  u8 argc = 1;

  // Act
  commands::begin(servos_list, argc, args);

  // Assert
  assert_equal(servos_list.size(), 1); // Check if the list size is correct after adding a servo
}

test(commands_begin_ignores_ignored_arguments) {
  // Arrange
  LinkedList<ParallelServo*> servos_list;
  String args = "-1, 0, 180"; // Ignored argument
  u8 argc = 1;

  // Act
  commands::begin(servos_list, argc, args);

  // Assert
  assert_equal(servos_list.size(), 0); // Check if the list size remains unchanged
}
*******************************************************************************/