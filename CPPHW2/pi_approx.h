#ifndef APPROX
#define APPROX

//struct to return both the approximation Pi as well as the error
struct PiResults {
    double approx;
    double error;
};

extern PiResults pi_approx(int N);

#endif