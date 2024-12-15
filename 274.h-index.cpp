#include <iostream>
#include <vector>
#include <map>
using namespace std;
int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end(), greater<int> ());
    for (int i=citations.size()-1; i>=0; --i) {
        if (citations[i]>=i+1)
            return min(i + 1, citations[i]);
    }
    return 0;
}
int main()
{
    vector<int> citations = {0, 1, 3, 5, 6};
    cout << hIndex(citations) << endl; // Output: 3
    return 0;
}