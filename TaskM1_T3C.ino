const uint8_t BTN_PIN = 2;
const uint8_t LED_PIN = 13;
const uint8_t MOTION_PIN = 3;

uint8_t buttonPrevState = LOW;
uint8_t ledState = LOW;

void setup()
{
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(MOTION_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(BTN_PIN), toggleBtn, CHANGE);
  attachInterrupt(digitalPinToInterrupt(MOTION_PIN), toggleMotion, CHANGE);
  
  
  Serial.begin(9600);
}

uint8_t buttonState;
uint8_t motionValue;

void loop()
{
  
}

void toggleBtn(){
  buttonState = digitalRead(BTN_PIN);
  
  if(buttonState != buttonPrevState)
  {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    Serial.println("LED SWITCHED");
  }
}

void toggleMotion(){
  motionValue = digitalRead(MOTION_PIN);
  
  if(motionValue == true){
    digitalWrite(LED_PIN, true);
    Serial.println("LED ON");
  } else{
    digitalWrite(LED_PIN, false);
    Serial.println("LED OFF");
  }
}
  
