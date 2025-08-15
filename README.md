# Arduino-8-8-LED-Matrix-Sequential-LED-Lighting-Effect-smily-face-
This Arduino sketch is an 8×8 LED matrix visual effect project. It sequentially lights up specific LEDs for a short time, creating a visual pattern.

🔍 How it works
1️⃣ Hardware used

Arduino board

8×8 LED matrix (common cathode)

Connecting wires

2️⃣ Program flow

Setup:

Define the row and column pins of the LED matrix.

Set all row and column pins as outputs.

Loop:

Run for 6 seconds:

Sequentially light up 8 predefined LEDs in ledPoints array.

Short delay (3 ms) creates a persistence-of-vision effect, making LEDs appear simultaneously.

After 6 seconds, clear the matrix and pause 2 seconds before repeating.

Functions:

lightUp(x, y) → Lights up a specific LED at column x and row y.

clearMatrix() → Turns off all LEDs.

3️⃣ What you’ll see

Eight LEDs light up one by one quickly, appearing almost simultaneously for 6 seconds.

The effect repeats every 8 seconds (6 sec on + 2 sec off).
