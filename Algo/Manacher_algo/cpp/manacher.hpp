#include <bits/stdc++.h>

using namespace std;

class manacher
{
	private:
		string s;
		string new_s = "#";
		int n;
	
	public:
		vector<int> lps_table;

		manacher(string s)
		{
			this->s = s;
			for(int i = 0; i < s.size(); i++)
			{
				new_s += s[i];
				new_s += "#";
			}

			n = new_s.size();
			lps_table.resize(n, 0);
		}

		string lps()
		{
			//center: 我們能看到最遠的palidrome的center
			int center = 1;
			//center_right: 我們能看到最遠的index
			int center_right = 2;
			//current lps lenght
			int max_len = 0;
			//current lps center
			int lps_center = 0;

			//i: the index that we update
			for(int i = 1; i < n; i++)
			{
				//initial case1 or case2
				if(i < center_right)
					lps_table[i] = min(lps_table[2*center - i], center_right - i);
				//case3
				else
					lps_table[i] = 0;

				//update lps_table
				while(i - lps_table[i] - 1 >= 0 &&
				      i + lps_table[i] + 1 < n &&
				      new_s[i - lps_table[i] - 1] == new_s[i + lps_table[i] + 1])
					lps_table[i]++;

				//update lps if needed
				if(lps_table[i] > max_len)
				{
					max_len = lps_table[i];
					lps_center = i;
				}

				//update the farest that we can check by paldrome feature
				if(i + lps_table[i] - 1 > center_right)
				{
					center = i;
					center_right = i + lps_table[i] - 1;
				}

			}

			int start = (lps_center - max_len) / 2;

			return s.substr(start, max_len);
		}
};
