SKETCH_DIR ?= sketch
TESTS_DIR  ?= tests
VENDOR_DIR ?=

ARDUINO_CLI_BIN ?= ${HOME}/.local/bin/arduino-cli
SOURCE_FLAGS    ?= --library $(SKETCH_DIR)/src
VENDOR_FLAGS    ?=

BOARD_NAME_SHORT ?= uno
BOARD_NAME_LONG  ?= arduino:avr:uno
PORT             ?= /dev/ttyUSB0
BAUD_RATE        ?= 115200

compile:
	@$(ARDUINO_CLI_BIN) compile $(VENDOR_FLAGS) --fqbn $(BOARD_NAME_LONG) --port $(PORT) $(SKETCH_DIR)

upload:
	@$(ARDUINO_CLI_BIN) compile --upload $(VENDOR_FLAGS) --fqbn $(BOARD_NAME_LONG) --port $(PORT) $(SKETCH_DIR)

test:
	@$(ARDUINO_CLI_BIN) compile --upload $(VENDOR_FLAGS) $(SOURCE_FLAGS) --fqbn $(BOARD_NAME_LONG) --port $(PORT) $(TESTS_DIR);\
	stty -F $(PORT) raw $(BAUD_RATE); cat $(PORT)
