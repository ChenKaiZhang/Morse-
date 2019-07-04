#include <Morse.h>

#include <Morse.h>

#include <Morse.h>

Morse morse(13);
char MORSE[][4] = {
  {'.', '-', '*', '*'}, //A
  {'-', '.', '.', '.'}, //B
  {'-', '.', '-', '.'}, //C
  {'-', '.', '.', '*'}, //D
  {'.', '*', '*', '*'}, //E
  {'.', '.', '-', '.'}, //F
  {'-', '-', '.', '*'}, //G
  {'.', '.', '.', '.'}, //H
  {'.', '.', '*', '*'}, //I
  {'.', '-', '-', '-'}, //J
  {'-', '.', '-', '*'}, //K
  {'.', '-', '.', '.'}, //L
  {'-', '-', '*', '*'}, //M
  {'-', '.', '*', '*'}, //N
  {'-', '-', '-', '*'}, //O
  {'.', '-', '-', '.'}, //P
  {'-', '-', '.', '-'}, //Q
  {'.', '-', '.', '*'}, //R
  {'.', '.', '.', '*'}, //S
  {'-', '*', '*', '*'}, //T
  {'.', '.', '-', '*'}, //U
  {'.', '.', '.', '-'}, //V
  {'.', '-', '-', '*'}, //W
  {'-', '.', '.', '-'}, //X
  {'-', '.', '-', '-'}, //Y
  {'-', '-', '.', '.'}  //Z
};

void setup()
{
  Serial.begin(9600);//初始化串口通信，设置通信波特率为9600
}

void loop()
{
  String wzy = "";  //定义未转义字符串
  String morse_s = "";  //定义转义后字符串
  int i, t , temp = 0;
  int n = 0;  //对传入字符计数
  while (Serial.available() > 0)
  {
    temp = 1;  //判断是否有数据传入
    wzy += char(Serial.read());  //将传入数据储存在字符串中
    delay(2);  //延迟2ms
    n++;
  }

  if (temp)
  {
    for (i = 0; i < n; i++)
    {
      for (t = 0; t < 4; t++)
      {
        if (wzy[i] >= 97 && wzy[i] <= 122)
        {
          morse_s += char(MORSE[int(wzy[i] - 97)][t]);
        }
      }
      morse_s += ' '; //补空与下一循环生成的morse码断开
    }
    Serial.println(morse_s);  //串口传入
    for (i = 0; morse_s[i]!='\0' ; i++)
    {
      if (morse_s[i] == '.')
      morse.dot();
      else if (morse_s[i] == '-')
      morse.dash();
      else if (morse_s[i] == ' ')
      morse.w_space();
      if (morse_s[i] != ' ' && str[i] != '*')
      morse.c_space();
    }
    Serial.println("发送完毕");
    delay(2);
  }
}
