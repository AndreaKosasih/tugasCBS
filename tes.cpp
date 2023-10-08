#include <iostream>
#define MAX_N 1000000
using namespace std;

void CekPrima(bool arr[], int prima[], int &banyakPrima);

int main() {
    int banyakPrima; cout << "Masukkan banyak prima yang ingin diketahui (1-1000000): "; cin >> banyakPrima; cout << endl;

    if (banyakPrima < 1 || banyakPrima > MAX_N) cout << "Masukkan jumlah prima yang valid antara 1 dan " << MAX_N << endl;
    
    bool num[MAX_N + 1];
    int primaKe_i[MAX_N + 1];

    CekPrima(num, primaKe_i, banyakPrima);

    for (int i = 1; i <= banyakPrima; i++) {
        int Ke_i; cout << "Prima ke-"; cin >> Ke_i;
        if (Ke_i < 1 || Ke_i > banyakPrima) cout << "Indeks prima tidak valid. Harap masukkan nilai antara 1 dan " << banyakPrima << endl;
        else cout << "Prima ke-" << Ke_i << " adalah " << primaKe_i[Ke_i] << endl << endl;
    }
    return 0;
}

void CekPrima(bool arr[], int prima[], int &banyakPrima) {
    for (int i = 2; i <= MAX_N; i++) arr[i] = true;

    int keBerapa = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (arr[i]) {
            prima[keBerapa] = i;
            keBerapa++;
            for (int j = i; j <= MAX_N; j += i) {
                arr[j] = false;
            }
        }
    }

    banyakPrima = keBerapa - 1; 
}

