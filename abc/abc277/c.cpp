#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;

int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> G;
    int a, b;
    rep(i, n)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> q;
    set<int> s;
    q.push(1);
    s.insert(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto x: G[x])
        {
            if (!s.count(x))
            {
                q.push(x);
                s.insert(x);
            }
        }
    }
    cout << *s.rbegin() << endl;





}

