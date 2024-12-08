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

typedef pair<int, int> pii;

void provinsi(vector<vector<pii>>& graf){
    int arr[46][3] = {
        {0, 1, 55}, {0, 2, 60}, {0, 3, 65}, {2, 3, 40}, {2, 4, 40}, {2, 5, 45}, {3, 5, 35}, {3, 6, 20}, {4, 5, 45}, {4, 7, 45}, {4, 8, 40}, 
        {5, 8, 30}, {6, 19, 90}, {7, 8, 50}, {7, 10, 15}, {8, 9, 20}, {10, 11, 15}, {10, 12, 20}, {12, 14, 40}, {13, 14, 12}, {14, 15, 30}, 
        {15, 16, 15}, {16, 17, 30}, {17, 18, 40}, {18, 33, 100}, {19, 20, 65}, {19, 21, 80}, {20, 22, 50}, {21, 22, 60}, {21, 23, 50}, 
        {21, 24, 60}, {24, 26, 40}, {24, 27, 30}, {25, 26, 60}, {25, 28, 40}, {26, 29, 45}, {26, 30, 60}, {27, 30, 50}, {29, 31, 100}, 
        {29, 33, 30}, {31, 32, 60}, {31, 33, 100}, {32, 34, 120}, {32, 35, 50}, {32, 36, 35}, {32, 37, 100}
    }; 

    graf.clear();

    for(int i = 0; i < 46; i++) {
        graf[arr[i][0]].emplace_back(arr[i][1], arr[i][2]);
        graf[arr[i][1]].emplace_back(arr[i][0], arr[i][2]);
    }
}

int dijkstra(int jumlahprovinsi, const vector<vector<pii>>& graf, int tujuan) {
    vector<int> jarak(jumlahprovinsi, numeric_limits<int>::max());
    jarak[0] = 0; 

    priority_queue<pii, vector<pii>, greater<pii>> antrian; 
    antrian.push({0, 0}); 

    while (!antrian.empty()) {
        int provinsiSekarang = antrian.top().first;
        int jarakSekarang = antrian.top().second;
        antrian.pop();

        if(provinsiSekarang == tujuan){
            return jarak[tujuan];
        }

        if (jarakSekarang > jarak[provinsiSekarang]) {
            continue;
        }

        for (const auto& tetangga : graf[provinsiSekarang]) {
            int provinsiBerikut = tetangga.first;
            int waktuPerjalanan = tetangga.second;
            int jarakBaru = jarakSekarang + waktuPerjalanan;

            if (jarakBaru < jarak[provinsiBerikut]) {
                jarak[provinsiBerikut] = jarakBaru;
                antrian.push({provinsiBerikut, jarakBaru});
            }

        }
    }
    return 0;
}

int hitungOngkir(int tujuan, const vector<vector<pii>>& graf){
    int jarakMinimal = dijkstra(38, graf, tujuan);

    switch (jarakMinimal/100){
    case 0:
        return 0;
        break;
    case 1:
    case 2:
        return 10000;
        break;
    case 3:
    case 4:
        return 15000;
        break;
    default:
        return 20000;
        break;
    }
}

void displayProvinsi(){
    system("CLS");
    cout<<"||================================================================================||"<<endl;
    cout<<"||                            PILIH PROVINSI LOKASI MU                            ||"<<endl;
    cout<<"||================================================================================||"<<endl;
    cout<<"|| 0. Medan                   13. Yogyakarta              26. Sulawesi Tengah     ||"<<endl;
    cout<<"|| 1. Aceh                    14. Jawa Tengah             27. Sulawesi Selatan    ||"<<endl;
    cout<<"|| 2. Sumatera Barat          15. Jawa Timur              28. Sulawesi Utara      ||"<<endl;
    cout<<"|| 3. Riau                    16. Bali                    29. Maluku Utara        ||"<<endl;
    cout<<"|| 4. Bengkulu                17. Nusa Tenggara Barat     30. Sulawesi Tengah     ||"<<endl;
    cout<<"|| 5. Jambi                   18. Nusa Tenggara Timur     31. Papua Barat         ||"<<endl;
    cout<<"|| 6. Kepri                   19. Kalimantan Barat        32. Papua               ||"<<endl;
    cout<<"|| 7. Lampung                 20. Kalimantan Tengah       33. Maluku              ||"<<endl;
    cout<<"|| 8. Sumatera Selatan        21. Kalimantan Timur        34. Papua Barat Daya    ||"<<endl;
    cout<<"|| 9. Kep. Bangka Belitung    22. Kalimantan Selatan      35. Papua Pegunungan    ||"<<endl;
    cout<<"|| 10. Banten                 23. Kalimantan Utara        36. Papua Tengah        ||"<<endl;
    cout<<"|| 11. Jakarta                24. Sulawesi Barat          37. Papua Selatan       ||"<<endl;
    cout<<"|| 12. Jawa Barat             25. Gorontalo                                       ||"<<endl;
    cout<<"||================================================================================||"<<endl;
}

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
    vector<vector<pii>> graf(38);
    provinsi(graf);
    int total = 0;
    int tujuan;
    
    for (int i : keranjang)
    {
        displayProvinsi();
        do{
            cin>>tujuan;
        }while(tujuan < 0 || tujuan > 37);
        int ongkir = hitungOngkir(tujuan, graf);
        
        total += barang.harga[i-1] + ongkir;
        cout << barang.nama[i-1] << " - Rp." << barang.harga[i-1] << endl;
    }
    
    riwayat.tambahTransaksi(riwayat.idTransaksi.size() + 1, total);

    return total;
}

