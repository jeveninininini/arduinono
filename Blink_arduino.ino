const int buttonPin = 2;   // the number of the pushbutton pin
const int RledPin = 3;     // the number of the R pin
const int GledPin = 4;     // the number of the G pin
const int BledPin = 5;     // the number of the B pin

// variables will change:
int buttonState = 0;       // variable for reading the pushbutton status
int ledcolor = 0;          // Color Counter
int ledState = LOW;        // Example state for blinking/control

bool ButtonPressed = false;// Whether the button is pressed

String currentcolor = "LED off";

void setup() {
  // initialize the LED pin as an output:
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // Button click toggle logic (from Slide 31)
  if(buttonState == HIGH && !ButtonPressed) {
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
  }
  
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }

  // Color state machine (from Slide 46)
  if (ledcolor == 0) {
    currentcolor = "LED off";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 1) {
    currentcolor = "Red";
    if (ledState == LOW) {
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  }
  else if (ledcolor == 2) {
    currentcolor = "Green";
    if (ledState == LOW) {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, HIGH);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  }
  else if (ledcolor == 3) {
    currentcolor = "Blue";
    if (ledState == LOW) {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, LOW);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  }
  else if (ledcolor == 4) {
    currentcolor = "Yellow";
    if (ledState == LOW) {
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, HIGH);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  }
  else if (ledcolor == 5) {
    currentcolor = "Purple";
    if (ledState == LOW) {
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, LOW);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  }
  else if (ledcolor == 6) {
    currentcolor = "Cyan";
    if (ledState == LOW) {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, LOW);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  }
  else if (ledcolor == 7) {
    currentcolor = "White";
    if (ledState == LOW) {
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, LOW);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  }
  else if (ledcolor == 8) {
    ledcolor = 0;
  }
}