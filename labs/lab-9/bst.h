#ifndef __BINTREE_H__
#define __BINTREE_H__

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

// Underlying class which will be used to implement the BSTree class.
// I.E. BSTree is made up of BSTNode
class BSTNode
{
    private:
        int data;
        BSTNode* left;
        BSTNode* right;

    public:
        BSTNode(int data);
        ~BSTNode();

    friend class BSTree;
};
// Please note that test.cpp shows that insert and remove methods
// only take one parameter (an integer).
// This means you will need to have a private and public version of some methods:
// A private function would take a pointer to the root node of the tree and the
// integer to be inserted/removed.
// A public version would only take the integer to be inserted/removed as a
// parameter and then use the private version of the method to implement.
class BSTree
{
    private:
        BSTNode* root;

        BSTNode* insert(int data, BSTNode* root);
        int height(BSTNode* root);

        void preorder(BSTNode* root, std::ostream& os);
        void inorder(BSTNode* root, std::ostream& os);
        void postorder(BSTNode* root, std::ostream& os);

        void destroy(BSTNode* root);
        bool search(int data, BSTNode* root);

    public:
        BSTree();
        ~BSTree();

        void insert(int data);
        int height();

        void preorder(std::ostream& os = std::cout);
        void inorder(std::ostream& os = std::cout);
        void postorder(std::ostream& os = std::cout);

        bool search(int data);

};

#endif
