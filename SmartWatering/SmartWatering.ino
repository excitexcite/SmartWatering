//relay work test
#define relay = 8;

void setup() {
  pinMode(relay, OUTPUT);
}

void loop() {
  digitalWrite(relay, HIGH);
  delay(5000);
  digitalWrite(relay, LOW);
}
