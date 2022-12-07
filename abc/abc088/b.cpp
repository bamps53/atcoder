#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    int n;
    std::vector<int> arr;

    cin >> n;
    rep(i, n)
    {
        int x;
        cin >> x;
        arr.emplace_back(x);
    }
    sort(arr.rbegin(), arr.rend());

    int count = 0;
    int ans = 0;
    for (const auto& x: arr)
    {
        if (count % 2 == 0)
        {
            ans += x;
        }
        else
        {
            ans -= x;
        }
        count++;

    }
    cout << ans << endl;

}

