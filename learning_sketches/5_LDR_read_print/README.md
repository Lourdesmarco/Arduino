# Analog Read with LDR (Photoresistor / Photocell)

This project reads the variable voltage from a Light Dependent Resistor (LDR) using an analog input pin and displays the raw values on the computer screen.

## Bill of Materials (BOM)
* 1x Arduino board
* 1x LDR (Photoresistor / Photocell)
* 1x 10k Ω Resistor (Color code: Brown-Black-Black-Red-Brown)
* 1x Breadboard / Mini Breadboard
* 3x Jumper wires (Male-to-Male)

### LDR and Resistor Specifications
* **LDR Purpose:** It changes its internal electrical resistance depending on the ambient light level (high resistance in the dark, low resistance under bright light).
* **Recommended Resistor value:** 10k Ω (Ohms) is required to build a fixed voltage divider so the Arduino can properly measure the voltage changes.
* **Pins layout:** The LDR has two pins (non-polarized, meaning they can be connected in any direction).
* **Behavior:** By default, higher ambient light levels will deliver higher analog values to the Arduino pin.


## Wiring Guide
* Connect one pin of the **LDR** to Arduino **5V**.
* Connect the other pin of the **LDR** to Arduino **A0**.
* Connect one leg of the **10k Ω Resistor** to that same Arduino **A0** pin (sharing the track with the LDR).
* Connect the remaining leg of the **10k Ω Resistor** to Arduino **GND**.
*(Note: This creates a voltage divider. Swapping the 5V and GND connections between the LDR and the resistor will reverse the reading behavior, making values go up in the dark).*


## Project Structure
* `5_LDR_read_print.ino`: Main Arduino source code.
* `README.md`: Project documentation (this file).
* `data/Circuit_01.jpg`: Circuit schematic diagram (without breadboard).



