#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

class Kendaraan {
protected:
    string merk, nama, nomorPolisi;
    int harga;

public:
    Kendaraan(string _merk, string _nama, string _nomorPolisi, int _harga) {
        merk = _merk;
        nama = _nama;
        nomorPolisi = _nomorPolisi;
        harga = _harga;
    }
	void setKendaraan(){
		cout << "\n==Tambah Kendaraan==\nMasukkan merk: ";
		getline(cin, merk);
		cout << "Masukkan nama: ";
		getline(cin, nama);
		cout << "Masukkan nomor polisi: ";
		getline(cin, nomorPolisi);
		cout << "Masukkan harga sewa: ";
		cin >> harga;		
	}
    ~Kendaraan() {
		cout << "Program Berakhir. " << endl;}
};

class Mobil : public Kendaraan {
private:
    int jumlahKursi;
    string bodyStyle;

public:
    Mobil(string _merk, string _nama, string _nomorPolisi, int _harga, int _jumlahKursi, string _bodyStyle) : Kendaraan(_merk, _nama, _nomorPolisi, _harga) {
        jumlahKursi = _jumlahKursi;
        bodyStyle = _bodyStyle;
    }
	void setMobil() {
		setKendaraan();
		cout << "Masukkan jumlah kursi mobil: ";
	    cin >> jumlahKursi;
	    cin.ignore();
	    cout << "Masukkan body style mobil: ";
	    getline(cin, bodyStyle);
	}
    void displayMobil() {
        cout << merk << "-" << nama << "-" << nomorPolisi << "-" << harga << "-" << jumlahKursi << "-" << bodyStyle << endl;
    }
    int getHargaMobil () {
    	return harga;
	}
	string getMerkMobil(){
		return merk;
	}
	string getNamaMobil() {
		return nama;
	}

    ~Mobil() {}
};

class Motor : public Kendaraan {
private:
	int cc;
    string jenis;

public:
    Motor(string _merk, string _nama, string _nomorPolisi, int _harga, int _cc, string _jenis) : Kendaraan(_merk, _nama, _nomorPolisi, _harga) {
        cc = _cc;
        jenis = _jenis;
    }
    void displayMotor() {
        cout << merk << "-" << nama << "-" << nomorPolisi << "-" << harga << "-" << cc << "-" << jenis << endl;
    }
	void setMotor() {
		setKendaraan();
		cout << "Masukkan cc motor : ";
	    cin >> cc;
	    cin.ignore();
	    cout << "Masukkan jenis motor: ";
	    getline(cin, jenis);
	}    
    int getHargaMotor() {
    	return harga;
	}
	string getMerkMotor(){
		return merk;
	}
	string getNamaMotor() {
		return nama;
	}
    ~Motor() {}
};

class Penyewa {
private:
    string nama;
    string tempatLahir;
    string alamat;
    string noHP;
    string jenisKelamin;
    int tanggalLahir;
    int bulanLahir;
    int tahunLahir;

public:
    Penyewa(string _nama, string _tempatLahir, int _tanggalLahir, int _bulanLahir, int _tahunLahir, string _alamat, string _noHP, string _jenisKelamin) {
        nama = _nama;
        tempatLahir = _tempatLahir;
        tanggalLahir = _tanggalLahir;
        bulanLahir = _bulanLahir;
        tahunLahir = _tahunLahir;
        alamat = _alamat;
        noHP = _noHP;
        jenisKelamin = _jenisKelamin;
    }
		string getNama(){
			return nama;
		}
		string getTempatLahir(){
			return tempatLahir;
		}
		int getTanggalLahir(){
			return tanggalLahir;
		}
		int getBulanLahir(){
			return bulanLahir;
		}
		int getTahunLahir(){
			return tahunLahir;
		}
		string getAlamat(){
			return alamat;
		}
		string getNoHP(){
			return noHP;
		}
		string getJenisKelamin(){
			return jenisKelamin;
		}
	void cetakStrukPenyewa() {
		cout << "\n===============================================\n";
		cout << "\n              STRUK RENTAL CB.GO               \n";
		cout << "\n===============================================\n";
		cout << "	Data Penyewa";
		cout << "\n	Nama : " << getNama();
		cout << "\n	Nomor Hp : " << getNoHP();
		cout << "\n===============================================\n";
	}
	
