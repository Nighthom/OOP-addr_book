#pragma once

#include "list.h"
#include "Data.h"
#include <iostream>




using namespace std;
// TODO ����Ʈ �����ڿ� �Ҹ��ڸ� ���� ���� / ���� ������� ������ ��.
class UI {
public:
    UI() {}            
    ~UI() {}
    
    void run();
private:
    List* uiList = nullptr;
};
////////////////////////////////////////
// �޴����� ���� ���� ���� ���ǵ� �ٸ� ui��.
class menuUI {
public:
    virtual List* run(List* uiList) = 0;
};

class Insert : public menuUI {
public:
    virtual List* run(List* uiList);
};
class Delete : public menuUI {
    virtual List* run(List* uiList);
};
class Search : public menuUI {
    virtual List* run(List* uiList);
};
class printAllData : public menuUI {
    virtual List* run(List* uiList);
};

