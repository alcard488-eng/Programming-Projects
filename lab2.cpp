
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

int main() {
    // 1. Information about the program
    cout << "Dmytro Pivtoratskyi" << endl;
    cout << "Variant: 177" << endl;
    cout << "Task: Calculate the sum of a power series "
        << "with the specified accuracy." << endl;

    double x, eps;

    // 2. Input x
    cout << "Enter x [-0.9; 0.9]: ";
    cin >> x;

    if (cin.fail()) {
        cout << "***** error" << endl;
        cout << "Invalid input: x must be a number." << endl;
        return 0;
    }

    if (!isfinite(x)) {
        cout << "***** error" << endl;
        cout << "Invalid input: x must be finite." << endl;
        return 0;
    }

    if (x < -0.9 || x > 0.9) {
        cout << "***** error" << endl;
        cout << "Invalid x: value must be in [-0.9; 0.9]."
            << endl;
        return 0;
    }

    // 3. Input accuracy
    cout << "Enter eps (> 0): ";
    cin >> eps;

    if (cin.fail()) {
        cout << "***** error" << endl;
        cout << "Invalid input: eps must be a number." << endl;
        return 0;
    }

    if (!isfinite(eps) || eps <= 0.0) {
        cout << "***** error" << endl;
        cout << "Invalid eps: accuracy must be "
            << "a positive finite number." << endl;
        return 0;
    }

    // 4. Start calculations
    cout << "***** do calculations ... ";

    // 5. Calculate the sum of the series
    double sum = 0.0;
    double term = pow(x, 7) / 21.0;
    double x4 = pow(x, 4);

    unsigned long long n = 0;

    // Add terms until the first term with |term| < eps
    do {
        sum += term;

        // Calculate the next term using recurrence
        double numerator = 4.0 * n + 3.0;
        double denominator = 4.0 * n + 11.0;

        term = -term * x4 * numerator / denominator;

        ++n;

    } while (fabs(term) >= eps);

    // 6. Finish calculations
    cout << "done" << endl;

    // 7. Output input values in scientific format
    cout << scientific << setprecision(7);
    cout << "for x = " << x << endl;

    cout << scientific << setprecision(9);
    cout << "for eps = " << eps << endl;

    // 8. Output result
    cout << fixed << setprecision(8);
    cout << "result = " << sum << endl;

    return 0;
}
