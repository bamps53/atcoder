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
    vector<int> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }

    int ans = 0;
    rep(i, n)
    {
        rep2(j, i+1, n)
        {
            rep2(k, j+1, n)
            {
                if ((v[i] != v[j]) & v[j] != v[k] & v[k] != v[i])
                {
                    if (v[i] + v[j] > v[k] & v[i] < v[j] + v[k] & v[i] + v[k] > v[j])
                    {
                        ans++;

                    }
                }
            }
        }
    }
    cout << ans << endl;
}

