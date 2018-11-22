#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include "BarcodeBST.h"
#include "BarcodeArray.h"

using namespace std;

void init(BarcodeBST &, BarcodeArray &);

/*
 * DESCRIPTION: Automated testing for both the BST and Array. It will output a csv file to graph the data. 
 * 
 * AUTHOR: Anthony Seo
 */
int main() {
    remove("results.csv");
    ofstream outputData;
    outputData.open("results.csv");
    BarcodeBST bst;
    BarcodeArray array(1200000);
    init(bst, array);

    int size = array.numberOfProducts();
    cout << size << endl;

    /* The loop that generates the data for the graph. The user can increase or
     * decrease the number of test cases by editing the += value. This case will
     * produce roughly 200 test cases.
     */
    for (int i = 0; i < size; i += 5000) {
        string testUPC = array.getUPCAtIndex(i);
        double bstTime = 0;
        double arrayTime = 0;

        // timing data for BST.
        clock_t t = clock();
        bst.searchProduct(testUPC);
        t = clock() - t;
        bstTime = t * 1.0 / CLOCKS_PER_SEC;
        cout << "BST search time: " << bstTime << " milliseconds" << endl;

        // timing data for Array
        t = clock();
        array.searchProduct(testUPC);
        t = clock() - t;
        arrayTime = t * 1.0 / CLOCKS_PER_SEC;
        cout << "Array search time: " << arrayTime << " milliseconds\n" << endl;
        outputData << i << "," << bstTime << "," << arrayTime << endl;
    }

    outputData.close();

    return 0;
}

/*
 * DESCRIPTION: This method initializes the product BinarySearchTree data
 * structure as well as the Array data structure.
 *
 * OUTPUT: none
 * INPUTS: BarcodeBST data structure and Array data structure.
 * AUTHOR: Anthony Seo
 */
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
