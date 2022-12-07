#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = INT_MAX / 2; 
const ll infl = 1LL << 60;
#define endl '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;
using v1dll = vector<ll>;
using v2dll = vector<vector<ll>>;

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
void sort_all(T& v) { sort(v.begin(), v.end()); }

template <typename T>
void reverse_all(T& v) { reverse(v.begin(), v.end()); }

vector<vector<int>> make_v2d(int d1, int d2, int value)
{
	v2d x(d1, v1d(d2, value));
	return x; 
}

// 素数を判定する関数
ll isprime(ll N) {
    if (N < 2) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return i;
    }
    return N;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	/**
	 * 最大の素数がルートK以上のときはその素数を回答して終わり
	 * それ以下のとき
	 */
	ll k;
	cin >> k;

	ll prime = isprime(k);
	if (prime == k)
	{
		cout << k << endl;
		return 0;
	}

	ll max_prime = prime;
	ll temp_k = k / prime;
	while(temp_k > 1)
	{
		ll prime = isprime(temp_k);
		chmax(max_prime, prime);
		temp_k /= prime;
	}
	debug(max_prime);

	if (max_prime >= 1e6)
	{
		cout << max_prime << endl;
		return 0;
	}
	else
	{
		int num = 2;
		while(true)
		{
			auto gcd_k = gcd(k, num);
			k /= gcd_k;
			// debug(k);
			if (k == 1)
			{
				cout << num << endl;
				return 0;
			}
			num++;
		}
	}





	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
