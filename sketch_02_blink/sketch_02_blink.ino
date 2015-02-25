const int nLEDPin = 13;

// Adjustable values
int nOnTimeMS = 50;
int nOffTimeMS = 450;
int nLEDState = HIGH;
long lPrevMills = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(nLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long lCurMills = millis();
  
  if (nLEDState == HIGH && lCurMills - lPrevMills > nOnTimeMS)
  {
    nLEDState = LOW;
    lPrevMills = lCurMills;
  }
  else if (nLEDState == LOW && lCurMills - lPrevMills > nOffTimeMS)
  {
    nLEDState = HIGH;
    lPrevMills = lCurMills;
  }

  digitalWrite(nLEDPin, nLEDState);
  
  while (Serial.available() > 0)
  {
    int nNewOnTime = Serial.parseInt();
    int nNewOffTime = Serial.parseInt();
    
    if (Serial.read() == '\n')
    {
      nOnTimeMS = constrain(nNewOnTime, 25, 5000);
      nOffTimeMS = constrain(nNewOffTime, 25, 5000);

      Serial.println("Set values:");
      Serial.println(nOnTimeMS);
      Serial.println(nOffTimeMS);
    }
  }
}
