#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);
}
int count(int n)
{
    if (n>1) return factorial(10) / factorial(10 - n) - factorial(9) / factorial(10 - n);
    return 10;
}
int countNumbersWithUniqueDigits(int n)
{
    if (n==0) return 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = count(i);
        cout << t << endl;
        sum += t;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << countNumbersWithUniqueDigits(n) << endl;
    return 0;
}