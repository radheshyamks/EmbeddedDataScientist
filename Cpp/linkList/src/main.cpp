#include "../hdr/hdrlink.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdint>
typedef enum{
    INSERNODE=1,APPENDNODE,DELETENODE,DISPLAYLIST,CLEARLIST,
}NodeVal;
int main(int argc, char* argv[], char** env){
    DataLinkList::LinkList nodeObj;
    //NodeVal
    uint16_t ch;
    uint32_t val;
    uint32_t pos;
    bool True = false;
    while(!True){
        //INSERNODE,APPENDNODE,DELETENODE,DISPLAYLIST
        std::cout<<"1. insert node\n";
        std::cout<<"2. append node\n";
        std::cout<<"3. delete node\n";
        std::cout<<"4. display list\n";
        std::cout<<"5. clear list\n";
        std::cout<<"6. Exit loop\n";
        std::cout<<"Enter your choice: ";
        std::cin>>ch;
        // std::cout<<(int)ch<<"\n";
        switch(ch){
            case APPENDNODE:
                std::cout<<"Enter value: ";
                std::cin>>val;
                nodeObj.appendNode(val);
                break;
            case INSERNODE:
                std::cout<<"Enter value: ";
                std::cin>>val;
                nodeObj.insertNode(val);
                break;
            case DELETENODE:
                std::cout<<"Enter Position: ";
                std::cin>>pos;
                nodeObj.deleteNode(pos);
                break;
            case DISPLAYLIST:
                nodeObj.displayList();
                break;
            case CLEARLIST:
                nodeObj.clearList();
                break;
            default:
                std::cout<<"Exiting the loop\n";
                True=true;
                break;
        }
    }
    return EXIT_SUCCESS;
}