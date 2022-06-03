#include "UI.h"

void UI::run() {
    char menu = 0;
    menuUI* menu_UI = nullptr;
    while(true) {
        ////////////////// �̺�Ʈ ���� /////////////////////////
        system("cls");
        cout << "-------------------------------" << endl;
        cout << "------��ü���� �ּҷ�-----------" << endl;
        cout << "---------ver. ���� ����Ʈ-------" << endl;
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
                    delete menu_UI;                         // ����� menu_UI ����.
                    return;
                default: 
                    throw "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
            }
            system("cls");
            uiList = menu_UI->run(uiList);
            system("pause");
        }
        ///////////////////// ����ó�� ///////////////////////
        catch(const char* eString) {
            system("cls");
            cout << "ERROR : " << eString << endl;
            system("pause");
        }
        cin.clear();
    }                                          
}

List* Insert::run(List* uiList) {                               // ������ ���Կ�.
    string name;
    string number;

    if (uiList == nullptr) {
        uiList = new List;
    }
    cout << "�ּҷϿ� ������ ����� �̸��� �Է��ϼ���. " << endl;
    cin >> name;
    cout << "�ּҷϿ� ������ ����� ��ȭ��ȣ�� �Է��ϼ���. " << endl;
    cin >> number;
    
    addr_book* newData = new addr_book(name, number);

    system("cls"); 
    cout << "����� ���� �Ϸ��߽��ϴ�. " << endl;
    return uiList->insertNode(newData);
}
List* Delete::run(List* uiList) {                                // ������ ������. 
    string name;

    if (uiList == nullptr) {
        throw "�����ͺ��̽��� ����ֽ��ϴ�. �����͸� ���� �������ּ���. ";
    }
    cout << "�ּҷϿ��� ���� ����� �̸��� �Է��ϼ���. " << endl;
    cin >> name;
    addr_book* delData = new addr_book(name, "");
    uiList->deleteNode(delData);
    delete delData;
    cout << "����� �����߽��ϴ�." << endl;
    return uiList;
}
List* Search::run(List* uiList) {                               // ������ �߿��� ���ϴ� �����͸� ã�� �Լ�.
    string name;

    if (uiList == nullptr) {
        throw "�����ͺ��̽��� ����ֽ��ϴ�. �����͸� ���� �������ּ���. ";
    }

    cout << "�ּҷϿ��� �˻��� ����� �̸��� �Է��ϼ���. " << endl;
    cin >> name;
    addr_book* searchData = new addr_book(name, "");            // addr_book ��ü�� ã��.
    Data* search = uiList->searchNode(searchData);

    system("cls");
    cout << "����� ã�ҽ��ϴ�. ����� ����մϴ�." << endl;
    system("pause");
    system("cls");
    search->printLable();
    search->printData();
    
    delete searchData;
    return uiList;
}

List* printAllData::run(List* uiList) {                     // ��� ������ ������ִ� ui �Լ�. 

    if (uiList == nullptr) {
        throw "�����ͺ��̽��� ����ֽ��ϴ�. �����͸� ���� �������ּ���. ";
    }
    if (uiList->getCurrent() == nullptr) {
        throw "�����ͺ��̽��� ����ֽ��ϴ�. �����͸� ���� �������ּ���. ";
    }
    uiList->printAllData();
    return uiList;
}