void setup()
{
 	pinMode(2, OUTPUT);
  	pinMode(3, OUTPUT);
  	pinMode(4, OUTPUT);
  	pinMode(5, OUTPUT);
  	digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
	Serial.begin(9600);
}

void loop()
{
  	int i;
    int a;
  	int num[10][4]={
    {2,3,4,5},
    {3,4,5},
    {2,3,4},
    {3,4},
    {2,3,5},
    {3,5},
    {2,5},
    {3},
    {2,3,5},
    {4,5}};
  	
    a=Serial.read();  
  	for(i=0;i<4;i++)
  	{
  		digitalWrite(num[a][i], LOW);
  	}
    delay(500);
}