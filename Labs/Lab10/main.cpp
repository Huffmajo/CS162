/*********************************************************************
 ** Program name: Iteration vs recursion
 ** Author: Joel Huffman
 ** Date: 03/14/18
 ** Description: Comparing speeds between iterative and recursive
 ** versions of the same function.
 *********************************************************************/

#include <ctime>
#include <iostream>
using std::cout;

int fibonacciRecursive(int n);
int fibonacciIterative(int n);
void runTime(int n, int t);

int main() {

    runTime(1, 1000);
    runTime(5, 1000);
    runTime(10, 1000);
    runTime(15, 1000);
    runTime(20, 1000);
    runTime(25, 1000);
    runTime(30, 1000);
    
    return 0;
}

/*********************************************************************
 ** Function is taken from source at:
 ** https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
 ** original author: joseph.arul83@gmail.com
 *********************************************************************/
/*********************************************************************
 ** fibonacciRecursive(int n):
 ** Accepts an integer. Returns the value of the nth number in the
 ** fibonacci sequence. The result is calculated recursively.
 *********************************************************************/
int fibonacciRecursive(int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }
    
    //other base case
    else if (n == 1)
    {
        return 1;
    }
    
    //recursive step
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

/*********************************************************************
 ** Function is taken from source at:
 ** https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
 ** original author: joseph.arul83@gmail.com
 *********************************************************************/
/*********************************************************************
 ** fibonacciIterative(int n):
 ** Accepts an integer. Returns the value of the nth number in the
 ** fibonacci sequence. The result is calculated iteratively.
 *********************************************************************/
int fibonacciIterative(int n)
{
    int first = 0;
    int second = 1;
    int counter = 2;
    
    while (counter < n)
    {
        int temp = second;
        second = first + second;
        first = temp;
        ++counter;
    }
    
    if (n == 0)
    {
        return 0;
    }
    
    else
    {
        return first + second;
    }
}

/*********************************************************************
 ** runTime(int n, int i):
 ** Accepts two integers. Returns the run time (in clock ticks) to calculate
 ** the nth number in the fibonacci sequence i times for both the recursive and
 ** iterative functions.
 *********************************************************************/
void runTime(int n, int t)
{
    clock_t rTime;
    clock_t iTime;
    double rDuration;
    double iDuration;

    //recursive function timed to run calculating the nth fibonacci number
    //i times
    rTime = clock();
    for (int i = 0; i < t; i++)
    {
        fibonacciRecursive(n);
    }
    rDuration = (clock() - rTime);

    //iterative function timed to run calculating the nth fibonacci number
    //i times
    iTime = clock();
    for (int i = 0; i < t; i++)
    {
        fibonacciIterative(n);
    }
    iDuration = clock() - iTime;
    
    cout << "For n = " << n << "\n";
    cout << "Recursive results: " << rDuration << " clock ticks.\n";
    cout << "Iterative results: " << iDuration << " clock ticks.\n\n";
}
