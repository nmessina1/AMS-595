#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// Question 2: function for printing a vector

//intake integer vector
void print_vector(vector <int> v){
    //output text "your vector is" before the vector is printed
    cout << "Your Vector is: ";
    //for each item in the vector, number of iterations = size of vector,
    //increment i by 1 each time
    for(int i=0; i < v.size(); i++){ 
        //output the value at each vector of the index
        cout<< v[i] << " ";
    }
    //new line
    cout << "\n";
}

//Question 4a If Prime
bool isprime(int p){
    //bool result;
    //always true for 1
    if (p == 2){
        return true;
    }
    //always false for 1
    else if (p <= 1)
    {
        return false;
    }
    
    else{
        //for every number from 2 to n/2, check if n if divisible by i
        for(int i = 2; i <=p/2; i++){
            if(p%i == 0){
                //if yes, false, there are factors other than 1 and itself so not prime
                return false; 
            }
        }
        //otherwise prime
        return true;
    }
    //otherwise prime
    return true;
}
//test casees for 4a
void test_isprime() {
    std::cout << "isprime(2) = " << isprime(2) << '\n';
    std::cout << "isprime(10) = " << isprime(10) << '\n';
    std::cout << "isprime(17) = " << isprime(17) << '\n';
}

//Question 4b Factorize 

//function outputs an integer n
vector<int> factorize(int n) {
    //initialize vector called answer
    vector<int> answer;
    //loop through go through all numbers 1 to n, if i is divisible by n it is a factor, so add it to the vector
    for (int i = 1; i<=n; i++) {
        if (n % i == 0){
            answer.push_back(i);
        }
    }
    //return the answer vector we added to
    return answer;
}
//Question 4B Test Case Function
void test_factorize() {
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));
}

//Question 4c Prime Factorization
//output an integer n
vector <int> prime_factorize(int n){
    //initialize answer vector
    vector<int> answer;
    //check if i is a factor, then use our prime funciton to check if it is prime
    //if it is a factor and prime, add it to the list
    for (int i = 1; i<=n; i++) {
        if (n % i == 0 && isprime(i)==true){
            answer.push_back(i);
        }
    }
    return answer;    
}

//Question 4c Test Cases
void test_prime_factorize() {
    print_vector(prime_factorize(2));
    print_vector(prime_factorize(72));
    print_vector(prime_factorize(196));
}

//Question 5 Recursive Functions and Loops
//return an integer called "row"
vector<int> pascal(int row) 
{
    //when n=1 the row is just 1
    vector<int> row_1 = {1};
    if (row == 1)
    {
        return row_1;
    }
    //set our previous row to a vector containing just "1"
    //set our counter to 1
    vector <int> prev_row = {1};
    int counter = 1;
    //while our counter is less than the row
    while (counter < row)
    {
        //initialize our current row to a vector containing "1"
        vector <int> cur_row = {1};

        //for i from 0 - length of the previous row - 1; increment i by 1 each time
        for (int i = 0; i < prev_row.size()-1 ; i++)
        {
            //our new value is equal to the value at i + the value at i+1
            int value = prev_row[i] + prev_row[i+1];
            //add this new value to our current row 
            cur_row.push_back(value);
        }
        //add the final 1 to our current row
        cur_row.push_back(1);
        //set previous row to current row, increment counter by 1
        prev_row = cur_row;
        counter ++;
    }
    //return our previous row which is now the current row
    return prev_row;
}
//Test Question 5 Pascal 
void test_pascal()
{
    print_vector(pascal(6));
    print_vector(pascal(2));
    print_vector(pascal(3));
    print_vector(pascal(4));
    print_vector(pascal(1));

}


// Question 1 Conditional Statements
int main(){
    //user enters an integer number, "z"
    int z;
    printf("Enter a number: ");
    scanf("%i", &z);
    //use swtich statement to return a phrase based on the value inputted
    switch(z){
        case -1:
            cout << "n is -1" << endl;
            break;
        case 0:
            cout << "n is 0" << endl;
            break;
        case 1:
            cout << "n is 1" << endl;
            break;
        default:
            cout << "other value" << endl;

    }

    // Test vector for Q2 printing a vector
    vector<int> vec = {1, 2, 3, 4, 5,6};
    print_vector(vec);


    // Question 3 While Loop - Fibonacci Sequence
    //initialize our first 2 values, 0 and 1
    int num1 = 0;
    int num2 = 1;
    //initialize our first output, which is the first two values added together
    int output = num1 + num2;
    //while our output is < 4,000,000
    while(num1 + num2 <4000000){
        //print all outputs with a comma in between
        cout << output << " , ";
        //set our number 1 to our number 2
        num1 = num2;
        //set our number 2 to the output, this way we always add the previous 2 numbers together
        num2 = output;
        //add the next 2 numbers together
        output = num1 + num2;
    }
     
    // Question 4a Test Cases

    test_isprime();

    //Question 4b Test Cases

    test_factorize();

    //Question 4c Test cases
    test_prime_factorize();

    //Question 5 Test Cases:
    test_pascal();


    return 0;
}
