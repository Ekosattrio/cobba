#include <iostream>

// Definisi struktur node
struct Node {
    int data;
    Node* next;
    
    // Konstruktor
    Node(int value) : data(value), next(nullptr) {}
};

// Kelas untuk linked list
class LinkedList {
private:
    Node* head; // Pointer ke node pertama
    
public:
    // Konstruktor
    LinkedList() : head(nullptr) {}
    
    // Fungsi untuk mengakses node pertama (head)
    Node* getHead() const {
        return head;
    }
    
    // Fungsi untuk menyisipkan node setelah node tertentu
    void insertAfter(Node* prevNode, int value) {
        if (prevNode == nullptr) {
            std::cerr << "Node sebelumnya tidak boleh kosong\n";
            return;
        }
        
        Node* newNode = new Node(value); // Buat node baru dengan data tertentu
        newNode->next = prevNode->next; // Atur pointer next node baru ke node setelahnya
        prevNode->next = newNode; // Atur pointer next node sebelumnya ke node baru
    }
    
    // Fungsi untuk menambahkan node di awal linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    
    // Fungsi untuk mencetak linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Membuat objek linked list
    LinkedList myList;
    
    // Menambahkan beberapa node ke linked list
    myList.insertAtBeginning(1);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(3);
    
    std::cout << "Linked List awal: ";
    myList.printList();
    
    // Menemukan node sebelumnya (dalam kasus ini node dengan data 2)
    Node* prevNode = myList.getHead()->next;
    
    // Menyisipkan node baru setelah node sebelumnya
    myList.insertAfter(prevNode, 4);
    
    std::cout << "Linked List setelah penyisipan: ";
    myList.printList();
    
    return 0;
}
