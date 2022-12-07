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
    cin >> n;
    int v[n];
    rep(i, n)
    {
        cin >> v[i];
    }
    int ans = 0;
    while(true)
    {
        bool is_ok = true;
        rep(i, n)
        {
            if (v[i] % 2 != 0)
            {
                is_ok = false;
                break;
            }
            else
                v[i] /= 2;
        }
        if (!is_ok)
        {
            break;
        }
        ans++;
    }
    cout << ans << endl;
}

