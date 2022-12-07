#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;

using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;

    ll total = 0;
    ll a;
    rep(i, n)
    {
        cin >> a;
        mp[a]++;
        total += a;
    }

    vector<ll> score(m, 0);
    ll last = -1000;
    rep(i, 2*m+1)
    {
        if ((last - i == 1) && (mp[i] > 0))
        {
            score[last] += i*mp[i];
            last = i;
        }
        else if (mp[i] > 0)
        {
            score[i] = mp[i];
            last = -1000;
        }
        else
        {
            last = -1000;
        }
    }
    ll ans = 10e10;
    for(auto x: score)
    {
        ans = min(ans, total - x);
    }
    cout << ans << endl;



}

