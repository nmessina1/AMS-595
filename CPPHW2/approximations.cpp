#include <iostream>
# include <vector>
#include <cstdlib> // For malloc
#include "pi_approx.h"

using namespace std;

double *approximations(vector<int> positiveIntegers) {

    int vecSize = positiveIntegers.size();

    // Dynamically allocate memory for the array
    double *approxArray = (double*) malloc(vecSize * sizeof(double));

    for (int i = 0; i < vecSize; i++) {
        int N = positiveIntegers[i];
        PiResults results = pi_approx(N);
        approxArray[i] = results.approx;

        // cout << results.absoluteError << endl;
    }

    return approxArray;
}

void print_arr(double *arr, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}


// int main() {

//     vector<int> vec;
//     vec.push_back(10);
//     vec.push_back(1000);
//     vec.push_back(10000);
//     vec.push_back(100000);

//     double *arr = approximations(vec);

//     print_arr(arr, vec.size());

    
//     // cout << arr[1] << endl;

//     // Need to free our dynamically allocated memory
//     free(arr);

//     return 0;
// }