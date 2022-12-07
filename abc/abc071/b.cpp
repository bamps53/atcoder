#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;

void print_vec(vector<int> v)
{
    rep(i, v.size())
    {
        if (i > 0)
        {cout << " ";}
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto x: s)
    {
        mp[x]++;
    }
    string ans = "None";
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (mp[ch]==0)
        {
            ans = ch;
            break;
        }
    }
    cout << ans << endl;
}

