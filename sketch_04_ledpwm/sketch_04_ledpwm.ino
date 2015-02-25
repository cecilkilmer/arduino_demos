const int nLEDPin = 13;

// Adjustable values
int nDelayMS = 50;
int nAdjustVal = 5;
int nBrightness = 0;
long lPrevMills = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(nLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long lCurMills = millis();
  
  if (lCurMills - lPrevMills > nDelayMS)
  {
    lPrevMills = lCurMills;
    
    nBrightness = nBrightness + nAdjustVal;
    nBrightness = constrain(nBrightness, 0, 255);
    if (nBrightness == 0 || nBrightness == 255)
    {
      nAdjustVal = -nAdjustVal;
    }
    
    analogWrite(nLEDPin, nBrightness);
  }

  while (Serial.available() > 0)
  {
    int nNewDelay = Serial.parseInt();
    int nNewAdjust = Serial.parseInt();
    
    if (Serial.read() == '\n')
    {
      nDelayMS = constrain(nNewDelay, 25, 5000);
      nAdjustVal = constrain(nNewAdjust, 0, 255);
    }
  }
}
