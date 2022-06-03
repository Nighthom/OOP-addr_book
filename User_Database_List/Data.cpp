#include "data.h"

//////////////////////////////////////////////////////////////////////////
// addr_book 연산자 밎 생성자
addr_book::addr_book(const string& rName, const string& rNumber) {
    name = rName;
    number = rNumber;
}

bool addr_book::operator==(const Data& rhs) {
    return addr_book::compare(rhs);
}
///////////////////////////////////////////////////////////////////////////
// addr_book 메서드

void addr_book::setData(const Data& rhs) {
    addr_book& setter = static_cast<addr_book&>(const_cast<Data&>(rhs));

    setData(setter.name, setter.number);
}

void addr_book::setData(const string& rName, const string& rNumber) {
    name = rName; number = rNumber;
}

void addr_book::printData() {
    cout << this << setw(10) << name << setw(10) << number << endl;
}
void addr_book::printLable() {
    cout << "주소" << setw(20) << "이름" << setw(15) <<"전화번호" << endl;
}
bool addr_book::compare(const Data& rhs) {
    addr_book& rightHeader = static_cast<addr_book&>(const_cast<Data&>(rhs)); 
    if(name == rightHeader.name)
        return true;
    return false;
}
