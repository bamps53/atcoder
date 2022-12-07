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
    int w, h, n;
    cin >> w >> h >> n;
    int h1 = 0;
    int h2 = h;
    int w1 = 0;
    int w2 = w;
    int x, y, a;
    rep(i, n)
    {
        cin >> x >> y >> a;
        if (a == 1)
            w1 = max(w1, x);
        else if (a == 2)
            w2 = min(w2, x);
        else if (a == 3)
            h1 = max(h1, y); 
        else if (a == 4)
            h2 = min(h2, y);
    }
    // cout << w2 << w1 << h2 << h1 << endl;
    cout << (max(w2 - w1, 0)) * (max(h2 - h1, 0)) << endl;
}

