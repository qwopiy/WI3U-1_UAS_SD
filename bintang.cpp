#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <ctime>
// #include <iomanip>
// #include <locale>
using namespace std;

// currency formatter
// struct group_facet: public std::numpunct<char> {
// protected:
// string do_grouping() const { return "\003"; }
// };

class Barang {
    public:
        int id[20];
        string nama[20];
        string kategori[20];
        int harga[20];

        void inisialisasi() {
            id[0] = 1;
            nama[0] = "Smartphone Samsung Galaxy S23";
            kategori[0] = "Elektronik";
            harga[0] = 12000000;

            id[1] = 2;
            nama[1] = "Laptop ASUS ROG Zephyrus G14";
            kategori[1] = "Elektronik";
            harga[1] = 25000000;

            id[2] = 3;
            nama[2] = "TV LED LG 43 Inch";
            kategori[2] = "Elektronik";
            harga[2] = 6500000;

            id[3] = 4;
            nama[3] = "Earbuds Apple AirPods Pro";
            kategori[3] = "Elektronik";
            harga[3] = 3500000;

            id[4] = 5;
            nama[4] = "Kamera DSLR Canon EOS 90D";
            kategori[4] = "Elektronik";
            harga[4] = 17000000;

            id[5] = 6;
            nama[5] = "Sepeda MTB Polygon";
            kategori[5] = "Fitness";
            harga[5] = 5000000;

            id[6] = 7;
            nama[6] = "Dumbbell 5kg";
            kategori[6] = "Fitness";
            harga[6] = 200000;

            id[7] = 8;
            nama[7] = "Matras Yoga";
            kategori[7] = "Fitness";
            harga[7] = 250000;

            id[8] = 9;
            nama[8] = "Mesin Elliptical";
            kategori[8] = "Fitness";
            harga[8] = 200000;

            id[9] = 10;
            nama[9] = "Resistance Band";
            kategori[9] = "Fitness";
            harga[9] = 100000;

            id[10] = 11;
            nama[10] = "Serum Wajah Vitamin C";
            kategori[10] = "Kecantikan";
            harga[10] = 150000;

            id[11] = 12;
            nama[11] = "Masker Wajah Aloe Vera";
            kategori[11] = "Kecantikan";
            harga[11] = 75000;

            id[12] = 13;
            nama[12] = "Lipstik Matte L'Oréal";
            kategori[12] = "Kecantikan";
            harga[12] = 120000;

            id[13] = 14;
            nama[13] = "Parfum Chanel";
            kategori[13] = "Kecantikan";
            harga[13] = 2500000;

            id[14] = 15;
            nama[14] = "Sabun Cuci Muka Himalaya";
            kategori[14] = "Kecantikan";
            harga[14] = 35000;

            id[15] = 16;
            nama[15] = "Roti Tawar Serba Roti";
            kategori[15] = "Konsumsi";
            harga[15] = 15000;

            id[16] = 17;
            nama[16] = "Kopi Arabica 100g";
            kategori[16] = "Konsumsi";
            harga[16] = 50000;

            id[17] = 18;
            nama[17] = "Mie Instan";
            kategori[17] = "Konsumsi";
            harga[17] = 5000;

            id[18] = 19;
            nama[18] = "Susu UHT Indomilk 1 Liter";
            kategori[18] = "Konsumsi";
            harga[18] = 18000;

            id[19] = 20;
            nama[19] = "Teh Kotak Sosro 500ml";
            kategori[19] = "Konsumsi";
            harga[19] = 7500;
        }
};

class RiwayatTransaksi {
    public:
        vector<int> idTransaksi;
        vector<int> totalBiaya;
        vector<time_t> tanggalTransaksi;

        void tambahTransaksi(int id, int total) {
            time_t now = time(0);
            
            idTransaksi.push_back(id);
            totalBiaya.push_back(total);
            tanggalTransaksi.push_back(now);
        }

        void tampilkanRiwayat() {
            for (int i = 0; i < idTransaksi.size(); i++)
            {
                cout << idTransaksi[i] << " - Rp." << fixed << setprecision(2) << totalBiaya[i] << " - " << ctime(&tanggalTransaksi[i]);
            }
        }
};

int pembayaran(RiwayatTransaksi &riwayat, Barang barang, vector<int> keranjang) {
    int total = 0;
    
    for (int i : keranjang)
    {
        total += barang.harga[i-1];
        cout << barang.nama[i-1] << " - Rp." << barang.harga[i-1] << endl;
    }
    
    riwayat.tambahTransaksi(riwayat.idTransaksi.size() + 1, total);

    return total;
}

int main() {
    Barang barang;
    RiwayatTransaksi riwayat;
    barang.inisialisasi();

    bool ulang = true;
    do {
    system("cls");

    // currency formatter, global tapi (untuk semua int) 😔
    // cout.imbue(locale(cout.getloc(), new group_facet));

    vector<int> arr = {1};
    cout << pembayaran(riwayat, barang, arr) << endl;
    cout << "Transaksi berhasil!" << endl;

    cout << "Apakah Anda ingin berbelanja lagi? (y/n) ";
    char pilihan;
    cin >> pilihan;
    if (pilihan == 'n')
        ulang = false;
    } while (ulang == true);

    riwayat.tampilkanRiwayat();

    return 0;
}