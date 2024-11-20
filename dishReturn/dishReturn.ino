
#include <Keypad.h>
//Missing FQBN (Fully Qualified Board Name)
//Compilation error: Missing FQBN (Fully Qualified Board Name)

const byte rows = 4;
const byte colms = 4;

//byte data_count = 0;

char hexaKeys [rows][colms] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '5', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[rows] = {7, 6, 5, 4}; 
byte colPins[colms] = {3, 2, 1, 0}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, rows, colms);

void setup() 
{
  Serial.begin(9600); //this is the so that when the program starts, 
                      //it will initialize the serial communication at a baud rate of 9600
                      //the baud rate is is the speed at which the data is transmitter over the serial communication
                      //the serial communication is a method of sending and recieving data one bit at a 
                      //time over a single wire or channel
  // put your setup code here, to run once:

}
//test
//test2
void loop() 
{
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();

  if (customKey)
  {
    //Data[data_count] = customKey;
    Serial.println(customKey); //prints out which key is pressed
    //data_count++;
  }


}
