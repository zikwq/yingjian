#include <SoftwareSerial.h>    //需要调用这个库实现串口通讯

SoftwareSerial softSerial(3,2); //新建一个softSerial对象，rx:3,tx:2
int a;                         //接收串口的值

void setup() {
  pinMode(13,OUTPUT);        //设置IO口13为输出模式
  Serial.begin(9600);
  softSerial.begin(9600);   //初始化软串口通信；
  digitalWrite(13,LOW);     //给13口低电平
  delay(3000);
}

void loop() {
  a=softSerial.read();      //读取串行端口的值
  switch(a)
  {
    case 1:					//前面提到的读取到1表示开灯
      digitalWrite(13,HIGH);//当喊“开灯”时，可以看到Arduino上的LED亮起
      break;
    case 2:
      digitalWrite(13,LOW);//当喊“关灯”时，可以看到Arduino上的LED熄灭
      break;
    default:
      break;
  }
}
