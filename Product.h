#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
using namespace std;

/*
 * DESCRIPTION: Prototype for Product class.
 * 
 * AUTHOR: Anthony Seo
 */
class Product {
  private:
    string upc;
    string itemDescription;

  public:
    Product(string upc = "", string item = "") : upc(upc), itemDescription(item) {}
    string getUPC();
    string getProduct();

    bool operator==(const string&);
    bool operator==(const Product&);
    bool operator<(const string&);
    bool operator<(const Product&);
    bool operator>(const string&);
    bool operator>(const Product&);

    // Operator overload of the << operator. Allows user to cout the Product object.
    friend ostream& operator<<(ostream &os, const Product &other) {
        os << other.upc << " " << other.itemDescription;
        return os;
    }
};

/*
 * DESCRIPTION: Method to return the UPC to the client.
 *
 * OUTPUT: (string) UPC
 * INPUTS: none
 * AUTHOR: Anthony Seo
 */
string Product::getUPC() {
    return upc;
}

/*
 * DESCRIPTION: Method to return the description of the product to the client.
 *
 * OUTPUT: (string) description
 * INPUTS: none
 * AUTHOR: Anthony Seo
 */
string Product::getProduct() {
    return itemDescription;
}

/*
 * DESCRIPTION: Equality operator overload for the Product class. Compares a
 * string upc with the current Product object.
 *
 * OUTPUT: True if equal, false if not equal.
 * INPUTS: UPC to compare in string format
 * AUTHOR: Anthony Seo
 */
bool Product::operator==(const string& rhs) {
    return upc == rhs;
}

/*
 * DESCRIPTION: Equality operator overload for the Product class. Compares the
 * UPC of another product with the current product UPC.
 *
 * OUTPUT: True if equal, false if not equal.
 * INPUTS: UPC to compare in string format
 * AUTHOR: Anthony Seo
 */
bool Product::operator==(const Product& rhs) {
    return upc == rhs.upc;
}

/*
 * DESCRIPTION: Less than (<) operator overload for the Product class. Compares
 * a upc with the current Product object.
 *
 * OUTPUT: True if less than, false if not less than.
 * INPUTS: UPC to compare in string format
 * AUTHOR: Anthony Seo
 */
bool Product::operator<(const string& rhs) {
    return upc < rhs;
}

/*
 * DESCRIPTION: Less than (<) operator overload for the Product class. Compares
 * another Product with the current Product object. Comparison is based on UPC 
 * values.
 *
 * OUTPUT: True if less than, false if not less than.
 * INPUTS: UPC to compare in string format
 * AUTHOR: Anthony Seo
 */
bool Product::operator<(const Product& rhs) {
    return upc < rhs.upc;
}

/*
 * DESCRIPTION: Greater than (>) operator overload for the Product class.
 * Compares a upc with the current Product object.
 *
 * OUTPUT: True if greater than, false if not greater than.
 * INPUTS: UPC to compare in string format
 * AUTHOR: Anthony Seo
 */
bool Product::operator>(const string& rhs) {
    return upc > rhs;
}

/*
 * DESCRIPTION: Greater than (>) operator overload for the Product class.
 * Compares another Product with the current Product object. The comparison is
 * based on UPC values.
 *
 * OUTPUT: True if greater than, false if not greater than.
 * INPUTS: (Product) Product to compare.
 * AUTHOR: Anthony Seo
 */
bool Product::operator>(const Product& rhs) {
    return upc > rhs.upc;
}

#endif // PRODUCT_H_