/**
*    author:  camaro
*    created: 05.06.2022 21:55:55
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    cin >> n;
    if ((n[0] == n[1]) & (n[1] == n[2])){
        cout << "Yes" << "\n";
    }
    else if ((n[1] == n[2]) & (n[2] == n[3])) {
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }

    return 0;
}