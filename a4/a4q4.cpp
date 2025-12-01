// #include <bits/stdc++.h>
// using namespace std;
// void fnr(string s)
// {
//     queue<char> q;
//     int freq[26] = {0};
//     for (int i = 0; i < s.length(); i++)
//     {
//         freq[(s[i]) - 'a']++;
//         q.push(s[i]);
//         while (!q.empty() && freq[q.front() - 'a'] > 1)
//         {
//             q.pop();
//         }
//         if (q.empty())
//         {
//             cout << -1 << " ";
//         }
//         else
//         {
//             cout << q.front() << " ";
//         }
//     }
// }
// int main()
// {
//     string str = "aabc";
//     cout << "output : ";
//     fnr(str);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
void display(queue<char> &q){
  while (!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
}
void q4(string s)
{
    queue<char> q;
    
    for (int i = 0; i < s.length(); i++)
    {
       if(q.empty()){
        q.push(s[i]);
       }
       else if(s[i]==q.front()){
        q.push(-1);
       }
       else {
        q.push(s[i]);
       }
    }
    display(q);
}


int main()
{
    string str = "aabc";
    cout << "output : ";
    q4(str);
    return 0;
}