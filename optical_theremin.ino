// Step 1: Define inputs/outputs and key variables
#define BUZZER 9
#define LDR1 A0

// We will be using frequency to store the value of the tone generated on the buzzer.
long frequency;

// pitch will store a multiplier value to determine the pitch of the sound.
int pitch = 1;

// tempo controls the speed of the change in sound. the higher the value, the slower the change. use 1 as a minimum.
int tempo = 2;

// range determines the range of pitches available to the instrument.
// try a range of 1 and 200 to hear the difference!
int range = 100;

// Step 2: create setup loop
void setup() {

	Serial.begin(9600);

	pinMode(BUZZER, OUTPUT);
	pinMode(LDR1, INPUT);
}

// Step 3: create main loop
void loop() {

	// reads the value of the first LDR and multiplies it by the pitch.
	// this value is stored in frequency and determines the tone generated on the buzzer.
	frequency = analogRead(LDR1) * pitch;

	// this formula rounds the value in frequency to create a range of accessible tones.
	frequency = range * ((frequency + 50) / range);

	// here is where the sound is generated.
	tone(BUZZER, frequency);

	// the tempo of the instrument is determined by this delay.
	delay(tempo * 100);

	// add a line here to show the value of frequency in the Serial Monitor.
	Serial.println(frequency);
}
