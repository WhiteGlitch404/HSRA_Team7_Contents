// Pin definitions
const int probeOut   = 25;   // Sends voltage
const int probeIn    = 26;   // Reads signal
const int speakerPin = 27;   // Connect to the positive leg of your speaker/buzzer

void setup() {
  Serial.begin(115200);

  pinMode(probeOut, OUTPUT);
  
  // Enable internal pull-down resistor to prevent false alarms
  pinMode(probeIn, INPUT_PULLDOWN); 
  
  pinMode(speakerPin, OUTPUT);

  digitalWrite(probeOut, LOW); // Start with probe off
}

void loop() {
  digitalWrite(probeOut, HIGH); // Turn on power to the probe
  delay(10); // Small stabilization delay

  int sensorValue = digitalRead(probeIn);

  digitalWrite(probeOut, LOW); // Turn off immediately to reduce electrolysis

  if (sensorValue == HIGH) {
    Serial.println("Liquid detected! Sounding alarm...");
    
    // Play a 1000 Hz (1 kHz) tone on the speaker
    tone(speakerPin, 1000); 
  } else {
    
    // Stop the sound when the probe is dry
    noTone(speakerPin); 
  }

  delay(1000); // Wait before checking again
}
