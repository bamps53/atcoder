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

double dist(vector<int>& a, vector<int>& b)
{
    double sum = 0;
    rep(i, a.size())
    {
        sum += pow((a[i] - b[i]), 2);
    }
    return sqrt(sum);
}
int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> v(n);
    int temp;
    rep(i, n)
    {
        rep(j, d)
        {
            cin >> temp;
            v[i].push_back(temp);
        }
    }
    int ans = 0;
    rep(i, n)
    {
        rep2(j, i+1, n)
        {
            double d = dist(v[i], v[j]);
            if (floor(d) == d)
                ans++;
        }
    }
    cout << ans << endl;
}

