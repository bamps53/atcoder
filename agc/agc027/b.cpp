#include <bits/stdc++.h>
using namespace std;
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
    int n, x;
    cin >> n >> x;
    v1d v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (auto y: v)
    {
        x -= y;
        if (x >= 0)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    if (x > 0)
        cout << ans - 1 << endl;
    else
        cout << ans << endl;
}

