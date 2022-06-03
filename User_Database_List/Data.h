#pragma once
#include "List.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


class addr_book : public Data {
public:

    addr_book(const string&, const string&);
    void setData(const string&, const string&);

    virtual void setData(const Data&);
    virtual bool compare(const Data&);
    virtual void printData();
    virtual void printLable();

    virtual bool operator==(const Data&);
private:
    string name;
    string number;
};
