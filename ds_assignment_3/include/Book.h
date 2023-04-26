#ifndef BOOK_H
#define BOOK_H
#include <bits/stdc++.h>
using namespace std;
class Book
{
private:
    string title;
    string author;
    string category;
    int no_of_pages;
public:
    Book();
    Book(string title,string author,string category,int no_of_pages);
    void set_title(string title);
    void set_author(string author);
    void set_category(string category);
    void set_no_of_pages(int no_of_pages);
    string get_title();
    string get_author();
    string get_category();
    int get_no_of_pages();
    void print();
    bool operator<(Book &book);
    bool operator>(Book &book);

};

#endif // BOOK_H
