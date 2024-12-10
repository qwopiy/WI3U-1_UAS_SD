#include <bits/stdc++.h>
using namespace std;

// PARAN
struct Produk {
    int id;
    string nama;
    string kategori;
    int harga;
};

string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void quickSortHarga(vector<Produk>& produk, int low, int high, bool ascending) {
    if (low < high) {
        int pivot = produk[high].harga;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if ((ascending && produk[j].harga < pivot) || (!ascending && produk[j].harga > pivot)) {
                i++;
                swap(produk[i], produk[j]);
            }
        }
        swap(produk[i + 1], produk[high]);
        int pi = i + 1;
        quickSortHarga(produk, low, pi - 1, ascending);
        quickSortHarga(produk, pi + 1, high, ascending);
    }
}

void quickSortKategori(vector<Produk>& produk, int low, int high, bool ascending) {
    if (low < high) {
        string pivot = produk[high].kategori;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            string kategoriProduk = toLowerCase(produk[j].kategori);
            string kategoriPivot = toLowerCase(pivot);
            if (ascending ? kategoriProduk < kategoriPivot : kategoriProduk > kategoriPivot) {
                i++;
                swap(produk[i], produk[j]);
            }
        }
        swap(produk[i + 1], produk[high]);
        int pi = i + 1;
        quickSortKategori(produk, low, pi - 1, ascending);
        quickSortKategori(produk, pi + 1, high, ascending);
    }
}

int searchProdukById(const vector<Produk>& produk, int id) {
    for (int i = 0; i < produk.size(); i++) {
        if (produk[i].id == id) {
            return i;
        }
    }
    return -1;  
}

void tampilkanProduk(const vector<Produk>& produk) {
    for (const auto& p : produk) {
        cout << "ID: " << p.id << ", Nama: " << p.nama << ", Kategori: " << p.kategori << ", Harga: Rp." << p.harga << endl;
    }
}

// ANANTA
void tampilkanKeranjang(const vector<Produk>& produk, const vector<int>& keranjang) {
    if (keranjang.empty()) {
        cout << "Keranjang Anda kosong!" << endl;
    } else {
        cout << "Isi Keranjang Belanja:\n";
        int totalHarga = 0;
        for (int id : keranjang) {
            int index = searchProdukById(produk, id);
            if (index != -1) {
                cout << "ID: " << produk[index].id << ", Nama: " << produk[index].nama << ", Harga: Rp." << produk[index].harga << endl;
                totalHarga += produk[index].harga;
            }
        }
        cout << "Total Harga: Rp." << totalHarga << endl;
    }
}

void tambahBarang(vector<int>& keranjang, int id, const vector<Produk>& produk) {
    int index = searchProdukById(produk, id);
    if (index != -1) {
        keranjang.push_back(id);
        cout << "Produk " << produk[index].nama << " telah ditambahkan ke keranjang!" << endl;
    } else {
        cout << "Produk dengan ID " << id << " tidak ditemukan!" << endl;
    }
}

void hapusBarang(vector<int>& keranjang, int id, const vector<Produk>& produk) {
    auto it = find(keranjang.begin(), keranjang.end(), id);
    if (it != keranjang.end()) {
        keranjang.erase(it);
        cout << "Produk dengan ID " << id << " telah dihapus dari keranjang!" << endl;
    } else {
        cout << "Produk dengan ID " << id << " tidak ada di keranjang!" << endl;
    }
}

// ARIIQ
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

// BINTANG
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
        for (int i = 0; i < idTransaksi.size(); i++) {
            cout << idTransaksi[i] << " - Rp." << fixed << setprecision(2) << totalBiaya[i] << " - " << ctime(&tanggalTransaksi[i]);
        }
    }
};

int pembayaran(RiwayatTransaksi &riwayat, vector<Produk> produk, vector<int> keranjang) {
    vector<vector<pii>> graf(38);
    provinsi(graf);
    int total = 0;
    int tujuan;
    displayProvinsi();
    do{
        cin>>tujuan;
    }while(tujuan < 0 || tujuan > 37);
    
    for (int i : keranjang) {
        int ongkir = hitungOngkir(tujuan, graf);
        
        total += produk[i-1].harga + ongkir;
        cout << produk[i-1].nama << " - Rp." << produk[i-1].harga << endl;
    }
    
    riwayat.tambahTransaksi(riwayat.idTransaksi.size() + 1, total);

    return total;
}

