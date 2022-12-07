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
    int ans = 1;
    if (n == 1)
        {cout << 1 << endl;
        return 0;}
    while(true)
    {
        if (ans * 2 > n)
            break;
        ans *= 2;   
    }
    cout << ans << endl;
    return 0;
}

