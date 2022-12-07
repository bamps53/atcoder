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
    v2d c(3);
    int temp;
    rep(i, 3)
    {
        rep(j, 3)
        {
            cin >> temp;
            c[i].push_back(temp);
        }
    }
    int a0, a1, a2, b0, b1, b2;
    string ans = "No";
    rep(i, 101)
    {
        a0 = i;

        b0 = c[0][0] - a0;
        b1 = c[0][1] - a0;
        b2 = c[0][2] - a0;

        a1 = c[1][0] - b0;
        a2 = c[2][0] - b0;

        if (a1 < 0 || a1 > 100)
            continue;
        if (a2 < 0 || a2 > 100)
            continue;
        if (b0 < 0 || b0 > 100)
            continue;
        if (b1 < 0 || b1 > 100)
            continue;
        if (b2 < 0 || b2 > 100)
            continue;

        if (a1 != (c[1][1] - b1))
        {
            continue;
        }
        if (a1 != (c[1][2] - b2))
        {
            continue;
        }

        if (a2 != (c[2][1] - b1))
        {
            continue;
        }
        if (a2 != (c[2][2] - b2))
        {
            continue;
        }

        ans = "Yes";
    }
    cout << ans << endl;
}

