#ifndef __RBTREE_H__
#define __RBTREE_H__

#include <iostream>
#include <ostream>

#ifndef NULL
#define NULL 0x00
#endif
// Defines MAX
// When used, MAX(a,b) will be replaced with ((a > b) ? a : b)
#ifndef MAX
#define MAX(a,b) ((a > b) ? a : b)
#endif

// Underlying class which will be used to implement the RBTree class.
// I.E. RBTree is made up of RBTNode
class RBTNode
{
    private:
        int data;
        RBTNode* left;
        RBTNode* right;

        void swapColor() {red != red;}
    public:
        RBTNode();
        RBTNode(int data);
        ~RBTNode();

    friend class RBTree;
};
// Fill in the private and public data members of the RBTree
// Please note that test.cpp shows that insert and remove methods
// only take one parameter (an integer).
// This means you will need to have a private and public version of some methods:
// A private function would take a pointer to the root node of the tree and the
// integer to be inserted/removed.
// A public version would only take the integer to be inserted/removed as a
// parameter and then use the private version of the method to implement.
class RBTree
{
    private:
        RBTNode* root;

        RBTNode* insert(int data, RBTNode* root);
        int height(RBTNode* root);

        void preorder(RBTNode* root, std::ostream& os);
        void inorder(RBTNode* root, std::ostream& os);
        void postorder(RBTNode* root, std::ostream& os);

        void destroy(RBTNode* root);
        bool search(int data, RBTNode* root);

        RBTNode* rotateLeft(RBTNode* root);
        RBTNode* rotateRight(RBTNode* root);
        
        bool isRed(RBTNode* node);

    public:
        RBTree();
        ~RBTree();

        void insert(int data);
        int height();

        void preorder(std::ostream& os = std::cout);
        void inorder(std::ostream& os = std::cout);
        void postorder(std::ostream& os = std::cout);

        bool search(int data);
        void clear();

};

#endif
