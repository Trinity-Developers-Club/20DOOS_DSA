#include<bits/stdc++.h>
using namespace std;

class Book{
    public:
        string name;
        int price;
        Book(){

        }
        Book(string name, int price){
            this->name = name;
            this->price = price;
        }
};

class Bookcompare{
    public:
        bool operator ()(Book A, Book B){
            if(A.name == B.name){
                return true;
            }
            return false;
        }
};

//Template + Iterator + Comparator
template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T Key, Compare cmp){
    while(start != end){
        if(cmp(*start, Key)){
            return start;
        }
        start++;
    }
    return end;
}
int main(){
    Book b1("C++", 100);        //Old Books
    Book b2("Java", 120);       
    Book b3("Python", 130);

    //list<Book> l;
    vector<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book booktofind("C++", 120);    //new book
    //Book booktofind("C", 120); 
    Bookcompare cmp;
    
    //list<book>::iterator it = search(l.begin(), l.end(), booktofind, cmp);
    auto it = search(l.begin(), l.end(), booktofind, cmp);

    if(it != l.end()){
        cout<<"Book found in the library!\n";
    }
    else
        cout<<"Book not found";
    /*
    if (cmp(b1, booktofind)){
        cout<<"True same books\n";
    }
    */
    return 0;
}