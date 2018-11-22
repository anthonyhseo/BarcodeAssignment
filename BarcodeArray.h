#ifndef BARCODEARRAY_H_
#define BARCODEARRAY_H_

#include <iostream>
#include "Product.h"

using namespace std;

class BarcodeArray {
  private:
    Product *products;
    int capacity;
    int size;

  public:
    BarcodeArray(int);
    ~BarcodeArray();
    void addProduct(string&, string&);
    void removeProduct(string);
    void searchProduct(string);
    int numberOfProducts();
};

/*
 * DESCRIPTION: Constructor for the BarcodeArray class. Initializes array with a
 * given capacity and sets the size to 0.
 *
 * AUTHOR: Anthony Seo
 */
BarcodeArray::BarcodeArray(int _capacity = 16) {
    products = new Product[_capacity];
    capacity = _capacity;
    size = 0;
}

/*
 * DESCRIPTION: Destructor for the BarcodeArray class. Deletes the dynamically
 * created array of products.
 *
 * AUTHOR: Anthony Seo
 */
BarcodeArray::~BarcodeArray() {
    delete [] products;
}

/*
 * DESCRIPTION: This method adds a product to the array of Products. It will add
 * new items to the end of the array.
 *
 * OUTPUT: none
 * INPUTS: upc as a string, description of the product as a string.
 * AUTHOR: Anthony Seo
 */
void BarcodeArray::addProduct(string& upc, string& description) {
    Product newItem(upc, description);
    products[size++] = newItem;
}

/*
 * DESCRIPTION: This method removes a product to the array of Products. It will
 * find the object in the array and shift all elements to the right one index
 * lower to overwrite the object.
 *
 * OUTPUT: none
 * INPUTS: upc as a string
 * AUTHOR: Anthony Seo
 */
void BarcodeArray::removeProduct(string upc) {
    int index = -1; 
    for (int i = 0; i < size; i++) {
        if (products[i] == upc) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Product not found!" << endl;
    } else {
        for (int i = i + 1; i < size; i++) {
            products[i - 1] = products[i];
        }
        size--;
    }
}

void BarcodeArray::searchProduct(string upc) {
    for (int i = 0; i < size; i++) {
        if (products[i] == upc) {
            cout << products[i].getProduct() << endl;
            return;
        }
    }

    cout << "Product with upc: " << upc << " not found." << endl;
}

/*
 * DESCRIPTION: This method returns the number of products in the array. 
 * 
 * OUTPUT: (int) the number of products in array
 * INPUTS: none
 * AUTHOR: Anthony Seo
 */
int BarcodeArray::numberOfProducts() {
    return size;
}


#endif // BARCODEARRAY_H_