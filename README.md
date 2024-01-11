# arduino-servo-stream-controll

## Commands Available

+ **`b | begin *pin:min:max`**: Use this command to create and attach each servo
  on each pin specified. The ammount of arguments given will determine how much
  servos you are dealing with.

+ **`wa | write_all *deg`**: Write the position for each servo, the position of
  each argument will determine which servo you'll select to move (e.g.: the
  first argument will move the first motor, the seccond argument will move the
  seccond motor, and so on)

## Development Notes & Contribution

**Project's dependencies**:
+ [LinkedList](https://github.com/ivanseidel/LinkedList) (you can install with `arduino-cli lib install LinkedList`)
+ [ParallelServo](https://github.com/kevinmarquesp/ParallelServo)

Development notes and reminders:
+ *All functions should have the following arguments:*
    + *`LinkedList<ParallelServo>& llps`*
    + *`u8 argc`*
    + *`String argv`*

Next todos:
+ [ ] Cleanup the `servos_list` on the `begin` command if it's already filled up
+ [ ] Create a `get_pos` command for debug propurses
+ [ ] Create a `get_lenght` command for debug propurses
+ [x] ~~Remove the `attach` command for now...~~
+ [x] ~~Add the [ParallelServo](https://github.com/kevinmarquesp/ParallelServo) library as dependencie~~
+ [x] ~~Create a global (linked) list of `ParallelServo` objects on the `sketch.ino` file~~
+ [x] ~~Use the `HashMap` object to handle all the shell command/execution stuff~~
+ [x] ~~Create the main command colections:~~
    + [x] ~~Add the `attach` command to the shell (with the `a` alias)~~
    + [x] ~~Add the `set_min` command to the shell (with the `smn` alias)~~
    + [x] ~~Add the `set_max` command to the shell (with the `smx` alias)~~
    + [x] ~~Add the `attach_min_max` command to the shell (with the `amm` alias)~~
+ [x] ~~Clen up memory garbage by deleting the `StringSplitter*` pointers~~
+ [x] ~~Create a local function, on the `commands` module, that process the input data~~
+ [x] ~~Put the argument special character (shell syntax related) into global macros~~
+ [x] ~~Fix the behavior of the begin command : verify arguments and apply changes after~~
