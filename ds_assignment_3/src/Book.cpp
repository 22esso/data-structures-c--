#include "Book.h"
Book::Book()
{

}

Book::Book(string title,string author,string category,int no_of_pages){
this->title=title;
this->author=author;
this->category=category;
this->no_of_pages=no_of_pages;
}
void Book::set_title(string title){
this->title=title;
}
void Book::set_author(string author){
this->author=author;
}
void Book::set_category(string category){
this->category=category;
}
void Book::set_no_of_pages(int no_of_pages){
this->no_of_pages=no_of_pages;
}
string Book::get_title(){
return title;
}
string Book::get_author(){
return author;
}
string Book::get_category(){
return category;
}
int Book::get_no_of_pages(){
return no_of_pages;
}
void Book::print(){
cout<<" the title of the book is : "<<title<<endl;
cout<<" the name of the author of the book is : "<<author<<endl;
cout<<" the category of the book is : "<<category<<endl;
cout<<" the number of pages of the book is : "<<no_of_pages<<endl;
}
bool Book::operator<(Book &book){
if(this->title<book.title){
    return true;
}else{
return false;
}
}
bool Book::operator>(Book &book){
if(this->title>book.title){
    return true;
}else{
return false;
}
}
