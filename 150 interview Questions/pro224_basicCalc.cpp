class Solution {
public:
    int calculate(string s) {
        int pos=0;
        return evaluate(s,pos);
    }
    
    int evaluate(string& s, int& i) {
        int res = 0;
        bool negFlag=false;
        while(i<s.size()&&s[i]!=')') {
            if(s[i]=='+'||s[i]==' ') 
                i++;
            else if(s[i]=='-') {
                i++;
                negFlag=true;
            }
            else if(s[i]=='(') {
                i++;
                res+=negFlag?-evaluate(s,i):evaluate(s,i);
                negFlag=false;
            }
            else {// numeric chars
                int num=0;
                while(i<s.size()&&isdigit(s[i]))
                    num = num*10 + s[i++]-'0';
                res+=negFlag?-num:num;
                negFlag=false;
            }
        }
        i++; // skip the current ')'
        return res;
    }
};