const int nLEDPin1 = 2;
const int nLEDPin2 = 3;
const int nLEDPin3 = 4;
const int nLEDPin4 = 5;
const int nLEDPin5 = 6;
const int nLEDPin6 = 7;

// Flash lights twice
void flash()
{
  unsigned char j, k;
  for (k = 0; k <= 2; ++k)
  {
    for (j = nLEDPin1; j <= nLEDPin6; ++j)
    {
      digitalWrite(j, HIGH);
    }
    delay(200);
    
    for (j = nLEDPin1; j <= nLEDPin6; ++j)
    {
      digitalWrite(j, LOW);
    }
    delay(200);
  }
}

// Light up each LED once every 200 ms
void style_1()
{
  unsigned char j;
  for (j = nLEDPin1; j <= nLEDPin6; ++j)
  {
    digitalWrite(j, HIGH);
    delay(200);
  }
  
  for (j = nLEDPin6; j >= nLEDPin1; --j)
  {
    digitalWrite(j, LOW);
    delay(200);
  }
}

void style_2()
{
  unsigned char j, k;
  k = 1;
  for (j = nLEDPin3; j >= nLEDPin1; --j)
  {
    digitalWrite(j, HIGH);
    digitalWrite(j + k, HIGH);
    delay(400);
    k += 2;
  }
  k = 5;
  
  for (j = nLEDPin1; j <= nLEDPin3; ++j)
  {
    digitalWrite(j, LOW);
    digitalWrite(j + k, LOW);
    delay(400);
    k -= 2;
  }
}

void style_3()
{
  unsigned char j, k;
  k = 5;
  for (j = nLEDPin1; j <= nLEDPin3; ++j)
  {
    digitalWrite(j, HIGH);
    digitalWrite(j + k, HIGH);
    delay(400);
    digitalWrite(j, LOW);
    digitalWrite(j + k, LOW);
    k -= 2;
  }
  k = 3;
  
  for (j = nLEDPin2; j >= nLEDPin1; --j)
  {
    digitalWrite(j, HIGH);
    digitalWrite(j + k, HIGH);
    delay(400);
    digitalWrite(j, LOW);
    digitalWrite(j + k, LOW);
    k += 2;
  }
}

void setup() {
  // put your setup code here, to run once:
  unsigned char j;
  for (j = nLEDPin1; j <= nLEDPin6; ++j)
  {
    pinMode(j, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  style_1();
  flash();
  style_2();
  flash();
  style_3();
  flash();
}
