#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class A {
public :
    string str="Harley";
    void display() {
        cout << "Class A" << endl;
    }
};

class B : virtual public A {
public:
    void display() {
        cout << "Class B" << endl;
    }
};

class C : virtual public A {
public:
    void display() {
        cout << "Class C" << endl;
    }
};

class D : public B, public C {
public:
     string str1;

     void input()
     {
        cin >> str1;
     }
    void display() {
        cout << "Class D" << endl;
    }
};

int main() {
    D obj;
    
    // obj.A::display();
    // obj.B::display();  
    // obj.C::display();  
    // obj.display();
    
    // C objc;
    // objc.A::display();
    // char a[50];
    // cin.getline(a,50);
   // cout << a; 
   obj.input();
   cout << obj.A::str +" "+ obj.str1;
    return 0;
}
