#include <iostream>
#include <stack>
using namespace std;

void revString(string s)
{
    stack<string> st;

    int i = 0;
    string word = "";
    while (i <= s.length())
    {
        if (i == s.length() || s[i] == ' ')
        {
            st.push(word);
            word = "";
        }
        else
            word += s[i];
        // cout << s[i] << " ";
        i++;
    }
    cout << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    revString("Hey, how you are doing?");
    return 0;
}
