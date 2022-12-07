#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> mp;

    rep(i, n)
    {
        int x;
        cin >> x;
        mp[x]=1;
    }
    cout << mp.size() << endl;
}

