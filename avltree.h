#ifndef AVLTREE_H
#define AVLTREE_H
#include"node.h"
#include<iostream>

using namespace std;
class AVLTree
{
public:
    AVLTree();
    /*Variables*/
    Node *root;
    int left_height;
    int right_height;
    /*Functions*/
    int Insert(Node *new_value,Node **sub_root);
    int Add(int value);
    int FindValue(int value);
    int Find(Node *sub_root, int value);
    /*Switch Side*/
    void SwitchRight(Node **sub_root);
    void SwitchLeft(Node **sub_root);
    void DoubleSwitchRight(Node **sub_root);
    void DoubleSwitchLeft(Node **sub_root);
    void Balance(Node **sub_root);
    void UpdateHeight(Node **sub_root);
    /*Arimethic*/
    int Diference(int value1,int value2);
    int Greater(int value1, int value2);
    /*Print*/
    void Print();
    void Print(Node **sub_root);
    
};

#endif // AVLTREE_H
