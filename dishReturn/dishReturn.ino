#include <Keypad.h>
//Missing FQBN (Fully Qualified Board Name)
//Compilation error: Missing FQBN (Fully Qualified Board Name)
//pinMode(13, OUTPUT); //red
//pinMode(12, OUTPUT);//yellow
//pinMode(11, OUTPUT);//green
//pinMode(10, OUTPUT);//blue

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

int hokieID = -1;
char dishType = ' ';
int numDishes = 0;

void setup() 
{
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
  char keyEntry = customKeypad.getKey();

  if (keyEntry)
  {
    if (hokieID == -1)
    {
      if (keyEntry >= '0' && keyEntry <= '9')
      {
        hokieID = keyEntry - '0';
        Serial.print("hokieID: ");
        Serial.println(hokieID);
        Serial.println("Enter dish type (A-D): ");
      }
    }
    else if (dishType == ' ')
    {
      if (keyEntry >= 'A' && keyEntry <= 'D')
      {
        dishType = keyEntry;
        Serial.print("dishType: ");
        Serial.println(dishType);
        Serial.println("Enter number of dishes (1-3): ");
      }
    }
    else if (numDishes == 0)
    {
      if (keyEntry >= '1' && keyEntry <= '3')
      {
        numDishes = keyEntry;
        Serial.print("number of dishes: ");
        Serial.println(numDishes);
      }
    }
  }
}








































//cap is percentage (please give me (count/amount can hold)*100)
void updateLights(int cap){
if (cap<=50){
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
}else if (cap<=75){
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
}else{
  digitalWrite(11, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
}
}
