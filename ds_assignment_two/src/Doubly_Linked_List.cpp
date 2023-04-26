#include "Doubly_Linked_List.h"

Doubly_Linked_List::Doubly_Linked_List()
{
    Head=nullptr;
    Tail=nullptr;
}
void Doubly_Linked_List::Insert(Book &data)
{
    Node *newnode=new Node(data,nullptr,nullptr);
    if(Head==nullptr&&Tail==nullptr)
    {
        Head=newnode;
        Tail=Head;
    }
    else
    {
        Tail->set_next(newnode);
        newnode->set_prev(Tail);
        Tail=newnode;
    }
}
void Doubly_Linked_List::Display_Linked_List()
{
    Node* temp=Head;
    while(temp!=nullptr)
    {
        temp->get_data().print();
        cout<<endl;
        temp=temp->get_next();
    }
}
void Doubly_Linked_List::Remove_by_title(string title)
{
    Node *temp=Head;
    while(temp!=nullptr)
    {
        if(temp->get_data().get_title()==title)
        {
            if(temp==Head)
            {
                Head=Head->get_next();
                delete temp;
                cout<<" the book has been deleted "<<endl;
                return;
            }
            else if(temp==Tail)
            {
                Tail=Tail->get_prev();
                delete temp;
                cout<<" the book has been deleted "<<endl;
                return;
            }
            else
            {
                temp->get_prev()->set_next(temp->get_next());
                temp->get_next()->set_prev(temp->get_prev());
                delete temp;
                cout<<" the book has been deleted "<<endl;
                return;
            }
        }
        else
        {
            temp=temp->get_next();
        }
    }
    cout<<"this title could not be found"<<endl;
    return;



}
void Doubly_Linked_List::Remove_by_author(string author)
{
    Node *temp=Head;
    int number_of_deleted_book=0;
    while(temp!=nullptr)
    {
        if(temp->get_data().get_author()==author)
        {
            number_of_deleted_book++;
            string Title=temp->get_data().get_title();
            cout<<" a book with title named : "<<Title<<" has been deleted "<<endl;
            if(temp==Head)
            {
                Head=Head->get_next();
                delete temp;
                temp=Head;
            }
            else if(temp==Tail)
            {
                Tail=Tail->get_prev();
                delete temp;

            }
            else
            {
                temp->get_prev()->set_next(temp->get_next());
                temp->get_next()->set_prev(temp->get_prev());
                Node *temp_two=temp->get_next();
                delete temp;
                temp=nullptr;
                temp=temp_two;
            }

        }
        else{
        temp=temp->get_next();
        }
    }
    if(number_of_deleted_book==0)
    {
        cout<<" this author name could not be found "<<endl;
    }
    else
    {
        cout<<" number of books that has been deleted is : "<<number_of_deleted_book<<endl;
    }
    return;

}
void Doubly_Linked_List::Display_By_Author(string author)
{
    Node *temp=Head;
    bool found=false;
    while(temp!=nullptr)
    {
        if(temp->get_data().get_author()==author)
        {
            temp->get_data().print();
            cout<<endl;
            found=true;
        }
        temp=temp->get_next();
    }
    if(found==false)
    {
        cout<<" the author name was not found "<<endl;
    }
}
void Doubly_Linked_List::Display_By_Category(string category)
{
    Node *temp=Head;
    bool found=false;
    while(temp!=nullptr)
    {
        if(temp->get_data().get_category()==category)
        {
            temp->get_data().print();
            cout<<endl;
            found=true;
        }
        temp=temp->get_next();
    }
    if(found==false)
    {
        cout<<" this category could be not found "<<endl;
    }
}
void Doubly_Linked_List::Sort()
{
    int Size=0;
    Node *temp=Head;
    while(temp!=nullptr)
    {
        Size++;
        temp=temp->get_next();
    }
    temp=Head;
    Book arr[Size];
    for(int i=0; i<Size; i++)
    {
        arr[i]=temp->get_data();
        temp=temp->get_next();
    }
    for(int i=0; i<Size; i++)
    {
        int min_index=i;
        for(int j=i+1; j<Size; j++)
        {
            if(arr[min_index]>arr[j])
            {
                min_index=j;
            }
        }
        string title;
        string author;
        string category;
        int numOfPages;
        title=arr[min_index].get_title();
        author=arr[min_index].get_author();
        category=arr[min_index].get_category();
        numOfPages=arr[min_index].get_numOfPages();
        arr[min_index].set_title(arr[i].get_title());
        arr[min_index].set_author(arr[i].get_author());
        arr[min_index].set_category(arr[i].get_category());
        arr[min_index].set_numOfPages(arr[i].get_numOfPages());
        arr[i].set_title(title);
        arr[i].set_author(author);
        arr[i].set_category(category);
        arr[i].set_numOfPages(numOfPages);
    }
    while(Head!=nullptr)
    {
        Node* temp_two=Head;
        Head=Head->get_next();
        delete (temp_two);
    }
    Head=nullptr;
    Tail=nullptr;
    for(int i=0; i<Size; i++)
    {
        this->Insert(arr[i]);
    }
}

Doubly_Linked_List::~Doubly_Linked_List()
{
    while(Head!=nullptr)
    {
        Node* temp_two=Head;
        Head=Head->get_next();
        delete temp_two;
    }
    delete Tail;
}
