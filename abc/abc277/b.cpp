#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define rep2(i, a, b) for (int i = a; i < (int)(b); i++)
using v1d = vector<int>;
using v2d = vector<vector<int>>;

void print_vec(vector<int> v)
{
    rep(i, v.size())
    {
        if (i > 0)
        {cout << " ";}
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    string s[100]; 
    rep(i, n)
    {
        cin >> s[i];
    }
   
    rep(i, n)
    {
        if (
            (s[i][0] != 'H') & 
            (s[i][0] != 'D') &
            (s[i][0] != 'C') &
            (s[i][0] != 'S')
            )
        {
            cout << "No" << endl;
            return 0;
        }
        if (
            (s[i][1] != 'A') & 
            (s[i][1] != '2') & 
            (s[i][1] != '3') & 
            (s[i][1] != '4') & 
            (s[i][1] != '5') & 
            (s[i][1] != '6') & 
            (s[i][1] != '7') & 
            (s[i][1] != '8') & 
            (s[i][1] != '9') & 
            (s[i][1] != 'T') & 
            (s[i][1] != 'J') & 
            (s[i][1] != 'Q') & 
            (s[i][1] != 'K')
            )
            {
                cout << "No" << endl;
                return 0;
            }
    }
    rep(i, n)
    {
        rep2(j, i+1, n)
        {
            if (s[i] == s[j])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}

