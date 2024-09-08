#include "../hdr/hdrlink.hpp"
#include <iostream>
#include <string>
// struct DataLink{
// uint32_t data; /* The value in this node */
// struct DataLink*Next; /* To point to the Next node */
// };DataLink
// struct DataLink*head; /* List head pointer */        
DataLinkList::LinkList::LinkList(){
    head = nullptr;
}
DataLinkList::LinkList::LinkList(DataLink*initPtr){
    head = initPtr;
}
DataLinkList::LinkList::~LinkList(){
    DataLink*p = head;
    std::cout<<"Destructor\n";
    while(p!=nullptr){
        head=p->Next;
        delete p;
        p = head;
    }
}
DataLinkList::LinkList::DataLink* 
DataLinkList::LinkList::NodeCreation(uint32_t val){
    DataLink*nodePtr;
    nodePtr = new DataLink;
    if(nodePtr!=nullptr){
        nodePtr->data = val;
        nodePtr->Next = nullptr;
        return nodePtr;
    }
    return nullptr;
}
void DataLinkList::LinkList::appendNode(uint32_t val){}
void DataLinkList::LinkList::insertNode(uint32_t val){
    DataLink*nodePtr = NodeCreation(val);
    if(head==nullptr && nodePtr!=nullptr){
        head = nodePtr;
    }else if(nodePtr!=nullptr){
        DataLink*tmpPtr = head;
        while(tmpPtr->Next!=nullptr){
            tmpPtr = tmpPtr->Next;
        }
        tmpPtr->Next = nodePtr;
    }else{
        std::cout<<"memory not allocated\n";
    }
}
void DataLinkList::LinkList::deleteNode(uint32_t pos){
    if(head==nullptr){
        std::cout<<"List is Empty\n";
        return;
    }else{
        DataLink*tmpPtr = head;
        DataLink*tmp = head;
        uint16_t cnt=0;
        while(tmp){
            tmp = tmpPtr->Next;
            cnt++;
            if(cnt==pos){}
            tmpPtr = tmp;
        }
        return;
    }
}
void DataLinkList::LinkList::displayList(void)const{
    if(head==nullptr){
        std::cout<<"List is Empty\n";
    }else{
        DataLink*tmpPtr  = head;
        while(tmpPtr!=nullptr){
            std::cout<<tmpPtr->data<<" ";
            tmpPtr = tmpPtr->Next;
        }
        std::cout<<"\n";
    }
}
void DataLinkList::LinkList::clearList(void){
    if(head==nullptr){
        std::cout<<"List is Empty\n";
    }else{
        DataLink* tmpPtr = head;
        while(tmpPtr){
            DataLink* tmp = tmpPtr->Next;
            delete tmpPtr;
            tmpPtr = tmp;
        }
        if(tmpPtr==nullptr)head=nullptr;
    }
}