#include <iostream>
using namespace std;

// Runtime 2 ms. Beats 54% of users with C++
// Memory 6.29 MB. Beats 94.74% of users with C++

bool canWinNim(int n)
{
    if (n % 4 == 0)
        return false;
    return true;
}
int main (){
    int n=1;
    if (canWinNim (n))
        cout << "yes\n";
    else cout <<"no\n";
    return 0;
}