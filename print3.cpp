#include <bits/stdc++.h>
using namespace std;

#define debug(arg) print(#arg, arg)

template <typename T> void print(std::string_view name, T arg)
{
  std::cerr << name << ": " << arg << '\n';
}

template<template <class...> class Container, class... Ts>
void print(std::string_view name, Container<Ts...> arg)
{
  std::cerr << name << ": [ ";
  std::copy(
    std::cbegin(arg),
    std::cend(arg), 
    std::ostream_iterator<typename Container<Ts...>::value_type>(std::cerr, " "));
  std::cerr << "]" << '\n';
}


int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    debug(v);

    set<int> w = {3, 4, 5};
    debug(w);
}