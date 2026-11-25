#include <Arduino.h>

// SYNKOC Day 30 final project
// Board: STM32 NUCLEO-C031C6 (STM32duino Arduino core)
// Pin plan: soil sensor PA0, status LED PA5, pump-driver control PA6.
// PA2/PA3 (USART2) and PA13/PA14 (SWD) are reserved.

const char* SYNKOC_ID = "EMB-C12N5S";

constexpr uint32_t SOIL_PIN = PA0;
constexpr uint32_t LED_PIN  = PA5;
constexpr uint32_t PUMP_PIN = PA6;

constexpr uint32_t SAMPLE_INTERVAL_MS = 1000;
constexpr uint32_t ADC_MAX = 4095;
constexpr uint32_t SENSOR_FAULT_LOW = 0;
constexpr uint32_t SENSOR_FAULT_HIGH = 4090;

constexpr uint32_t PUMP_ON_BELOW_PCT = 30;
constexpr uint32_t PUMP_OFF_AT_OR_ABOVE_PCT = 40;

unsigned long previousSampleMs = 0;
bool pumpOn = false;

void setOutputs(bool enabled) {
  pumpOn = enabled;
  digitalWrite(PUMP_PIN, pumpOn ? HIGH : LOW);
  digitalWrite(LED_PIN, pumpOn ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);

  pinMode(LED_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
  setOutputs(false);

  Serial.print("SYNKOC ");
  Serial.print(SYNKOC_ID);
  Serial.println(" C");
  Serial.println("PROJECT STM32 Smart Irrigation System");
  Serial.println("t_ms,raw,moisture_pct,pump,status");
}

void loop() {
  const unsigned long now = millis();

  if (now - previousSampleMs >= SAMPLE_INTERVAL_MS) {
    previousSampleMs = now;

    const uint32_t raw = analogRead(SOIL_PIN);
    const uint32_t moisturePct = (raw * 100UL) / ADC_MAX;

    // Treat ADC rail readings as invalid sensor/wiring readings.
    // Fail safe: pump and LED are both switched OFF.
    if (raw == SENSOR_FAULT_LOW || raw >= SENSOR_FAULT_HIGH) {
      setOutputs(false);
      Serial.print(now);
      Serial.print(",");
      Serial.print(raw);
      Serial.print(",");
      Serial.print(moisturePct);
      Serial.println(",OFF,FAULT");
      return;
    }

    // Hysteresis prevents rapid switching between 30% and 40%.
    if (moisturePct < PUMP_ON_BELOW_PCT) {
      setOutputs(true);
    } else if (moisturePct >= PUMP_OFF_AT_OR_ABOVE_PCT) {
      setOutputs(false);
    }

    Serial.print(now);
    Serial.print(",");
    Serial.print(raw);
    Serial.print(",");
    Serial.print(moisturePct);
    Serial.print(",");
    Serial.print(pumpOn ? "ON" : "OFF");
    Serial.println(",OK");
  }
}
