#pragma once
#include <memory>
using namespace std;

class Data {
public:
//////////////////////////////////////////////////////////////
// 리스트연산을 위해 필요한 Data의 함수들. 그 명세.
    virtual bool operator==(const Data&) = 0;

    virtual void setData(const Data&) = 0;
    virtual bool compare(const Data&) = 0;
    virtual void printData() = 0;
    virtual void printLable() = 0;
    
};
class lNode {                    
public:              // 리스트의 노드들입니다. 
///////////////////////////////////////////////////////////////
// 생성자 및 연산자
    lNode() = default;                     
    ~lNode(){}                                                                
    lNode* operator=(const lNode* rhs);
    bool operator==(const lNode* rhs);
///////////////////////////////////////////////////////////////
// 사용자 함수
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
public:                                     // 리스트의 헤드입니다. 헤드 노드와, 현재(current) 노드를 멤버로 갖습니다.
//////////////////////////////////////////////////////////
// 생성자, 연산자 재정의
    List() = default;
    ~List();
//////////////////////////////////////////////////////////
//  interface 함수
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
