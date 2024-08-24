#include "manacher.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s = "babcbabcbaccba";
	manacher m(s);

	string lps = m.lps();

	cout << "The LPS of " << s << " is " << lps << endl;

	return 0;
}
