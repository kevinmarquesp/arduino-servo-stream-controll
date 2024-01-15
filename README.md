# arduino-servo-stream-controll
<!--TODO: add a project's description-->

## Commands Available
+ **`b | begin *pin:min:max`**: Use this command to create and attach each servo
  on each pin specified. The ammount of arguments given will determine how much
  servos you are dealing with.

+ **`wa | write_all *deg`**: Write the position for each servo, the position of
  each argument will determine which servo you'll select to move (e.g.: the
  first argument will move the first motor, the seccond argument will move the
  seccond motor, and so on)

## Development Notes & Contribution Related
**Project's dependencies**:
+ [LinkedList](https://github.com/ivanseidel/LinkedList) (you can install with `arduino-cli lib install LinkedList`)
+ [ParallelServo](https://github.com/kevinmarquesp/ParallelServo)

Next todos:
+ [ ] Write the documentation for the `get_pos` command
+ [ ] Rename the `clean_input_string()` function from the `string` module
+ [ ] Create a `get_lenght` command for debug propurses
+ [ ] Cleanup the `servos_list` on the `begin` command if it's already filled up