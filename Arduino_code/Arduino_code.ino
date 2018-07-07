byte pin_data = 2;
byte pin_latch = 3;
byte pin_clock = 4;
uint32_t pattern = 0b0000000000000011;
byte LEDs_count = 13;
byte pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin_latch, OUTPUT);
  pinMode(pin_clock, OUTPUT);
  pinMode(pin_data, OUTPUT);
}

void loop() {
  uint32_t val = 0;
  val = pattern << pos;
  pos = (pos + 1) % LEDs_count;

  digitalWrite(pin_latch, LOW);
  shiftOut(pin_data, pin_clock, LSBFIRST, (val & 0xFF) | ((val >> LEDs_count) & 0xFF));
  shiftOut(pin_data, pin_clock, LSBFIRST, ((val >> 8) & 0xFF) | ((val >> (LEDs_count + 8)) & 0xFF));
  digitalWrite(pin_latch, HIGH);
  delay(110);
}

