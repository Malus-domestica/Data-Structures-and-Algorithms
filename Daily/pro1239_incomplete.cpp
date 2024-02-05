class Solution {
public:
int funct(vector<string> &new_arr, int i, string &str, unordered_map<char,int> &mp)
{
    if(i >= new_arr.size()) return 0;
    //not take
    int len = funct(new_arr,i+1,str,mp);
    //take
    bool check = true;
    for(int j=0;j<new_arr[i].size();j++)
    {
        if(mp[new_arr[i][j]] != 0)
        {
            check =false;
            break;
        }
    }
    if(check)
    {
        //update word map
        for(int j=0;j<new_arr[i].size();j++)
        {
            mp[new_arr[i][j]]++;
            str += new_arr[i][j];//updating string
        }
        int take = new_arr[i].size() + funct(new_arr, i+1, str, mp);
        len = max( len, take );
    }
    return len;
}
    int maxLength(vector<string>& arr) {
        vector<string> new_arr;
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        {
            string temp = sort(arr[i].begin(),arr[i].end());//sort string
            //gen map to accumulate strring with only unique chars
            unordered_map<char, int> mp;
            bool check = true;
            for(int j=0;j<arr[i].size();j++)
            {
                if(mp[arr[i][j]] != 0)
                {
                    check = false;
                    break;
                }
            }
            
            if(check) new_arr.push_back(arr[i]);//push back only elements with unique chars
        }
string str="";
unordered_map<char,int> mp;
        int ans = funct(new_arr,0,str, mp);
        return ans;
    }
};