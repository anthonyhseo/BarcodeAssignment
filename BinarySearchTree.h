#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
using namespace std;

/*
 * DESCRIPTION: Node data structure for the binary tree. The user will have to
 * manually initialize the data, left and right nodes.
 *
 * AUTHOR: Anthony Seo
 */
template <class T>
struct BinaryNode {
    T data;
    BinaryNode<T>* left;
    BinaryNode<T>* right;
};

/*
 * DESCRIPTION: Prototype for the BinarySearchTree class
 * 
 * 
 * 
 * AUTHOR: Anthony Seo
 */
template <class T>
class BinarySearchTree {
  protected:
    BinaryNode<T> *root;

  public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(BinarySearchTree<T> &other);
    ~BinarySearchTree();
    void insert(T &);
    void search(T &);
    void deleteNode(T &);
    void inorderTraverse();
    BinaryNode<T>* findMin(BinaryNode<T> *);

    BinarySearchTree<T> operator=(BinarySearchTree<T> &rhs);

  protected:
    BinaryNode<T>* copy(BinaryNode<T> *);
    void destroy(BinaryNode<T> *&);
    bool insert(BinaryNode<T> *&, T &);
    bool deleteNode(BinaryNode<T> *&, T &);
    BinaryNode<T> *search(BinaryNode<T> *, T &);
    void inorderTraverse(BinaryNode<T> *);
};




template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>& rhs){
    // TODO: implement copy constructor
    root = nullptr;
    if (this != &rhs) {
        root = copy(rhs.root);
    }
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    // TODO: need to implement destructor
    destroy(root);
}

/*
 * DESCRIPTION: Helper method to deep copy all nodes in the BinarySearchTree.
 * 
 * OUTPUT: Pointer to the root of the copied binary tree
 * INPUTS: root of the binary tree to be copied
 * AUTHOR: Anthony Seo
 */
template <class T>
BinaryNode<T>* BinarySearchTree<T>::copy(BinaryNode<T>* p) {
    if (p == nullptr) return nullptr;

    BinaryNode<T>* newNode = new BinaryNode<T>;
    newNode->data = p->data;
    newNode->left = copy(p->left);
    newNode->right = copy(p->right);

    return newNode;
}

/*
 * DESCRIPTION: Helper method to delete all nodes in the BinarySearchTree. It is used to initialize the BinarySearchTree or used in the destructor to free dynamic memory elements.
 * 
 * OUTPUT: none
 * INPUTS: pointer to the BinaryNode element
 * AUTHOR: Anthony Seo
 */
template <class T>
void BinarySearchTree<T>::destroy(BinaryNode<T>*& p) {
    if (p != nullptr) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
    p = nullptr;
}

template <class T>
void BinarySearchTree<T>::insert(T& item) {
    bool inserted = insert(root, item);
    if (!inserted) {
        cout << "Insert failed, duplicate item" << endl;
    }
}

template <class T>
bool BinarySearchTree<T>::insert(BinaryNode<T>*& p, T& item) {
    if (p == nullptr) {
        BinaryNode<T> *newNode = new BinaryNode<T>;
        newNode->data = item;
        newNode->left = nullptr;
        newNode->right = nullptr;
        p = newNode;
        return true;
    } else if (item < p->data) {
        return insert(p->left, item);
    } else if (item > p->data) {
        return insert(p->right, item);
    } else { // item == p->data
        // do nothing to the BST, return false
        return false;
    }
}

template <class T>
void BinarySearchTree<T>::search(T& item) {
    BinaryNode<T>* found = search(root, item);
    if (found == nullptr) {
        cout << "Item not found." << endl;
    } else {
        cout << found->data << endl;
    }
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::search(BinaryNode<T>* p, T& item) {
    if (p == nullptr) return nullptr;
    if (item < p->data) {
        return search(p->left, item);
    } else if (item > p->data) {
        return search(p->right, item);
    } else {
        return p;
    }
}

template <class T>
void BinarySearchTree<T>::deleteNode(T &item) {
    bool deleted = deleteNode(root, item);
    if (!deleted) {
        cout << "Item was not found" << endl;
    }
}

template <class T>
bool BinarySearchTree<T>::deleteNode(BinaryNode<T>*& p, T& item) {
    if (p == nullptr) {
        // Item was not found.
        return false;
    } else {
        if (item < p->data) {
            // item is less than current node, go left.
            return deleteNode(p->left, item);
        } else if (item > p->data) {

            // item is greater than current node, go right.
            return deleteNode(p->right, item);
        } else if (p->left != nullptr && p->right != nullptr) {
            // two children
            p->data = findMin(p->right)->data;
            return deleteNode(p->right, p->data);
        } else {
            // zero or one children
            BinaryNode<T> *temp = p;
            if (p->left != nullptr) {
                p = p->left;
            } else {
                p = p->right;
            }
            delete p;

            return true;
        }
    }
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::findMin(BinaryNode<T>* p) {
    if (p != nullptr) {
        while (p->left != nullptr) {
            p = p->left;
        }
    }

    return p;
}


template <class T>
void BinarySearchTree<T>::inorderTraverse() {
    inorderTraverse(root);
    cout << '\n';
}

/*
 *
 * 
 * 
 */
template <class T>
void BinarySearchTree<T>::inorderTraverse(BinaryNode<T> *root) {
    if (root == nullptr) return;
    inorderTraverse(root->left);
    cout << root->data << " ";
    inorderTraverse(root->right);
}

/*
 *
 * 
 * 
 */
template <class T>
BinarySearchTree<T> BinarySearchTree<T>::operator=(BinarySearchTree<T>& rhs) {
    // TODO: implement assignment operator
    cout << "running assignment operator" << endl;
    if (this != &rhs) {
        destroy(root);
        root = copy(rhs.root);
    }

    return *this;
}


#endif // BINARYSEARCHTREE_H_