#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Runtime 15 ms. Beats 74.86% of users with C++
// Memory 19.54 MB. Beats 76.97% of users with C++
int numDistinct(string s, string t)
{
    if (s == t)
        return 1;
    vector<vector<int>> res(t.size() + 1, vector<int>(s.size() + 1, 0));
    for (int i = 0; i <= s.size(); i++)
        res[0][i] = 1;
    for (int i = 1; i <= t.size(); i++)
    {
        for (int j = 1; j <= s.size(); j++)
        {
            if (t[i - 1] == s[j - 1])
                res[i][j] = res[i][j - 1] + res[i - 1][j - 1];
            else
                res[i][j] = res[i][j - 1];
        }
    }
    return res[t.size()][s.size()];
}
int main()
{
    string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo", t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    cout << numDistinct(s, t) << endl;
    return 0;
}