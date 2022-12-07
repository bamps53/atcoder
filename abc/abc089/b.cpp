#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main()
{
    int n;
    cin >> n;
    string ans = "Three"; 
    rep(i, n)
    {
        char s;

        cin >> s;
        if (s == 'Y')
        {
            ans = "Four";
            break;
        }
    }
    cout << ans << endl;

}

