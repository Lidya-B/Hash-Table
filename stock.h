//*****************************************************************************************************
//
//		File:					Stock.h
//
//		This program will impliment and test a hashtable class.
//	
//		Other files required: 
//         1. none 
//			
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

//*****************************************************************************************************

#include <string>

//*****************************************************************************************************

class Stock
{
private:
    std::string companyName;
    std::string stockSymbol;
    double price;

public:
    Stock(const std::string& n = "", const std::string& s = "", double p = 0);
    Stock(const Stock& s);
    void display() const;
    std::string getName() const;
    std::string getSymbol() const;
    double getPrice() const;
    int hash(int size) const;
    bool operator==(const Stock& rhs) const;
    bool operator!=(const Stock& rhs) const;
    bool operator<(const Stock& rhs) const;
    bool operator>(const Stock& rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const Stock& stock);
};

#endif 

//*****************************************************************************************************

inline std::string Stock::getName() const
{
    return companyName;
}

//*****************************************************************************************************

inline std::string Stock::getSymbol() const
{
    return stockSymbol;
}

//*****************************************************************************************************

inline double Stock::getPrice() const
{
    return price;
}

//*****************************************************************************************************

inline int Stock::hash(int size) const
{
    return stockSymbol.length() % size;
}

//*****************************************************************************************************

inline bool Stock::operator==(const Stock& rhs) const
{
    return stockSymbol == rhs.stockSymbol;
}

//*****************************************************************************************************

inline bool Stock::operator!=(const Stock& rhs) const
{
    return stockSymbol != rhs.stockSymbol;
}

//*****************************************************************************************************

inline bool Stock::operator<(const Stock& rhs) const
{
    return stockSymbol < rhs.stockSymbol;
}

//*****************************************************************************************************

inline bool Stock::operator>(const Stock& rhs) const
{
    return stockSymbol > rhs.stockSymbol;

}

//*****************************************************************************************************
