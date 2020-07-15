const int pin = 2;  // 开关引脚
const int pin2 = 13;  // 电路部分正向电压引脚
const float V_all = 5.0;  // 最大电压
int flag = 1;   // 控制系统开关

void setup()
{
  Serial.begin(9600);
  pinMode(pin,  INPUT_PULLUP);  //设置引脚为内部上拉输入模式
  pinMode(pin2, OUTPUT);  // 控制电压
}
 
void loop()
{
  /* 开关部分，控制开关 */
  float time= pulseIn(pin, LOW,60000000)/1000;  // 计算按下时间
  if(time > 1000) // 长按进入系统开关控制部分
  {
    if(flag == 1) // 打开
    {
      flag = 0;
      digitalWrite(pin2, HIGH);
      Serial.println("System Open\n");
    }
    
    else  // 关闭
    {
      flag = 1;
      digitalWrite(pin2, LOW);
      Serial.println("System Close");
    }

  }

  /* 系统打开期间，计算各部分电压 */
  else if(digitalRead(pin2) == HIGH)
  {
    /* 串口输出按下开关的时间 */
    Serial.print("Pressing time = ");
    Serial.print(time);
    Serial.println("ms");


    /* 输出定值电阻两端电压U1 */
    float V1 = analogRead(A0);
    float vol = V1*(5.0 / 1023.0);    
    Serial.print("U1 = ");
    Serial.print(vol);
    Serial.println(" V");

    /* 输出编组去接入部分两端电压 */
    Serial.print("U2 = ");
    Serial.print(V_all - vol); 
    Serial.println(" V\n");
  }
}
