// AVL MAIN
/*
 *  C++ Program to Implement Self Balancing Binary Search Tree
 */



                                    // An  " //O " means, an this was an Original line.

#include <iostream>
#include <cstdlib>
#include "AVLtree.h"
using namespace std;

int main()
{
    AVLtree sbbst;
    cout<<"AVLtree Test\n";
    int val;
    char ch;
    int choice=0;

    /*  Perform tree operations  */
   do
    {
        cout<<"\n\nA Self Balancing Binary Search Tree of the AVL type.\n";
        cout<<"\n1. Insert. "<<endl;
        cout<<"2. Count nodes."<<endl;
        cout<<"3. Search."<<endl;
        cout<<"4. Check for an empty tree. "<<endl;
        cout<<"5. Make empty."<<endl;
        cout<<"6. Quit."<<endl;


        do{
        choice = 6;                                                   // An anti-infinite loop, reset.
        cout<<"\nEnter a Choice: ";
        cin>>choice;
        } while(choice < 1 || choice > 6 && choice != 6);             //chk.  6 is for quitting.


        switch (choice)
        {

            case 1 :
                cout<<"Insert an integer element: ";
                cin>>val;
                sbbst.insert(val);
                break;

            case 2 :
                cout<<"Nodes count: " <<sbbst.countNodes()<<endl;
                break;

            case 3:
                cout<<"Enter integer element to search: ";
                cin>>val;
                if (sbbst.search(val))
                    cout<<val<<" found in the tree."<<endl;
                else
                    cout<<val<<" not found."<<endl;
                break;

            case 4 :
                cout<<"Empty status, (bool):  ";
                if (sbbst.isEmpty())
                    cout<<"Tree is empty."<<endl;
                else
                    cout<<"Tree is not empty."<<endl;
                break;

            case 5 :
                cout<<"\nTree cleared.\n";
                sbbst.makeEmpty();
                break;

            case 6:
                cout<<"Goodbye."<<endl;
                break;

            default :
                cout<<"Wrong Entry. \n ";
                break;

        }

        /*  Display tree*/
        cout<<"\nPost order : ";
        sbbst.postorder();
        cout<<"\nPre order : ";
        sbbst.preorder();
        cout<<"\nIn order : ";
        sbbst.inorder();
//      cout<<"\nDo you want to continue?  ";                       //O
//      cin>>ch;                                                    //O

    }
      while (ch == 'y' || ch == 'Y'  || choice != 6); //O

    return 0;
}



