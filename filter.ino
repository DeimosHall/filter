#define SIGNAL_PIN 33
#define OUTPUT_PIN 34
#define ORDER 32
#define SAMPLING_RATE 25 // microseconds

// The filter coefficients
double h[ORDER];
double x[ORDER];
double output = 0.0;
double adcValue = 0.0;

void setup() {
  Serial.begin(115200);

  // Initialize the input buffer with zeros
  for (int i = 0; i < ORDER; i++) {
      x[i] = 0.0;
  }

  for (int i = 0; i < ORDER; i++) {
      h[i] = i + 1.0;
  }

  speedTest();
}

void loop() {
  // filter();
  // delayMicroseconds(SAMPLING_RATE);
}

void filter() {
  adcValue = analogRead(SIGNAL_PIN);

  // Update the input buffer, shift to the right
  for (int i = ORDER - 1; i > 0; i--) {
      x[i] = x[i - 1];
  }
  x[0] = adcValue;

  // Calculating the output of the filter
  output = 0.0;
  for (int i = 0; i < ORDER; i++) {
      output += h[i] * x[i];
  }

  analogWrite(OUTPUT_PIN, output);
}

void speedTest() {
  unsigned long start = micros();
  filter();
  unsigned long end = micros();
  Serial.println("Time: " + String(end - start) + " microseconds");
}
