#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;

int main()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;

    ll total = 0; // 全カードの合計、ここから出した最大の枚数を引いた値が答え
    ll a;
    rep(i, n)
    {
        cin >> a;
        mp[a]++;
        total += a;
    }

    // vectorへ持ち替え
    vector<pair<ll, ll>> v;
    for(auto x: mp)
    {
        v.push_back(x);
    }
    ll k = v.size();

    // vを最初からみていき、切れ目があったところでストップ
    // 連続していないところから開始し、一周すれば答えが見つかる保証がある
    ll start = -1;
    rep2(i, 1, k)
    {
        if (v[i-1].first+1 != v[i].first)
        {
            start = i;
            break;
        }
    }

    // 切れ目がなかったとき
    if (start == -1)
    {
        // 最後から最初へループしているケースをチェック
        if ((v[k-1].first+1)%m != v[0].first)
        {
            start = k;
        }
        else
        {
            // 全部出せる
            cout << 0 << endl;
            return 0;
        }
    }
    if (k == 1)
        {
            // 全部出せる
            cout << 0 << endl;
            return 0;
        }  

    ll v_idx;
    ll last_card = -1000;
    ll sum = 0;
    ll max_sum = 0;
    ll this_card, num_this_card;
    rep(i, 2*k)
    {
        v_idx = (start + i) % k;
        this_card = v[v_idx].first;
        num_this_card = v[v_idx].second;

        // 連続していなければこれまでの合計はリセット
        if ((last_card + 1) % m != this_card)
            sum = 0;

        sum += this_card * num_this_card;
        max_sum = max(max_sum, sum);

        last_card = this_card;
    }
    cout << total - max_sum << endl;
}

