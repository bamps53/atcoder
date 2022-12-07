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
    int n, k;
    cin >> n >> k;
    v1d v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    rep(i, k)
    {
        ans += v[i];
    }
    cout << ans << endl;


}

