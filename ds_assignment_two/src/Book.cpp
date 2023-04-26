#include "Book.h"

Book::Book()
{
    title="";
    author="";
    category="";
    numOfPages=0;
}
Book::Book(string title, string author, string category, int numOfPages)
{
    this->title=title;
    this->author=author;
    this->category=category;
    this->numOfPages=numOfPages;
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
int Book::get_numOfPages(){
return numOfPages;
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
void Book::set_numOfPages(int x){
this->numOfPages=x;
}
void Book::print(){
cout<<" the title of the book is : "<<title<<endl;
cout<<" the name of the author is : "<<author<<endl;
cout<<" the category of the book is : "<<category<<endl;
cout<<" the number of pages of the book is : "<<numOfPages<<endl;
cout<<"------------------------------------------------------------------"<<endl;
}
bool Book::operator>(Book x){
if(this->numOfPages>x.get_numOfPages()){
    return true;
}else{
return false;
}
}

