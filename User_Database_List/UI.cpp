#include "UI.h"

void UI::run() {
    char menu = 0;
    menuUI* menu_UI = nullptr;
    while(true) {
        ////////////////// 이벤트 루프 /////////////////////////
        system("cls");
        cout << "-------------------------------" << endl;
        cout << "------객체지향 주소록-----------" << endl;
        cout << "---------ver. 연결 리스트-------" << endl;
        cout << "-------------------------------" << endl;
        cout << "insert : i, delete : d, search : s, printAllData : p ,exit : q" << endl;
        
        cin >> menu;
        try {
        switch(menu){
                case 'i':
                    menu_UI = new Insert;
                    break;
                case 'd':
                    menu_UI = new Delete;
                    break;
                case 's':
                    menu_UI = new Search;
                    break;
                case 'p':
                    menu_UI = new printAllData;
                    break;
                case 'q':
                    delete menu_UI;                         // 종료시 menu_UI 삭제.
                    return;
                default: 
                    throw "유효하지 않은 입력입니다. 다시 입력해 주세요.";
            }
            system("cls");
            uiList = menu_UI->run(uiList);
            system("pause");
        }
        ///////////////////// 예외처리 ///////////////////////
        catch(const char* eString) {
            system("cls");
            cout << "ERROR : " << eString << endl;
            system("pause");
        }
        cin.clear();
    }                                          
}

List* Insert::run(List* uiList) {                               // 데이터 삽입용.
    string name;
    string number;

    if (uiList == nullptr) {
        uiList = new List;
    }
    cout << "주소록에 삽입할 대상의 이름을 입력하세요. " << endl;
    cin >> name;
    cout << "주소록에 삽입할 대상의 전화번호를 입력하세요. " << endl;
    cin >> number;
    
    addr_book* newData = new addr_book(name, number);

    system("cls"); 
    cout << "대상을 삽입 완료했습니다. " << endl;
    return uiList->insertNode(newData);
}
List* Delete::run(List* uiList) {                                // 데이터 삭제용. 
    string name;

    if (uiList == nullptr) {
        throw "데이터베이스가 비어있습니다. 데이터를 먼저 삽입해주세요. ";
    }
    cout << "주소록에서 지울 대상의 이름을 입력하세요. " << endl;
    cin >> name;
    addr_book* delData = new addr_book(name, "");
    uiList->deleteNode(delData);
    delete delData;
    cout << "대상을 삭제했습니다." << endl;
    return uiList;
}
List* Search::run(List* uiList) {                               // 데이터 중에서 원하는 데이터를 찾는 함수.
    string name;

    if (uiList == nullptr) {
        throw "데이터베이스가 비어있습니다. 데이터를 먼저 삽입해주세요. ";
    }

    cout << "주소록에서 검색할 대상의 이름을 입력하세요. " << endl;
    cin >> name;
    addr_book* searchData = new addr_book(name, "");            // addr_book 객체로 찾기.
    Data* search = uiList->searchNode(searchData);

    system("cls");
    cout << "대상을 찾았습니다. 대상을 출력합니다." << endl;
    system("pause");
    system("cls");
    search->printLable();
    search->printData();
    
    delete searchData;
    return uiList;
}

List* printAllData::run(List* uiList) {                     // 모든 데이터 출력해주는 ui 함수. 

    if (uiList == nullptr) {
        throw "데이터베이스가 비어있습니다. 데이터를 먼저 삽입해주세요. ";
    }
    if (uiList->getCurrent() == nullptr) {
        throw "데이터베이스가 비어있습니다. 데이터를 먼저 삽입해주세요. ";
    }
    uiList->printAllData();
    return uiList;
}