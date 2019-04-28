#define OUTPUT_PIN D4

const int dotLength = 100;     // length of the morse code 'dot'
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
  turnOff(messagePause);
  convertToMorseCode('ą');
  convertToMorseCode('ć');
  convertToMorseCode('ę');
  convertToMorseCode('ł');
  convertToMorseCode('ń');
  convertToMorseCode('ó');
  convertToMorseCode('ś');
  convertToMorseCode('ź');
  convertToMorseCode('ż');
  Serial.println("");
}
/*
void convertStringToMorseCode(String message) {
  message.toLowerCase();
  for (int i = 0; i < message.length(); i++) {
    unsigned char characterToConvert = message[i];
    convertToMorseCode(characterToConvert);
  }
  turnOff(messagePause);
}
*/
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

void convertToMorseCode(unsigned char character) {
  Serial.print(character);
  switch (character) {
    case 'a':
      dot(); dash();
      break;
    case 133: //ą
      dot(); dash(); dot(); dash();
      break;
    case 'b':
      dash(); dot(); dot(); dot();
      break;
    case 'c':
      dash(); dot(); dash(); dot();
      break;
    case 135: //ć
      dash(); dot(); dash(); dot(); dot();
      break;
    case 'd':
      dash(); dash(); dot();
      break;
    case 'e':
      dot();
      break;
    case 153: //ę
      dot(); dot(); dash(); dot(); dot();
      break;
    case 'f':
      dot(); dot(); dash(); dot();
      break;
    case 'g':
      dash(); dash(); dot();
      break;
    case 'h':
      dot(); dot(); dot(); dot();
      break;
    case 'i':
      dot(); dot();
      break;
    case 'j':
      dot(); dash(); dash(); dash();
      break;
    case 'k':
      dash(); dot(); dash();
      break;
    case 'l':
      dot(); dash(); dot(); dot();
      break;
    case 130: //ł
      dot(); dash(); dot(); dot(); dash();
      break;
    case 'm':
      dash(); dash();
      break;
    case 'n':
      dash(); dot();
      break;
    case 132: //ń
      dash(); dash(); dot(); dash(); dash();
      break;
    case 'o':
      dash(); dash(); dash();
      break;
    case 179: //ó
      dash(); dash(); dash(); dot();
      break;
    case 'p':
      dot(); dash(); dash(); dot();
      break;
    case 'q':
      dash(); dash(); dot(); dash();
      break;
    case 'r':
      dot(); dash(); dot();
      break;
    case 's':
      dot(); dot(); dot();
      break;
    case 155: //ś
      dot(); dot(); dot(); dash(); dot(); dot(); dot();
      break;
    case 't':
      dash();
      break;
    case 'u':
      dot(); dot(); dash();
      break;
    case 'v':
      dot(); dot(); dot(); dash();
      break;
    case 'w':
      dot(); dash(); dash();
      break;
    case 'x':
      dash(); dot(); dot(); dash();
      break;
    case 'y':
      dash(); dot(); dash(); dash();
      break;
    case 'z':
      dash(); dash(); dot(); dot();
      break;
    case 186: //ź
      dash(); dash(); dot(); dot(); dash();
      break;
    case 188: //ż
      dash(); dash(); dot(); dot(); dash(); dot();
      break;
    case '1':
      dot(); dash(); dash(); dash(); dash();
      break;
    case '2':
      dot(); dot(); dash(); dash(); dash();
      break;
    case '3':
      dot(); dot(); dot(); dash(); dash();
      break;
    case '4':
      dot(); dot(); dot(); dot(); dash();
      break;
    case '5':
      dot(); dot(); dot(); dot(); dot();
      break;
    case '6':
      dash(); dot(); dot(); dot(); dot();
      break;
    case '7':
      dash(); dash(); dot(); dot(); dot();
      break;
    case '8':
      dash(); dash(); dash(); dot(); dot();
      break;
    case '9':
      dash(); dash(); dash(); dash(); dot();
      break;
    case '0':
      dash(); dash(); dash(); dash(); dash();
      break;
    default:
      turnOff(spacePause);
      break;
  }

  turnOff(characterPause);
}
