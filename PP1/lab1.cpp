#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>
#include <stdexcept>

using namespace std;

/** Prints the author of the program and the task description. */
void print_program_info() {
	cout << "The author of the program is Dmytro Pivtoratskyi, ITK-11." << endl;
	cout << "This program calculates the value of the expression by given x. "
		<< "Variant 177." << endl;
}

/**
 * Asks the user for x exactly once.
 * @return the entered value
 * @throws runtime_error if the input is not a real number
 */
double input_x() {
	double x;
	cout << "Enter x (7 <= x <= 9): ";
	cin >> x;
	if (cin.fail()) {
		throw runtime_error("wrong input");
	}
	return x;
}

/**
 * Checks that the expression can be evaluated for x.
 * The arccos argument (x - 8) must lie in [-1; 1]; this also guarantees
 * that both denominators and the square root argument are valid.
 * @throws domain_error if x is outside [7; 9]
 */
void check_domain(double x) {
	if (x < 7.0 || x > 9.0) {
		throw domain_error("x is outside the domain");
	}
}

/** Calculates the value of the expression for the given x. */
double f(double x) {
	return sin(28.0 / 63.0)
		+ 25.0 * numbers::pi
		- 70.0 * numbers::e * 9.0 / ((x + 14.0) * (x - 11.0))
		+ 7.0 * acos(x - 8.0)
		+ 1.0 / sqrt(x + 12.0);
}

/** Prints the entered x and the result with fixed number of digits. */
void print_result(double x, double result) {
	cout << "done" << endl;
	cout << fixed << setprecision(5) << "for x = " << x << endl;
	cout << setprecision(9) << "result = " << result << endl;
}

/** Prints the entered x and the message that the result is undefined. */
void print_undefined_result(double x) {
	cout << "done" << endl;
	cout << fixed << setprecision(5) << "for x = " << x << endl;
	cout << "result = undefined" << endl;
}

int main() {
	double x = 0.0;

	print_program_info();
	try {
		x = input_x();
		cout << endl << "***** do calculations ... ";
		check_domain(x);
		print_result(x, f(x));
	}
	catch (const domain_error&) {
		print_undefined_result(x);
	}
	catch (const runtime_error&) {
		cout << endl << "wrong input" << endl;
	}
	return 0;
}