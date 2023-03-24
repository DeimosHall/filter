// #define SIGNAL_PIN 33
// #define OUTPUT_PIN 25
#define ORDER 32
#define SAMPLING_RATE 25 // microseconds

const int SIGNAL_PIN = 33;
const int OUTPUT_PIN = 25;

// The filter coefficients
float h[ORDER];
float x[ORDER];
float output = 0.0;
int adcValue = 0.0;

void setup() {
  Serial.begin(115200);
  pinMode(SIGNAL_PIN, INPUT);
  pinMode(OUTPUT_PIN, OUTPUT);

  // Initialize the input buffer with zeros
  for (int i = 0; i < ORDER; i++) {
      x[i] = 0.0;
  }

  for (int i = 0; i < ORDER; i++) {
      h[i] = i + 1.0;
  }

  for (int i = 0; i < 10; i++) {
    speedTest();
  }
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
