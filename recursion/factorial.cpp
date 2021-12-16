/* factorials

Recursion and Iteration
*/
#include <assert.h> 
#include <iostream>
#include <limits>

using namespace std;


int fibonacciRecursive( int n,  
                        int prev_number = 0,
                        int next_number = 1,
                        int final_number = 1 ){
   
    if(n >= 0){
        final_number = prev_number + next_number;
        cout << final_number << endl;
        prev_number = next_number;
        next_number = final_number;
        n--;
        fibonacciRecursive(n, prev_number, next_number, final_number);
    } else {
        return 0;
    }

    return 0;
}

int fibonacciIerative(int n){
    // add the prev number and current to get next
    // 1, 1, 2, 3, 5, 8, 13,  21
    int NumberA = 0;
    int NumberB = 1;
    int NumberC = 1;

    int i = 0;
    cout << NumberC << endl;
    while( i <= n){
        NumberC = NumberA + NumberB;
        cout << NumberC << endl;
        NumberA = NumberB;
        NumberB = NumberC;
        i++;
    }

    return 0;
}

int factorialRecursive(int n){
    if (n < 1) {
        return 1;
    } 
    else {
        return n * factorialRecursive(n - 1);
    }
}

int factorialIterative(int n){
    if (n < 1) {


        return 1;
    } 
    else {
        int result = n;
        for(int i = 1; i < n; i++){     
          result = result * (n-i);   
          //cout << "step" << i << "is" << result << endl;
        }
        return result;
    }
}

void iterativeSeriesNegative(int n){
    int start = n;
    while (start > 0){
        cout << start << " " << endl;
        start--;
    }
}

void recursiveSeriesNegative(int n){
    /*
    cout << n << endl;
    if (n == 1){
        return 0;
    } else {
        recursiveSeriesNegative(n-1);
    }

    return 0;
    */

    if(n <= 0)
        return;
    cout << n << endl;
    recursiveSeriesNegative(n - 1);
}

int triangularNumberIterative(int term)
{
    int value = 0;

    while (term > 0){
        value += term;
        term--;
    }

    return value;
}

int triangularNumberRecursive(int term)
{
    int value = term;
    //base case
    if (term == 1) return 1;
    //recurse case
    //return (triangularNumberRecursive(term-1) + term);
    value += triangularNumberRecursive(term-1);
    return value;
    
}

//raising number to power using recursion
int recursivePow(int number, int power)
{
    //5² = 5 x 5 (2-1 = 1 time)
    //5^power = 5 x 5 (power-1 times)

    assert(power >= 0);

    // base case
    if (power == 0) return 1;
    // recursive case
    return (number * recursivePow(number, power-1));
}

int doubleFactorial(int n){
    //n * (n-2) * (n-4) until n is 0 or 1

    assert(n >= 0);
    //base case
    if (n == 0 || n == 1) return 1;
    //recurse case
    return (n * doubleFactorial(n-2));
}

int main () {
    int n = 1;
    int power = n;

    cout << "Enter the number to be factorialed or fibonacisosised or otherwised: ";
    cin >> n;

    cout << "Recursive Factorial of " << n << " is " << factorialRecursive(n) << "." << endl;
    cout << "Iterative Factorial of " << n << " is " << factorialIterative(n) << "." << endl;
    cout << "The double recursive factorial of " << n << " is " << doubleFactorial(n) << "." << endl;

    cout << "Iterative fibonacci of " << n << " is " << endl;
    fibonacciIerative(n);
    cout << "Recursive fibonacci of " << n << " is " << endl << "1" << endl;
    fibonacciRecursive(n);

    cout << "iterativeSeriesNegative of " << n << " is " << endl ;
    iterativeSeriesNegative(n);

    cout << "recursiveSeriesNegative of " << n << " is " << endl ;
    recursiveSeriesNegative(n);

    cout << "The value of the " << n << "th triangular term using a loop: ";
    cout << triangularNumberIterative(n) << "." << endl;

    cout << "The value of the " << n << "th triangular term using recursion: ";
    cout << triangularNumberRecursive(n);
    cout << '.' << endl;

    do{
        std::cin.clear();
        cout << "Enter the power (valid positive number or 0) you wish to raise current number to: " ;
        cin >> power;
    }
    while (!std::cin.good());

    cout << "The value of raising " << n << " to the power " << power << " using recursion is: ";
    cout << recursivePow(n, power);
    cout << '.' << endl;


    return 0;
}
