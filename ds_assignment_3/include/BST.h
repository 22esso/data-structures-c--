#ifndef BST_H
#define BST_H
#include "Book.h"
#include<bits/stdc++.h>
using namespace std;
class BST {

    struct BSTNode{
        Book data;
        BSTNode* left;
        BSTNode* right;
    };

    BSTNode* root;

    BSTNode* makeEmpty(BSTNode* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    BSTNode* insert(Book x, BSTNode* t)
    {
        if(t == NULL)
        {
            t = new BSTNode;
            t->data.set_title(x.get_title());
            t->data.set_author(x.get_author());
            t->data.set_category(x.get_category());
            t->data.set_no_of_pages(x.get_no_of_pages());
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    BSTNode* findMin(BSTNode* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    BSTNode* findMax(BSTNode* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    BSTNode* remove(string title , BSTNode* t) {
        BSTNode* temp;
        if(t == NULL)
            return NULL;
        else if(title < t->data.get_title())
            t->left = remove(title, t->left);
        else if(title > t->data.get_title())
            t->right = remove(title, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data.set_title(temp->data.get_title());
            t->data.set_author(temp->data.get_author());
            t->data.set_category(temp->data.get_category());
            t->data.set_no_of_pages(temp->data.get_no_of_pages());
            t->right = remove(t->data.get_title(), t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(BSTNode* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        t->data.print();
        cout<<endl;
        inorder(t->right);
    }

    void in_reversed_order(BSTNode* t) {
        if(t == NULL)
            return;
        in_reversed_order(t->right);
        t->data.print();
        cout<<endl;
        in_reversed_order(t->left);
    }

    BSTNode* searchTitle(BSTNode* r, string key) {
        if(r == NULL || r->data.get_title() == key)
            return r;

        if(r->data.get_title() < key)
            return searchTitle(r->right,key);

        return searchTitle(r->left,key);
     }

    void searchAuth(BSTNode* r, string key) {
       if(r==NULL){
        return;
       }else if(r->data.get_author()==key){
       r->data.print();
       cout<<"------------------------------------------------------------"<<endl;
       }
       searchAuth(r->left,key);
       searchAuth(r->right,key);
     }
     void searchCat(BSTNode* r, string key){
     if(r==NULL){
        return;
     }else if(r->data.get_category()==key){
     r->data.print();
     cout<<"------------------------------------------------------------"<<endl;
     }
     searchCat(r->left,key);
     searchCat(r->right,key);
     }




public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(Book x) {
        root = insert(x, root);
    }

    void remove(string  title) {
        root = remove(title, root);
    }

    void traverseAsc() {
        inorder(root);
        cout << endl;
    }
    void traverseDesc(){
    in_reversed_order(root);
    cout<<endl;
    }

    void searchTitle(string x) {
    	BSTNode* temp;
        temp = searchTitle(root, x);
        if(temp == NULL){
            cout<<"the title named "<<x<<" isn't found."<<endl;
        }else{
            cout<<"the title named "<<temp->data.get_title()<<" is found."<<endl;
            temp->data.print();

        }

    }
    void searchAuth(string key){
    searchAuth(root,key);
    }
    void searchCat(string key){
    searchCat(root,key);
    }


};
#endif // BST_H
