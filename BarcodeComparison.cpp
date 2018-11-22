#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include "BarcodeBST.h"
#include "BarcodeArray.h"

using namespace std;

void init(BarcodeBST &, BarcodeArray &);

int main() {

    BarcodeBST bst;
    BarcodeArray array(1200000);
    init(bst, array);


    return 0;
}

void init(BarcodeBST &bst, BarcodeArray &array) {
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

        bst.insertProduct(upc, desc);
        array.addProduct(upc, desc);
    }
}
