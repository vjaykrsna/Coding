#include <bits/stdc++.h>
using namespace std;

class ueue
{
    stack<int> st;

public:
    void enqueue(int x)
    {
        st.push(x);
    }

    int dequeue()
    {
        if (st.empty())
        {
            cout << "errror" << endl;
            exit(0);
        }
        int temp = st.top();
        st.pop();
        if (st.empty())
        {
            return temp;
        }
        int result = dequeue();
        st.push(temp);
        return result;
    }
};

int main()
{
    ueue q;
    q.enqueue(5);
    q.enqueue(10);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}