#include <iostream>
#include <conio.h>
using namespace std;

	int pil;
	void pilih();
	void buat_baru();
	void tambah_depan();
	void tambah_tengah();
	void tambah_belakang();
	void hapus_tengah();
	void hapus_belakang();
	void hapus_depan();
	void tampil();
	
	class node{
		public :
		char nama[20];
		int nim;
		char asal[30];
		node *prev, *next;
	};
	
	node *baru, *head=NULL, *tail=NULL,*hapus,*bantu,*bantu2;
	
int main(){
	do{
		system("cls");
		cout << "INPUT DATA MAHASISWA " << endl;
		cout << "1. Penambahan Depan" << endl;
		cout << "2. Penambahan Tengah" << endl;
		cout << "3. Penambahan Belakang" << endl;
		cout << "4. Hapus Depan" << endl;
		cout << "5. Hapus tengah" << endl;
		cout << "6. Hapus Belakang" << endl;
		cout << "7. Tampilkan" << endl;
		cout << "8. Keluar" << endl;
		cout << "Pilihan : "; cin >> pil;
		pilih();
	}
		while(pil != 8);
	}
	
		void pilih(){
			if(pil == 1)
				tambah_depan();
			else if(pil == 2)
				tambah_tengah();
			else if(pil == 3)
				tambah_belakang();
			else if(pil == 4)
				hapus_depan();
			else if(pil == 5)
				hapus_tengah();
			else if(pil == 6)
				hapus_belakang();
			else if(pil == 7)
				tampil();
			else
				cout << "selesai";
	}
	
	void buat_baru(){
		baru = new(node);
		cin.ignore();
		cout << "Nama : ";
		cin.getline(baru->nama,50);
		cout << "Nim  : ";
		cin >> baru -> nim;
		cin.ignore();
		cout << "Asal : ";
		cin.getline(baru->asal,50);
		baru -> prev = NULL;
		baru -> next = NULL;
	}
	
	void tambah_belakang(){
		buat_baru();
		if(head == NULL){
			head = baru;
			tail = baru;
		}
		else{
			tail -> next = baru;
			baru -> prev = tail;
			tail = baru;
		}
		cout << endl << endl;
		tampil();
		}
		
	void tambah_tengah(){
		int letak;
		if(head!=NULL){
			cout<<"akan disisipkan diposisi data ke- : ";
			cin>>letak;
			bantu = head;
		for(int i=1;i<letak-1;i++){
			bantu = bantu -> next;
			}
	
		buat_baru();
		bantu2 = bantu -> next;
		baru -> next = bantu2;
		bantu2 -> prev = baru;
		bantu -> next = baru;
		baru -> prev = bantu;
		}else{
			cout << "belum ada data" << endl;
		}
		cout << endl;
		tampil();
	}
	
	void tambah_depan(){
		buat_baru();
		if(head == NULL){
			head = baru;
			tail = baru;
		}
		else{
			baru -> next = head;
			head -> prev = baru;
			head = baru;
		}
		cout << endl << endl;
		tampil();
	}
	void hapus_depan() {
		if (head == NULL)
			cout << "Data Masih Kosong !";
		else if(head -> next == NULL){
			hapus = head;
			head = NULL;
			tail = NULL;
			delete hapus;
			}
		else{
				hapus = head;
				head = hapus -> next;
				head -> prev = NULL;
				delete hapus;
			}
			cout << endl << endl;
			tampil();
		}
	void hapus_tengah(){
		int x=1,lok=1,data_ke;
		if(head!=NULL){
			cout<<"Pilih Hapus Data Ke- :";
			cin>>data_ke;
			bantu=head;
			while(bantu->next!=NULL){
				bantu=bantu->next;
				x++;
			}
			if((data_ke<=0)||(data_ke>x)){
				cout<<"Data kagak ada cuy"<<endl;
			}
			else{bantu=head;
				 while(lok<(data_ke-1)){
					bantu=bantu->next;
					lok++;
				}
				hapus=bantu->next;
				bantu->next=hapus->next;
				delete hapus;
			}
		}else{
			cout<<"Data NULL"<<endl;
		}
		tampil();
	}
	void hapus_belakang(){
		if (head == NULL)
			cout << "Data Masih Kosong !";
			else if (head -> next == NULL){
				hapus = head;
				head = NULL;
				tail = NULL;
				delete hapus;
			}
		else{
			hapus = tail;
			tail = hapus -> prev;
			tail -> next = NULL;
			delete hapus;
		}
		cout << endl << endl;
		tampil();
	}
	
	void tampil(){
		if (head == NULL){
		
		cout << "Data Kosong !\n";}
		else {
			bantu = head;
			cout << " No \t | Nama \t | NIM \t | Asal\t\t |" << endl;
			int no = 0;
			while(bantu != NULL){
			no++;
			cout << " " << no << "\t | ";
			cout << " " << bantu -> nama << "\t | ";
			cout << " " << bantu -> nim << "\t | ";
			cout << " " << bantu -> asal << "\t | " << endl;
			bantu = bantu -> next;
			}
		}
		getch();
	}
