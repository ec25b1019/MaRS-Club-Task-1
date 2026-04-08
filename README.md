# MaRS-Club-Task-1
This repo is the submission of task 1 of the MaRS club

Section A:

Q1. Blinking LED with different time intervals
Tinkercad Link: https://www.tinkercad.com/things/dIMJeyZBf6b-blinking-led-with-different-time-intervals
Code Explanation:
  This code uses a non-blocking approach to handle multiple timers simultaneously without using the delay() function, which would pause the entire program. By calling three distinct functions (led1(), led2(), and led3()) within the main loop(), the Arduino repeatedly checks whether the required time (500ms, 1000ms, 1500ms) has elapsed for each LED. When a condition is met, only that specific LED's state is toggled, and its "previous" timestamp is updated, allowing all three LEDs to blink at their own rates without interfering with one another.

Q2. Controlling the colour of the RGB LED and the blinking speed of another LED with a potentiometer
Tinkercad Link: https://www.tinkercad.com/things/7FZpUgGDVXB-controlling-rgb-led-and-blinking-of-led-with-potentiometer
Code Explanation:
  The math utilises the map() function to translate the Arduino's 10-bit Analog-to-Digital Converter (ADC) range into usable values. The code uses a non-blocking millis() structure to toggle a standard LED, where the blink interval is dynamically updated based on the potentiometer's position.
  Blink Rate Mapping: The raw input (0 to 1023) is mapped to a time interval (50 to 1000ms). 
  RGB Segmentation: To create a full colour cycle, the 1024 possible input values are divided into three equal segments of approximately 341 units each (1024/3 = 341.33).
    Segment 1 (0–341): Fades Red out (255 to 0) and Green in (0 to 255).
    Segment 2 (342–682): Fades Green out (255 to 0) and Blue in (0 to 255).
    Segment 3 (683–1023): Fades Blue out (255 to 0) and Red back in (0 to 255).

Q3. Build a reaction time tester
Tinkercad Link: https://www.tinkercad.com/things/81tj6ZhuMAq-build-a-reaction-time-tester
Code Explanation:
  The "sensor math" for this project relies on calculating the temporal difference between two discrete events using the processor's internal uptime clock.
  The reaction time is calculated using the following formula:
      reactTime = millis - OnTime
    OnTime: The timestamp captured via millis() is the exact moment the LED pin is set to HIGH.
    millis: The timestamp captured when the digitalRead(button) first detects a LOW state.
    reactTime: The duration, in milliseconds, that the user took to respond to the visual stimulus.
  By resetting ResetTime to the current millis() after each press, you ensure that the randDelay math remains accurate for every subsequent round without the need for a hardware reset.
