#pragma once

#include "list.h"
#include "Data.h"
#include <iostream>




using namespace std;
// TODO 디폴트 생성자와 소멸자를 파일 저장 / 삭제 기능으로 구현할 것.
class UI {
public:
    UI() {}            
    ~UI() {}
    
    void run();
private:
    List* uiList = nullptr;
};
////////////////////////////////////////
// 메뉴에서 받은 값에 따라 정의될 다른 ui들.
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

