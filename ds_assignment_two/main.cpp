#include <iostream>
#include "include\Book.h"
#include "include\Doubly_Linked_List.h"
#include <bits/stdc++.h>
using namespace std;
/*
int from_string_to_integer(string Line){
int num=0;
for(int i=0;i<Line.size();i++){
    num+=(Line[i]-'0')*pow(10,(Line.size()-i-1));
}
return num;
}*/




void Read_From_File(string File_name,Doubly_Linked_List &Dll){
ifstream File(File_name);
string Line;
getline(File,Line);
int no_of_Books=stoi(Line);
for(int i=0;i<no_of_Books;i++){
    getline(File,Line);
    string title_of_book=Line;
    getline(File,Line);
    string author_name=Line;
    getline(File,Line);
    string category_of_book=Line;
    getline(File,Line);
    int no_of_pages_of_the_Book=stoi(Line);
    Book newbook(title_of_book,author_name,category_of_book,no_of_pages_of_the_Book);
    Dll.Insert(newbook);
}
File.close();
}




int main()
{
 ///creating doubly linked list
 Doubly_Linked_List Dll;
 ///reading from the file
 Read_From_File("Books.txt",Dll);
 ///creating and adding an extra book
 Book extra_book("Outliers", "Malcolm Gladwell", "Self Help", 309);
 Dll.Insert(extra_book);
 ///displaying the linked list
 Dll.Display_Linked_List();
 ///sorting the linked list by the number of pages
 Dll.Sort();
 cout<<endl;
 cout<<"---------------------------The sorted Linked list ----------------------------- "<<endl;
 cout<<endl;
 Dll.Display_Linked_List();
 cout<<"---------------------------The Novels Category of Linked list ----------------------------- "<<endl;
 Dll.Display_By_Category("Novels");
 cout<<endl;
 cout<<"--------------------------Linked list after deleting books by  the author Paulo Koelho --------------"<<endl;
 Dll.Remove_by_author("Paulo Koelho”");
 cout<<endl;
 cout<<"--------------------------Linked list after deleting books by  the author Paulo Coelho --------------"<<endl;
 Dll.Remove_by_author("Paulo Coelho");
 cout<<endl;
 cout<<"---------------------------The Novels Category of Linked list ----------------------------- "<<endl;
 Dll.Display_By_Category("Novels");
 cout<<endl;
 cout<<"-------------------------- Deleting Pecoming ----------------------------- "<<endl;
 Dll.Remove_by_title("Pecoming");
 cout<<endl;
 cout<<"-------------------------- Deleting Becoming ----------------------------- "<<endl;
 Dll.Remove_by_title("Becoming");
 cout<<endl;
 cout<<"-------------------------- Books of Michelle Obama ----------------------------- "<<endl;
 Dll.Display_By_Author("Michelle Obama");
 cout<<endl;
 cout<<"-------------------------- the linked list after the adjustments ----------------------------- "<<endl;
 Dll.Display_Linked_List();
 cout<<endl;







    return 0;
}
