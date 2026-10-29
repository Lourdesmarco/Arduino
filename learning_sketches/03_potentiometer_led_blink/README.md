# Potentiometer to Adjust Blinking LED Time

This project reads the analog value from a potentiometer on pin A0 and uses it to adjust the blinking delay of an external LED, while continuously printing the raw values to the computer screen.

## Bill of Materials (BOM)
* 1x Arduino board
* 1x Potentiometer (Any standard value, e.g., 10k Ω)
* 1x 5mm LED (Any color)
* 1x Resistor 
* 1x Breadboard / Mini Breadboard
* 5x Jumper wires (Male-to-Male)

### Potentiometer Specifications
* **Recommended value:** 10k Ω (Ohms) is the standard for Arduino analog inputs.
* **Alternative values:** 1k Ω to 100k Ω potentiometers work perfectly fine.
* **Pins layout:** It features three pins (two outer terminals for power and a middle terminal for the variable signal).
* **Purpose:** It acts as a variable voltage divider, changing the voltage sent to the Arduino pin to dynamically alter the delay time.

### Resistor Specifications
* **Recommended value:** 220 Ω to 330 Ω (Ohms) for optimal brightness and safety.
* **Purpose:** It limits the current coming from Pin 13 to prevent burning out the LED or damaging the Arduino board.


## Wiring Guide

### Potentiometer Connections
* Connect the **Left Pin** of the potentiometer to Arduino **GND**.
* Connect the **Middle Pin** (Wiper) of the potentiometer to Arduino **A0**.
* Connect the **Right Pin** of the potentiometer to Arduino **5V**.
*(Note: Swapping the Left and Right pins will simply reverse the direction the knob turns to increase the delay).*

### LED Connections
* Connect the long leg of the LED (Anode) to Arduino **Pin 13**.
* Connect the short leg (Cathode) to one end of the **Resistor**.
* Connect the other end of the resistor to Arduino **GND**.


## Project Structure
* `3_potentiometer_led_blink.ino`: Main Arduino source code.
* `README.md`: Project documentation (this file).
* `data/Circuit_01.webp`: Breadboard schematic diagram view.

