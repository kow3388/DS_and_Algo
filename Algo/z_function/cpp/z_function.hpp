#include <bits/stdc++.h>

using namespace std;

class z_function
{
    public:
        vector<int> z;
        string s;
        int len;

        z_function(string str)
        {
            s = str;
            len = s.size();
            z.resize(len, 0);
        }

        void cal_z()
        {
            int l = 0, r = 0;
            for(int i = 1; i < len; i++)
            {
                if(i < r)
                    z[i] = min(r - i, z[i - l]);
                
                while(i + z[i] < len && s[z[i]] == s[i + z[i]])
                    z[i]++;
                
                if(i + z[i] > r)
                {
                    l = i;
                    r = i + z[i];
                }
            }
        }

        void show_res()
        {
            cout << "string: ";
            for(char &c : s)
                cout << c << " ";
            
            cout << endl;

            cout << "z_func: ";
            for(int i = 0; i < len; i++)
                cout << z[i] << " ";
            cout << endl;
        }
};