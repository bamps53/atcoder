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
    int t, a;
    cin >> t >> a;
    int ans = 0;
    double min_error = 10e5;
    double error;
    int h;
    rep(i, n)
    {
        cin >> h;
        error = abs(a - (t - h * 0.006));
        if (error < min_error)
        {
            min_error = error;
            ans = i;
        }
    }
    cout << ans+1 << endl;

}

