#include <bits/stdc++.h>
using namespace std;
//Example of composition
class Book;
class Author
{
    string  auth_name;

    public:
    friend class Book;

    // void getauth()
    // {
    //     cout << "Enter author name  " << endl;
    //     cin >> auth_name;
    // }
};

class Book
{

    string book_name;
    int price;
    public:
    Author a;
    void getbook()
    {
        cout << "Enter book name : " ;
        cin >> book_name;
        cout << "Enter author name : ";
        cin >> a.auth_name;
        cout << "Enter book price : ";
        cin >> price;
    }
    void show(Author a)
    {
        cout << "Author :  " << a.auth_name << endl;
        cout << "Book name : " << book_name << endl;
        cout << "Price : " << price << endl; 
    }
};

int main()
{
    Author a;
    Book b;
    //a.getauth();
    b.getbook();
    b.show(a);
}