#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> generateGrayCode(int n)
{
    vector<int> grayCode;
    int numElements = 1 << n; // 2^n elements in the Gray code sequence
    for (int i = 0; i < numElements; ++i)
    {
        grayCode.push_back(i ^ (i >> 1));
    }
    return grayCode;
}

vector<int> circularPermutation(int n, int start)
{
    vector<int> grayCode = generateGrayCode(n);
    vector<int> result;
    int startIndex = 0;

    // Find the index of the start element in the Gray code sequence
    for (int i = 0; i < grayCode.size(); ++i)
    {
        if (grayCode[i] == start)
        {
            startIndex = i;
            break;
        }
    }

    // Generate the circular permutation starting from the found index
    for (int i = 0; i < grayCode.size(); ++i)
    {
        result.push_back(grayCode[(startIndex + i) % grayCode.size()]);
    }

    return result;
}
int main()
{
    int n, start;
    cin >> n >> start;
    vector<int> res = circularPermutation(n, start);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}