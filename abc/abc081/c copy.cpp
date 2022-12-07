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

bool sort_by_second(pair<int, int>& a, pair<int, int>& b)
{
    return a.second < b.second;
}

int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    int x;
    rep(i, n)
    {
        cin >> x;
        mp[x]++;
    }
    vector<pair<int, int>> pv;
    for (auto [k, v]: mp)
    {
        pv.push_back(make_pair(k, v));
    }
    sort(pv.begin(), pv.end(), sort_by_second);
    int ans = 0;
    auto ptr = pv.begin();
    auto size = pv.size();
    while(size > k)
    {
        ans+= (*ptr).second;
        pv.erase(ptr);
        ptr++;
        size--;
    }
    cout << ans << endl;


}

