#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
   
    Node *right_son;
    Node *left_son;
    
    int valor;
    int right_height;
    int left_height;
};

#endif // NODE_H
