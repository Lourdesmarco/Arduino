# Arduino Serial Monitor Guide

This project communicates with the computer using serial communication. To see the output data and messages sent by the Arduino board, you need to open the built-in Serial Monitor in the Arduino IDE.

## How to Open the Serial Monitor

Depending on your Arduino IDE language settings, follow these steps:

### Option A: If your IDE is in Spanish
1. Go to the top menu and click on **Herramientas**.
2. Select **Monitor Serie** from the dropdown list.

### Option B: If your IDE is in English
1. Go to the top menu and click on **Tools**.
2. Select **Serial Monitor** from the dropdown list.

---

## Alternative Shortcuts
You can also open the monitor quickly using these keyboard shortcuts:
* **Windows / Linux:** `Ctrl + Shift + M`
* **macOS:** `Cmd + Shift + M`
* **Visual Icon:** You can also click the **magnifying glass icon** 🔍 located in the top-right corner of the Arduino IDE interface.

> ⚠️ **Important Configuration:** Make sure the baud rate inside the Serial Monitor window is set to **9600 baud** to match the speed defined in the `Serial.begin(9600)` code. Otherwise, the text will appear as corrupted or strange symbols.
