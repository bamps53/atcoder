#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)

int main()
{
    const int max_n = 200005;
    int n, m;
    cin >> n >> m;
    vector<int>v[max_n];
    
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    rep2(i, 1, n+1)
    {
        sort(v[i].begin(),v[i].end());
        cout << v[i].size();
        for(const auto& x: v[i])
        {
            cout << " " << x;
        }
        cout << endl;
    }

}
