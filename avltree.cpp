#include "avltree.h"

AVLTree::AVLTree()
{
    this->root = nullptr;
    this->left_height = 0;
    this->right_height = 0;
}
/*Insert Element*/
int AVLTree::Insert(Node *new_value, Node **sub_root)
{
    if(*sub_root == nullptr)
    {
        return -1;
    }
    if((*sub_root)->valor == new_value->valor)
    {
        return -1;
    }
    if((*sub_root)->valor > new_value->valor)
    {
        (*sub_root)->left_height = Insert(new_value,&((*sub_root)->left_son)) + 1;
        Balance(sub_root);
        return (*sub_root)->left_height;
    }
    else if((*sub_root)->valor < new_value->valor)
    {
        (*sub_root)->right_height = Insert(new_value,&((*sub_root)->right_son)) +1;
        Balance(sub_root);
        return (*sub_root)->right_height;
    }
    else
    {
        return -1;
    }
}
/*Add Element*/
int AVLTree::Add(int value)
{
    Node *new_value = new Node();
    new_value->valor = value;
    Insert(new_value,&root);
    return 0;
}
/*Find Value*/
int AVLTree::FindValue(int value)
{
    return Find(root , value);
}
/*Find*/
int AVLTree::Find(Node *sub_root, int value)
{
    if(sub_root == nullptr)
    {
        return -1;
    }
    if((sub_root)->valor == value)
    {
        return -1;
    }

    if(sub_root->valor > value)
    {
        return Find(sub_root->left_son , value);
    }
    else
    {
        return Find(sub_root->right_son , value);
    }
}
/*Balance*/
void AVLTree::Balance(Node **sub_root)
{
    if(Diference((*sub_root)->right_height,(*sub_root)->left_height) < 2)
    {
        return;
    }
    if((*sub_root)->right_height > (*sub_root)->left_height)
    {
        if((*sub_root)->right_son->right_height > (*sub_root)->right_son->left_height)
        {
            SwitchRight(sub_root);
        }
        else
        {
            DoubleSwitchRight(sub_root);
        }
    }
    else
    {
        if((*sub_root)->left_son->right_height > (*sub_root)->left_son->left_height)
        {
            SwitchLeft(sub_root);
        }
        else
        {
            DoubleSwitchLeft(sub_root);
        }
    }
}
/*Switch Right*/
void AVLTree::SwitchRight(Node **sub_root)
{
    Node *new_right_son = (*sub_root)->right_son;
    (*sub_root)->right_son = new_right_son->left_son;
    new_right_son->left_son = (*sub_root);
    *sub_root = new_right_son;
    UpdateHeight(sub_root);
}
/*Switch Left*/
void AVLTree::SwitchLeft(Node **sub_root)
{
    Node *new_left_son = (*sub_root)->left_son;
    (*sub_root)->left_son = new_left_son->right_son;
    new_left_son->right_son = (*sub_root);
    *sub_root = new_left_son;
    UpdateHeight(sub_root);
}
/*Double Switch Left*/
void AVLTree::DoubleSwitchLeft(Node **sub_root)
{
    SwitchRight(&(*sub_root)->left_son);
    SwitchLeft(sub_root);
}
/*Double Switch Right*/
void AVLTree::DoubleSwitchRight(Node **sub_root)
{
    SwitchLeft(&(*sub_root)->right_son);
    SwitchRight(sub_root);
}
/*Update height*/
void AVLTree::UpdateHeight(Node **sub_root)
{
    Node *new_right_son = (*sub_root)->right_son;
    Node *new_left_son = (*sub_root)->left_son;
    bool right = false;
    bool left = false;

    if(new_right_son == nullptr)
    {
        (*sub_root)->right_height = 0;
        right = true;
    }
    if(new_left_son == nullptr)
    {
        (*sub_root)->left_height = 0;
        left = true;
    }
    if(!right)
    {
        if(new_right_son->left_son == nullptr)
        {
            new_right_son->left_height = 0;
        }
        else
        {
            new_right_son->left_height = Greater(new_right_son->left_son->left_height,new_right_son->left_son->right_height) + 1;
        }
        if(new_right_son->right_son == nullptr)
        {
            new_right_son->right_height = 0;
        }
        else
        {
            new_right_son->right_height = Greater(new_right_son->right_son->left_height,new_right_son->right_son->right_height) +1;
        }
    }
    if(!left)
    {
        if(new_left_son->left_son == nullptr)
        {
            new_left_son->left_height = 0;
        }
        else
        {
            new_left_son->left_height = Greater(new_left_son->left_son->left_height,new_left_son->left_son->right_height) + 1;
        }
        if(new_left_son->right_son == nullptr)
        {
            new_left_son->right_height = 0;
        }
        else
        {
            new_left_son->right_height = Greater(new_left_son->right_son->left_height,new_left_son->right_son->right_height) +1;
        }
    }
    if(!left)
    {
        (*sub_root)->left_height = Greater(new_left_son->left_height,new_left_son->right_height) +1;
    }
    if(!right)
    {
             (*sub_root)->right_height = Greater(new_right_son->left_height,new_right_son->right_height) +1;
    }
}
/*Greater*/
int AVLTree::Greater(int value1, int value2)
{
    int greater;
    if(value1 > value2)
    {
        greater = value1;
    }
    else
    {
        greater = value2;
    }
    return greater;
}
/*Diference*/
int AVLTree::Diference(int value1, int value2)
{
    int diference;
    if(value1 > value2)
    {
        diference = value1 - value2;
    }
    else if(value2 > value1)
    {
        diference = value2 - value1;
    }
    return diference;
}
/*Print*/
void AVLTree::Print()
{
    Print(&root);
}
/*Print*/
void AVLTree::Print(Node **sub_root)
{
    if(*sub_root == nullptr)
    {
        return;
    }
    Print(&((*sub_root)->right_son));
    Print(&((*sub_root)->left_son));

    cout<<(*sub_root)->valor<<endl;

}
