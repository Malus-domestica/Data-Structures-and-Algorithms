#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int v)
    {
        data = v;
    }
};

class Queue
{
    node *front;
    node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x)
    {
        node *n = new node(x);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        node *temp;
        temp = front;
        front = front->next;
        delete temp;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "No data" << endl;
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.empty() << endl;
    return 0;
}
