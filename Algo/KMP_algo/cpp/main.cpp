#include "KMP_algo.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string src = "abcabcabcabe";
	string tar = "abcabe";	

	KMP k;

	bool found = k.search(src, tar);

	if(found)
		cout << tar << " is in " << src << endl;
	else
		cout << tar << " is not in " << src << endl;

	return 0;
}
