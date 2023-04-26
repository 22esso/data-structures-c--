#include <iostream>
#include"BST.h"
using namespace std;
void readBooks(string file_name,BST &tree)
{
    ifstream File(file_name);
    string line;
    getline(File,line);
    int no_of_Books;
    no_of_Books=stoi(line);
    for(int i=0; i<no_of_Books; i++)
    {
        getline(File,line);
        string Title=line;
        getline(File,line);
        string Author=line;
        getline(File,line);
        string Category=line;
        getline(File,line);
        int no_of_Pages=stoi(line);
        Book new_book(Title,Author,Category,no_of_Pages);
        tree.insert(new_book);
    }
    cout<<" Books Loading has been done "<<endl;
    File.close();
}
int main()
{
    BST tree;
    readBooks("BOOKS.txt",tree);
    int choice;
    while(true)
    {
        cout<<"1-Display all books sorted by title ascendingly \n2-Display all books sorted by title descendingly .\n3-Remove a book by title "<<endl;
        cout<<"4-Add a new book\n5-Search for a book by title\n6-Display certain author's books "<<endl;
        cout<<"7-Display certain category's books\n8-exit "<<endl;
        cout<<" choose your option ";
        cin>>choice;
        if(choice==1)
        {
            tree.traverseAsc();
        }
        else if(choice==2)
        {
            tree.traverseDesc();
        }
        else if(choice==3)
        {
            cout<<" state the title of the book you want to remove : ";
            string title;
            cin.ignore();
            getline(cin,title);
            tree.remove(title);
        }
        else if(choice==4)
        {
            cin.ignore();
            string line;
            cout<<" insert title of the book to be inserted ";
            getline(cin,line);
            string Title=line;
            cout<<" insert author name of the book to be inserted ";
            getline(cin,line);
            string Author=line;
            cout<<" insert name of the category of the book to be inserted ";
            getline(cin,line);
            string Category=line;
            cout<<" insert number of pages of the book to be inserted ";
            getline(cin,line);
            int no_of_Pages=stoi(line);
            Book new_book(Title,Author,Category,no_of_Pages);
            tree.insert(new_book);
        }
        else if(choice==5)
        {
            cout<<" state the title of the book you want to find : ";
            string title;
            cin.ignore();
            getline(cin,title);
            tree.searchTitle(title);
        }
        else if(choice==6)
        {
            cout<<" state the name of the author you want to display his/her books : ";
            string author;
            cin.ignore();
            getline(cin,author);
            tree.searchAuth(author);
        }
        else if(choice==7)
        {
            cout<<" state the category you want to display its books : ";
            string category;
            cin.ignore();
            getline(cin,category);
            tree.searchCat(category);
        }
        else if(choice==8)
        {
            break;
        }

    }

    return 0;
}
