
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Sim800l.h>
#include <SoftwareSerial.h>               
#include <NewPing.h>

Sim800l Sim800l;  //to declare the library
char* text;
char* texta;
char* text1;
char* text2;
char* text3;
char* text4;
char* number;
char* number1;
bool error;           //to catch the response of sendSms


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A5, A4, A0, A1, A2, A3);

int buzzer = 13;
int ledPin = 2;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','F'},
  {'4','5','6','G'}, 
  {'7','8','9','H'},
  {'*','0','#','J'}
};
byte rowPins[ROWS] = {1, 0, 3, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 6, 7, 8};//nect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


int gas_value;
int recipient;
int num_reci;
int countDigit=0;
int countSend=0;
char st_num[15];
char st_num1[15];
char st_num2[15];
char st_num3[15];
char store_num[15];
//////////
const int trigPin = 12;
const int echoPin = 9;
long duration;
int distance;
/////////////
int count_num;

void setup() {
lcd.begin(16, 2);
Sim800l.begin();
pinMode(ledPin, OUTPUT);
pinMode(buzzer, OUTPUT);
//number="+2348038516291"; 
//number1="+2348064678011";


digitalWrite(buzzer,LOW);
store_num[0]='+';
  text="Intruder Detected, ALERT!  ALERT!";     //text for the message. 
  text1="Intruder Detected, ALERT! ALERT!";     //text for the message.
  text2="Intruder Detected, ALERT!  ALERT!";     //text for the message.
  text3="Intruder Detected, ALERT!  ALERT!";     //text for the message. 
  text4="Intruder Detected, ALERT! ALERT!";     //text for the message.
  texta="Intruder Detected, ALERT!  ALERT!";
  number="+2348038516291";     //change to a valid number.
 // number1="+2348064678011"; 


blinkled();
delay(1000);
blinkled();




lcd.print("A GSM BASED");
lcd.setCursor(0,1);
lcd.print("ELECTRONIC EYE");
delay(3000);

countSend=0;
}

void loop() {

lcd.clear();
lcd.print("Press F1 TO CONT");
lcd.setCursor(0,1);
lcd.print("Press F2 TO CHG");
delay(500); 
 int x=0;
 while (x==0)
 {
char key = keypad.getKey();
if (key){
switch(key){;
case 'F':
x=1;
break;

case 'G':
lcd.clear();
lcd.print("NO. OF RECIPIENT");
lcd.setCursor(0,1);
countSend=1;
num_reci=recipientCheck();// to set the no. of people
                          // to send message to
countDigit= num_reci; 
storeCheck(num_reci);     // to enter the phone no.
                          // 2348034543433
x=1;                      
break;
}// close case statement
}// close if 
} // close while /* to continue program*/
// /* or enter number*/
///////////////////
int r=0;
int dd=0;
while (r==0){
while (dd==0)//dis make checking gas display once
{
lcd.clear();
lcd.print("Checking...");
lcd.setCursor(0,1);
lcd.print("Distance     CM");
dd=1;
}

//gas_value=digitalRead(sensor);
////''''''''''''''''''''''''''
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
  // Send ping, get distance in cm and print result (0 = outside set distance range)
  int x = distance;

  if(distance>=100)
  {
  
  lcd.setCursor(10,1);
  lcd.print(distance);
     Serial.println(distance);
  }

 if((distance<100) && (distance >=10)){
    lcd.setCursor(12,1);
  lcd.print(" ");
  lcd.setCursor(10,1);
  lcd.print(distance);
  Serial.println(distance);
  }

  if(distance<10){
  lcd.setCursor(11,1);
  lcd.print("  ");
  lcd.setCursor(10,1);
  lcd.print(distance);
  Serial.println(distance);
  }
  
   
////''''''''''''''''''''''''''

if (x<=30)
{
      lcd.clear();
      lcd.print("Security Breach");
      delay(500);
      
      digitalWrite(buzzer, HIGH);
      delay(1000);
      
      error=Sim800l.sendSms(number,text);
      delay(2700);
     // error=Sim800l.sendSms(number1,texta);
      //delay(2000);

if(countSend==1)
{
disp_phonum(countDigit);
}

delay(10000);
digitalWrite(buzzer,LOW);
dd=0;
}//CLOSES IF

char key = keypad.getKey();
if (key){
switch(key)// this makes it posible to exit loop
{
case '*':
r=1;
break;
}// closes swich
}// closes loop
delay(1000);
}//CLOSES WHILE
/////////////////////////
}//closes loop function

