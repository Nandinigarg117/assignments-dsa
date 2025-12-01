
#include <iostream>
#include <queue>
using namespace std;
class stack_2queue
{
    queue<int> q1, q2;

public:
    void push(int val)
    {
        q1.push(val);
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
        swap(q1, q2);
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q2.push(val);
        q1.pop();
        swap(q1, q2);
        return val;
    }
    bool isempty()
    {
        return q1.empty();
    }
    void display()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        int n = q1.size();
        cout << "Stack elements (bottom to top): ";
        for (int i = 0; i < n; i++)
        {
            int val = q1.front();
            q1.pop();
            cout << val << " ";
            q1.push(val);
        }
        cout << endl;
    }
};
int main()
{
    stack_2queue st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    cout << "Top: " << st.top() << endl;
    st.pop();
    st.display();

    return 0;
}