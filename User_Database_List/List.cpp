#include "List.h"
/////////////////////////////////////////////////////////////
// Node의 연산자 // 생성자
lNode* lNode::operator=(const lNode* rhs) {
    pData = rhs->pData;
    pNext = rhs->pNext;
    return this;
}
bool lNode::operator==(const lNode* rhs) {                                      // 동등비교연산. Data의 연산자를 빌려온다. 
    return pData == rhs->pData ? true : false;
}
/////////////////////////////////////////////////////////////
// Node의 메서드
lNode* lNode::getNext() {
    return pNext;
}
Data* lNode::getData() {
    return pData;
}

bool lNode::compare(const lNode* rhs) {
    return this == rhs;                                                         // 동등비교용 함수. Data의 연산자를 빌려온다.  
}
void lNode::setNext(const lNode* setArg) {
    pNext = const_cast<lNode*>(setArg);
}
void lNode::setData(const Data* setArg) {
    pData = const_cast<Data*>(setArg);
}
/////////////////////////////////////////////////////////////
// List의 생성자, 소멸자
List::~List() {                 // 소멸자는 모든 리스트를 삭제한다.
    pCurr = pHead;
    while (pCurr != nullptr) {
        pCurr = pHead->getNext();
        delete pHead;
        pHead = pCurr;
    }
}

//////////////////////////////////////////////////////////////////
// List의 메서드

void List::nextNode() {
    pCurr = pCurr->getNext();
}

Data* List::searchNode(Data* search) {                // curr노드 기반으로 값 찾기.    
    while (pCurr != nullptr) {
        if (*(pCurr->getData()) == *search)
            return pCurr->getData();
        nextNode();
    }
    currPointHead();
    throw "검색하려는 데이터가 없습니다. 연산을 종료합니다.";
    return nullptr;
}
lNode* List::initNode(Data* insert) {
    lNode* newNode = new lNode;
    newNode->setData(insert);
    newNode->setNext(nullptr);

    return newNode;
}
void List::setHead(lNode* newHead) {
    pHead = newHead;
    pCurr = newHead;
}
List* List::insertNode(Data* insert) {                 // Data타입을 인터페이스로부터 전달받아서, 입력하는 메서드.
    lNode* newNode = initNode(insert);

    if (pHead == nullptr) {                              // 현재 리스트가 비어있을 경우
        setHead(newNode);
        return this;
    }
    while (pCurr->getNext() != nullptr) {
        if (pCurr->getData() == insert)
            throw "이미 있는 값입니다. 다른값을 삽입해 주세요. ";
        nextNode();
    }

    pCurr->setNext(newNode);

    currPointHead();
    return this;
}

List* List::deleteNode(Data* del) {                    // 지울 값을 가져와서 노드를 찾은 후, 해당 노드 삭제.
    lNode* next, * delNode;
    while (1) {
        if (*(pHead->getData()) == *del) {
            delNode = pHead;
            pHead = pHead->getNext();
            currPointHead();
            delete delNode;
            return this;
        }
        next = pCurr->getNext();
        if (next == nullptr)
            break;
        if (*(next->getData()) == *del) {
            delNode = next;
            pCurr->setNext(delNode->getNext());
            delete delNode;
            currPointHead();
            return this;
        }
        nextNode();
    }
    // TODO throw Delete_Data_Missing;
    throw "삭제하려는 데이터가 존재하지 않습니다.";
    return nullptr;
}

int List::length() {
    int len = 1;
    while (pCurr->getData() == nullptr) {
        nextNode();
        len++;
    }
    currPointHead();
    return len;
}


void List::printAllData() {
    while (pCurr != nullptr) {
        getCurrentData()->printLable();
        getCurrentData()->printData();
        nextNode();
    }
    currPointHead();
}

///////////////////////////////////////////
// 구조가 단순한 함수들.
Data* List::getCurrentData() {
    return pCurr->getData();
}
void List::currPointHead() {
    pCurr = pHead;
}
lNode* List::getCurrent() {
    return pCurr;
}