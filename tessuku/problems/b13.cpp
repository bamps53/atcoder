#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;

#ifdef LOCAL
#include "../../debug_print.hpp"
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <typename T>
void chmin(T &a, T b)
{
	a = min(a, b);
}
template <typename T>
void chmax(T &a, T b)
{
	a = max(a, b);
}
template <typename T>
void cin_v(vector<T> &v)
{
	rep(i, v.size()) cin >> v[i];
}
template <typename T>
void cout_v(vector<T> &v)
{
	rep(i, v.size())
	{
		if (i > 0)
			cout << " ";
		cout << v[i];
	}
	cout << "\n";
}

template <typename T>
void sort_all(T v)
{
	sort(v.begin(), v.end());
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n+1, 0);
	rep(i, n)
	{
		ll x;
		cin >> x;
		a[i+1] = a[i] + x;
	}
	debug(a);

	int right = 0;
	ll ans = 0;
	rep2(left, 1, n+1)
	{
		if (right - left < 0)
			right = left;

		while (a[right]-a[left-1]<=k && right < n+1)
		{
			right++;
		}
		ans += right - left;
		debug(left, right, ans, a[left-1], a[right]);
	}
	cout << ans << endl;
}
