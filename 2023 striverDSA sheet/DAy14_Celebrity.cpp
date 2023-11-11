#include <bits/stdc++.h>
using namespace std;

// Max # of persons in the party
#define N 8

// Person with 2 is celebrity
bool MATRIX[N][N] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0},
                     {0, 0, 1, 0}};

bool knows(int a, int b) { return MATRIX[a][b]; }

int findCelebrity(int n)
{
    // Write your code here.
    stack<int> s;

    // Celebrity
    int C;

    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top 2

    // Find a potential celebrity
    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B))
        {
            s.push(B);
        }
        else
        {
            s.push(A);
        }
    }
    // Potential candidate?
    C = s.top();
    s.pop();

    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ((i != C) && (knows(C, i) || !knows(i, C)))
            return -1;
    }

    return C;
}