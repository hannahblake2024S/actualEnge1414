#include <Keypad.h>



const byte rows = 4;
const byte colm = 4;

char keys[rows][colm] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '5', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[rows] = {9, 8, 7, 6}; 
byte colPins[colm] = {5, 4, 3, 2}; 

Keypad hokieKeypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, colm);

String hokieID = String("-1");
//note that it can only store 10 ids in this version
String ids[10];
int idPosition = 0;

//type A
int numDishes = 0;
//type C
int numUtensils = 0;
//type B
int numCups = 0;

void setup() 
{
pinMode(13, OUTPUT); //red
pinMode(12, OUTPUT);//yellow
pinMode(11, OUTPUT);//green
pinMode(10, OUTPUT);//blue
  // put your setup code here, to run once:
  Serial.begin(9600); //this is the so that when the program starts, 
                      //it will initialize the serial communication at a baud rate of 9600
                      //the baud rate is is the speed at which the data is transmitter over the serial communication
                      //the serial communication is a method of sending and recieving data one bit at a 
                      //time over a single wire or channel
  Serial.println("Enter your hokieID (0-9): ");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  char keyEntry = hokieKeypad.getKey();


      if (keyEntry >= '0' && keyEntry <= '9')
      {
        hokieID = hokieID + keyEntry;
      
      }
  if(keyEntry == 'D'){
   
    ids[idPosition] = hokieID;
    idPosition = idPosition +1;
    hokieID = -1;

    //flash blue
    digitalWrite(10, HIGH);
    delay(1000);
    digitalWrite(10, LOW);
  }

  if(keyEntry=='A'){
    numDishes = numDishes + 1;
  } else if (keyEntry=='B'){
    numCups = numCups +1;
  }else if (keyEntry == 'C'){
    numUtensils = numUtensils+1;
  }

  //reset all counts
  if (keyEntry == '*'){
    numDishes = 0;
    numCups = 0;
    numUtensils = 0;
    updateLights(numDishes);
  }

  //determine most full

  if(numDishes>numCups && numDishes>numUtensils){
    updateLights(numDishes);
  }else if (numCups> numDishes && numCups>numUtensils){
    updateLights(numCups);
  }else if (numUtensils>numDishes && numUtensils> numCups){
    updateLights(numUtensils);
  }else{
     digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  }
  
}




//count is current amount
//we are assuming capacity is 10
void updateLights(int count){
if (count<5){
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
}else if (count<8){
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
}else{
  digitalWrite(11, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
}
}