int main() {
    vector<Produk> produk = {
        {1, "Smartphone Samsung Galaxy S23", "Elektronik", 12000000},
        {2, "Laptop ASUS ROG Zephyrus G14", "Elektronik", 25000000},
        {3, "TV LED LG 43 Inch", "Elektronik", 6500000},
        {4, "Earbuds Apple AirPods Pro", "Elektronik", 3500000},
        {5, "Kamera DSLR Canon EOS 90D", "Elektronik", 17000000},
        {6, "Sepeda MTB Polygon", "Fitness", 5000000},
        {7, "Dumbbell 5kg", "Fitness", 200000},
        {8, "Matras Yoga", "Fitness", 250000},
        {9, "Mesin Elliptical", "Fitness", 200000},
        {10, "Resistance Band", "Fitness", 100000},
        {11, "Serum Wajah Vitamin C", "Kecantikan", 150000},
        {12, "Masker Wajah Aloe Vera", "Kecantikan", 75000},
        {13, "Lipstik Matte L'Oréal", "Kecantikan", 120000},
        {14, "Parfum Chanel", "Kecantikan", 2500000},
        {15, "Sabun Cuci Muka Himalaya", "Kecantikan", 35000},
        {16, "Roti Tawar Serba Roti", "Konsumsi", 15000},
        {17, "Kopi Arabica 100g", "Konsumsi", 50000},
        {18, "Mie Instan", "Konsumsi", 5000},
        {19, "Susu UHT Indomilk 1 Liter", "Konsumsi", 18000},
        {20, "Teh Kotak Sosro 500ml", "Konsumsi", 7500}
    };

    RiwayatTransaksi riwayat;
    vector<int> keranjang;
    
    do {
        system("cls");
        cout << "======================================" << endl;
        cout << "||      Menu Keranjang Belanja      ||" << endl;
        cout << "======================================" << endl;
        cout << "|| 1. Lihat Keranjang               ||" << endl;
        cout << "|| 2. Lihat Produk                  ||" << endl;
        cout << "|| 3. Tambah barang                 ||" << endl;
        cout << "|| 4. Hapus barang                  ||" << endl;
        cout << "|| 5. Pembayaran                    ||" << endl;
        cout << "|| 6. Tampilkan Riwayat             ||" << endl;
        cout << "|| 7. Keluar                        ||" << endl;
        cout << "======================================" << endl;
        cout << "Pilihan Anda: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanKeranjang(produk, keranjang);
                break;
            case 2: {
                int subPilihan;
                do {
                    system("cls");
                    cout << "====================================" << endl;
                    cout << "|| 1. Tampilkan semua produk      ||\n";
                    cout << "|| 2. Sortir berdasarkan harga    ||\n";
                    cout << "|| 3. Sortir berdasarkan kategori ||\n";
                    cout << "|| 4. Cari produk berdasarkan ID  ||\n";
                    cout << "|| 5. Kembali ke menu utama       ||\n";
                    cout << "====================================" << endl;
                    cout << "Pilihan Anda: ";
                    cin >> subPilihan;

                    switch (subPilihan) {
                        case 1:
                        system("cls");
                            tampilkanProduk(produk);
                            break;
                        case 2: {
                            system("cls");
                            cout << "Sortir berdasarkan harga (1: Ascending, 2: Descending): ";
                            int sortOrder;
                            cin >> sortOrder;
                            bool ascending = sortOrder == 1;
                            quickSortHarga(produk, 0, produk.size() - 1, ascending);
                            tampilkanProduk(produk);
                            break;
                        }
                        case 3: {
                            system("cls");
                            cout << "Masukkan kategori produk yang ingin ditampilkan: ";
                            string kategoriInput;
                            cin >> kategoriInput;
                            kategoriInput = toLowerCase(kategoriInput);

                            bool found = false;
                            for (const auto& p : produk) {
                                if (toLowerCase(p.kategori) == kategoriInput) { 
                                    cout << "ID: " << p.id << ", Nama: " << p.nama << ", Kategori: " << p.kategori << ", Harga: Rp." << p.harga << endl;
                                    found = true;
                                }
                            }

                            if (!found) {
                                cout << "Tidak ada produk dengan kategori '" << kategoriInput << "' ditemukan!" << endl;
                            }

                            break;
                        }
                        case 4: {
                            system("cls");
                            cout << "Masukkan ID produk yang ingin dicari: ";
                            int id;
                            cin >> id;
                            int index = searchProdukById(produk, id);
                            if (index != -1) {
                                cout << "ID: " << produk[index].id << ", Nama: " << produk[index].nama << ", Kategori: " << produk[index].kategori << ", Harga: Rp." << produk[index].harga << endl;
                            } else {
                                cout << "Produk dengan ID " << id << " tidak ditemukan!" << endl;
                            }
                            break;
                        }
                        case 5:
                            cout << "Kembali ke menu utama...\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid!\n";
                    }

                    if (subPilihan != 5) {
                        cout << "\nTekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                    }

                } while (subPilihan != 5); 
                break;
            }
            case 3: {
                cout << "Masukkan ID barang yang ingin ditambahkan: ";
                int id;
                cin >> id;
                tambahBarang(keranjang, id, produk);
                break;
            }
            case 4: {
                cout << "Masukkan ID barang yang ingin dihapus: ";
                int id;
                cin >> id;
                hapusBarang(keranjang, id, produk);
                break;
            }
            case 5: {
                if (keranjang.empty()) {
                    cout << "Keranjang belanja masih kosong!" << endl;
                } else {
                    int total = pembayaran(riwayat, produk, keranjang);
                    cout << "Pembayaran sebesar Rp." << total << " telah berhasil dilakukan!" << endl;
                    keranjang.clear();
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                break;
            }
            case 6:
                riwayat.tampilkanRiwayat();
                break;
            case 7:
                cout << "Terima kasih telah berbelanja!" << endl;
                return 0;
            
            default:
                cout << "Pilihan tidak valid!\n";
        }

        if (pilihan != 5) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

    } while (true);

    return 0;
}