  void dot();
  void dash();
  void c_space();
  void w_space();
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
    pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  String wzy = "";  
  String morse_s = "";  
  int i, t , temp = 0;
  int n = 0;  
  while (Serial.available() > 0)
  {
    temp = 1;  
    wzy += char(Serial.read());  
    delay(2);  
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
      morse_s += ' '; 
    }
    Serial.println(morse_s);  
    for (i = 0; morse_s[i]!='\0' ; i++)
    {
      if (morse_s[i] == '.')
      dot();
      else if (morse_s[i] == '-')
      dash();
      else if (morse_s[i] == ' ')
      w_space();
      if (morse_s[i] != ' ' && wzy[i] != '*')
      c_space();
    }
    delay(2);
  }
}
void dot()
{   digitalWrite(2, HIGH);
  delay(250);
  digitalWrite(2, LOW);
  delay(250);
}
void dash()
{
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(250);
} 
void c_space()
{
  digitalWrite(2,LOW);
  delay(500*3);
}

void w_space()
{
  digitalWrite(2,LOW);
  delay(500*7);
} 
