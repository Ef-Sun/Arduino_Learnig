const int red = 11;
const int blue = 10;
const int green = 9;
const int button1 = 0;
const int button2 = 1;
int k = 0;
int ctl = 0;
int t1 = 0;
int t2 = 0;

void changeColor()
{
   k = (k+1)%3;
}

void control()
{
  if (ctl)
  {
    Serial.println("System Close.");
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
  }
  else{
    Serial.println("System Open.");
  }
  ctl = (ctl+1)%2;
  delay(1000);

  
}

void setup(){
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(button1, changeColor, FALLING);
  attachInterrupt(button2, control, FALLING);
  Serial.begin(9600);
}

void loop(){
  
  if (ctl){
  int flag1 = 0;
  int flag2 = 0;
  int ifPrint = 1;
  float tmp = analogRead(A1);
  int light = analogRead(A0);
  /* 根据阻值大小，调整RGB灯的颜色 */
  if (light >= 900 || tmp >= 70 || tmp <= 35)
   {

      flag1 = 0;
      flag2 = 1;
      if (k == 0)
      {
        analogWrite(red, 0);
        analogWrite(blue, 0);
        analogWrite(green, 150);
      }

      if (k == 1)
      {
        analogWrite(red, 150);
        analogWrite(blue, 0);
        analogWrite(green, 0);
      }
      if (k == 2)
      {
        analogWrite(red, 0);
        analogWrite(blue, 150);
        analogWrite(green, 0);
      }
    }
    
    else
    {
      flag1 = 1;
      flag2 = 0;
      digitalWrite(red, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(green, LOW);
    }

    if((t1-light >= 30 || t1-light <= -30) && (t2-tmp >= 30 || t2-tmp <= 30) && (flag1-flag2 != 0))
      ifPrint = 1;
    else
      ifPrint = 0;

     
    if (flag1 && ifPrint)
      Serial.println("Suitable for sleeping.");
    else if (flag2 && ifPrint)
      Serial.println("Unsuitable for sleeping.");
      
    t1 = light;
    t2 = tmp;
   delay(1000);
  }
}
