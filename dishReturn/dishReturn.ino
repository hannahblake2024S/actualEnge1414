
#include <Keypad.h>
//Missing FQBN (Fully Qualified Board Name)
//Compilation error: Missing FQBN (Fully Qualified Board Name)

const byte rows = 4;
const byte colm = 4;

//byte data_count = 0;

char keys[rows][colm] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '5', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[rows] = {7, 6, 5, 4}; 
byte colPins[colm] = {3, 2, 1, 0}; 

Keypad hokieKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, rows, colm);

char inputList[100];
int inputIndex = 0;

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
//  for (int i = 0; i < rows; i++)
//  {
//   pinMode(rowsPins[i], OUTPUT); // Set the key pin as input with pull-up resistor [8, 10]
//  }

//  for (int i = 0; i < colm; i++)
//  {
//   pinMode(colPins[i], INPUT_PULLUP); // Set the key pin as input with pull-up resistor [8, 10]
//  }

}
//test
//test2
void loop() 
{
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();

  if (key)
  {
    if (hokieID == -1)
    {
      if (key >= '0' && key <= '9')
      {
        hokieID = key - '0';
        Serial.print("hokieID: ");
        Serial.println(hokieID);
        Serial.println("Enter dish type (A-D): ")
      }
    }
    else if (dishType == ' ')
    {
      if (key >= 'A' && key <= 'D')
      {
        dishType = key;
        Serial.print("dishType: ");
        Serial.println(dishType);
        Serial.println("Enter number of dishes (1-3): ")
      }
    }
    else if (numDishes == 0)
    {
      if (key >= '1' && key <= '3')
      {
        numDishes = key - '0';
        Serial.print("number of dishes: ");
        Serial.println(numDishes);
      }
    }
    // inputList[inputIndex] = key;
    // inputIndex++;
    // Serial.print(key); //prints out which key is pressed
  }
  // int keyState = digitalRead(keyPin); // Read the state of the key pin [8, 10]

  // if (keyState == LOW) 
  // { // Check if key is pressed (LOW means pressed with pull-up resistor) [8, 10]
  //     // Determine which key is pressed based on your keyboard connection
  //     char keyChar = 'A'; // Replace with the correct character for the pressed key
  //     Serial.print(keyChar); // Print the key character to the serial monitor [2, 3, 8]
  // }

  // for (int row = 0; row < ROWS; row++) 
  // {
  //   digitalWrite(rowPins[row], LOW);  
  //   for (int col = 0; col < colm; colm++) 
  //   {
  //     if (digitalRead(colPins[colm]) == LOW) 
  //     {
  //       Serial.print("Key Pressed: ");
  //       Serial.println(key);
  //       Serial.println(keys[row][colm]);
  //     }
  //   }
  //   digitalWrite(rowPins[row], HIGH);
  // }
  // delay(10); // Debounce delay
}
