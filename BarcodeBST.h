#ifndef BARCODEBST_H_
#define BARCODEBST_H_

#include "BinarySearchTree.h"
#include "Product.h"

/*
 * DESCRIPTION: Prototype for the BarcodeBST 
 * 
 * AUTHOR: Anthony Seo
 */
class BarcodeBST : public BinarySearchTree<Product> {
  private:
    int numberOfProducts;

  public:
    BarcodeBST();
    void insertProduct(string& upc, string& description);
    void searchProduct(string upc);
    void removeProduct(string upc);

  private:
    void search(BinaryNode<Product> *root, string upc);
};

BarcodeBST::BarcodeBST() {
    numberOfProducts = 0;
}

void BarcodeBST::insertProduct(string& upc, string& description) {
    Product newProduct(upc, description);
    bool inserted = insert(root, newProduct);
    if (inserted) {
        numberOfProducts++;
    }
}

void BarcodeBST::searchProduct(string upc) {
    search(root, upc);
    
}

void BarcodeBST::search(BinaryNode<Product> *root, string upc) {
    if (root == nullptr) {
        // upc was not found
        cout << "Product with UPC: " << upc << " was not found." << endl;
    }

    if (root->data > upc) {
        // upc < current data, go left
        search(root->left, upc);
    } else if (root->data < upc) {
        // upc > current data, go right
        search(root->right, upc);
    } else {
        // Product found, print
        cout << root->data.getProduct() << endl;
    }
}

void BarcodeBST::removeProduct(string upc) {
    string dummyDescription = "";
    Product comparison(upc, dummyDescription);
    deleteNode(root, comparison);
}

#endif // BARCODEBST_H_