#include <iostream>
using namespace std;

struct Node {
    int no;           // Nomor
    string nim;       // NIM
    string nama;      // Nama
    string kelas;     // Kelas
    Node* next;       // Pointer ke node berikutnya
    Node* prev;       // Pointer ke node sebelumnya
};

void tambahData(Node*& head, int no, string nim, string nama, string kelas) {
    Node* baru = new Node{no, nim, nama, kelas, nullptr, nullptr};

    // Jika list kosong
    if (!head) {
        head = baru;
        head->next = head;
        head->prev = head;
        return;
    }

    Node* current = head;
    do {
        // Sisipkan berdasarkan urutan kelas
        if (current->kelas > kelas) {
            baru->next = current;
            baru->prev = current->prev;
            current->prev->next = baru;
            current->prev = baru;

            // Jika node baru berada sebelum head, update head
            if (current == head) head = baru;
            return;
        }
        current = current->next;
    } while (current != head);

    // Tambahkan di akhir jika kelas lebih besar dari semua node
    baru->next = head;
    baru->prev = head->prev;
    head->prev->next = baru;
    head->prev = baru;
}

void pecahBerdasarkanKelas(Node* head, Node*& headA, Node*& headB, Node*& headC) {
    if (!head) return;

    Node* current = head;
    do {
        if (current->kelas == "A") {
            tambahData(headA, current->no, current->nim, current->nama, current->kelas);
        } else if (current->kelas == "B") {
            tambahData(headB, current->no, current->nim, current->nama, current->kelas);
        } else if (current->kelas == "C") {
            tambahData(headC, current->no, current->nim, current->nama, current->kelas);
        }
        current = current->next;
    } while (current != head);
}

void tampil(Node* head) {
    if (!head) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Node* current = head;
    do {
        cout << "No: " << current->no
             << ", NIM: " << current->nim
             << ", Nama: " << current->nama
             << ", Kelas: " << current->kelas << endl;
        current = current->next;
    } while (current != head);  // Kembali ke node pertama
}

int main() {
    Node* head = nullptr;
    Node* headA = nullptr;
    Node* headB = nullptr;
    Node* headC = nullptr;

    // Tambahkan data awal
    tambahData(head, 1, "301230004", "Hilmi Nurpadilah", "B");
    tambahData(head, 2, "301230001", "Abdul Rachman Ibrahim", "A");
    tambahData(head, 3, "301230018", "Alpi Salman Alparisi", "C");

    // Tampilkan linked list utama
    cout << "Linked List Utama:" << endl;
    tampil(head);

    // Pecah berdasarkan kelas
    pecahBerdasarkanKelas(head, headA, headB, headC);

    // Tampilkan hasil pecahan
    cout << "\nLinked List Kelas A:" << endl;
    tampil(headA);

    cout << "\nLinked List Kelas B:" << endl;
    tampil(headB);

    cout << "\nLinked List Kelas C:" << endl;
    tampil(headC);

    return 0;
}
