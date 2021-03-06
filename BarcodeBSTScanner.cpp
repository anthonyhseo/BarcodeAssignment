#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include "BarcodeBST.h"

using namespace std;

void init(BarcodeBST&);

/*
 * DESCRIPTION: Main method for the BarcodeBSTScanner
 * to compile: g++ BarcodeBSTScanner.cpp -o BarcodeBSTScanner.out
 * to run ./BarcodeBSTScanner.out
 * 
 * AUTHOR: Anthony Seo
 * 
 */
int main() {
    BarcodeBST products;
    init(products);

    string product = "";

    while (true) {
        cout << "Enter UPC of product would you like to search for (Enter 'q' to quit): ";
        getline(cin, product);

        if (product == "q") break;

        clock_t t = clock();

        products.searchProduct(product);

        t = clock() - t;
        cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " milliseconds" << endl;
    }

    return 0;
}

/*
 * DESCRIPTION: This method initializes the product BinarySearchTree data
 * structure.
 *
 * OUTPUT: none
 * INPUTS: BarcodeBST data structure.
 * AUTHOR: Anthony Seo
 */
void init(BarcodeBST &prod) {
    string output;
    ifstream file;
    file.open("upc_corpus.txt");
    while (getline(file, output)) {
        bool upcParsed = false;
        string upc = "";
        string desc = "";
        string token = "";
        istringstream ss(output);
        while (getline(ss, token, ',')) {
            if (!upcParsed) {
                upc = token;
                upcParsed = true;
            } else {
                // += because there might be commas in the description.
                desc += token;
            }
        }

        prod.insertProduct(upc, desc);
    }

    file.close();
}