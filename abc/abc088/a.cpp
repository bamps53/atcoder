/**
*    author:  camaro
*    created: 05.06.2022 19:14:46
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, res;
    cin >> n >> a;
    res = n % 500;
    if (res <= a){
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }

    return 0;
}