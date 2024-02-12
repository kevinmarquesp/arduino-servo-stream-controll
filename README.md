# Arduino Servo Stream Controll *<sup>`under dev.`</sup>*
<!--TODO: add a project's description-->

## Commands Available[^1]
[^1]: Each command listed here will be formated with the following notation: `command_name/arity (abbr) arg_format`; Where `command_name` is the name of the command, `arity` is how much arguments this command expect (when it's a `*` means that this command can handle *N* number of arguments), `abbr` the abreviated variation that you can use intead of `command_name` and the `arg_format` is the expected format for each argument -- E. g. `min:max` means that something like `15:150` is expected (most of the time, the arguments will be numbers separated by the `:` character)

+ **`begin/* (b) pin:min:max`**: Use this command to create and attach each servo
  on each pin specified. The ammount of arguments given will determine how much
  servos you are dealing with.
    + Send: `begin 5:0:180 6:0:180 7:0:180`
    + Expect: *No errors*, the servos at pin 5, 6 and 7 should be attached

+ **`write_all/* (wa) deg`**: Write the position for each servo, the position of
  each argument will determine which servo you'll select to move (e.g.: the
  first argument will move the first motor, the seccond argument will move the
  seccond motor, and so on)
    + Send: `write_all 180 180 180`
    + Expect: *No errors*, the first three servos should be at its max position

+ **`get_pos/0 (gp)`**: Returns a list of the current servo positions, it is important
  that the servos was already set by the `begin` command.
    + Send: `get_pos`
    + Expect: `50 75 180`

## Development Notes & Contribution Related
**Project's dependencies**:
+ [LinkedList](https://github.com/ivanseidel/LinkedList) (you can install with `arduino-cli lib install LinkedList`)
+ [ParallelServo](https://github.com/kevinmarquesp/ParallelServo)

Next todos:
+ [ ] Cleanup the `servos_list` on the `begin` command if it's already filled up
+ [ ] Create a `get_lenght` command for debug propurses
+ [x] ~~Rename the `clean_input_string()` function from the `string` module~~
+ [x] ~~Write the documentation for the `get_pos` command~~