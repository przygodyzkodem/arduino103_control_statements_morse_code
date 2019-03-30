#define OUTPUT_PIN D4

const int dotLength = 100;     // length of the morse code 'dot' in miliseconds
const int dashLength = dotLength * 3;    // length of the morse code 'dash'
const int elementPause = dotLength;  // length of the pause between elements of a character
const int characterPause = dotLength * 3;     // length of the spaces between characters
const int spacePause = dotLength * 7;  // length of the pause between words
const int messagePause = dotLength * 15;

void setup() {
  Serial.begin(115200);
  pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
  dot();
  dash();
  turnOff(messagePause);
  Serial.println(""); //print new message in new line
}

void dot() {
  Serial.print("*");
  digitalWrite(OUTPUT_PIN, LOW);
  delay(dotLength);
  turnOff(elementPause);
}

void dash() {
  Serial.print("-");
  digitalWrite(OUTPUT_PIN, LOW);
  delay(dashLength);
  turnOff(elementPause);
}

void turnOff(int duration) {
  if(duration == characterPause) {
    Serial.print(" ");
  } else if (duration == spacePause) {
    Serial.print("    ");
  }
  digitalWrite(OUTPUT_PIN, HIGH);
  delay(duration);
}
