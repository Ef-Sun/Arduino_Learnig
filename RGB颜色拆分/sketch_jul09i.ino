const int RedPin = 11;
const int GreenPin = 10;
const int BluePin = 9;
const int ChangeVal = 10;
const int sec = 20;

void setup()
{
  Serial.begin(9600);
  pinMode(RedPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  
}

void loop()
{
  int val = analogRead(A0);
  val = map(val, 0, 1023,0, 255);
  Serial.println(val);
  for(int i = 0; i<val; i+= ChangeVal)
  {
    analogWrite(RedPin, i);
    delay(sec);
    for(int j = 5; j<val; j+=ChangeVal){
      analogWrite(GreenPin, j);
          delay(sec);

      for(int k = 5; k<val; k+=ChangeVal){
        analogWrite(BluePin, k);
            delay(sec);

      }
    }
  }
  Serial.println("here");
 
  for(int i =0; i<=val; i+= ChangeVal)
  {
    analogWrite(BluePin, val-i);
        delay(sec);

    for(int j = 0; j<=val; j+=ChangeVal)
    {
      analogWrite(GreenPin, val-j);
      delay(sec);

     for(int k = 0; k<=val; k+=ChangeVal)
     {
       analogWrite(RedPin, val-k);
       delay(sec);
     }
    }
  }
 
  
  analogWrite(BluePin, 0);
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  delay(2000);


  
}
