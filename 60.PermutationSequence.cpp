#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Runtime 62 ms. Beats 20.16% of users with C++
// Memory 7.32 MB. Beats 49.02% of users with C+

void setting (string &res, int n){
        for (int i=0;i<n;i++){
            res+=to_string (i+1);
        }
    }
    void create (string &res, int n, int &ok){
        int i=n-2;
        while (i>=0 && res[i]>res[i+1]){
            i--;
        }
        if (i<0) ok=0;
        else {
            int j=n-1;
            while (j>i && res[j]<res[i]){
                j--;
            }
            swap (res[i], res[j]);
            int l=i+1, r=n-1;
            while (l<r){
                swap (res[l], res[r]);
                l++;
                r--;
            }
            //reverse (res.begin ()+i+1, res.end());
        }
    }
    string getPermutation(int n, int k) {
        string res;
        setting (res, n);
        int ok=1, count=1;
        while (ok){
            if (count==k) return res;
            create (res, n, ok);
            count++;
        }
        return res;
    }
    
int main (){
    string s;
    int n, k, ok=1, count=1;
    cin >> n >> k;
    cout<<getPermutation (n, k)<<endl;
    return 0;
}