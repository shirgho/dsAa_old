/* factorials

Recursion and Iteration
*/

#include <iostream>
using namespace std;

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


int main () {
    int n = 1;
    cout << "Recursive Factorial of " << n << " is " << factorialRecursive(n) << endl;
    cout << "Iterative Factorial of " << n << " is " << factorialIterative(n) << endl;
    return 0;
}
