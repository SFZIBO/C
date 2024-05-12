#include <iostream>
using namespace std;

// Fungsi pencarian sequential tanpa sentinel
int sequential_search_sorted(int arr[], int size, int target) {
    int i = 0;
    while (i < size && arr[i] < target) {
        i++;
    }

    // Mengembalikan indeks jika ditemukan, atau -1 jika tidak ditemukan
    if (i < size && arr[i] == target) {
        return i;
    } else {
        return -1;
    }
}

int main() {
    int arr[] = {3, 5, 7, 9, 12, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    int result = sequential_search_sorted(arr, size, target);

    if (result != -1) {
        cout << "Nilai ditemukan pada indeks ke-" << result << endl;
    } else {
        cout << "Nilai tidak ditemukan dalam array." << endl;
    }

    return 0;
}
