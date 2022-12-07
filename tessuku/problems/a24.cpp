#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	/**
	 * 動的計画法
	 * ただしn*a_maxのdpテーブルを作ると間に合わない
	 * それまで処理した集合について保持しておきたいのは、最後の高さと最長増加部分列の長さ
	 * これをL[x]=長さxの最長増加部分列の最後の値の最小値として記録する（それ以外が最適になることはない）
	 * L[x]はどうやって更新する？
	 * a[i+1]がギリギリ乗る箇所をLに対して二分探索し、L[x+1] = min(L[x+1], a[i+1])となる
	 * L.size()が答え？
	 */
	int n;
	cin >> n;
	v1d a(n);
	cin_v(a);

	v1d L;
	for (auto x: a){
		if (L.size() == 0){
			L.push_back(x);
		}
		auto pos = lower_bound(L.begin(), L.end(), x);
		debug(x, *pos, *(pos+1), pos-L.begin());
		if (pos == L.end()){
			L.push_back(x);
		}
		else{
			*pos = min(*pos, x);
		}
		debug(L);
	}
	cout << L.size() << endl;


	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
