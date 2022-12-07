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
void sort_all(T &v) { sort(v.begin(), v.end()); }

template <typename T>
void reverse_all(T &v) { reverse(v.begin(), v.end()); }

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
	 * とりあえずn^2の解法
	 * h+s*iの配列をソートする
	 * 一番大きい値を前に持ってきて、最大値が改善するか
	 * しなかったら終了
	 */
	int n;
	cin >> n;
	v1d hs(n);
	v1d ss(n);
	rep(i, n)
	{
		cin >> hs[i] >> ss[i];
	}

	v1d order(n);
	iota(order.begin(), order.end(), 0); // 打つ順番

	v1d points(n);
	bool swapped = false;
	int max_pos = 0;
	int max_val = 0;
	while (true)
	{
		swapped = false;
		max_pos = 0;
		max_val = 0;
		rep(i, n)
		{
			points[i] = hs[order[i]] + ss[order[i]] * i;
			if (points[i] > max_val)
			{
				max_pos = i;
				max_val = points[i];
			}
		}
		debug(points);
		debug(max_pos);
		if (max_pos == 0)
		{
			break; //最初が最大値であればどうしようもない
		}

		rep(i, max_pos)
		{
			int left_val = hs[order[i]] + ss[order[i]] * max_pos;
			if (left_val < max_val)
			{
				swap(order[i], order[max_pos]);
				swapped = true;
				break;
			}
		}

		if (!swapped)
		{
			break; //どう入れ替えても改善しなければ終了
		}
		debug(order);
	}
	cout << max_val << endl;

	// cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
