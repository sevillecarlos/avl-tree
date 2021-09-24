#include <iostream>
#include"avltree.h"
using namespace std;

int main()
{
    AVLTree avltree;

    int value;
    int option;

    do{
        cout<<"**********************"<<endl;
        cout<<"1.Add Element"<<endl;
        cout<<"2.Print Tree"<<endl;
        cout<<"3.Find Value"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"**********************"<<endl;
        cout<<"Answer : " ;
        cin>>option;

        switch(option)
        {
        case 1:
            cout<<"Give me a number to add : "<<endl;
            cin>>value;
            cout<<avltree.Add(value)<<endl;
            cout<<"You add an element !"<<endl;
            break;
        case 2:
            cout<<"All the Element in the tree"<<endl;
            avltree.Print();
            break;
        case 3:
            cout<<"Give an element to find : "<<endl;
            cin>>value;
            cout<< "The value is : " << avltree.FindValue(value)<<endl;
            break;
        case 4:
            cout<<"Thank You!"<<endl;
            exit(0);
        }

    }while(-4);

}

//code by @sevillecarlos