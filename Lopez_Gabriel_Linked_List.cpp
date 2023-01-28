#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{

    public:
        Node* next;
        int key;

};


class linkedList
{

    public:
        int length;
        Node* head;

        linkedList()
        {

            length = 0;
            head = NULL;

        }        

        void pushFront(int pkey)
        {

           Node* temp = new Node();
           temp->key = pkey;
           temp->next = this->head;
           this->head = temp;
           this->length++;


        }

        int keyTopFront()
        {

            return this->head->key;

        }

        int popFront()
        {
            if(head->next == NULL)
            {
                return NULL; 
            }

            int temp = head->key;
            head = head->next;
            this->length--;
            return temp;

        }

};

int main()
{



}