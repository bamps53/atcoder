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
    ll sn = sqrt(n)+100;
    ll min_f = 10e5;
    ll f;
    rep2(i, 1, sn+1)
    {
        if (n % i != 0)
            continue;
        f = max(to_string(i).size(), to_string(n/i).size());
        
        min_f = min(min_f, f);
    }
    cout << min_f << endl;

}

