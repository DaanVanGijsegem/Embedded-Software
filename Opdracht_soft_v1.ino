#define led 9
#define sensor A0

int input;
int sensorHigh = 255;

void setup() 
{
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  input = map(analogRead(sensor), 0, 1023, 0, 255);
  analogWrite(led,(sensorHigh-input));
  Serial.println(input);
}
