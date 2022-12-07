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
    int n, k;
    cin >> n >> k;
    v1d v(n, 0);
    int temp;
    rep(i, n)
    {
        cin >> temp;
        v[temp-1]++;
    } 
    // print_vec(v);
    sort(v.begin(), v.end());
    int num=0;
    for(auto x: v)
    {
        if (x > 0)
        {
            num++;
        }
    }
    // cout << "num:" << num << endl;
    int ans = 0;
    int pos = 0;
    while(num > k)
    {
        if (v[pos] > 0)
        {
            ans+=v[pos];
            num--;
        }
        pos++;
    }
    cout << ans << endl;

}

