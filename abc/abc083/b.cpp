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
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    string s;
    int sum;
    rep2(i, 1, n+1)
    {
        sum = 0;
        s = to_string(i);
        
        for(auto ch: s)
        {
            
            sum += ch - '0';
        }
        if ((a <= sum) & (sum <= b))
            ans+=i;
    }
    cout << ans << endl;
}

