class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> list(13);
        list[0] = {"I",1};
        list[1] = {"IV",4};
        list[2] = {"V",5};
        list[3] = {"IX",9};
        list[4] = {"X",10};
        list[5] = {"XL",40};
        list[6] = {"L",50};
        list[7] = {"XC",90};
        list[8] = {"C",100};
        list[9] = {"CD",400};
        list[10] = {"D",500};
        list[11] = {"CM",900};
        list[12] = {"M",1000};

        string ans="";

        reverse(list.begin(),list.end());

        for(auto a: list)
        {
            string symbol = a.first;
            int value = a.second;

            if(num/value != 0)
            {
                int n = num/value;
                for(int i=0;i<n;i++) ans+=symbol;
                num = num%value;
            }
        }
        return ans;
    }
};