#include "data.h"

//////////////////////////////////////////////////////////////////////////
// addr_book ������ �G ������
addr_book::addr_book(const string& rName, const string& rNumber) {
    name = rName;
    number = rNumber;
}

bool addr_book::operator==(const Data& rhs) {
    return addr_book::compare(rhs);
}
///////////////////////////////////////////////////////////////////////////
// addr_book �޼���

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
    cout << "�ּ�" << setw(20) << "�̸�" << setw(15) <<"��ȭ��ȣ" << endl;
}
bool addr_book::compare(const Data& rhs) {
    addr_book& rightHeader = static_cast<addr_book&>(const_cast<Data&>(rhs)); 
    if(name == rightHeader.name)
        return true;
    return false;
}
