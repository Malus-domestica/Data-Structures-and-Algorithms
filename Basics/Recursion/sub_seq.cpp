#include <bits/stdc++.h>
using namespace std;

void print_subSeq(int n, vector<int> &arr, int i, vector<int> temp)
{
    if (i >= n)
    {
        if (temp.size() == 0)
            cout << "{}" << endl;
        else
            for (int i = 0; i < temp.size(); i++)
                cout << temp[i] << "  ";
        cout << endl;
    }
    else
    {
        temp.push_back(arr[i]);
        print_subSeq(n, arr, i + 1, temp);
        temp.pop_back();
        print_subSeq(n, arr, i + 1, temp);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4,0,1,3,2};
    int n = 3;
    vector<int> temp = {};
    print_subSeq(n, arr, 0, temp);
    return 0;
}
