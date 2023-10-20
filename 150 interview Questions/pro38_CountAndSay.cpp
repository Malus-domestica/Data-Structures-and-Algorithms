#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        string ans="11";
        for(int i=3;i<=n;i++){
            int cnt=1;
            ans = ans+'&';//delimeter is needed so that we can store last checked value
            string t="";
            for(int j=1;j<ans.size();j++){
                if(ans[j] != ans[j-1]){
                    t = t+to_string(cnt)+ans[j-1];
                    cnt=1;
                }
                else cnt++;
            }
            ans=t;
        }
        // ans = ans.substr(0,ans.size()); since the last value is of t which does not contain delimeter
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
