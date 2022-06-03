#pragma once
#include <memory>
using namespace std;

class Data {
public:
//////////////////////////////////////////////////////////////
// ����Ʈ������ ���� �ʿ��� Data�� �Լ���. �� ��.
    virtual bool operator==(const Data&) = 0;

    virtual void setData(const Data&) = 0;
    virtual bool compare(const Data&) = 0;
    virtual void printData() = 0;
    virtual void printLable() = 0;
    
};
class lNode {                    
public:              // ����Ʈ�� �����Դϴ�. 
///////////////////////////////////////////////////////////////
// ������ �� ������
    lNode() = default;                     
    ~lNode(){}                                                                
    lNode* operator=(const lNode* rhs);
    bool operator==(const lNode* rhs);
///////////////////////////////////////////////////////////////
// ����� �Լ�
    bool compare(const lNode* rhs);
    lNode* getNext();
    Data* getData();
    void setData(const Data*);
    void setNext(const lNode*);

private:
    Data* pData;
    lNode* pNext;
};

class List {
public:                                     // ����Ʈ�� ����Դϴ�. ��� ����, ����(current) ��带 ����� �����ϴ�.
//////////////////////////////////////////////////////////
// ������, ������ ������
    List() = default;
    ~List();
//////////////////////////////////////////////////////////
//  interface �Լ�
    void nextNode();                        
    void currPointHead();

    Data* searchNode(Data*);
    List* deleteNode(Data*);
    List* insertNode(Data*);

    void printAllData();

    static lNode* initNode(Data*);
    void setHead(lNode* newHead);

    lNode* getCurrent();
    Data* getCurrentData();
    int length();


private:
    lNode* pHead = nullptr;
    lNode* pCurr = nullptr;
};
