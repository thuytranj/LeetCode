#include <iostream>
#include <cmath>
using namespace std;

// Runtime 0 ms. Beats 100% of users with C++
// Memory 8.2 MB. Beats 18.52% of users with C+

double myPow(double x, int n) {
    if (n==0) return 1.0;
    double temp=myPow (x, abs (n)/2);
    if (abs(n)%2==0){
        if (n>0) return temp*temp;
        else
            return 1.0 / (temp * temp);
    }
    else {
        if (n>0) return x*temp*temp;
        else return 1.0/(x*temp*temp);
    }
}
int main() {
    int n = -2;
    double x = 2;
    cout<<myPow (x, n)<<endl;
    cout<<pow (x, n)<<endl;
    return 0;
}