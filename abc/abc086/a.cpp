/**
*    author:  camaro
*    created: 05.06.2022 19:31:02
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a*b%2 == 0){
        cout << "Even" << "\n";
    }
    else {
        cout << "Odd" << "\n";
    }
    return 0;
}