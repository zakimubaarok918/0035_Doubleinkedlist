#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // step 1: Allocate memory for new node
        Node *newNode = new Node();

        // step 2: Assign value to the data fields
        newNode->noMhs = nim;
        
        // step 3: Insert at beginning if list is empty or nim is smallest
        if(START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // step 4: newNode.next = START
            newNode->next = START;

            // step 5: START.prev = newNode (if START exists)
            if (START != NULL)
                START->prev = newNode;

            // step 6: newNode.prev = NULL
            newNode->prev = NULL;
            
            // step 7: START = newNode
            START = newNode;
            return;
        }

        // insert in between node 
        // step 8: Locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != Null && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // step 9; Insert between current and current->next
        newNode->next = current->next; // Step 9a: newNode.next = current.next
        newNode->prev = current;       // Step 9b: newNode.prev = current

        // insert last node
        if (current->next != NULL)
            current->next->prev = newNode; // Steo 9c: current.next.prev = newNode

        current->next = newNode; // Step 9d: current.next = newNode    
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse the list to find the node
        while (current != NULL && current->NoMhs != rollno)
            current = current->next;

        if (current == NULL)
        {
            START + current->next; // Step 2a: START = START.next
            if (START != NULL)
                START->prev = NULL; // Step 2b: START.prev = NULL
        }
        else
        {
            current->prev->next = current->next;

            if(current->next != NULL)
               current->next->prev = current->prev;
        }    

        delete current;
        cout << "Record with roll number " << rollNO << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }


        Node *currentNode = START;
        
        cout << "\nRecords in ascending order of roll number are:\n";
        int i =0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        Node *currentNode = currentNode->next;
        i++;
    }

    cout << "\nRecords in descending order of roll number are:\n:";
    while (currentNode != NULL)
    {
        currentNode = currentNode->next;
        i++;
    }

    cout << "\nRecords in descending order of roll number are:\n";
    while (currentNode != NULL)
    {
        cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

        currentNode = currentNode->prev;
        i++;
    }
}

void searchData()