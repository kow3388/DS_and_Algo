#include <bits/stdc++.h>
#include "z_function.hpp"

using namespace std;

int main()
{
    string s = "aabcaabxaaaz";
    z_function z(s);

    z.cal_z();
    z.show_res();

    return 0;
}