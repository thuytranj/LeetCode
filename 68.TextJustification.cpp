#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Runtime 0 ms. Beats 100% of users with C++
// Memory 8.01 MB. Beats 77.73% of users with C++

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> cur;
    string temp;
    int count = 0, start = 0, t = -1;
    for (int i = 0; i < words.size(); i++)
    {
        count += words[i].size();
        if (count > maxWidth - (i - start))
        {
            t = i - 1;
            int space, modSpace;
            if (i - 1 - start != 0)
            {
                space = (maxWidth - count + words[i].size()) / (i - 1 - start);
            }
            else
            {
                space = 0;
            }
            modSpace = maxWidth - space * (i - 1 - start) - count + words[i].size();
            for (int j = start; j < i - 1; j++)
            {
                temp += words[j];
                if (j - start + 1 <= modSpace)
                {
                    for (int k = 0; k <= space; k++)
                    {
                        temp += " ";
                    }
                }
                else
                {
                    for (int k = 0; k < space; k++)
                    {
                        temp += " ";
                    }
                }
            }
            temp += words[i - 1];
            if (temp.size() != maxWidth)
            {
                for (int k = 0; k < space + modSpace; k++)
                {
                    temp += " ";
                }
            }
            cur.push_back(temp);
            temp.clear();
            count = 0;
            start = i;
            i--;
        }
    }
    count = 0;
    if (t != words.size() - 1)
    {
        for (int i = t + 1; i < words.size(); i++)
        {
            temp += words[i];
            if (i != words.size() - 1)
                temp += " ";
            count += words[i].size();
        }
        for (int i = 0; i < maxWidth - count - (words.size() - t - 2); i++)
        {
            temp += " ";
        }
        cur.push_back(temp);
    }
    return cur;
}
void output (vector<string> res){
    for (int i=0;i<res.size();i++){
        cout << res[i] << endl;
    }
}
int main()
{
    vector<string> words{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth = 20;
    vector<string> res=fullJustify(words, maxWidth);
    output(res);
    return 0;
}