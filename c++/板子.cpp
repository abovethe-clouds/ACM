#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <bits/stdc++.h>
using boost::multiprecision::cpp_int;

int main()
{
    cpp_int res = 1;
    int base = 114514;

    for (int i = 0; i < 114514; i++)
    {
        res *= base;
    }

    std::cout << res << "\n";
}
