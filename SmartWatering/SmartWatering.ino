//full program

#define relay 8
#define sensorPower 2
#define sensorControl A0
#define redDiod 7
#define yellowDiod 12
#define greenDiod 13  
int veryWetBorder = 500;
int semiWetBorder = 700;
int veryDryBorder = 1023;

void setup() {
  // set up console output and pin mode
  Serial.begin(9600);
  pinMode(sensorPower, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(redDiod, OUTPUT);
  pinMode(yellowDiod, OUTPUT);
  pinMode(greenDiod, OUTPUT); 
}

void loop() {
  digitalWrite(sensorPower, HIGH);
  delay(100);

  for (int i = 0; i < 3; i++) {
    //get moisture value
    moisture_value = analogRead(sensorControl);
    //output moisutre value to serial console 
    Serial.print(moisture_value);
    Serial.print("\n");
      if (setMoistureLevelDiod() == 1) {
            digitalWrite(relay, HIGH);
            //watering time
            delay(2500);                 
            digitalWrite(relay, LOW);
            delay(15000);    
       }
      else 
          break;
  }
  
  digitalWrite(sensorPower, LOW);
  //time to the next moisture check in ms
  // 1 hour
  delay(600000);

}

// return 0 if the earth is dry and 1 if the earth is wet or semi-wet
int setMoistureLevelDiod() {
  if (moisture_value >= 0 && moisture_value < veryWetBorder) {
    digitalWrite(greenDiod, HIGH);
    digitalWrite(yellowDiod, LOW);
    digitalWrite(greenDiod, LOW);
    return 1;
  } 
  else if (moisture_value >= veryWetBorder && moisture_value < semiWetBorder) {
    digitalWrite(yellowDiod, HIGH);
    digitalWrite(redDiod, LOW);
    digitalWrite(greenDiod, LOW);
    return 1;
  }
  else if (moisture_value >= semiWetBorder && moisture_value < veryDryBorder) {
     digitalWrite(redDiod, HIGH);
     digitalWrite(yellowDiod, LOW);
     digitalWrite(greenDiod, LOW);
     return 0;
  }
}
