#include <bits/stdc++.h>
using namespace std;

#define debug(arg) print(#arg, arg)

template <typename T> void print(std::string_view name, T arg)
{
  std::cerr << name << ": " << arg << '\n';
}

template <typename T> void print(std::string_view name, std::vector<T> v)
{
  std::cerr << name << ": [ ";
  std::copy(v.cbegin(), v.cend(), std::ostream_iterator<T>(std::cerr, " "));
  std::cerr << "]" << '\n';

}

int main()
{
    int a = 1;
    debug(a);
    double b = 2.0;
    debug(b);
    vector<int> v = {1, 2, 3, 4, 5};
    debug(v);

}