void storeCheck(int x)
{

while(x>=1)// THIS IS TO STORE FIVE NUMBERS IN THE SYSTEM
{
  lcd.clear();
  lcd.print("Enter Phone No.");
  lcd.setCursor(0,1);
  
  int t=1;
  int a=1;
  int b=0;
  int c=0;
  //char* store_num;
 while(t==1){
char key = keypad.getKey();
//store=key;
if (key)
{
  switch(key){
  case '1':
  b=1;
  lcd.print(key);
  store_num[a]='1';
  a=a+1;
  c=c+1;
  blinkled();
  break;

  case '2':
  lcd.print(key);
  store_num[a]='2';
  a=a+1;
  c=c+1;
  blinkled();
  b=1;
  break;

  case '3':
  lcd.print(key);
  store_num[a]='3';
  a=a+1;
  blinkled();
  b=1;
  c=c+1;
  break;

  case '4':
  lcd.print(key);
  store_num[a]='4';
  a=a+1;
  blinkled();
  b=1;
  c=c+1;
  break;

  case '5':
  lcd.print(key);
  store_num[a]='5';
  a=a+1;
  blinkled();
  b=1;
  c=c+1;
  break;

  case '6':
  lcd.print(key);
  store_num[a]='6';
  a=a+1;
  blinkled();
  b=1;
  c=c+1;
  break;

  case '7':
  lcd.print(key);
  store_num[a]='7';
  a=a+1;
  b=1;
  blinkled();
  c=c+1;
  break;

  case '8':
  lcd.print(key);
  store_num[a]='8';
  a=a+1;
  blinkled();
  b=1;
  c=c+1;
  break;

  case '9':
  lcd.print(key);
  store_num[a]='9';
  a=a+1;
  blinkled();
  b=1;
  c=c+1;
  break;

  case '0':
  lcd.print(key);
  store_num[a]='0';
  a=a+1;
  b=1;
  c=c+1;
  break;

  case 'F':
  if(b==1){
  a=a-1;
  c=c-1;
  lcd.setCursor(c,1);
  lcd.print("*");
  lcd.setCursor(c,1);
  }
  break;

  case '*':
  t=0;
  int count_num=x;
  x=x-1;
 // char philip[15];
  //strcpy(philip,store_num);
  //lcd.clear();
//lcd.print(philip);
//delay(500); 
  save_phonum(store_num, count_num);
  break;

}//close switch
}//close if
}//close while t==1
}//close while x>=1
}// close main function

void save_phonum(char* stsd, int count){
  if(count==1)
  {
    strcpy(st_num,stsd);
  }
  else if(count==2)
  {
    strcpy(st_num1,stsd);
  }
  else if(count==3)
  {
    strcpy(st_num2,stsd);
  }
  else if (count==4)
  {
    strcpy(st_num3,stsd);
  }

  else
  {
  }
   
  }



int recipientCheck()
{

int a=0;
int x=0;
 while(a==0){
 char key = keypad.getKey();
if (key)
{
  switch(key){
  case '1':
  lcd.print(key);
  lcd.setCursor(0,1);
  x=1;
  blinkled();
  break;
  
  case '2':
  lcd.print(key);
  lcd.setCursor(0,1);
  x=2;
  blinkled();
  break;

  case '3':
  lcd.print(key);
  lcd.setCursor(0,1);
  x=3;
  blinkled();
  break;

  case '4':
  lcd.print(key);
  lcd.setCursor(0,1);
  x=4;
  blinkled();
  break;

  case '*':
  blinkled();
  a=1;
  break; 
}// close switch
}// close if
}// close while
return x;
}// close function

void blinkled()
{
digitalWrite(ledPin,HIGH);
 delay(800);
 digitalWrite(ledPin,LOW);  
}