    int hitungUmur(int tahunLahir, int bulanLahir, int tanggalLahir) {
        time_t now = time(0);
        tm* sekarang = localtime(&now);

        int tahunSekarang = sekarang->tm_year + 1900;
        int bulanSekarang = sekarang->tm_mon + 1;
        int tanggalSekarang = sekarang->tm_mday;

        // Menghitung umur
        int umur = tahunSekarang - tahunLahir;

        // Memperbaiki perhitungan umur jika belum melewati bulan dan tanggal lahir
        if (bulanSekarang < bulanLahir || (bulanSekarang == bulanLahir && tanggalSekarang < tanggalLahir)) {
            umur--;
        }

        return umur;
    }
};

struct Node {
    Mobil* mobil;
    Motor* motor;
    Node* next;
};

class List {
private:
    Node* head;
    Node* tail;
    int mobilCount;
    int motorCount;
    string alamatPengiriman;
    int jumlahHariSewa;
    int total;

public:
    List(string _alamatPengiriman) {
        head = NULL;
        tail = NULL;
        mobilCount = 0;
        motorCount = 0;
        alamatPengiriman = _alamatPengiriman;
        
    }
    
	Node* getHead() {
    return head;
	}
	
    void addMobil(Mobil mobil) {
        Node* newNode = new Node;
        newNode->mobil = new Mobil(mobil);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        mobilCount++;
    }

    void displayMobil() {
        Node* current = head;
        int index = 1;

        while (current != NULL) {
        	cout << index << ". " ;	
            current->mobil->displayMobil();
            current = current->next;
            index++;
        }
    }
    
    int getMobilCount() {
    	return mobilCount;
	}

    void addMotor(Motor motor) {
        Node* newNode = new Node;
        newNode->motor = new Motor(motor);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        motorCount++;
    }

    void displayMotor() {
        Node* current = head;
        int index = 1;

        while (current != NULL) {
        	cout << index << ". " ;	
            current->motor->displayMotor();
            current = current->next;
            index++;
        }
    }
    
    int getMotorCount() {
    	return motorCount;
	}
    void removeKendaraanByIndex(int index) {

        if (index == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            Node* previous = NULL;
            int currentIndex = 1;

            while (currentIndex != index) {
                previous = current;
                current = current->next;
                currentIndex++;
            }

            previous->next = current->next;

            if (current == tail) {
                tail = previous;
            }

            delete current;
        }
    }
    string getAlamatPengiriman () {
    	return alamatPengiriman;
	}
	
	int getJumlahHariSewa () {
		return jumlahHariSewa;
	}
	int getTotal(){
		return total;
	}
		    
};


