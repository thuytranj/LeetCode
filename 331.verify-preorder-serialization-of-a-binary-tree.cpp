#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool isValidSerialization(string preorder)
{
    stringstream ss(preorder);
    string word;
    int slot = 1;
    while (getline(ss, word, ','))
    {
        slot--; // a node use 1 slot
        if (slot<0) //if don't have a slot for node return false
            return 0;
        if (word!="#") //a node create 2 slots
            slot += 2;
    }
    return slot == 0; // for a valid serialization, all slots are used
}

int main()
{
    string s;
    getline(cin, s);
    if (isValidSerialization(s))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}