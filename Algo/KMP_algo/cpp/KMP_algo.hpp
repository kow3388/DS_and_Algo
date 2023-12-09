#include <bits/stdc++.h>

using namespace std;

class KMP
{
	public:
		bool search(string s, string t)
		{
			int n = s.length();
			int m = t.length();

			vector<int> lps = LPS(t, m);

			//index for s and t
			int i = 0, j = 0;
			while((n-i) >= (m-j))
			{
				if(s[i] == t[j])
				{
					i++;
					j++;
				}


				if(j == m)
					return true;

				else if(i < n && s[i] != t[j])
				{
					if(j != 0)
					{
						j = lps[j-1];
						cout << "target string index start from " << j << endl;
					}
					else
						i++;
				}
			}
			
			return true;
		}

		//logest prefix suffix
		vector<int> LPS(string t, int m)
		{
			vector<int> lps(m, 0);
			//length of the previous lps
			int len = 0;
			int i = 1;

			while(i < m)
			{
				if(t[i] == t[len])
				{
					len++;
					lps[i] = len;
					i++;
				}
				else
				{
					if(len != 0)
						len = lps[len-1];
					else
					{
						lps[i] = 0;
						i++;
					}
				}
			}

			return lps;
		}
};
