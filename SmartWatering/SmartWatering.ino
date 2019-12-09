//moisture sensor work test
#define relay = 8;
#define sensorPower = 2;
#define sensorControl = A0;
int moisture_value;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPower, OUTPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  digitalWrite(sensorPower, HIGH);
  //get moisture value
  moisture_value = analogRead(sensorControl);
  //output moisutre value to serial console
  Serial.print(moisture_value);
  Serial.print("\n");
  //watering plant is the earth is dry
  if (moisture_value >= 0 && moisture_value <= 550) {
    digitalWrite(relay, HIGH);
    delay(5000);
    digitalWrite(relay, LOW);
  }
  digitalWrite(sensorPower, LOW);
  //time to the next moisture check
  delay(30000);
}
