
//*****************************************************************************************************
//
//		File:					HashTable.h
//
//		This program will impliment and test a hashtable class.
//	
//		Other files required: 
//         1. HTElement.h 
//			
//*****************************************************************************************************

#ifndef HASHTABLE_H
#define HASHTABLE_H

//*****************************************************************************************************

#include "HTElement.h"
#include <iostream>

//*****************************************************************************************************

using namespace std;

//*****************************************************************************************************

template<typename T>
class HashTable {
private:
    HTElement<T>* table;

    int capacity;
    int size;

    int hash(const T& item) const;
    int findPosition(const T& item) const;

public:
    HashTable(int size = 10);
    ~HashTable();
    void remove(const T& item);
    void insert(const T& item);
    void display() const;
    T* search(const T& item) const;
};

#endif

//*****************************************************************************************************

template<typename T>
inline int HashTable<T>::hash(const T& item) const
{
    return item.getSymbol().length() % capacity;
}

//*****************************************************************************************************

template<typename T>
inline HashTable<T>::~HashTable()
{
    delete[] table;
}

//*****************************************************************************************************

template<typename T>
HashTable<T>::HashTable(int size)
{
    capacity = size;
    table = new HTElement<T>[capacity];
    size = 0;
}

//*****************************************************************************************************

template<typename T>
int HashTable<T>::findPosition(const T& item) const
{
    int index = hash(item);
    int i = 1;
    while (table[index].status == 1 && table[index].item != item)
    {
        index = (index + i * i) % capacity;
        ++i;
    }
    return index;
}

//*****************************************************************************************************


template<typename T>
void HashTable<T>::remove(const T& item)
{
    int index = findPosition(item);
    if (table[index].status == 1)
    {
        table[index].status = -1;
        --size;
    }
}

//*****************************************************************************************************

template<typename T>
void HashTable<T>::insert(const T& item)
{
    if (size >= capacity)
    {
        std::cout << "Hash table is full!\n";
        return;
    }
    int index = findPosition(item);
    if (table[index].status != 1) {
        table[index].item = item;
        table[index].status = 1;
        ++size;
    }
}

//*****************************************************************************************************

template<typename T>
void HashTable<T>::display() const
{
    for (int i = 0; i < capacity; ++i)
    {
        if (table[i].status == 1)
        {
            std::cout << "Index " << i << ": ";
            table[i].item.display();
        }
    }
}

//*****************************************************************************************************

template<typename T>
T* HashTable<T>::search(const T& item) const
{
    int index = findPosition(item);
    if (table[index].status == 1 && table[index].item == item)
    {
        T* copy = new T(table[index].item);
        return copy;
    }
    return nullptr;
}

//*****************************************************************************************************
