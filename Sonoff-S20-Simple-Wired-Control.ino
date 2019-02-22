#include <EasyButton.h>

#define BUTTON_PIN 0
#define RELAY_PIN 12 // LOW for ON
#define GREENLED_PIN 13 // HIGH for ON
#define IN_PIN 3 

EasyButton button(BUTTON_PIN);

int previousTriggerState = LOW;
int currentTriggerState = LOW;
int currentRelayState = LOW;

bool OVERRIDE_ENABLED = false;

void onPressedForDuration() { // Button being held will turn on/off override mode but not toggle relay (for holding current state)

  if(OVERRIDE_ENABLED) {
    OVERRIDE_ENABLED = false;
    digitalWrite(GREENLED_PIN, HIGH);
  } else {
    OVERRIDE_ENABLED = true;
    digitalWrite(GREENLED_PIN, LOW);
  }
}

void setRelayState(int targetState, bool fromOverrideButton) {

  if(currentRelayState != targetState && (!OVERRIDE_ENABLED or fromOverrideButton)) {
    digitalWrite(RELAY_PIN, targetState);     
    currentRelayState = targetState; 

  } else if(OVERRIDE_ENABLED) {
    //Action blocked because of override enabled
  }
  
}

void onPressed() { // Single press will toggle relay state and turn on override mode
  setRelayState(!currentRelayState, true); // toggle state
  
  if(!OVERRIDE_ENABLED) {
    OVERRIDE_ENABLED = true;
    digitalWrite(GREENLED_PIN, LOW);
  }  
}

void setup() {
  pinMode(GREENLED_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(IN_PIN, INPUT);

  // Turn off relay and LED to start
  digitalWrite(GREENLED_PIN, HIGH);
  digitalWrite(RELAY_PIN, LOW);

  button.begin();
  button.onPressed(onPressed);
  button.onPressedFor(2000, onPressedForDuration);
}

void loop() {
  button.read();

  currentTriggerState = digitalRead(IN_PIN);

  if(currentTriggerState != previousTriggerState) {
    setRelayState(currentTriggerState, false);
    previousTriggerState = currentTriggerState;
  }
}
