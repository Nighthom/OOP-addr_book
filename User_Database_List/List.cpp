#include "List.h"
/////////////////////////////////////////////////////////////
// Node�� ������ // ������
lNode* lNode::operator=(const lNode* rhs) {
    pData = rhs->pData;
    pNext = rhs->pNext;
    return this;
}
bool lNode::operator==(const lNode* rhs) {                                      // ����񱳿���. Data�� �����ڸ� �����´�. 
    return pData == rhs->pData ? true : false;
}
/////////////////////////////////////////////////////////////
// Node�� �޼���
lNode* lNode::getNext() {
    return pNext;
}
Data* lNode::getData() {
    return pData;
}

bool lNode::compare(const lNode* rhs) {
    return this == rhs;                                                         // ����񱳿� �Լ�. Data�� �����ڸ� �����´�.  
}
void lNode::setNext(const lNode* setArg) {
    pNext = const_cast<lNode*>(setArg);
}
void lNode::setData(const Data* setArg) {
    pData = const_cast<Data*>(setArg);
}
/////////////////////////////////////////////////////////////
// List�� ������, �Ҹ���
List::~List() {                 // �Ҹ��ڴ� ��� ����Ʈ�� �����Ѵ�.
    pCurr = pHead;
    while (pCurr != nullptr) {
        pCurr = pHead->getNext();
        delete pHead;
        pHead = pCurr;
    }
}

//////////////////////////////////////////////////////////////////
// List�� �޼���

void List::nextNode() {
    pCurr = pCurr->getNext();
}

Data* List::searchNode(Data* search) {                // curr��� ������� �� ã��.    
    while (pCurr != nullptr) {
        if (*(pCurr->getData()) == *search)
            return pCurr->getData();
        nextNode();
    }
    currPointHead();
    throw "�˻��Ϸ��� �����Ͱ� �����ϴ�. ������ �����մϴ�.";
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
List* List::insertNode(Data* insert) {                 // DataŸ���� �������̽��κ��� ���޹޾Ƽ�, �Է��ϴ� �޼���.
    lNode* newNode = initNode(insert);

    if (pHead == nullptr) {                              // ���� ����Ʈ�� ������� ���
        setHead(newNode);
        return this;
    }
    while (pCurr->getNext() != nullptr) {
        if (pCurr->getData() == insert)
            throw "�̹� �ִ� ���Դϴ�. �ٸ����� ������ �ּ���. ";
        nextNode();
    }

    pCurr->setNext(newNode);

    currPointHead();
    return this;
}

List* List::deleteNode(Data* del) {                    // ���� ���� �����ͼ� ��带 ã�� ��, �ش� ��� ����.
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
    throw "�����Ϸ��� �����Ͱ� �������� �ʽ��ϴ�.";
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
// ������ �ܼ��� �Լ���.
Data* List::getCurrentData() {
    return pCurr->getData();
}
void List::currPointHead() {
    pCurr = pHead;
}
lNode* List::getCurrent() {
    return pCurr;
}