/*
Speaker - Musical scale

Generates a musical scale by playing 12 notes sequentially. Each note lasts for 1.5 seconds, followed by a 0.5 second pause.
*/

int speakerPin = 13;
int frequency = 220;    // frequency corresponding to the note La
int counter;          // variable for the counter
float m = 1.059;         // constant to multiply frequencies (ratio between semitones)


void setup()
{
}


void loop()
{
for (counter = 0, frequency = 220; counter < 12; counter++)
    {
      frequency = frequency * m;     // updates the frequency for the next note in the scale
      tone(speakerPin, frequency);   // plays the current tone
      delay(1500);                   // keeps it for 1.5 seconds
      noTone(speakerPin);            // turns off the tone before playing the next one
      delay(500);                    // waits for half a second between notes
    }
}
