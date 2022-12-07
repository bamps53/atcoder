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
    int a, b, c, x;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;
    int ans = 0;
    rep(i, a+1)
    {
        rep(j, b+1)
        {
            rep(k, c+1)
            {
                if (i*500+j*100+k*50 == x)
                    ans++;
            }
        }
    }
    cout << ans << endl;

}

