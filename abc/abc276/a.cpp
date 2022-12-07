#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    string s;
    cin >> s;
    auto n = s.size();
    rep(i, n)
    {
        if (s[n-i-1] == 'a')
        {
            cout << n-i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

