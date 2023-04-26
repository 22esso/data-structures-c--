#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student
{
    public:

        Student(string name="",string id="",double GPA=0.0){
        this->name=name;
        this->id=id;
        this->GPA=GPA;
        }
        void set_name(string name){
        this->name=name;
        }
        void set_id(string id){
        this->id=id;
        }
        void set_GPA(double GPA){
        this->GPA=GPA;
        }
        string get_name(){
        return name;
        }
        string get_id(){
        return id;
        }
        double get_GPA(){
        return GPA;
        }
        void print(){
        cout<<name<<" "<<id<<" "<<GPA<<endl;
        }
        friend bool operator<(const Student & x,const Student &y);
        friend bool operator<=(const Student& X,const Student &Y);
    private:
        string name;
        string id;
        double GPA;

};

bool operator<(const Student & x,const Student &y){
if(x.name<y.name){
    return true;
}else{
return false;
}

}
bool operator<=(const Student& X,const Student &Y){
if(X.name<=Y.name){
    return true;
}else{
return false;
}
}

#endif // STUDENT_H
