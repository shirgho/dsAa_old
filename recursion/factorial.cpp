/* factorials

Recursion and Iteration
*/

#include <iostream>
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
    cout << " " << n;
    recursiveSeriesNegative(n - 1);
}

int main () {
    int n = 1;
    cout << "Enter the number to be factorialed or fibonacisosised: \n" << endl;
    cin >> n;

    cout << "Recursive Factorial of " << n << " is " << factorialRecursive(n) << endl;
    cout << "Iterative Factorial of " << n << " is " << factorialIterative(n) << endl;
     
    cout << "Iterative fibonacci of " << n << " is " << endl;
    fibonacciIerative(n);
    cout << "Recursive fibonacci of " << n << " is " << endl << "1" << endl;
    fibonacciRecursive(n);

    cout << "iterativeSeriesNegative of " << n << " is " << endl ;
    iterativeSeriesNegative(n);

    cout << "recursiveSeriesNegative of " << n << " is " << endl ;
    recursiveSeriesNegative(n);

    return 0;
}
