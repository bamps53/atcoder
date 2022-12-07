/**
 *    author:  camaro
 *    created: 05.06.2022 19:01:50
 **/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == '1')
        {
            ans++;
        };
    };
    cout << ans << "\n";
    return 0;
}