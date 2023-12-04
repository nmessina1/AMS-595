#include <iostream>
#include <vector>
#include "pi_approx.h"
#include "approximations.h"
#include <cmath> // For pow
#include <cstdlib> // for free

using namespace std;

int main(int argc, char *argv[]) {

    cout << "Using Q1, here is Pi approximation and error for N = 10000" << endl;
    PiResults result = pi_approx(10000);
    cout << "Approximation: " << result.approx << endl;
    cout << "Absolute Error: " << result.error << endl << endl;

    vector<int> powersOf10;
    for (int power = 1; power <= 7; power++){
        powersOf10.push_back(pow(10,power));
    }

    double *array = approximations(powersOf10);

    print_arr(array, powersOf10.size());

    // Free our dynamically allocated array
    free(array);


    return 0;
}