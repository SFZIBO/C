#include <iostream>
using namespace std;

// Fungsi pencarian sequential
int sequential_search(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

int main() {
    int arr[] = {12, 5, 8, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    int result = sequential_search(arr, size, target);

    if (result != -1) {
        cout << "Nilai ditemukan pada indeks ke-" << result << endl;
    } else {
        cout << "Nilai tidak ditemukan dalam array." << endl;
    }

    return 0;
}
