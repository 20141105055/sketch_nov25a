int readPin = 0;   //用来连接电位器
int servopin = 7;    //定义舵机接口数字接口7
 
void servopulse(int angle)//定义一个脉冲函数
{
  int pulsewidth=(angle*11)+500;  //将角度转化为500-2480的脉宽值
  digitalWrite(servopin,HIGH);    //将舵机接口电平至高
  delayMicroseconds(pulsewidth);  
  digitalWrite(servopin,LOW);     
  delayMicroseconds(20000-pulsewidth);
}
 
void setup()
{
  pinMode(servopin,OUTPUT);
}
 
void loop()
{
  
  int readValue = analogRead(readPin);
  
  int angle = readValue / 4;
  
  for(int i=0;i<50;i++)
  {
   
    servopulse(angle);
  }
}
