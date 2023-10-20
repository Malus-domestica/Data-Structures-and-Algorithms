//14.2 write a program to check is a given number is power of 2
#include<bits/stdc++.h>
using namespace std;

bool ispowOfTwo(int num){
    return (num && !(num & num-1));
}

int main(int argc, char const *argv[])
{
    cout<<ispowOfTwo(14)<<endl;
    return 0;
}
