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
    int n, l;
    cin >> n >> l;
    vector<string> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(auto x: v)
    {
        cout << x;
    }
    cout  << endl;
}

