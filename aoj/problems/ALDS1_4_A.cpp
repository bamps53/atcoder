#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)

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
    int n;
    vector<int> s;
    int q;
    vector<int> t;

    cin >> n;
    rep(i, n)
    {
        int x;
        cin >> x;
        s.push_back(x);
    }
    cin >> q;
    rep(i, q)
    {
        int y;
        cin >> y;
        t.push_back(y);
    }

    int ans = 0;
    for(auto& x: t)
    {
        for(auto& y: s)
        {
            if (x == y)
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}

