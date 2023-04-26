#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include "Book.h"
class Node{
private:
Book data;
Node *next;
Node *prev;
public:
Node(){
next=nullptr;
prev=nullptr;
}
Node(Book &data,Node *next,Node *prev){
this->data.set_title(data.get_title());
this->data.set_author(data.get_author());
this->data.set_category(data.get_category());
this->data.set_numOfPages(data.get_numOfPages());
this->next=next;
this->prev=prev;
}
Book get_data(){
return data;
}
Node* get_next(){
return next;
}
Node* get_prev(){
return prev;
}

void set_data(Book data){
this->data.set_title(data.get_title());
this->data.set_author(data.get_author());
this->data.set_category(data.get_category());
this->data.set_numOfPages(data.get_numOfPages());
}
void set_next(Node *next){
this->next=next;
}
void set_prev(Node *prev){
this->prev=prev;
}

};

class Doubly_Linked_List
{
   private:
       Node *Head;
       Node *Tail;

    public:
        Doubly_Linked_List();
        void Insert(Book &data);
        void Display_Linked_List();
        void Remove_by_title(string title);
        void Remove_by_author(string author);
        void Display_By_Author(string author);
        void Display_By_Category(string category);
        void Sort();












        ~Doubly_Linked_List();




};
#endif // DOUBLY_LINKED_LIST_H
