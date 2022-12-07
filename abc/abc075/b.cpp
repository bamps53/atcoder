#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)

int main()
{
    int h, w;
    string S[1000];

    int dxs[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dys[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    cin >> h >> w;
    rep(i, h){cin >> S[i];}

    rep(i, h)
    {
        rep(j, w)
        {
            if (S[i][j] == '#')
            {
                cout << '#';
            }
            else
            {
                int count = 0;
                rep(k, 8)
                {
                    int pos_x = j + dxs[k];
                    int pos_y = i + dys[k];
                    if ((0 <= pos_x) & (pos_x <= w) & (0 <= pos_y) & (pos_y <= h) & (S[pos_y][pos_x] == '#'))
                    {
                        count += 1;
                    }
                }
                cout << count;
            }
        }
        cout << endl;
    }
}
