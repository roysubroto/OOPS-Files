#include <bits/stdc++.h>
using namespace std;

class B;
class A
{
   int value;
   public:
   void get()
   {
        cin >> value;
   }
   friend void operator>=(A,B);
};
class B
{
   int value;
   public:
   void get()
   {
        cin >> value;
   }
   friend void operator>=(A,B);
};

void operator>=(A a1,B b1)
{
    if(a1.value>b1.value)
    cout << "a1 is greater than b1" << endl;
    else if(a1.value<b1.value)
    cout << "b1 is greater than a1" << endl;
    else
    cout << "Both are equal";
}
int main()
{
    A a1;
    B b1;
    cout << "Enter the value of a1:" << endl;
    a1.get();
    cout << "Enter the value of b1:" << endl;
    b1.get();

    
    a1>=b1;

}