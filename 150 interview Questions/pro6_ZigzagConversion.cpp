#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
        unordered_map<int,vector<char> > mp;

        int n= s.size();
        int i=0;
        while(i<n)
        {
            // cout<<"hel"<<endl;
            int j=1;
            while(j<=numRows)
            {
                if(i<n)
               {
                   mp[j].push_back(s[i]);
                   j++;i++;
                }
                else break;
            }
            j = numRows-1;
            while(j>1)
            {
                if(i<n)
                {
                    mp[j].push_back(s[i]);
                    j--;i++;
                }
                else break;
            }
        }
        string ans="";
        for(int i=1;i<=numRows;i++)
        {
            
            for(int j=0;j<mp[i].size();j++)
            {
                cout<<mp[i][j];
                ans+= mp[i][j];
            }
            cout<<endl;
        }
        return ans;
    }

int main()
{
    string s ="PAYPALISHIRING";
    int numRows = 4;
    cout<<convert(s,numRows)<<endl;
    return 0;
}
