#include <bits/stdc++.h>
using namespace std;

int factWOMD(int n)
{
    // factorial without using multiplication and division
    int fact = 1, temp;
    for (int i = n; i > 0; i--)
    {
        temp = fact;
        fact = 0;

        for (int j = 0; j < i; j++)
        {
            fact += temp;
        }
    }
    return fact;
}

int factWR(int n)
{
    // Factorial using recursion
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factWR(n - 1);
}

int fact(int n)
{
    // Simple way using loops
    int fact = 1;
    for (int i = n; i > 0; i--)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int n;
    cin >> n;

    cout << factWOMD(n) << endl;
    cout << factWR(n) << endl;
    cout << fact(n) << endl;
}