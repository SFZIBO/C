#include <iostream>
using namespace std;

// Fungsi pencarian sequential dengan sentinel
int sequential_search_with_sentinel(int arr[], int size, int target) {
    // Menambahkan sentinel di akhir array
    arr[size] = target;

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    // Mengembalikan indeks jika ditemukan, atau -1 jika tidak ditemukan
    if (i < size) {
        return i;
    } else {
        return -1;
    }
}

int main() {
    int arr[] = {12, 5, 8, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    int result = sequential_search_with_sentinel(arr, size, target);

    if (result != -1) {
        cout << "Nilai ditemukan pada indeks ke-" << result << endl;
    } else {
        cout << "Nilai tidak ditemukan dalam array." << endl;
    }

    return 0;
}
