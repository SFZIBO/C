#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Rekaman {
    int nomorinduk;
    string nama;
    string alamat;
    char golongan;
};

bool compare_nomorinduk(const Rekaman &a, const Rekaman &b) {
    return a.nomorinduk < b.nomorinduk;
}

bool compare_nama(const Rekaman &a, const Rekaman &b) {
    return a.nama < b.nama;
}

bool compare_golongan(const Rekaman &a, const Rekaman &b) {
    return a.golongan < b.golongan;
}

Rekaman* linear_search(Rekaman records[], int size, int target_nomorinduk) {
    for (int i = 0; i < size; ++i) {
        if (records[i].nomorinduk == target_nomorinduk) {
            return &records[i];
        }
    }
    return nullptr;
}

void display_record(Rekaman* record) {
    if (record) {
        cout << "Nomor Induk: " << record->nomorinduk << endl;
        cout << "Nama: " << record->nama << endl;
        cout << "Alamat: " << record->alamat << endl;
        cout << "Golongan: " << record->golongan << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

int main() {
    Rekaman records[10] = {
        {101, "Asep", "Jl. Merdeka No. 10", 'A'},
        {202, "Dadang", "Jl. Jenderal Sudirman No. 5", 'B'},
        {303, "Andi", "Jl. Pahlawan No. 15", 'C'},
        {404, "Sakinah", "Jl. Asia Afrika No. 20", 'D'},
        {505, "Udin", "Jl. Gatot Subroto No. 25", 'E'},
        {606, "Mamat", "Jl. Diponegoro No. 30", 'F'},
        {707, "Eva", "Jl. Hayam Wuruk No. 35", 'G'},
        {808, "Jajang", "Jl. Gajah Mada No. 40", 'H'},
        {909, "Cecep", "Jl. Ahmad Yani No. 45", 'I'},
        {1010, "Ubed", "Jl. Thamrin No. 50", 'J'}
    };
    
    int pilihan;
    cout << "Pilih metode pengurutan (1: nomorinduk, 2: nama, 3: golongan): ";
    cin >> pilihan;

    bool (*compare_function)(const Rekaman&, const Rekaman&);
    if (pilihan == 1) {
        compare_function = compare_nomorinduk;
    } else if (pilihan == 2) {
        compare_function = compare_nama;
    } else if (pilihan == 3) {
        compare_function = compare_golongan;
    } else {
        cout << "Pilihan tidak valid. Pengurutan tidak dilakukan." << endl;
        return 0;
    }

    // Mengurutkan records berdasarkan pilihan pengguna
    sort(records, records + 10, compare_function);

    // Menampilkan hasil pengurutan
    for (int i = 0; i < 10; ++i) {
        cout << "Nomor Induk: " << records[i].nomorinduk << ", Nama: " << records[i].nama << ", Golongan: " << records[i].golongan << endl;
    }

    return 0;
}
