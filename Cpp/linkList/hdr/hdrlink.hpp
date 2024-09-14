/*************************************************************************
* Author Name: Radheshyam Kumar Singh
* Date: 08-Sept-2024
* File Name: hdrlink.hpp
* File Description: This file is having the link list class private member
*                   staruct Datalink and that Datalink structure having 
*                   data and a pointer name Next, this Next pointer is a self referencial pointer.
*                   A public pointer Head pointing to structure DataLink.
**************************************************************************/
#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <cstdint>
namespace DataLinkList{
    class LinkList{
        private:
            /* Declared a structure for the nodes */
            typedef struct DataLink{
                uint32_t data; /* The value in this node */
                struct DataLink*Next; /* To point to the Next node */
            }DataLink;
            uint16_t listEleCnt;
            DataLink*head; /* List head pointer */
        public:
            /* struct DataLink*Head=nullptr; */
            /* Constructor */
            LinkList();
            LinkList(DataLink*initPtr);
            /* Destructor */
            ~LinkList();

            /* Link list operation */
            DataLink*NodeCreation(uint32_t val);
            void appendNode(uint32_t val);
            void insertNode(uint32_t val);
            void deleteNode(uint32_t pos);
            void displayList(void)const;
            void clearList(void);
    };
}
#endif //NUMBERLIST_H
