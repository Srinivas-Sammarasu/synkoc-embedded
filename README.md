# STM32 Smart Irrigation System — SYNKOC Day 30

**Personal ID:** `EMB-C12N5S`  
**Target board:** STM32 NUCLEO-C031C6  
**Development/simulation:** Wokwi browser with STM32 Arduino core (or STM32CubeIDE with equivalent HAL implementation)

## Project overview

This project reads a 12-bit soil sensor value on PA0, converts it to a percentage for demonstration, and controls a pump-driver output on PA6. A status LED on PA5 follows the pump command. Sampling is scheduled every 1,000 ms with `millis()`; the integrated loop does not use `delay()`.

The control uses hysteresis:
- Below 30%: pump ON.
- At or above 40%: pump OFF.
- Between 30% and below 40%: retain the previous pump state.
- ADC rail readings (`0` or `4090` and above): report `FAULT` and force pump/LED OFF.

> The percentage conversion `raw * 100 / 4095` is a simple demonstration mapping. For a real soil probe, calibrate dry and wet ADC values and map the calibrated range to moisture percentage.

## Pin assignments

| Function | STM32 pin |
|---|---|
| Soil sensor analog output | PA0 |
| Status LED | PA5 |
| Pump driver control | PA6 |
| USART2 | PA2/PA3 reserved |
| SWD | PA13/PA14 reserved |

**Hardware safety:** Do not power a pump directly from an STM32 GPIO. Use a correctly rated transistor/MOSFET or relay driver, an external pump supply, and suitable flyback protection for an inductive DC pump. Connect grounds appropriately.

## Build and run

1. Open this folder in an STM32 Arduino-core/Wokwi setup for the NUCLEO-C031C6.
2. Use `src/main.cpp` as the sketch source (or copy it into the Arduino sketch).
3. Connect the soil-sensor potentiometer/output to PA0, LED to PA5 through a suitable resistor, and a pump-driver input to PA6.
4. Start the simulation and open Serial Monitor at **115200 baud**.
5. Change the sensor input and verify the thresholds, fault behavior, LED, and one-second timestamps.

## Serial format

The program prints the personal ID line, project line, then CSV:

```text
SYNKOC EMB-C12N5S C
PROJECT STM32 Smart Irrigation System
t_ms,raw,moisture_pct,pump,status
```

Illustrative output only (not a captured run):

```text
1000,2048,50,OFF,OK
2000,1433,35,OFF,OK
3000,1024,25,ON,OK
4000,1433,35,ON,OK
5000,1638,40,OFF,OK
6000,2457,60,OFF,OK
7000,0,0,OFF,FAULT
8000,4095,100,OFF,FAULT
9000,819,20,ON,OK
10000,1843,45,OFF,OK
```

Your actual output may differ depending on sensor input and timing. Paste the actual Serial Monitor capture into the SYNKOC submission form.

## Day 30 task evidence

- A1 Timer PWM: passed in the lab checker. Settings recorded: PSC 47, ARR 19999, CCR 8000; 50 Hz, 40% duty.
- A2 UART CSV: passed in the lab checker.
- A3 Breakpoints: passed in the lab checker.
- C Final submission: complete the real hardware/simulation tests and attach evidence before marking it passed.

## Test table — fill with actual results

For every row, enter your actual test action and mark PASS or FAIL only after testing.

| Requirement | How tested | Expected result | Actual result |
|---|---|---|---|
| R1 Soil sensor | Turn potentiometer / vary sensor input | Raw reading changes | TO VERIFY |
| R2 Moisture display | Observe Serial Monitor | Moisture percentage is displayed | TO VERIFY |
| R3 Pump ON | Set moisture below 30% | Pump ON | TO VERIFY |
| R4 Pump OFF | Raise moisture to 40% or above | Pump OFF | TO VERIFY |
| R5 LED | Observe LED at both pump states | LED follows pump command | TO VERIFY |
| R6 Sensor fault | Test ADC rail/invalid reading | FAULT shown; pump OFF | TO VERIFY |
| R7 Sampling interval | Compare timestamps | One reading per second | TO VERIFY |
| R8 Non-blocking loop | Inspect loop and observe periodic sampling | No `delay()` in integrated loop | TO VERIFY |
| R9 Board | Inspect simulator/board configuration | NUCLEO-C031C6 selected | TO VERIFY |
| R10 Pin reservations | Inspect wiring and pin definitions | PA2/PA3 and PA13/PA14 reserved | TO VERIFY |

## Bug log

**Bug: incorrect moving-average divisor in the A3 starter.** The starter divided the sum by a fixed value of 5 even when fewer than five samples were stored. This produced an incorrect average during the buffer fill period. The fix was to divide by the current sample count (`avg = sum / count`). Add the actual Git commit hash for the fix before submission.

**Commit:** `ADD_ACTUAL_COMMIT_HASH_HERE`

## Submission links — replace placeholders

- **Final Wokwi project:** `ADD_YOUR_FINAL_INTEGRATED_WOKWI_URL`
- **GitHub repository:** https://github.com/Srinivas-Sammarasu/synkoc-embedded
- **Demo video (2–3 minutes):** `ADD_YOUR_VIDEO_URL`
- **Report:** This README (tick the “README in my repository” option in the lab form, if available).

Before submitting, open the demo link in a private/incognito window and confirm it is accessible to your mentor.
