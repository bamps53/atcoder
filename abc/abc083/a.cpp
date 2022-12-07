/**
*    author:  camaro
*    created: 05.06.2022 21:50:48
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b , c, d;
    cin >> a >> b >>  c >> d;
    if (a + b > c + d) {
        cout << "Left" << "\n";
    }
    else if (a + b == c + d) {
        cout << "Balanced" << "\n";
    }
    else {
        cout << "Right" << "\n";
    }
    return 0;
}