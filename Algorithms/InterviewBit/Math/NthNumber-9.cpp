// C++ implementataion of above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find Nth number in base 9
long long findNthNumber(long long N)
{
    // Stores the Nth number
    long long result = 0;

    long long p = 1;

    // Iterate while N is
    // greater than 0
    while (N > 0) {

        // Update result
        result += (p * (N % 9));

        // Divide N by 9
        N = N / 9;

        // Multiply p by 10
        p = p * 10;
    }
    // Return result
    return result;
}

// Driver Code
int main()
{
    int N = 9;
    cout << findNthNumber(N);
    return 0;
}
