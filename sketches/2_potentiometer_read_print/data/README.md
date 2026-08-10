# Analog Read with Potentiometer

This project reads the variable voltage from a potentiometer using an analog input pin and displays the raw values on the computer screen.

## Bill of Materials (BOM)
* 1x Arduino board
* 1x Potentiometer (Any standard value, e.g., 10k Ω)
* 1x Breadboard / Mini Breadboard
* 3x Jumper wires (Male-to-Male)

### Potentiometer Specifications
* **Recommended value:** 10k Ω (Ohms) is the standard for Arduino analog inputs.
* **Alternative values:** 1k Ω to 100k Ω potentiometers work perfectly fine.
* **Pins layout:** It features three pins (two outer terminals for power and a middle terminal for the variable signal).
* **Purpose:** It acts as a variable voltage divider, changing the voltage sent to the Arduino pin as you turn the knob.


## Wiring Guide
* Connect the **Left Pin** of the potentiometer to Arduino **GND**.
* Connect the **Middle Pin** (Wiper) of the potentiometer to Arduino **A0**.
* Connect the **Right Pin** of the potentiometer to Arduino **5V**.
*(Note: Swapping the Left and Right pins will simply reverse the direction the knob turns to increase the values).*


## Project Structure
* `2_potentiometer_read_print.ino`: Main Arduino source code.
* `data/README.md`: Project documentation (this file).
* `data/Circuit_01.jpg`: Circuit schematic diagram (without breadboard)
* `data/Circuit_02.webp`: Breadboard schematic diagram view.
* `data/potentiometer.webp`: Potentiometer terminals explanation.

