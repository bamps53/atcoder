#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    // input
    int n;
    unordered_map<int, unordered_map<int, int>> mp;
    cin >> n;
    rep(i, n)
    {
        int a;
        cin >> a;
        unordered_map<int, int> comment;
        rep(j, a)
        {
            int x, y;
            cin >> x >> y;
            comment[x-1] = y;
        }
        mp[i] = comment;
    }

    // for (const auto& [k, v]:mp)
    // {
    //     for (const auto&[k2, v2]: v)
    //     {
    //         cout << k << " " << k2 << " " << v2 << " " << endl;
    //     }
    // }



    int ans = 0;
    // bit全探索
    rep(bit, 1<<n)
    {
        // 正しい証言と仮定したものが矛盾していないかチェック
        bool valid = true;
        int count = 0;
        rep(j, n)
        {
            // 正しいと仮定した人
            if (bit & 1<<j)
            {
                count +=1;
                // その人の証言を検証
                for(const auto& [k, v]: mp[j])
                {
                    // 証言に矛盾しないかチェック
                    if (v==1 && !(bit & (1 << k)))
                    {
                        valid = false;
                        break;
                    }
                    if (v == 0 && (bit & (1 << k)))
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (valid)
        {ans = max(ans, count);}
    }
    cout << ans << endl;


}

