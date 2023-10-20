class Solution {
public:
    // Declare an array to store already computed results
    int dp[105];

    // Define the recursive function to calculate the number of ways to decode a given string
    int numDecode(int index,string &s)
    {
        // If we have reached the end of the string, we have found a valid way to decode the string, so return 1
        if(index==s.size()) return 1;

        // If we have gone past the end of the string, we have not found a valid way to decode the string, so return 0
        if(index>s.size()) return 0;

        // If the current digit is '0', we cannot decode it, so return 0
        if(s[index]=='0') return 0;

        // If the result of this subproblem has already been computed, return the result
        if(dp[index]!=-1) return dp[index];

        int ans=0;

        // If the current digit is '1', we can decode it as a single letter or as part of a two-letter code
        if(s[index]=='1')
            ans+=numDecode(index+1,s)+numDecode(index+2,s);

        // If the current digit is '2' and the next digit is between 0 and 6, inclusive, we can decode it as a single letter or as part of a two-letter code
        else if(s[index]=='2' && index<s.size() &&(s[index+1]>='0' && s[index+1]<='6'))
            ans+=numDecode(index+1,s)+numDecode(index+2,s);

        // If the current digit is not '0', '1' or '2', or if it is '2' but the next digit is not between 0 and 6, inclusive, we can only decode it as a single letter
        else
            ans+=numDecode(index+1,s); 

        // Store the result in the array and return it
        return dp[index]=ans;
    }

    // Define the function that will be called by the user to solve the problem
    int numDecodings(string s) {
        // Initialize the array with -1 to indicate that no subproblems have been computed yet
        memset(dp,-1,sizeof(dp));
        // Call the recursive function with the initial index of 0 and the given string
        return numDecode(0,s);
    }
};