#define ORDER 32
#define SAMPLING_RATE 100
#define SIGNAL_PIN 33
#define OUTPUT_PIN 34

double h[ORDER];

double x[ORDER];
double output = 0.0;

void setup() {
  for (int i = 0; i < ORDER; i++) {
    x[i] = 0.0;
  }
}

void loop() {
  filterV1();
}

void filterV1() {

}

void filterV2() {
  double adcValue = analogRead(SIGNAL_PIN);
  
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
  delay(SAMPLING_RATE);
}
