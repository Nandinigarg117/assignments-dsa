
#include <iostream>
#include <queue>
using namespace std;
class stack_1queue
{
    queue<int> q;

public:
    void push(int val)
    {
        int s = q.size();
        if (q.empty())
        {
            q.push(val);
        }
        else
        {
            q.push(val);
            for (int i = 0; i < s; i++)
            {
                q.push(q.front());
                q.pop();
            }
        }
    }
    void pop()
    {
        if (q.empty())
        {
            cout << "stack is empty " << endl;
            return;
        }
        else
        {
            cout << q.front() << " popped" << endl;
            q.pop();
        }
    }
    int top()
    {
        return q.front();
    }
    bool isempty()
    {
        return q.empty();
    }
    void display()
    {
        cout<<"Top to bottom "<<endl;
        for (int i = 0; i < q.size(); i++)
        {
            cout<<q.front()<<" ";
            q.push(q.front());
            q.pop();
        }
        cout<<endl;
    }
};
int main()
{
    stack_1queue st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.display();
    cout << "Top: " << st.top() << endl;
    st.pop();
    st.display();

    return 0;
}