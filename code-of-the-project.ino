// C++ code
//
int motor = 7;
int analog = A0;
int mug = 8;
int readAnalog;
int read;
void setup() {
  // // put your setup code here, to run once:
  pinMode(motor, OUTPUT);
  pinMode(analog, INPUT);
  pinMode(mug, INPUT);
  Serial.begin(9600);
}

void loop() {
readAnalog = analogRead(analog);
read = digitalRead(mug);
Serial.println(readAnalog); // for knowing specific ranges
  if (digitalRead(motor) == LOW && readAnalog <870 && read == 0) {
    digitalWrite(motor, HIGH);// if motor is not forking and two sensors read an object, turn on the motor
  }
  if (digitalRead(motor) == HIGH && readAnalog >871 || read == 1) {
    digitalWrite(motor, LOW); // if motor is working while there is no object decected by the sensor, turn the motot off
  }
  delay(700); // analize in every 0.7 second
}