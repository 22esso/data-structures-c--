#include <iostream>
#include <bits/stdc++.h>
#include "Student.h"
using namespace std;
///to write in a file
template<class T>
void write_into_a_file(string name_of_file,T arr[],int Size,int no_of_comps){
ofstream file(name_of_file,ios::trunc);
file<<"Number of comparisons = "<<no_of_comps<<endl;
for(int i=0;i<Size;i++){
    file<<arr[i].get_name()<<endl<<arr[i].get_id()<<endl<<arr[i].get_GPA()<<endl;
}
file.close();
}


///Reading students data from the file given the file name
template <class T>
void Read_From_File(string File_Name,T* &arr,int &Size){
    fstream file(File_Name,ios::in);
    string line;
    getline(file,line);
    Size=stoi(line);
    arr=new T[Size];
    for(int i=0;i<Size;i++){
        string name;
        string id;
        double GPA;
        getline(file,name);
        getline(file,id);
        getline(file,line);
        GPA=stod(line);
        arr[i].set_name(name);
        arr[i].set_id(id);
        arr[i].set_GPA(GPA);

    }
    file.close();
}

///Selection sort
template <class T>
void selection_sort(T arr[],int Size,int &counter_of_selection_comps){
for(int i=0;i<Size;i++){
    T Default_Student=arr[i];
    int index=i;
    for(int j=i+1;j<Size;j++){
        counter_of_selection_comps++;
        if(arr[j]<Default_Student){
            Default_Student=arr[j];
            index=j;

        }
    }
    T temp=arr[index];
    arr[index]=arr[i];
    arr[i]=temp;
}
}
///Shell sort with hibbard's increments
template <class T>
void shell_sort(T arr[],int Size,int &counter_of_shell_comps){
T temp;
int jump;
int val=log(Size+1)/log(2);
for(jump=pow(2,val);jump>0;jump=pow(2,val--))
    for(int i=jump;i<Size;i++){
        for(int j=i-jump;j>=0&&arr[j+jump]<arr[j];j-=jump){
            counter_of_shell_comps++;
            temp=arr[j];
            arr[j]=arr[j+jump];
            arr[j+jump]=temp;
        }
    }
}
template <class T>
int Binary_search(T arr[],int Size,string Name){
int left=0;
int right=Size-1;
while(left<=right){
    int mid=left+((right-left)/2);
    if(arr[mid].get_name()==Name){
        return mid;
    }else if(arr[mid].get_name()>Name){
    right=mid-1;
    }else if(arr[mid].get_name()<Name){
    left=mid+1;
    }

}
return -1;
}

template<class T>
void Merge(T * &arr,int left,int mid,int right,int &Comparisons_count)
{

    int size1=mid-left+1;
    int size2=right-mid;
    ///creating temp arrays for sorting
    T temp_arr1[size1];
    T temp_arr2[size2];
    for(int i=0; i<size1; i++)
    {
        temp_arr1[i]=arr[left+i];
    }
    for(int i=0; i<size1; i++)
    {
        temp_arr1[i]=arr[left+i];
    }
    for(int i=0; i<size2; i++)
    {
        temp_arr2[i]=arr[mid+1+i];
    }
    int cursor1=0,cursor2=0,index=left;
    while(cursor1<size1&&cursor2<size2)
    {
        if(temp_arr1[cursor1]<=temp_arr2[cursor2])
        {
            arr[index]=temp_arr1[cursor1];
            cursor1++;
        }
        else
        {
            arr[index]=temp_arr2[cursor2];
            cursor2++;
        }
        index++;
        Comparisons_count++;
    }
    ///checking if there was any left elements in the first arra
    if(cursor1<size1)
    {
        while(cursor1<size1)
        {
            arr[index]=temp_arr1[cursor1];
            cursor1++;
            index++;
        }
    }
    if(cursor2<size2)
    {
        while(cursor2<size2)
        {
            arr[index]=temp_arr2[cursor2];
            cursor2++;
            index++;
        }
    }


}

///Merge Sort
template <class T>
void Merge_sort(T * &arr,int left,int right,int & Comparisons_count)
{
    if(left < right)
    {
        int mid = left+(right-left)/2;
        ///diving the array into sub-arrays
        Merge_sort(arr,left,mid,Comparisons_count);
        Merge_sort(arr,mid+1,right,Comparisons_count);
        ///Merging the arrays after the final division
        Merge(arr,left,mid,right,Comparisons_count);
    }

}



int main()
{
int Size;
Student*arr1;
Student*arr2;
Student*arr3;

Read_From_File<Student>("Students.txt",arr1,Size);
Read_From_File<Student>("Students.txt",arr2,Size);
Read_From_File<Student>("Students.txt",arr3,Size);

///selection sort
int Selection_sort_count_of_comps=0;
selection_sort<Student>(arr1,Size,Selection_sort_count_of_comps);
write_into_a_file("selection.txt",arr1,Size,Selection_sort_count_of_comps);
///Shell sort
int shell_sort_count_of_comps=0;
shell_sort<Student>(arr2,Size,shell_sort_count_of_comps);
write_into_a_file("shell.txt",arr2,Size,shell_sort_count_of_comps);
///Merge sort
int Merge_sort_count_of_comps=0;
Merge_sort(arr3,0,Size-1,Merge_sort_count_of_comps);
///printing the array
/*

for(int i=0;i<Size;i++){
    arr2[i].print();
}*/

while(true){
    int option;
    cout<<"1-show number of comparisons and sorted array of selection sort"<<endl;
    cout<<"2-show number of comparisons and sorted array of shell sort"<<endl;
    cout<<"3-show number of comparisons and sorted array of merge sort"<<endl;
    cout<<"4-search for a student by name"<<endl;
    cout<<"5-Exit"<<endl;
    cout<<" select your option : ";
    cin>>option;
    if(option==1){
        cout<<"number of comparisons of selection sort = "<<Selection_sort_count_of_comps<<endl;
        for(int i=0;i<Size;i++){
            arr1[i].print();
        }
    }else if(option==2){
    cout<<" number of comparisons of shell sort = "<<shell_sort_count_of_comps<<endl;
    for(int i=0;i<Size;i++){
        arr2[i].print();
    }
    }else if(option==3){
    cout<<" number of comparisons of Merge sort = "<<Merge_sort_count_of_comps<<endl;
    for(int i=0;i<Size;i++){
        arr3[i].print();
    }

    }else if(option==4){
    cin.ignore();
    string name_wanted;
    cout<<" please enter the name wanted : ";
    getline(cin,name_wanted);
    ///binary search
    int index_of_chosen_name=Binary_search<Student>(arr2,Size,name_wanted);
    if( index_of_chosen_name==-1){
        cout<<" this name can not be found"<<endl;
    }else{
    arr2[index_of_chosen_name].print();
    }

    }







}
















return 0;
}
