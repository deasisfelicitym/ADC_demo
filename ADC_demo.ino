/*====================================================
                 ADC DEMO
======================================================
Description:
  This program uses the ADC (Analog-to-Digital Converter)
  to read the brightness level detected by a photoresistor
  (LDR). The LDR changes its resistance depending on the
  amount of light it receives, allowing the system to
  determine whether the surroundings are dark or bright.

  The detected brightness is divided into three levels.
  Each level corresponds to a different LED color:
  Level 1 - Green
  Level 2 - Yellow
  Level 3 - Red

  PWM (Pulse Width Modulation) is used to control the
  LEDs based on the brightness level detected by the LDR.

Programmer:
  De Asis, Felicity M.
  Dela Torre, Shanna Dale R.
  Galpo, Rhile L.

Date:
  16 September 2026
----------------------------------------------------*/
// GPIOS
const uint8_t POT = 36;

const uint8_t LED_G = 32;
const uint8_t LED_Y = 33;
const uint8_t LED_R = 25;

// PWM
const int PWM_FREQ = 5000;
const byte PWM_RES = 12;

// variables
int pot_val = 0;

void setup() {

  // ADC pin
  pinMode(POT, INPUT);

  // PWM setup
  ledcAttach(LED_G, PWM_FREQ, PWM_RES);
  ledcAttach(LED_Y, PWM_FREQ, PWM_RES);
  ledcAttach(LED_R, PWM_FREQ, PWM_RES);

  Serial.begin(9600);
}

void loop() {

  pot_val = analogRead(POT);

  if (pot_val >= 0 && pot_val <= 1365) {

    ledcWrite(LED_G, pot_val);
    ledcWrite(LED_Y, 0);
    ledcWrite(LED_R, 0);

    Serial.println("Brightness: Level 1");

  } 
  else if (pot_val >= 1366 && pot_val <= 2730) {

    ledcWrite(LED_G, 0);
    ledcWrite(LED_Y, pot_val);
    ledcWrite(LED_R, 0);

    Serial.println("Brightness: Level 2");

  } 
  else if (pot_val >= 2731 && pot_val <= 4095) {

    ledcWrite(LED_G, 0);
    ledcWrite(LED_Y, 0);
    ledcWrite(LED_R, pot_val);

    Serial.println("Brightness: Level 3");
  }

  delay(500);
}