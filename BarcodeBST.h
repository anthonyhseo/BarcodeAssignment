#ifndef BARCODEBST_H_
#define BARCODEBST_H_

#include "BinarySearchTree.h"
#include "Product.h"

/*
 * DESCRIPTION: Prototype for the BarcodeBST. It inherits from the
 * BinarySearchTree class.
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
    int numProducts();

  private:
    void search(BinaryNode<Product> *root, string upc);
};

/*
 * DESCRIPTION: Constructor for the BarcodeBST class
 * 
 * AUTHOR: Anthony Seo
 */
BarcodeBST::BarcodeBST() {
    numberOfProducts = 0;
}

/*
 * DESCRIPTION: The method inserts a Product with a given UPC and description.
 * It calls the private method in the BinarySearchTree class.
 * 
 * OUTPUT: none
 * INPUTS: (string reference) UPC, (string reference) description
 * AUTHOR: Anthony Seo
 */
void BarcodeBST::insertProduct(string& upc, string& description) {
    Product newProduct(upc, description);
    bool inserted = insert(root, newProduct);
    if (inserted) {
        numberOfProducts++;
    }
}

/*
 * DESCRIPTION: Searches a product given a UPC in string format.
 * 
 * OUTPUT: none
 * INPUTS: (string) UPC
 * AUTHOR: Anthony Seo
 */
void BarcodeBST::searchProduct(string upc) {
    search(root, upc);
}

/*
 * DESCRIPTION: Private method to search for the item in BST.
 * 
 * OUTPUT: none
 * INPUTS: The root of the BST. (string) UPC
 * AUTHOR: Anthony Seo
 */
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

/*
 * DESCRIPTION: Removes a product with a given UPC.
 * 
 * OUTPUT: none
 * INPUTS: (string) UPC
 * AUTHOR: Anthony Seo
 */
void BarcodeBST::removeProduct(string upc) {
    string dummyDescription = "";
    Product comparison(upc, dummyDescription);
    bool deleted = deleteNode(root, comparison);
    if (deleted) {
        numberOfProducts--;
    }
}

/*
 * DESCRIPTION: returns the number of Products in the BST
 * 
 * OUTPUT: (int) number of Product object in the BST.
 * INPUTS: none
 * AUTHOR: Anthony Seo
 */
int BarcodeBST::numProducts() {
    return numberOfProducts;
}

#endif // BARCODEBST_H_