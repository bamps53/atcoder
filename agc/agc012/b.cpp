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
    ll n;
    cin >> n;
    vector<ll> v(3*n);
    
    rep(i, n*3)
        cin >> v[i];
    
    sort(v.rbegin(), v.rend());
    ll ans = 0;

    rep(i, n)
        ans += v[i*2+1];

    cout << ans << endl;


}

