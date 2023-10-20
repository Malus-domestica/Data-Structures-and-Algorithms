#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
private:
    vector<int> arr;
    unordered_map<int, int> mp;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
        {
            return false;
        }
        else
        {
            arr.push_back(val);
            mp[val] = arr.size() - 1;
            return true;
        }
    }

    bool remove(int val)
    {
        if (mp.find(val)==mp.end())
        {
            return false;
        }
        else
        {
            int last = arr.back();
            arr[mp[val]] = last;
            arr.pop_back();
            mp[last] = mp[val];
            mp.erase(val);
            return true;
        }
    }

    int getRandom()
    {
        return arr[rand()%arr.size()];
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