int main() {
    int jawab, choose, pilihan, tahunLahir, bulanLahir, tanggalLahir, harga, jumlahKursi, cc;
    string nama, tempatLahir, alamat, noHP, jenisKelamin, editNama, editNomorHp, editAlamat, editJenisKelamin;
    string merk, nomorPolisi, bodyStyle, jenis, alamatPengiriman;
    
    Kendaraan kendaraan(merk, nama, nomorPolisi, harga);
    Mobil mobil(merk, nama, nomorPolisi, harga, jumlahKursi, bodyStyle);
    Motor motor(merk, nama, nomorPolisi, harga, cc, jenis);
    Penyewa penyewa(nama, tempatLahir, tanggalLahir, bulanLahir, tahunLahir, alamat, noHP, jenisKelamin);
    List list (alamatPengiriman);  
    
    cout << "Masukkan nama penyewa : ";
    getline(cin, nama);
    cout << "Masukkan tempat lahir : ";
    getline(cin, tempatLahir);
    cout << "Masukkan tanggal lahir (YYYY/MM/DD) : ";
    cin >> tahunLahir >> bulanLahir >> tanggalLahir;
    cin.ignore();
    cout << "Masukkan alamat : ";
    getline(cin, alamat);
    cout << "Masukkan nomor HP : +62-";
    getline(cin, noHP);
    cout << "Masukkan jenis Kelamin : ";
    getline(cin, jenisKelamin);
  
    int umur = penyewa.hitungUmur(tahunLahir, bulanLahir, tanggalLahir);
	if (umur > 17) {
	    cout << "\n---Pilih Jenis Kendaraan---\n1. Mobil\n2. Motor\nPilih (1/2)...";
	    cin >> choose;
	    if (choose==1) {
	    	// Data mobil sebelumnya
	    	Mobil c1("Daihatsu", "Xenia", "L 2191 DA", 250000, 8, "Small MPV");
		    Mobil c2("Toyota", "Avanza", "L 1119 AZ", 350000, 8, "Small MPV");
		    list.addMobil(c1);
		    list.addMobil(c2);
		} else if (choose==2) {
			// Data motor sebelumnya
			Motor m1("Honda", "Vario", "L 3232 JA", 60000, 110, "automatic");
		    Motor m2("Honda", "Beat", "L 8430 AX", 70000, 120, "automatic");
		    list.addMotor(m1);
		    list.addMotor(m2);
		}
		while (1) {
			system("pause");
			system("cls");
			cout << "==Menu Rental CB.GO==" << endl;
			cout << "1. Tambah List Kendaraan\n";
	        cout << "2. Tampilkan List Kendaraan Tersedia\n";
	        cout << "3. Hapus List Kendaraan\n";
	        cout << "4. Tampilkan Data Penyewa\n";
	        cout << "5. Pilih Kendaraan\n";
	        cout << "6. Keluar\n";
	        cout << "Pilihan Anda: ";
	        cin >> pilihan;
	        cin.ignore();
	        
	        switch (pilihan) {
	        	case 1:
	        		// Input data mobil baru
					char lanjut;
					do {
	        			if (choose==1) {
		        			mobil.setMobil();
						    list.addMobil(mobil);
						}
						else if (choose==2){
							motor.setMotor();
							list.addMotor(motor);
						}				
					    cout << "Tambahkan kendaraan lagi? (y/n): ";
					    cin >> lanjut;
					    cin.ignore();
					} while (lanjut == 'y' || lanjut == 'Y');
					break;
				
				case 2:
					cout << endl << "Data Kendaraan:" << endl;				
					if (choose==1){
					    list.displayMobil();					
					}
					else if (choose==2){
						list.displayMotor();
					}
				break;
				
				case 3:
					int x, indeks;
					cout << "Data Kendaraan saat ini :" << endl;
					if (choose==1){
					    list.displayMobil();
						cout << "Masukkan indeks mobil yang ingin dihapus : " ;
						cin >> indeks;
						cin.ignore();
						if (indeks >= 1 && indeks <= list.getMobilCount()) {
							x=list.getMobilCount();
							list.removeKendaraanByIndex(indeks);
							x--;
	        				cout << "Kendaraan dengan indeks " << indeks << " telah dihapus." << endl;
						}
						else {
							cout << "\nIndeks mobil tidak valid" << endl;
						}					
					}
					else if (choose==2){
						list.displayMotor();
						cout << "Masukkan indeks motor yang ingin dihapus : " ;
						cin >> indeks;
						cin.ignore();
						if (indeks >= 1 && indeks <= list.getMotorCount()) {
							x=list.getMotorCount();
							list.removeKendaraanByIndex(indeks);
							x--;
	        				cout << "Kendaraan dengan indeks " << indeks << " telah dihapus." << endl;
						}
						else {
							cout << "\nIndeks motor tidak valid" << endl;
						}					
					}
					break;	
				
				case 4: {			
					Penyewa penyewa(nama, tempatLahir, tanggalLahir, bulanLahir, tahunLahir, alamat, noHP, jenisKelamin);
			        cout << "\n=Data Penyewa==" << endl;
			        cout << "Nama : " << penyewa.getNama() << endl;
			        cout << "Tempat Lahir : " << penyewa.getTempatLahir() << endl;
			        cout << "Tanggal Lahir : " << penyewa.getTanggalLahir() << "/" << penyewa.getBulanLahir() << "/" << penyewa.getTahunLahir() << endl;
			        cout << "Alamat : " << penyewa.getAlamat() << endl;
			        cout << "Nomor HP : " << penyewa.getNoHP() << endl;
			        cout << "Jenis Kelamin : " << penyewa.getJenisKelamin() << endl;
					break;
				}
				
				case 5: {
					int index, x;
					cout << "\nData Kendaraan saat ini :" << endl;
					if (choose==1) {
						list.displayMobil();
						cout << "Masukkan indeks mobil yang ingin Anda pilih: ";
						cin >> index;
						cin.ignore();
						x=list.getMobilCount();
						if (index >= 1 && index <= list.getMobilCount()) {
						    // Lakukan sesuatu dengan mobil yang dipilih
						    // Misalnya, dapatkan mobil dari indeks dan tampilkan detailnya
						    Node* current = list.getHead();
						    int currentIndex = 1;
						
						    while (currentIndex != index) {
						        current = current->next;
						        currentIndex++;
						    }
						
						    cout << "\nMobil yang Anda pilih : " << endl;
						    current->mobil->displayMobil();
						    int jumlahHariSewa;
							cout << "\nMasukkan Jumlah Hari penyewaan : " ;
							cin >> jumlahHariSewa;
							int total = current->mobil->getHargaMobil() * jumlahHariSewa;
							cout << "Total biaya dengan jumlah hari = " << jumlahHariSewa << " adalah : Rp." << total<< endl;
							cout << "\nMasukkan alamat pengiriman kendaraan : ";
							cin.ignore();
							getline(cin, alamatPengiriman);
							cout << "\nCetak struk? \n1. Ya\n2. Tidak";
							cout << "\nPilihan (1/2)...";
							int pil;
							cin >> pil;
							if (pil==1) {
								system("cls");
								Penyewa penyewa(nama, tempatLahir, tanggalLahir, bulanLahir, tahunLahir, alamat, noHP, jenisKelamin);
								penyewa.cetakStrukPenyewa();
								cout << "\n	Merk : " << current->mobil->getMerkMobil();
								cout << "\n	Nama : " << current->mobil->getNamaMobil();
								cout << "\n	Jumlah Hari Sewa : " << jumlahHariSewa;
								cout << "\n	Harga : " << total;
								cout << "\n	Alamat Pengiriman : " << alamatPengiriman;	
								cout << "\n=================================\n";
								}
							else {}
						} else {
						    cout << "Indeks mobil tidak valid." << endl;
						}				
					} else if (choose==2) {
						list.displayMotor();
						cout << "Masukkan indeks motor yang ingin Anda pilih: ";
						cin >> index;
						cin.ignore();
						if (index >= 1 && index <= list.getMotorCount()) {
						    // Lakukan sesuatu dengan mobil yang dipilih
						    // Misalnya, dapatkan mobil dari indeks dan tampilkan detailnya
						    Node* current = list.getHead();
						    int currentIndex = 1;
						
						    while (currentIndex != index) {
						        current = current->next;
						        currentIndex++;
						    }
						    cout << "\nMotor yang Anda pilih:" << endl;
						    current->motor->displayMotor();
						    int jumlahHariSewa;
							cout << "\nMasukkan Jumlah Hari penyewaan = " ;
							cin >> jumlahHariSewa;
							int total = current->motor->getHargaMotor() * jumlahHariSewa;
							cout << "Total biaya dengan jumlah " << jumlahHariSewa << " hari adalah : Rp." << total<< endl;
							cout << "\nMasukkan alamat pengiriman kendaraan : ";
							cin.ignore();
							getline(cin, alamatPengiriman);
							cout << "\nCetak struk? \n1. Ya\n2. Tidak";
							cout << "\nPilihan (1/2)...";
;							int pil;
							cin >> pil;
							if (pil==1) {
								system("cls");
								Penyewa penyewa(nama, tempatLahir, tanggalLahir, bulanLahir, tahunLahir, alamat, noHP, jenisKelamin);
								penyewa.cetakStrukPenyewa();
								cout << "\n	Merk : " << current->motor->getMerkMotor();
								cout << "\n	Nama : " << current->motor->getNamaMotor();
								cout << "\n	Jumlah Hari Sewa : " << jumlahHariSewa;
								cout << "\n	Harga : " << total;
								cout << "\n	Alamat Pengiriman : " << alamatPengiriman;	
								cout << "\n\n===============================================\n";
								}
							else {}
						} else {
						    cout << "Indeks mobil tidak valid." << endl;
						}						
					}				
				}
					break;
					
					case 6:
						exit(1);						
					default :
						cout << "Pilihan salah, masukkan ulang!"<<endl;
				}				
			}
		} else {
			cout << "Maaf, anda belum cukup umur untuk merental kendaraan." << endl;
		}
    return 0;
}

