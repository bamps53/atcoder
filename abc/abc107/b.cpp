#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)


int main()
{
    vector<vector<char>> mat;
    int h, w;
    cin >> h >> w;
    rep(i, h)
    {
        string s;
        cin >> s;
        bool has_black = false;
        rep(j, w)
        {
            if (s[j] == '#')
            {
                has_black = true;
            }
        }
        if (has_black)
        {
            vector<char> vec;
            for (auto c: s)
            {
                vec.emplace_back(c);
            }
            mat.emplace_back(vec);
        }
    }

    vector<bool> valid;
    rep(j, w)
    {
        bool has_black = false;
        rep(i, mat.size())
        {
            if (mat[i][j] == '#')
            {
                has_black = true;
            }
        }
        valid.emplace_back(has_black);
    }

    rep(i, mat.size())
    {
        rep(j, valid.size())
        {
            if (valid[j])
            {
                cout << mat[i][j];
            }
        }
        cout << endl;
    }
}

