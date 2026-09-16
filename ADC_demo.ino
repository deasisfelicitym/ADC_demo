/*====================================================
                 ADC DEMO 
======================================================
Description:
  This code uses ADC with a potentiometer to read its 
  value, which is converted into LED brightness using 
  PWM. The potentiometer value is also displayed in 
  the Serial Monitor.

Programmer:
  De Asis, Felicity M.
  Dela Torre, Shanna Dale R.
  Galpo, Rhile L.

Date:
  16 September 2026
----------------------------------------------------*/
// GPIOs
const uint8_t POT = 36;
const uint8_t LED = 32;

// PWM config
const int PWM_FREQ = 5000;
const byte PWM_RES = 12;

// Variable
int pot_val = 0;

void setup() {
  // ADC pin
  pinMode(POT, INPUT);

  Serial.begin(9600);

  ledcAttach(LED, PWM_FREQ, PWM_RES);
}

void loop() {
  pot_val = analogRead(POT);

  ledcWrite(LED, pot_val);

  Serial.println(pot_val);

  delay(500);
}