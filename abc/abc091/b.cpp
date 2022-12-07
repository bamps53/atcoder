#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    map<string, int> mp;
    int n;
    cin >> n;
    rep(i, n)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    int m;
    cin >> m;
    rep(i, m)
    {
        string s;
        cin >> s;
        mp[s]--;
    }

    int ans = 0;
    for (const auto& iter: mp)
    {
        if (ans < iter.second)
        {
            ans = iter.second;
        }
    }
    cout << ans << endl;
    
}

