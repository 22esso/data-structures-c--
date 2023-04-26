#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    string category;
    int numOfPages;
public:
    Book();
    Book(string title, string author, string category, int numOfPages);
    string get_title();
    string get_author();
    string get_category();
    int get_numOfPages();
    void set_title(string);
    void set_author(string);
    void set_category(string);
    void set_numOfPages(int);
    void print();
    bool operator>(Book x);
};

#endif // BOOK_H
