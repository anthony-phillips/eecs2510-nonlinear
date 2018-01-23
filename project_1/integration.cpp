#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double lower_limit;
    double upper_limit;

    int step_count;
    double step_size;

    double integral = 0;

    cout << "f(x) = sin(x)" << endl;
    
    cout << "Enter the lower limit of integration : ";
    cin >> lower_limit;

    cout << "Enter the upper limit of integration : ";
    cin >> upper_limit;

    if (upper_limit <= lower_limit)
    {
        cout << "Upper limit must be greater than lower limit." << endl;
        return EXIT_FAILURE;
    }

    cout << "Enter number of steps between upper and lower limit : ";
    cin >> step_count;

    if (step_count <= 0)
    {
        cout << "Number of steps must be greater than zero." << endl;
        return EXIT_FAILURE;
    }

    step_size = (upper_limit - lower_limit) / step_count;
    cout << "Step size : " << step_size << endl << endl;

    cout << fixed << setw(10) << left << "   a";
    cout << fixed << setw(10) << left << "   b";
    cout << fixed << setw(10) << left << "  f(a)";
    cout << fixed << setw(10) << left << "f(2a+b/3)";
    cout << fixed << setw(10) << left << "f(a+2b/3)";
    cout << fixed << setw(10) << left << "  f(b)";
    cout << " value"<< endl;

    for (int i=0; i < step_count; i++)
    {
        double a = lower_limit + (i * step_size);
        double b = a + step_size;

        double f_a = sin(a);
        double f_b = sin(b);

        double f_2a_b_3 = sin((2 * a + b) / 3);
        double f_a_2b_3 = sin((a + 2 * b) / 3);

        double interval_area = (b - a) / 8 * (f_a + 3 * f_2a_b_3 + 3 * f_a_2b_3 + f_b);

        cout << fixed << setw(10) << left << setprecision(5) << a;
        cout << fixed << setw(10) << left << setprecision(5) << b;
        cout << fixed << setw(10) << left << setprecision(5) << f_a;
        cout << fixed << setw(10) << left << setprecision(5) << f_2a_b_3;
        cout << fixed << setw(10) << left << setprecision(5) << f_a_2b_3;
        cout << fixed << setw(10) << left << setprecision(5) << f_b;
        cout << setprecision(5) << interval_area << endl;

        integral += interval_area;
    }

    cout << endl << "Calculated integral : " << integral << endl;

    return EXIT_SUCCESS;
}