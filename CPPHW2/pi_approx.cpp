// Windows specific according to: https://stackoverflow.com/questions/26065359/m-pi-flagged-as-undeclared-identifier
// Required to import M_PI
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <math.h>

#include "pi_approx.h"

// struct PiResults {
//     double piValue;
//     double absoluteError;
// };

using namespace std;

//approximate the value of Pi using the Trapezoidal Rule and partitioning interval (0,1)
//define our function f(x)
double func(double x) {
    return sqrt(1-(x*x));
}

//numerical evaluation - the summation
double eval_numerically(int N) {
    
    // b-a = 1-0 = 1
    double delta_x = 1/(double)N;

    double ctr = 0;

    for (int k = 1; k <= N; k++) {
        double x_k_minus1 = (k-1) * delta_x;
        double x_k = k * delta_x;

        double sum = (func(x_k)+func(x_k_minus1)) / (double)2;

        ctr += delta_x * sum;
    }

    return ctr;
}
//setting up the struct so that we can display both the approximation and the error for Pi
PiResults pi_approx(int N) {
    PiResults result;
    //multiply by 4 sine we are evaluating
    double piApprox =  4 * eval_numerically(N);
    double absErr = abs(piApprox-M_PI);

    result.error = absErr;
    result.approx = piApprox;

    return result;
}


// int main() {
//     PiResults a = pi_approx(1000);
//     double p = a.piValue;
//     double e = a.absoluteError;

//     cout << p << endl;
//     cout << e << endl;

//     return 0;
// }