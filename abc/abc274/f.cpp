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

#include <bits/stdc++.h>
using namespace std;

struct frac
{
    int x, y;
    friend bool operator<(const frac &l, const frac &r)
    {
        // l.x/l.y < r.x/r.y
        assert(l.y > 0 && r.y > 0);
        return l.x * r.y < l.y * r.x;
    }
};

int main()
{
    int n, a;
    cin >> n >> a;
    vector<array<int, 3>> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i][0] >> data[i][1] >> data[i][2];

    frac zero = {0, 1};

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // iが左端
        vector<pair<frac, int>> event; //(時刻,-増分)
        for (int j = 0; j < n; j++)
        {
            int x_diff = data[j][1] - data[i][1];
            int v_diff = data[j][2] - data[i][2];
            if (v_diff == 0)
            {
                if (0 <= x_diff && x_diff <= a)
                    event.push_back({zero, -data[j][0]});
            }
            else if (v_diff > 0)
            {
                frac start = {-x_diff, v_diff};
                event.push_back({start, -data[j][0]});
                frac end = {a - x_diff, v_diff};
                event.push_back({end, data[j][0]});
            }
            else
            {
                frac start = {x_diff - a, -v_diff};
                event.push_back({start, -data[j][0]});
                frac end = {x_diff, -v_diff};
                event.push_back({end, data[j][0]});
            }
        }
        sort(event.begin(), event.end());
        int crr = 0;
        for (auto [t, val] : event)
        {
            crr -= val;
            if (!(t < zero))
                ans = max(ans, crr);
        }
    }
    cout << ans << endl;
}
