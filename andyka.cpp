// no 1

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void selectionSort(vector<pair<string, string>>& data) {
    int n = data.size();
    for (int i = 0; i < n-1; i++) {
        int indexterkecil = i;
        for (int j = i+1; j < n; j++) {
            if (data[j].first < data[indexterkecil].first) {
                indexterkecil = j;
            }
        }
        if (indexterkecil != i) {
            swap(data[indexterkecil], data[i]);
        }
    }
}

void printTable(const vector<pair<string, string>>& data) {
    const int lbrNama = 15;
    const int lbrAlamat = 20;
    const int totalLebar = lbrNama + lbrAlamat + 7;

    cout << "+";
    cout << string(totalLebar - 2, '-') << "+\n";

    cout << "| " << left << setw(lbrNama) << "Nama" 
         << " | " << setw(lbrAlamat) << "Alamat" << " |\n";

    cout << "+";
    cout << string(totalLebar - 2, '-') << "+\n";

    for (const auto& item : data) {
        cout << "| " << left << setw(lbrNama) << item.first
             << " | " << setw(lbrAlamat) << item.second << " |\n";
    }

    cout << "+";
    cout << string(totalLebar - 2, '-') << "+\n";
}

int main() {
    vector<pair<string, string>> data = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    selectionSort(data);
    cout << "Data yang telah diurutkan menggunakan Selection Sort:\n";
    printTable(data);

    return 0;
}



#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void bubbleSort(vector<pair<string, string>>& data) {
    int n = data.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (data[j].first > data[j+1].first) {
                swap(data[j], data[j+1]);
            }
        }
    }
}


void printTable(const vector<pair<string, string>>& data) {
    const int lbrNama = 15;
    const int lbrAlamat = 20;
    const int totalLebar = lbrNama + lbrAlamat + 7;

    cout << "+";
    cout << string(totalLebar - 2, '-') << "+\n";

    cout << "| " << left << setw(lbrNama) << "Nama" 
         << " | " << setw(lbrAlamat) << "Alamat" << " |\n";

    cout << "+";
    cout << string(totalLebar - 2, '-') << "+\n";

    for (const auto& item : data) {
        cout << "| " << left << setw(lbrNama) << item.first
             << " | " << setw(lbrAlamat) << item.second << " |\n";
    }

    cout << "+";
    cout << string(totalLebar - 2, '-') << "+\n";
}

int main() {
    vector<pair<string, string>> data = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };
    bubbleSort(data);

    cout << "Data yang telah diurutkan menggunakan Bubble Srot:\n";
    printTable(data);

    return 0;
}
//  NO 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int pencarianBiner(const vector<int>& arr, int x) {
    int bawah = 0;
    int atas = arr.size() - 1;

    while (bawah <= atas) {
        int tengah = (atas + bawah) / 2;
        if (arr[tengah] == x) {
            return tengah;
        } else if (arr[tengah] < x) {
            bawah = tengah + 1;
        } else {
            atas = tengah - 1;
        }
    }
    return -1;
}

string cariIndeks(const vector<int>& arr, int x) {
    vector<pair<int, int>> arr_urut_dengan_indeks;
    for (int i = 0; i < arr.size(); ++i) {
        arr_urut_dengan_indeks.emplace_back(arr[i], i + 1); // indeks 1-based
    }
    sort(arr_urut_dengan_indeks.begin(), arr_urut_dengan_indeks.end());

    vector<int> arr_urut;
    vector<int> indeks_asli;
    for (const auto& p : arr_urut_dengan_indeks) {
        arr_urut.push_back(p.first);
        indeks_asli.push_back(p.second);
    }

    int hasil_idx = pencarianBiner(arr_urut, x);

    if (hasil_idx == -1) {
        return "Angka " + to_string(x) + " tidak ada dalam array";
    } else {
        vector<int> daftar_indeks_asli;
        int kiri = hasil_idx;
        while (kiri >= 0 && arr_urut[kiri] == x) {
            daftar_indeks_asli.push_back(indeks_asli[kiri]);
            --kiri;
        }
        int kanan = hasil_idx + 1;
        while (kanan < arr_urut.size() && arr_urut[kanan] == x) {
            daftar_indeks_asli.push_back(indeks_asli[kanan]);
            ++kanan;
        }

        sort(daftar_indeks_asli.begin(), daftar_indeks_asli.end());

        string hasil = "Angka " + to_string(x) + " ada di indeks ke ";
        for (size_t i = 0; i < daftar_indeks_asli.size(); ++i) {
            hasil += to_string(daftar_indeks_asli[i]);
            if (i != daftar_indeks_asli.size() - 1) {
                hasil += " dan ";
            }
        }
        return hasil;
    }
}

int main() {
    vector<int> arr = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    int angka_dicari;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> angka_dicari;

    cout << cariIndeks(arr, angka_dicari) << endl;

    return 0;
}