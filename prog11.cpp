#include <bits/stdc++.h>
using namespace std;

class Test
{
    int a;
    public:
    void getdata()
    {
        cout << "Enter value : ";
        cin >> a;
    
    }
    void compare(Test t)
    {
        if(a>t.a)
        cout << a << " is greater"<< endl;
        else if(a<t.a)
        cout << t.a << " is greater"<< endl;
        else
        cout << "Both are equal"<< endl;
    }
};
int main()
{
    Test t1,t2;
    t1.getdata();
    t2.getdata();
    t1.compare(t2);
}