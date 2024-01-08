#define print(c) Serial.print(c)
#define println(c) Serial.println(c)

#define BAUD_RATE 115200
#define START_DELAY_MS 500

void setup(void) {
  Serial.begin(BAUD_RATE);

  delay(START_DELAY_MS);
}

void loop(void) {
  String user_input = read_serial_user_input_string();
  println(user_input);
}
