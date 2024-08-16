#include <TM1637Display.h>
#include <Adafruit_NeoPixel.h> 

// Onboard led
#define ONBOARD_LED 48
#define NUMPIXELS 1

// Define sensor pins
#define team1Sensor 12
#define team2Sensor 1
//8, 46, 3

#define MAX_SCORE 10

#define GOAL_VALUE 3000

// TM1637 7 segment 4 digit display
#define CLK  13
#define DIO  14

#define BUZZER_PIN 11

TM1637Display display = TM1637Display(CLK, DIO);

int8_t blueGoals = 0;
int8_t whiteGoals = 0;



void setup() {
  Serial.begin(115200);
  pinMode(team1Sensor, INPUT);
  pinMode(team2Sensor, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  display.setBrightness(6); // set the brightness to 7 (0:dimmest, 7:brightest)
  display.clear();

  Adafruit_NeoPixel pixels(NUMPIXELS, ONBOARD_LED, NEO_GRB + NEO_KHZ800);

  // For the stupid onboard led to be not lit
  pixels.begin();
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.show();
  printScore();
  display.showNumberDecEx(0000, 0b11100000, false, 4, 0);
}


void loop() {
  checkIfGoal();
}
  //   isGameLive = true;
  //   changingStatus("yes");
  // }


void checkIfGoal() {
  int team1Val = analogRead(team1Sensor);
  int team2Val = analogRead(team2Sensor);
  Serial.print("Val1: "); 
  Serial.println(team1Val);
  // Serial.print("Val2: ");
  // Serial.println(team2Val);
  // delay(200);

  if(team1Val > GOAL_VALUE) {
    blueGoals++;
    Serial.println("Blue Scored!!!");
    printScore();
    makeBuzzerSound();
    delay(1000);
  }

  // else
  // if(team2Val > GOAL_VALUE) {
  //   whiteGoals++;
  //   Serial.println("White Scored!!!");
  //   printScore();
  //   makeBuzzerSound();
  //   delay(1000);
  // }

  // checkForWinner();
}


void makeBuzzerSound() {
  // tone(BUZZER_PIN, 3000, 500);
  // tone(BUZZER_PIN, 4000, 500);
  // tone(BUZZER_PIN, 3000, 500);
  noTone(BUZZER_PIN);
}


void printScore() {
  display.clear();

  // Print the score to the serial monitor
  Serial.println("White::Blue");
  Serial.print(whiteGoals);
  Serial.print("::");
  Serial.println(blueGoals);
  
  // Convert scores to two-digit format for display
  int displayValue = (whiteGoals * 100) + blueGoals;

  // Show the score on the TM1637 display
  display.showNumberDecEx(displayValue, 0b11100000, false, 4, 0);
}


void checkForWinner() {
  if(whiteGoals >= MAX_SCORE) {
    Serial.println("White wins!");
    printScore();
    delay(1000);
    display.clear();
    animateRotation();
    makeBuzzerSound();
    whiteGoals = 0;
    blueGoals = 0;
  }

  if(blueGoals >= MAX_SCORE) {
    Serial.println("Blue wins!");
    printScore();
    delay(1000);
    display.clear();
    animateRotation();
    makeBuzzerSound();
    whiteGoals = 0;
    blueGoals = 0;
  }
}


void animateRotation() {
  // Define the segments for a rotating animation
  uint8_t rotationSegments[] = {
    0b01111110, // - 
    0b00000110, // -
    0b00011100, // -
    0b00111111  // -
  };

  // Perform the rotation animation several times
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 4; j++) {
      // Display the animation segments
      display.setSegments(rotationSegments, 4, 0);
      delay(200);
      // Rotate through each digit
      uint8_t temp = rotationSegments[0];
      for (int k = 0; k < 3; k++) {
        rotationSegments[k] = rotationSegments[k + 1];
      }
      rotationSegments[3] = temp;
    }
  }

  // Clear the display after the animation
  display.clear();
}
