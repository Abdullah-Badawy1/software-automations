/*=================================================*/
/*=================================================*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {}

    Node* Insert(Node* pNode, int item) {
        if (pNode == nullptr) {
            return new Node(item);
        } else if (item < pNode->data) {
            pNode->left = Insert(pNode->left, item);
        } else {
            pNode->right = Insert(pNode->right, item);
        }
        return pNode;
    }

    void insertItems(int items) {
        root = Insert(root, items);
    }

    void pre_Order(Node* pNode) {
        if (pNode == nullptr)
            return;
        cout << pNode->data << "\t";
        pre_Order(pNode->left);
        pre_Order(pNode->right);
    }

    void In_Order(Node* pNode) {
        if (pNode == nullptr)
            return;
        In_Order(pNode->left);
        cout << pNode->data << "\t";
        In_Order(pNode->right);
    }

    void Post_Order(Node* pNode) {
        if (pNode == nullptr)
            return;
        Post_Order(pNode->left);
        Post_Order(pNode->right);
        cout << pNode->data << "\t";
    }

    Node* Search(Node* pNode, int key) {
        if (pNode == nullptr || pNode->data == key) {
            return pNode;
        }
        if (key < pNode->data) {
            return Search(pNode->left, key);
        }
        return Search(pNode->right, key);
    }

    bool SearchItem(int key) {
        return Search(root, key) != nullptr;
    }

    Node* findMin(Node* pNode) {
        if (pNode == nullptr)
            return nullptr;
        while (pNode->left != nullptr) {
            pNode = pNode->left;
        }
        return pNode;
    }

    Node* findMax(Node* pNode) {
        if (pNode == nullptr)
            return nullptr;
        while (pNode->right != nullptr) {
            pNode = pNode->right;
        }
        return pNode;
    }

    Node* Delet(Node* pNode, int key) {
        if (pNode == nullptr)
            return nullptr;

        if (key < pNode->data) {
            pNode->left = Delet(pNode->left, key);
        } else if (key > pNode->data) {
            pNode->right = Delet(pNode->right, key);
        } else {
            if (pNode->left == nullptr) {
                Node* temp = pNode->right;
                delete pNode;
                return temp;
            } else if (pNode->right == nullptr) {
                Node* temp = pNode->left;
                delete pNode;
                return temp;
            }
            Node* temp = findMin(pNode->right);
            pNode->data = temp->data;
            pNode->right = Delet(pNode->right, temp->data);
        }
        return pNode;
    }
};

int main() {
    Tree tree;
    tree.insertItems(45);
    tree.insertItems(15);
    tree.insertItems(79);
    tree.insertItems(90);
    tree.insertItems(10);
    tree.insertItems(55);
    tree.insertItems(12);
    tree.insertItems(20);
    tree.insertItems(50);

    cout << "Pre-order traversal: ";
    tree.pre_Order(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.Post_Order(tree.root);
    cout << endl;

    cout << "In-order traversal: ";
    tree.In_Order(tree.root);
    cout << endl;

    int key = 45;
    if (tree.SearchItem(key)) {
        cout << "Item " << key << " found." << endl;
    } else {
        cout << "Item " << key << " not found." << endl;
    }

    Node* minNode = tree.findMin(tree.root);
    if (minNode != nullptr) {
        cout << "Minimum value in the tree: " << minNode->data << endl;
    } else {
        cout << "No items exist." << endl;
    }

    Node* maxNode = tree.findMax(tree.root);
    if (maxNode != nullptr) {
        cout << "Maximum value in the tree: " << maxNode->data << endl;
    } else {
        cout << "No items exist." << endl;
    }

    tree.Delet(tree.root, 12);
    cout << "After deletion of 12: ";
    tree.pre_Order(tree.root);

    return 0;
}
/*============================================*/
/*============================================*/

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
};

class Queue {
public:
    Node* Front;
    Node* Rear;

    Queue() : Front(nullptr), Rear(nullptr) {}

    bool isEmpty() {
        return Front == nullptr;
    }

    void Enqueue(int item) {
        Node* new_node = new Node();
        new_node->data = item;
        new_node->next = nullptr;
        if (isEmpty()) {
            Front = Rear = new_node;
        } else {
            Rear->next = new_node;
            Rear = new_node;
        }
    }

    void Display() {
        if (isEmpty()) {
            cout << "Queue Is Empty" << endl;
            return;
        }
        Node* temp = Front;
        while (temp != nullptr) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    int Dequeue() {
        if (isEmpty()) {
            cout << "The Queue Is Empty" << endl;
            return -1;
        }
        int delvalue = Front->data;
        Node* delptr = Front;
        Front = Front->next;
        delete delptr;
        if (Front == nullptr) {
            Rear = nullptr;
        }
        return delvalue;
    }

    bool isFound(int item) {
        Node* temp = Front;
        while (temp != nullptr) {
            if (temp->data == item) {
                cout << "Found" << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Not Found" << endl;
        return false;
    }

    void Clear() {
        while (!isEmpty()) {
            Dequeue();
        }
    }
};

int main() {
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Display();

    q.Dequeue();
    q.Display();

    q.isFound(20);

    cout << "After clear:" << endl;
    q.Clear();
    q.Display();

    return 0;
}
/*======================================*/
/*=====================================*/
#include <iostream>

using namespace std;
int func(int *p)
{
    *p = *p+1 ;
    return *p ;
}
int main()
{

    int f = 1 ;

   int r =  func(&f) ;
   cout<<r<<endl;
   cout<<func(&r)<<endl;

    ////func //////


   int x = 20 ;
   int *ptr = &x;
   float y =5.5;

   cout<<*ptr<<endl;

///   int *ptr2 = &y ;  ====> Not same as the data type

  // cout<<*ptr2;

  void *ptr2 ;
  ptr2 = &y ;
  float i =static_cast<float>(ptr2);
  cout<<*i<<endl ;

  /////convert from void type to float type through static_cast<float*>
  int arr[5] = {10,20,30,40,50} ;
cout<<"Print the First Element Plus i value " <<endl ;
  for(int i = 0 ; i<5 ;i++)
  {
     cout<<*arr +i<<endl;
  }

cout<<"Print Array Element " <<endl ;
for(int i = 0 ; i<5 ;i++)
  {
     cout<<*(arr + i)<<endl;
  }
/*===================================================*/
/*===================================================*/
#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAtPosition(int data, int position) {
        if (position <= 0) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;

        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteNode(int data) {
        if (head == nullptr) {
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    int getLength() {
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            ++length;
            current = current->next;
        }
        return length;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(3);
    list.insertAtBeginning(4);

    std::cout << "Linked List before deletion: ";
    list.printList();

    list.deleteNode(3);

    std::cout << "Linked List after deletion: ";
    list.printList();

    list.insertAtEnd(5);

    std::cout << "Linked List after insertion at end: ";
    list.printList();

    list.insertAtPosition(10, 2);

    std::cout << "Linked List after insertion at position 2: ";
    list.printList();

    std::cout << "Length of the Linked List: " << list.getLength() << std::endl;

    return 0;
}
/*=================================================*/
/*=================================================*/
#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        Node* current = top;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack Underflow" << std::endl;
            return -1; // Assuming -1 represents an error condition
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            return -1; // Assuming -1 represents an error condition
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element of stack: " << stack.peek() << std::endl;

    std::cout << "Elements popped from stack: ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}
