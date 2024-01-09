# arduino-servo-stream-controll

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
+ [x] ~~Add the [ParallelServo](https://github.com/kevinmarquesp/ParallelServo) library as dependencie~~
+ [x] ~~Create a global (linked) list of `ParallelServo` objects on the `sketch.ino` file~~
+ [x] ~~Use the `HashMap` object to handle all the shell command/execution stuff~~
+ [ ] Create the main command colections:
    + [x] ~~Add the `attach` command to the shell (with the `a` alias)~~
    + [ ] Add the `set_min` command to the shell (with the `smn` alias)
    + [ ] Add the `set_max` command to the shell (with the `smx` alias)
    + [ ] Add the `attach_min_max` command to the shell (with the `amm` alias)


