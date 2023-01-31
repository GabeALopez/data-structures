#include <iostream>
#include <cstdlib>

using namespace std;

//class that holds a node
class Node
{

    public:
        Node* next;
        int key;

};


//main linked list class
class linkedList
{

    private:
        //adds a node at a partciular point
        void addAtPosition(int position, int n)        
        {
 
            //nodes that are need to iterate through list
            Node* prevNode = new Node();
            Node* currentNode = new Node();
            Node* temp = new Node();

            //put node if it is at position 0
            if(position == 0)
            {

                temp->key = n;
                temp->next = this->head;
                this->head = temp;

            }
            //put node at n position
            else
            {

                currentNode = this->head;
                for(int i = 0; i < position; i++)
                {

                    prevNode = currentNode;
                    currentNode = currentNode->next;


                }
                temp->key = n;
                temp->next = currentNode;
                prevNode->next = temp;

            }

            //increase the length
            this->length++;

        }

        //same as addAtPosition but for deleting
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
                    currentNode = currentNode->next;


                }

                preNode->next = currentNode->next;

            }

            this->length--;

        }
    
    public:
        //hold the length and create the head of the linked list
        int length;
        Node* head;

        //creates an initial linked list
        linkedList()
        {

            length = 0;
            head = NULL;

        }        

        //create a new node at the beginning
        void pushFront(int pKey)
        {

            addAtPosition(0,pKey);

        }

        //return the beginning node
        void topFront()
        {

            if(head->next == NULL)
            {
                cout << "NULL" << endl; 
            }           

            cout << head->key << endl;;

        }

        //delete the beginning node 
        int popFront()
        {

            deleteAtPosition(0);

        }

        

        //add a node at the end of the list
        void pushBack(int pKey)
        {

            addAtPosition(length, pKey);

        }

        //return the node at the end of the list
        void topBack()
        {

            Node* newNode = this->head;
            for(int i = 0; i < length-1; i++)
            {

                newNode = newNode->next;

            }

            cout << newNode->key << endl;


        }

        //delete the node at the end of the list
        void popBack()
        {

            deleteAtPosition(this->length-1);

        }

        //finds if key is within list
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

        //checks if list is empty
        bool empty()
        {

            if(head == NULL)
            {

                return true;

            }
            else
            {

                return false;

            }

        }

        //adds node before a specified position
        void addBefore(int pNode, int pKey)
        {

            addAtPosition(pNode, pKey);

        }

        //adds node after a specified position
        void addAfter(int pNode, int pKey)
        {

           addAtPosition(pNode+1, pKey); 

        }



        //returns size of list
        int size()
        {

            return length;

        }

        //displays all values in list
        void displayAll()
        {

            Node *newNode = this->head;

            int i = 1;

            while(newNode)
            {

                cout << newNode->key << endl;
                newNode = newNode->next;
                i++;

            }


        }

        //replaces a key with a new key
        void replaceKey(int pNode, int pKey)
        {

            Node* prevNode = new Node();
            Node* currentNode = new Node();

            if(pNode == 0)
            {

                this->head->key = pKey;                 

            }
            else
            {

                currentNode = this->head;
                for(int i = 0; i < pNode; i++)
                {

                    prevNode = currentNode;
                    currentNode = currentNode->next; 


                }

                prevNode->key = pKey;
            }

        }



};

int main()
{

    //implementation
    linkedList list;    

    //push values into list
    list.pushFront(25); 
    list.pushFront(50); 
    list.pushFront(90); 
    list.pushFront(40); 
    list.pushBack(35); 

    list.displayAll();
    cout << endl;

    list.topFront();

    cout << endl;

    list.topBack();

    cout << endl;

    list.popFront();
    list.displayAll();

    cout << endl;

    list.popBack();
    list.displayAll();

    cout << endl;

    //replacing values
    list.pushBack(10);
    list.pushBack(12);
    list.pushBack(14);
    list.displayAll();

    cout << endl;

    //running find key checks
    if(list.findKey(25))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    if(list.findKey(6))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    //check if empty
    if(list.empty())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    cout << endl;

    //adding nodes, returning size, and replacing key
    list.addBefore(3,94);

    list.displayAll();

    cout << endl;

    list.addAfter(2,5);
    list.displayAll();

    cout << endl;

    list.size();

    cout << endl;

    list.replaceKey(6,87);

    list.displayAll();

    cout << endl;

    //poping them all values off
    list.popFront();
    list.popFront();
    list.popFront();
    list.popFront();
    list.popFront();
    list.popFront();
    list.popFront();
    list.popFront();


    if(list.empty())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }


}