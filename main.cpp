/*
 *          ORDER-1
 * output = SUM h[i]*x[i]
 *          i=0
*/

#include <iostream>
#include <vector>
using namespace std;

#define ORDER 32

// The filter coefficients
double h[ORDER] = {32.0, 31.0, 30.0, 29.0, 28.0,
                   27.0, 26.0, 25.0, 24.0, 23.0,
                   22.0, 21.0, 20.0, 19.0, 18.0,
                   17.0, 16.0, 15.0, 14.0, 13.0,
                   12.0, 11.0, 10.0, 9.0, 8.0,
                   7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};

double x[ORDER];
double output = 0.0;

// The filter function
void filter();

int main() {
    // Initialize the input buffer with zeros
    for (int i = 0; i < ORDER; i++) {
        x[i] = 0.0;
    }

    // Apply the filter to a test signal
    for (int i = 0; i < 10; i++) {
        filter();
        cout << output << '\n';
    }

    return 0;
}

void filter() {
    // Generate a test signal to simulate the analog input
    // double adcValue = 2.0 * static_cast<double>(rand()) / RAND_MAX - 1.0;
    double adcValue = 1.0;

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
}
