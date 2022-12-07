#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    int n, y;
    cin >> n >> y;
    int k;
    rep(i, n+1)
    {
        rep(j, n-i+1)
        {
            k = n - i - j;
            assert(i+j+k == n);
            assert(k >= 0);
            if (i*10000+j*5000+k*1000 == y)
            {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
            
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}

