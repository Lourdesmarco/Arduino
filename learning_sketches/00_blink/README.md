# Blink with LED and Resistor

This project implements the standard Arduino Blink sketch using external components on a breadboard to prevent board damage.

## Bill of Materials (BOM)
* 1x Arduino board
* 1x 5mm LED (Any color)
* 1x Resistor 
* 1x Breadboard / Mini Breadboard
* 2x Jumper wires (Male-to-Male)

### Resistor Specifications
* **Recommended value:** 220 Ω to 330 Ω (Ohms) for optimal brightness and safety.
* **Alternative values:** Up to 1k Ω (1000 Ohms) can be used, though the LED will shine slightly dimmer.
* **Color codes to look for:**
  * **220 Ω:** Red - Red - Brown - Gold
  * **330 Ω:** Orange - Orange - Brown - Gold
* **Purpose:** It limits the current coming from Pin 13 to prevent burning out the LED or damaging the Arduino board.


## Wiring Guide
* Connect the long leg of the LED (Anode) to Arduino **Pin 13**.
* Connect the short leg (Cathode) to the **Resistor**.
* Connect the other end of the resistor to Arduino **GND**.
* Refer to the circuit images in this folder for a visual schematic.


## Project Structure
* `0_blink.ino`: Main Arduino source code.
* `README.md`: Project documentation (this file).
* `data/Circuit_01.png`: Circuit schematic diagram (without breadboard, not recommended).
* `data/Circuit_02.jpeg`: Breadboard schematic diagram view.
