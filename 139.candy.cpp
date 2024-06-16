#include <iostream>
#include <vector>
using namespace std;
void set (vector<int> ratings, vector<int> &cur, int pos) {
    int left=pos-1, right=pos+1;
    cur[pos]=1;
    while (left >= 0 && right < ratings.size())
    {
        if (left==0 || ratings[left-1]>=ratings[left]) {
            if (ratings[left]>ratings[left+1]) cur[left]=cur[left+1]+1;
            else {
                cur[left]=1;
            }
            left--;
        }
        else break;
        if (right==ratings.size()-1 || ratings[right+1]>=ratings[right]) {
            if (ratings[right]==ratings[right-1]) {
                cur[right]=1;
            }
            else 
                cur[right] = cur[right-1]+1;
            right++;
        }
        else break;
    }
    while (left>=0) {
        if (left == 0 || ratings[left - 1] >= ratings[left])
        {
            if (ratings[left] > ratings[left + 1])
                cur[left] = cur[left + 1] + 1;
            else
            {
                cur[left]=1;
            }
            left--;
        }
        else
            break;
    }
    while (right<ratings.size()) {
        if (right == ratings.size() - 1 || ratings[right + 1] >= ratings[right])
        {
            if (ratings[right] == ratings[right - 1])
            {
                cur[right]=1;
            }
            else
                cur[right] = cur[right - 1] + 1;
            right++;
        }
        else
            break;
    }
}
int candy(vector<int> &ratings)
{
    if (ratings.size()==0) return 0;
    if (ratings.size()==1) return 1;

    vector<pair<int, int> > tmp;
    tmp.push_back(make_pair(0, ratings[0]));

    for (int i=1;i<ratings.size();i++) {
        if (ratings[i]!=ratings[i-1]) {
            tmp.push_back(make_pair (i, ratings[i]));
        }
    }
    if (tmp.size()==1)
        return ratings.size();

    vector<int> pos;
    vector<int> cur(ratings.size(), -1);

    if (tmp[0].second<tmp[1].second) {
        cout<<tmp[0].first<<endl;
        set(ratings, cur, tmp[0].first);
    }
    for (int i = 1; i < tmp.size()-1; i++)
    {
        if (tmp[i].second<tmp[i-1].second && tmp[i].second<tmp[i+1].second) {
            cout<<tmp[i].first<<endl;
            set(ratings, cur, tmp[i].first);
        }
    }
    if (tmp[tmp.size()-1].second<tmp[tmp.size()-2].second) {
        cout<<tmp[tmp.size()-1].first<<endl;
        set(ratings, cur, tmp[tmp.size() - 1].first);
    }

    int sum=0;
    for (int i=0;i<cur.size();i++) {
        if (cur[i]!=-1)
            sum += cur[i];
        else {
            sum+=max(cur[i-1], cur[i+1])+1;
        }
    
    }
    for (int i=0;i<cur.size();i++) {
        cout << cur[i] << ' ';
    }
    cout<<endl;
    return sum;
}

int main () {
    int n;
    cin>>n;
    vector<int> ratings(n);
    for (int i = 0; i<n; i++)
    {
        cin >> ratings[i];
    }
    cout<<candy (ratings)<<endl;
    return 0;
}