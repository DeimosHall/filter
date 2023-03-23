#define ORDER 32
#define SAMPLING_RATE 100

double taps[ORDER];

double input[ORDER];
double output = 0.0;

void setup() {
  for (int i = 0; i < ORDER; i++) {
    input[i] = 0.0;
  }
}

void loop() {
  double x = analogRead(A0);
  
  // Actualización del buffer de entrada
  for (int i = ORDER - 1; i > 0; i--) {
    input[i] = input[i - 1];
  }
  input[0] = x;
  
  // Cálculo de la salida del filtro FIR
  output = 0.0;
  for (int i = 0; i < ORDER; i++) {
    output += taps[i] * input[i];
  }
  
  // Escritura de la salida en la salida analógica
  analogWrite(A1, output);
  
  // Retardo para controlar la frecuencia de muestreo
  delay(10);
}
