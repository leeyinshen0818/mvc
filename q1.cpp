#include<iostream>
using namespace std;

class Node
{
    public:
        int item;
        Node *next;
        
        Node(int d = 0)
        { 
          item = d;
          next = NULL;
        }
};

// To print the list of nodes from head to tail
void print(Node *head)
{
    Node *node = head;
    
    while (node)
    {
        cout << node->item << "\t";
        node = node->next;
    }
    cout << endl << endl;
}

int main()
{
    Node *head, *tail;
    
    head = tail = new Node(45);
    
    for (int n = 50; n <= 80; n += 5)
    {
        tail->next = new Node(n);
        tail = tail->next;
    }

    print(head);//original
    
    Node *node;

    //-------------------------------------------------
    // Task 1: Insert a new node (with the item = 111) at 
    // the end of the list
    tail->next = new Node(111);
    tail = tail->next;

    print(head);//with 111

    //-------------------------------------------------
    // Task 2: Insert a new node (with the item = 222) between 
    // node 65 and node 70
    node = head;
    while (node && node->item != 65) {
        node = node->next;
    }
    if (node && node->next) {
        Node *newNode = new Node(222);
        newNode->next = node->next;
        node->next = newNode;
    }

    print(head);//222 between 65 and 70
    
    //-------------------------------------------------  
    // Task 3: Delete the first node from the list
    node = head;
    head = head->next;
    delete node;

    print(head);//45 disappear
        
    //-------------------------------------------------   
    // Task 4: Swap the positions of the first and last nodes
    Node *prev = NULL, *last = head;
    while (last->next) {
        prev = last;
        last = last->next;
    }
    if (prev) {
        last->next = head->next;
        prev->next = head;
        head->next = NULL;
        head = last;
    }

    print(head);//swap 1st and last element
    
    //------------------------------------------------- 
    // Task 5: Find a node in the list with the number that 
    // you have entered
    int num;
    bool found = false;  
 
    cout << "Enter a number that you want to find in the list: ";
    cin >> num;
    
    node = head;
    while (node) {
        if (node->item == num) {
            found = true;
            break;
        }
        node = node->next;
    }

    cout << num;
    if (found)
        cout << " is in the list" << endl;
    else
        cout << " is NOT in the list" << endl;
    
    return 0;    
}
