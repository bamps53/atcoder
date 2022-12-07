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
    ll n;
    cin >> n;
    seen.assign(2*(n+1), false);
    v2d G(2*(n+1));
    unordered_map<ll, ll> count;
    unordered_map<ll, ll> mp;
    ll a, b;
    ll idx= 0;
    rep(i, n)
    {
        cin >> a >> b;
        if (count[a] == 0)
        {
            count[a]++;
            mp[a] = idx;
            idx++;
        }
        if (count[b] == 0)
        {
            count[b]++;
            mp[b] = idx;
            idx++;
        }
        G[mp[a]].push_back(mp[b]);
        G[mp[b]].push_back(mp[a]);
    }

    if (count[1] > 0)
        dfs(G, mp[1]);
    else
    {
        cout << 1 << endl;
        return 0;
    }

    unordered_map<ll, ll> mp2;
    for (const auto [k, v]: mp)
    {
        mp2[v] = k;
    }
    
    ll ans = 1;
    rep(i, 2*(n+1))
    {
        if (seen[i])
        {
            ans = max(ans, mp2[i]);
        }
    }
    cout << ans << endl;

}

