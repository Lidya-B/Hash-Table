//*****************************************************************************************************
//
//		File:					hash.cpp
//
//		This program will impliment and test a hashtable class.
//	
//		Other files required: 
//         1. stock.h
//         2. HashTable.h
//			
//*****************************************************************************************************

#include"HashTable.h"
#include "stock.h"
#include <iostream>

//*****************************************************************************************************

using namespace std;

//*****************************************************************************************************

int main()
{
    HashTable<Stock> stockTable(10);
    Stock s1("ABC Inc.", "ABC", 100.0);
    Stock s2("XYZ Corp.", "XYZ", 200.0);


    stockTable.insert(s1);
    stockTable.insert(s2);

    cout << "Displaying stocks in the hash table:\n";
    stockTable.display();

    Stock searchStock("XYZ Corp.", "XYZ", 200.0);
    Stock* foundStock = stockTable.search(searchStock);
    if (foundStock != nullptr) 
    {
        cout << "Found stock: " << *foundStock << endl;
        delete foundStock;
    }
    else 
    {
        cout << "Stock not found.\n";
    }

    stockTable.remove(s2);
    cout << "After removing a stock:\n";
    stockTable.display();

    return 0;
}

//*****************************************************************************************************
