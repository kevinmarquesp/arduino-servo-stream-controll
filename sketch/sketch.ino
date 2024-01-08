#define START_DELAY_MS 500

void setup(void) {
  Serial.begin(115200);

  delay(START_DELAY_MS);
}

void loop(void) {
  String user_input = read_serial_user_input_string();
  Serial.println(user_input);
}
