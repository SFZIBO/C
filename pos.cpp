#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int id;
    string nama;
    double harga;
    int stok;
    Node* next;
};

// Head pointer untuk linked list
Node* head = nullptr;

void bacaCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Gagal membuka file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, nama, hargaStr, stokStr;

        getline(ss, idStr, ',');
        getline(ss, nama, ',');
        getline(ss, hargaStr, ',');
        getline(ss, stokStr, ',');

        int id = stoi(idStr);
        double harga = stod(hargaStr);
        int stok = stoi(stokStr);

        // Tambahkan data ke linked list
        Node* baru = new Node{id, nama, harga, stok, nullptr};
        if (!head) {
            head = baru;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = baru;
        }
    }

    file.close();
}

void tampilBarang() {
    if (!head) {
        cout << "Daftar barang kosong." << endl;
        return;
    }

    Node* temp = head;
    cout << "ID\tNama\t\tHarga\tStok" << endl;
    while (temp) {
        cout << temp->id << "\t" << temp->nama << "\t\t" << temp->harga << "\t" << temp->stok << endl;
        temp = temp->next;
    }
}

void cariBarang(int id) {
    Node* temp = head;
    while (temp) {
        if (temp->id == id) {
            cout << "Barang ditemukan:" << endl;
            cout << "ID: " << temp->id << ", Nama: " << temp->nama
                 << ", Harga: " << temp->harga << ", Stok: " << temp->stok << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Barang dengan ID " << id << " tidak ditemukan." << endl;
}

void tambahBarang(int id, const string& nama, double harga, int stok) {
    // Tambahkan data ke linked list
    Node* baru = new Node{id, nama, harga, stok, nullptr};
    if (!head) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Barang berhasil ditambahkan!" << endl;

    // Tambahkan data ke file CSV
    ofstream file("data_barang.csv", ios::app); // Mode append
    if (!file.is_open()) {
        cout << "Gagal membuka file untuk menyimpan data." << endl;
        return;
    }
    file << id << "," << nama << "," << harga << "," << stok << endl;
    file.close();
}


void hapusBarang(int id) {
    if (!head) {
        cout << "Daftar barang kosong." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp) {
        if (temp->id == id) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp;
            cout << "Barang dengan ID " << id << " berhasil dihapus." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Barang dengan ID " << id << " tidak ditemukan." << endl;
}

int main() {
    int pilihan;
    string filename = "data_barang.csv"; // File CSV

    // Membaca data barang dari file CSV
    bacaCSV(filename);

    do {
        cout << "\n=== Toko POS ===" << endl;
        cout << "1. Tampilkan Barang" << endl;
        cout << "2. Cari Barang" << endl;
        cout << "3. Tambah Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilBarang();
                break;
            case 2: {
                int id;
                cout << "Masukkan ID Barang: ";
                cin >> id;
                cariBarang(id);
                break;
            }
            case 3: {
                int id, stok;
                string nama;
                double harga;
                cout << "Masukkan ID: ";
                cin >> id;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Harga: ";
                cin >> harga;
                cout << "Masukkan Stok: ";
                cin >> stok;
                tambahBarang(id, nama, harga, stok);
                break;
            }
            case 4: {
                int id;
                cout << "Masukkan ID Barang yang akan dihapus: ";
                cin >> id;
                hapusBarang(id);
                break;
            }
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
