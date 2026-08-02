// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printFibonacciSequence(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }
    
    cout << "Fibonacci sequence: ";
    
    if (n >= 1) {
        cout << "0 ";
    }
    if (n >= 2) {
        cout << "1 ";
    }
    
    if (n > 2) {
        long long prev = 0, curr = 1;
        for (int i = 2; i < n; i++) {
            long long next = prev + curr;
            cout << next << " ";
            prev = curr;
            curr = next;
        }
    }
    
    cout << endl;
}

bool isFibonacci(long long num) {
    if (num < 0) {
        return false;
    }
    
    if (num == 0 || num == 1) {
        return true;
    }
    
    long long prev = 0, curr = 1;
    
    while (curr < num) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    
    return curr == num;
}

int main() {
    int choice;
    
    do {
        cout << "\n=============================" << endl;
        cout << "   FIBONACCI MENU" << endl;
        cout << "=============================" << endl;
        cout << "1. Print first N Fibonacci terms" << endl;
        cout << "2. Check if number is Fibonacci" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        
        if (choice == 1) {
            int n;
            cout << "How many terms? ";
            cin >> n;
            printFibonacciSequence(n);
        }
        else if (choice == 2) {
            long long num;
            cout << "Enter a number to check: ";
            cin >> num;
            
            if (isFibonacci(num)) {
                cout << num << " is a Fibonacci number." << endl;
            } else {
                cout << num << " is NOT a Fibonacci number." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
    
    return 0;
}


