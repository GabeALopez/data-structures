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

        void pushFront(int pKey)
        {

            addAtPosition(0,pKey);

        }

        Node* topFront()
        {

            if(head->next == NULL)
            {
                return NULL; 
            }           

            return head->next;

        }

        int popFront()
        {

            deleteAtPosition(0);

        }

        void addAtPosition(int position, int n)        
        {
 
            Node* prevNode = new Node();
            Node* currentNode = new Node();
            Node* temp = new Node();

            if(position == 0)
            {

                temp->key = n;
                temp->next = this->head;
                this->head = temp;

            }
            else
            {

                currentNode = this->head;
                for(int i = 0; i < position; i++)
                {

                    prevNode = currentNode;

                    if(currentNode->next == NULL)
                    {

                        cout << "Out of Bounds" << endl;
                        return;

                    }

                    currentNode = currentNode->next;


                }
                temp->key = n;
                temp->next = currentNode;
                prevNode->next = temp;

            }

            this->length++;

        }

        void deleteAtPosition(int position)
        {

            Node* preNode = new Node();
            Node* currentNode = new Node();
            currentNode = this->head;


            if(position == 0)
            {

                preNode = this->head;
                head = head->next;

            }
            else
            {

                for(int i = 0; i < position; i++)
                {

                    preNode = currentNode;

                    if(currentNode->next == NULL)
                    {

                        cout << "Out of Bounds" << endl;
                        return;

                    } 

                    currentNode = currentNode->next;


                }

                preNode->next = currentNode->next;

            }

            this->length--;

        }


        void pushBackKey(int pKey)
        {

            addAtPosition(length, pKey);

        }

        Node* topBack()
        {

            Node* newNode = this->head;
            for(int i = 0; i < length; i++)
            {

                newNode = newNode->next;

            }

            return newNode;


        }

        void popBack()
        {

            deleteAtPosition(this->length-1);

        }

        bool findKey(int pKey)
        {

           Node* findNode = this->head;
           for(int i = 0; i < length; i++)
           {

            
            if(findNode->key == pKey)
            {

                return true;

            }

            findNode = findNode->next;

           } 

           return false;

        }

};

int main()
{



}