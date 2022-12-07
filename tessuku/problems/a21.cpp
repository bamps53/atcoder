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
	 * 左右のブロックがどこまでとり除かれたかをテーブルとし、その最大値をメモる
	 * dpテーブルはN+1 x N+1
	 * 初期値はL=0, R=0(それぞれ何も取り除いていない)でスコアは0
	 * 変な条件分岐をなくすためにもL=0でRを埋めたときとその逆も初期化しとく
	 * ある状態から、左を取り除いた場合と右を取り除いた場合で進めていく
	 * ポイントが入るのは、次に取り除くブロックに書かれている番号が、Lより大きくR未満のとき
	 * ある点は、左のますから一つ右に進む（Right）か、上のますから一つ下に進む（Left）の最大値
	 * 場合わけとしては、
	 * - 
	 * R-L=1となる点での最大値が答え
	 *
	 **/
	int n;
	cin >> n;
	v1d p(n+1);
	v1d a(n+1);
	rep2(i, 1, n+1)
	{
		cin >> p[i] >> a[i];
	}

	auto dp = make_v2d(n+1, n+1, 0);
	dp[0][0] = 0;
	rep2(i, 1, n+1)
	{
		// LEFT
		if (i < p[i])
			dp[i][0] = dp[i-1][0] + a[i];
		else
			dp[i][0] = dp[i-1][0];

		// RIGHT
		int right = n + 1 - i;
		if (right > p[right])
			dp[0][i] = dp[0][i-1] + a[right];
		else
			dp[0][i] = dp[0][i-1];
	}
	debug(dp);

	rep2(i, 1, n+1)
	{
		rep2(j, 1, n+1)
		{
			if (i + j >= n+1)
			{
				continue;
			}

			// どこまで取り除いたか
			int left = i;
			int right = n+1-j;

			int l_value = dp[i-1][j];
			if (i < p[i] && p[i] < right)
				l_value += a[i];
			
			int r_value = dp[i][j-1];
			if (i < p[right] && p[right] < right)
				r_value += a[right];

			dp[i][j] = max(l_value, r_value);
		}
	}
	debug(dp);

	int ans = 0;
	rep(i, n+1)
	{
		rep(j, n+1)
		{
			if (i + j == n)
			{
				ans = max(ans, dp[i][j]);
			}
		}
	}


	cout << ans << '\n';
	// printf("%.20lf\n", ans);
	// cout << fixed;
	// cout << setprecision(3) << c << endl;
}
