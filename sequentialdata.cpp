#include <iostream>
#include <string>
using namespace std;
struct Rekaman {
    int nomorinduk;
    string nama;
    string alamat;
    char golongan;
};
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
    int target_nomorinduk;
    cout << "Nomor Induk : ";
    cin >> target_nomorinduk;

    Rekaman* found_record = linear_search(records, 10, target_nomorinduk);

    display_record(found_record);

    return 0;
}
