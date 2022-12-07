#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

#define bit(x, i) (((x) >> (i)) & 1)

double x[20], y[20];
double dp[17][1 << 17];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n + m; i++)
        scanf("%lf%lf", x + i, y + i);
    for (int i = 0; i < n + m; i++)
        for (int s = 0; s < 1 << (n + m); s++)
            dp[i][s] = 1e18;
    for (int i = 0; i < n + m; i++)
        dp[i][1 << i] = hypot(x[i], y[i]);
    debug(x);
    debug(y);

    for (int s = 1; s < 1 << (n + m); s++)
    {
        double coef = pow(0.5, __builtin_popcount(s >> n));
        for (int i = 0; i < n + m; i++)
        {
            if (bit(s, i))
            {
                for (int j = 0; j < n + m; j++)
                    if (!bit(s, j))
                    {
                        dp[j][s ^ (1 << j)] = fmin(dp[j][s ^ (1 << j)], dp[i][s] + hypot(x[i] - x[j], y[i] - y[j]) * coef);
                    }
            }
        }
    }

    double ans = 1e18;
    for (int i = 0; i < n + m; i++)
        for (int s = (1 << n) - 1; s < 1 << (n + m); s += 1 << n)
            ans = fmin(ans, dp[i][s] + hypot(x[i], y[i]) * pow(0.5, __builtin_popcount(s >> n)));
    printf("%.10f\n", ans);
}
