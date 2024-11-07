#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * Time Complexity: O(2^n)
 * For each call fibonacci(n), it recursively calls fibonacci(n-1) and fibonacci(n-2). 
 * This creates a tree of recursive calls where each node represents a function call.
 * The size of this recursive call tree is exponential, and the time complexity is O(2^n) 
 * because for each n, you essentially have two branches (n-1 and n-2).

 * Space Complexity: O(n)
 * The recursion depth is proportional to n because it will reach the base case after n 
 * recursive calls. Since there is no extra memory allocated except for the recursive call 
 * stack, the space complexity is linear.
 */
void recursive(int n)
{
    for (int i = 0; i < n; i++)
        cout << fibonacci(i) << " ";
}

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void iterative(int n)
{
    int a1 = 0;
    int a2 = 1;

    cout << a1 << " " << a2 << " ";

    for (int i = 2; i < n; i++)
    {
        int a3 = a2 + a1;
        a1 = a2;
        a2 = a3;
        cout << a2 << " ";
    }

    cout << endl;
}

int main()
{
 //  recursive(10);
 //  cout << endl;
 //  iterative(10);
int num;
   cout<<"Enter What is your Number "<<endl;
   cin>>num;
   cout<<"RECURSIVE" <<endl;
   recursive(num);
   cout<<endl;
   cout<<"ITERATIVE" <<endl;
   iterative(num);
    
    return 0;
}
/*
FOR RECURSIVE:
Time Complexity: O(2^n)
Why is it O(2^n)?
In each call to fibonacci(n), there are two recursive calls: one to fibonacci(n-1) and one to fibonacci(n-2).
This forms a binary tree of calls, where each level splits into two more calls, and you keep dividing it in half.
At the top level, you have 1 call (fibonacci(n)). On the next level, 2 calls (fibonacci(n-1) and fibonacci(n-2)), then 4, then 8, and so on.
This results in an exponential growth of calls. The total number of calls is about 2^n.
So, the time complexity is O(2^n).
Space Complexity: O(n)
Why is it O(n)?
Each recursive call takes up space on the call stack (the memory used for keeping track of function calls).
The maximum depth of the recursion occurs when you go down to the base case. The deepest you will go is n recursive calls (like fibonacci(n) ? fibonacci(n-1) ? ... ? fibonacci(1)).
Thus, the space complexity is determined by the depth of the recursion, which is O(n).





FOR ITERATIVE:
Time Complexity: O(n)
Why is it O(n)?
The loop runs n-2 times (starting from 2 to n-1).
For each iteration, you just perform simple arithmetic and assign values, which takes constant time (O(1)).
Therefore, the total time complexity is proportional to the number of iterations, which is O(n).
Space Complexity: O(1)
Why is it O(1)?
The only extra space used is for the two variables a1 and a2 to store the last two Fibonacci numbers, and one temporary variable a3 to calculate the next Fibonacci number.
Since the space required does not depend on the size of n, it remains constant, O(1).




*/
