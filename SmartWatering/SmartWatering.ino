//diod support test
#define relay = 8;
#define sensorPower = 2;
#define sensorControl = A0;
#define redDiod = 7;
#define greenDiod = 13; 
int moisture_value;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPower, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(redDiod, OUTPUT);
  pinMode(greenDiod, OUTPUT); 
}

void loop() {
  digitalWrite(sensorPower, HIGH);
  //get moisture value
  moisture_value = analogRead(sensorControl);
  Serial.print(moisture_value);
  Serial.print("\n");
  //red light until the watering moment and green light after
  if (moisture_value >= 0 && moisture_value <= 550) {
    digitalWrite(greenDiod, LOW);
    digitalWrite(redDiod, HIGH);
    digitalWrite(relay, HIGH);
    delay(5000);
    digitalWrite(relay, LOW);
    digitalWrite(redDiod, LOW);
    digitalWrite(greenDiod, HIGH);
  }
  digitalWrite(sensorPower, LOW);
  delay(30000);
}