//function untuk keranjang
void tampilkanKeranjang(Barang barang, vector<int> &keranjang) {
    if (keranjang.empty()) {
        cout << "Keranjang kosong.\n";
        return;
    }
    cout << "\nDaftar Keranjang Belanja:\n";
    for (int id : keranjang) {
        cout << "ID: " << id << " - " << barang.nama[id - 1] << " - Rp." << barang.harga[id - 1] << endl;
    }
}

void tambahBarang(vector<int> &keranjang, int id, Barang barang) {
    if (id < 1 || id > 20) {
        cout << "ID barang tidak valid!\n";
        return;
    }
    keranjang.push_back(id);
    cout << barang.nama[id - 1] << " berhasil ditambahkan ke keranjang.\n";
}

void hapusBarang(vector<int> &keranjang, int id, Barang barang) {
    auto it = find(keranjang.begin(), keranjang.end(), id);
    if (it != keranjang.end()) {
        cout << barang.nama[id - 1] << " berhasil dihapus dari keranjang.\n";
        keranjang.erase(it);
    } else {
        cout << "barang dengan ID " << id << " tidak ditemukan di keranjang.\n";
    }
}
// end function untuk keranjang
int main() {
    Barang barang;
    RiwayatTransaksi riwayat;
    barang.inisialisasi();

    vector<int> keranjang;
    bool ulang = true;

    while (ulang) {
        system("cls"); // Bersihkan layar
        cout << "=======================================" << endl;
        cout << "||      Menu Keranjang Belanja       ||" << endl;
        cout << "=======================================" << endl;
        cout << "|| 1. Lihat Keranjang                ||" << endl;
        cout << "|| 2. Tambah barang                  ||" << endl;
        cout << "|| 3. Hapus barang                   ||" << endl;
        cout << "|| 4. Keluar                         ||" << endl;
        cout << "=======================================" << endl;
        cout << "Pilihan Anda: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tampilkanKeranjang(barang, keranjang);
            break;
        case 2: {
            cout << "Masukkan ID barang yang ingin ditambahkan: ";
            int id;
            cin >> id;
            tambahBarang(keranjang, id, barang);
            break;
        }
        case 3: {
            cout << "Masukkan ID barang yang ingin dihapus: ";
            int id;
            cin >> id;
            hapusBarang(keranjang, id, barang);
            break;
        }
        case 4:
            ulang = false;
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }

        if (ulang) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
    }

    cout << "Terima kasih telah berbelanja!\n";
    return 0;

    // bool ulang = true;
    // do {
    // system("cls");

    // currency formatter, global tapi (untuk semua int) 😔
    // cout.imbue(locale(cout.getloc(), new group_facet));

    // vector<int> arr = {1};
    // cout << pembayaran(riwayat, barang, arr) << endl;
    // cout << "Transaksi berhasil!" << endl;

    // cout << "Apakah Anda ingin berbelanja lagi? (y/n) ";
    // char pilihan;
    // cin >> pilihan;
    // if (pilihan == 'n')
    //     ulang = false;
    // } while (ulang == true);

    // riwayat.tampilkanRiwayat();

    // return 0;
}