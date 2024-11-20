
#include <Keypad.h>
//Missing FQBN (Fully Qualified Board Name)
//Compilation error: Missing FQBN (Fully Qualified Board Name)
pinMode(13, OUTPUT); //red
pinMode(12, OUTPUT);//yellow
pinMode(11, OUTPUT);//green
pinMode(10, OUTPUT);//blue
const byte rows = 4;
const byte colms = 4;

//byte data_count = 0;

char keys[rows][colms] = 
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
 for (int i = 0; i < rows; i++)
 {
  pinMode(rowsPins[i], OUTPUT); // Set the key pin as input with pull-up resistor [8, 10]
 }

 for (int i = 0; i < colms; i++)
 {
  pinMode(colPins[i], INPUT_PULLUP); // Set the key pin as input with pull-up resistor [8, 10]
 }

}
//test
//test2
void loop() 
{
  // put your main code here, to run repeatedly:
  // char customKey = customKeypad.getKey();

  // if (customKey)
  // {
  //   //Data[data_count] = customKey;
  //   Serial.print(customKey); //prints out which key is pressed
  //   //data_count++;
  // }

  // int keyState = digitalRead(keyPin); // Read the state of the key pin [8, 10]

  // if (keyState == LOW) 
  // { // Check if key is pressed (LOW means pressed with pull-up resistor) [8, 10]

  //     // Determine which key is pressed based on your keyboard connection

  //     char keyChar = 'A'; // Replace with the correct character for the pressed key

  //     Serial.print(keyChar); // Print the key character to the serial monitor [2, 3, 8]

  // }

  for (int row = 0; row < ROWS; row++) {

    digitalWrite(rowPins[row], LOW);  

    for (int col = 0; col < COLS; col++) {

      if (digitalRead(colPins[col]) == LOW) {

        Serial.print("Key Pressed: "); 

        Serial.println(keys[row][col]); 

      }

    }

    digitalWrite(rowPins[row], HIGH); 

  }

  delay(10); // Debounce delay
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
}else(){
  digitalWrite(11, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
}
}
