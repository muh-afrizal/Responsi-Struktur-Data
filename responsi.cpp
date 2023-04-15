#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

struct pegawai{
    string nama;
    int umur; 
    string pekerjaan; 
    pegawai *next;
    pegawai *prev;
};

pegawai *head = NULL, *tail, *cur, *temp, *tempNode, *newNode, *minNode, *del;

int countLinkedList(){ // Fungsi untuk menghitung banyak data dalam list
    cur = head;
    int jumlah = 0;
    while(cur != NULL){
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void addFront(){ // Fungsi menambahkan data ke depan
    newNode = new pegawai();
    cout << "\nMENAMBAHKAN DATA KE DEPAN" << endl;
    cout << "Masukan Nama : ";
    getline(cin >> ws, newNode->nama);
    transform(newNode->nama.begin(), newNode->nama.end(), newNode->nama.begin(), ::toupper); // convert string ke Uppercase
    cout << "Masukan Umur : ";
    cin >> newNode->umur;
    cout << "Masukan Pekerjaan : ";
    getline(cin >> ws, newNode->pekerjaan);
    transform(newNode->pekerjaan.begin(), newNode->pekerjaan.end(), newNode->pekerjaan.begin(), ::toupper); // convert string ke Uppercase
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL){
        head->prev = newNode;
        head = newNode;
        return;
    }
    head = newNode;
    tail = head;
}

void addBack(){ // Fungsi menambahkan data ke belakang
    newNode = new pegawai();
    cout << "\nMENAMBAHKAN DATA KE BELAKANG" << endl;
    cout << "Masukan Nama : ";
    getline(cin >> ws, newNode->nama);
    transform(newNode->nama.begin(), newNode->nama.end(), newNode->nama.begin(), ::toupper); // convert string ke Uppercase
    cout << "Masukan Umur : ";
    cin >> newNode->umur;
    cout << "Masukan Pekerjaan : ";
    getline(cin >> ws, newNode->pekerjaan);
    transform(newNode->pekerjaan.begin(), newNode->pekerjaan.end(), newNode->pekerjaan.begin(), ::toupper); // convert string ke Uppercase
    newNode->next = NULL;
    newNode->prev = tail;
    if (head != NULL) {
        tail->next = newNode;
        tail = newNode;
        return;
    }
    tail = newNode;
    head = tail;
}

void removeFront(){ // Fungsi hapus data paling depan
    cout << "\nData yang akan dihapus : ";
    cout << "\nNama : " << head->nama;
    cout << "\nUmur : " << head->umur;
    cout << "\nPekerjaan : " << head->pekerjaan;
    del = head;
    if (head->next == NULL){
        head = NULL;
        tail = NULL;
        delete del;
        return;
    }
    head = head->next;
    head->prev = NULL;
    delete del;
}

void removeBack(){ // Fungsi hapus data paling belakang
    if (tail == NULL){
        cout << "\nData hanya ada satu!!";
        return;
    }
    cout << "\nData yang akan dihapus : ";
    cout << "\nNama : " << tail->nama;
    cout << "\nUmur : " << tail->umur;
    cout << "\nPekerjaan : " << tail->pekerjaan;
    del = tail;
    if (tail->prev == NULL){
        head = NULL;
        tail = NULL;
        delete del;
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void sortNama(){ // Fungsi Sort menurut nama
    tempNode = new pegawai();
    cur = head;
    while (cur->next != NULL){
        minNode = cur;
        temp = cur->next;
        while (temp != NULL){
            if (temp->nama < minNode->nama) {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != cur) { // swapping data
            tempNode->nama = cur->nama;
            cur->nama = minNode->nama;
            minNode->nama = tempNode->nama;

            tempNode->umur = cur->umur;
            cur->umur = minNode->umur;
            minNode->umur = tempNode->umur;
            
            tempNode->pekerjaan = cur->pekerjaan;
            cur->pekerjaan = minNode->pekerjaan;
            minNode->pekerjaan = tempNode->pekerjaan;
        }
        cur = cur->next;
    }
    cout << "\nData di-sort menurut nama" << endl;
}

void sortUmur(){ // Fungsi Sort menurut umur
    tempNode = new pegawai();
    cur = head;
    while (cur->next != NULL){
        minNode = cur;
        temp = cur->next;
        while (temp != NULL){
            if (temp->umur < minNode->umur) {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != cur) { // swapping data
            tempNode->nama = cur->nama;
            cur->nama = minNode->nama;
            minNode->nama = tempNode->nama;

            tempNode->umur = cur->umur;
            cur->umur = minNode->umur;
            minNode->umur = tempNode->umur;
            
            tempNode->pekerjaan = cur->pekerjaan;
            cur->pekerjaan = minNode->pekerjaan;
            minNode->pekerjaan = tempNode->pekerjaan;
        }
        cur = cur->next;
    }
    cout << "\nData di-sort menurut umur" << endl;
}

void sortPekerjaan(){ // Fungsi Sort menurut pekerjaan
    tempNode = new pegawai();
    cur = head;
    while (cur->next != NULL){
        minNode = cur;
        temp = cur->next;
        while (temp != NULL){
            if (temp->pekerjaan < minNode->pekerjaan) {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != cur) { // swapping data
            tempNode->nama = cur->nama;
            cur->nama = minNode->nama;
            minNode->nama = tempNode->nama;

            tempNode->umur = cur->umur;
            cur->umur = minNode->umur;
            minNode->umur = tempNode->umur;
            
            tempNode->pekerjaan = cur->pekerjaan;
            cur->pekerjaan = minNode->pekerjaan;
            minNode->pekerjaan = tempNode->pekerjaan;
        }
        cur = cur->next;
    }
    cout << "\nData di-sort menurut pekerjaan" << endl;
}

void searchNama(){ // Fungsi search data menurut nama
    string cari;
    int i = 0;
    cur = head;

    cout << "\nCARI DATA BERDASARKAN NAMA";
    cout << "\nData yang ingin dicari : ";
    getline(cin >> ws, cari);
    while (cur != NULL){
        if (cur->nama == cari){
            cout << "\nData " << cari << " ditemukan pada indeks ke-" << i+1;
            cout << "\nNama : " << cur->nama;
            cout << "\nUmur : " << cur->umur;
            cout << "\nPekerjaan : " << cur->pekerjaan;
            cur = cur->next;
        }else if (cur->next == NULL){
            cout << "\nData tidak ditemukan!";
            break;
        }else{
            cur = cur->next;
        }
        i++;
    }
}

void searchUmur(){ // Fungsi search data menurut umur
    int cari, i = 0;
    cur = head;

    cout << "\nCARI DATA BERDASARKAN UMUR";
    cout << "\nData yang ingin dicari : ";
    cin >> cari;
    while (cur != NULL){
        if (cur->umur == cari){
            cout << "\nData " << cari << " ditemukan pada indeks ke-" << i+1;
            cout << "\nNama : " << cur->nama;
            cout << "\nUmur : " << cur->umur;
            cout << "\nPekerjaan : " << cur->pekerjaan;
            cur = cur->next;
        }else if (cur->next == NULL){
            cout << "\nData tidak ditemukan!";
            break;
        }else{
            cur = cur->next;
        }
        i++;
    }
}

void searchPekerjaan(){ // Fungsi search data menurut pekerjaan
    string cari;
    int i = 0;
    cur = head;

    cout << "\nCARI DATA BERDASARKAN PEKERJAAN";
    cout << "\nData yang ingin dicari : ";
    getline(cin >> ws, cari);
    while (cur != NULL){
        if (cur->pekerjaan == cari){
            cout << "\nData " << cari << " ditemukan pada indeks ke-" << i+1;
            cout << "\nNama : " << cur->nama;
            cout << "\nUmur : " << cur->umur;
            cout << "\nPekerjaan : " << cur->pekerjaan;
            cur = cur->next;
        }else if (cur->next == NULL){
            cout << "\nData tidak ditemukan!";
            break;
        }else{
            cur = cur->next;
        }
        i++;
    }
}

void printLinkedList(){ // Fungsi menampilkan semua data
    if (countLinkedList() == 0){
        cout << "\nDouble Linked List belum dibuat!!!";
        return;
    }
    system("CLS");
    cout << "\nMENAMPILKAN SEMUA DATA";
    cout << "\nJumlah data : " << countLinkedList();
    cout << "\nData : ";
    cur = head;
    while(cur != NULL){
        cout << "\nNama : " << cur->nama;
        cout << "\nUmur : " << cur->umur;
        cout << "\nPekerjaan : " << cur->pekerjaan;
        cur = cur->next;
    }
}

void menuAdd(){ 
    bool addMenu = true;
    char menu;
    do{
        system("CLS");
        cout << "\n1. Menambah data dari depan"
             << "\n2. Menambah data dari belakang"
             << "\n3. Kembali"
             << "\nPilih Menu >> ";
        cin >> menu;
        switch (menu){
        case '1':
            addFront();
            getch();
            break;
        case '2':
            addBack();
            getch();
            break;
        case '3':
            addMenu = false;
            break;
        default:
            cout << "Pilihan tidak ada!!\nMasukan pilihan sesuai dengan daftar menu" << endl;
            getch();
            break;
        }
        system("CLS");
    } while (addMenu);
}

void menuDelete(){
    if(countLinkedList()==0){
        cout << "\nDouble Linked List belum dibuat!!!";
        getch();
        return;
    }
    bool deleteMenu = true;
    char menu;
    do{
        system("CLS");
        cout << "\n1. Hapus data dari depan"
             << "\n2. Hapus data dari belakang"
             << "\n3. Kembali"
             << "\nPilih Menu >> ";
        cin >> menu;
        switch (menu){
        case '1':
            removeFront();
            getch();
            break;
        case '2':
            removeBack();
            getch();
            break;
        case '3':
            deleteMenu = false;
            break;
        default:
            cout << "Pilihan tidak ada!!\nMasukan pilihan sesuai dengan daftar menu" << endl;
            getch();
            break;
        }
        system("CLS");
    } while (deleteMenu);
}

void menuSort(){
    if(countLinkedList()==0){
        cout << "\nDouble Linked List belum dibuat!!!";
        getch();
        return;
    }
    bool sortMenu = true;
    char menu;
    do{
        system("CLS");
        cout << "\nSorting (Selection Sort)";
        cout << "\n1. Sort Nama (Ascending)"
             << "\n2. Sort Umur (Ascending)"
             << "\n3. Sort Pekerjaan (Ascending)"
             << "\n4. Kembali"
             << "\nPilih Menu >> ";
        cin >> menu;
        switch (menu){
        case '1':
            sortNama();
            getch();
            break;
        case '2':
            sortUmur();
            getch();
            break;
        case '3':
            sortPekerjaan();
            getch();
            break;
        case '4':
            sortMenu = false;
            break;
        default:
            cout << "Pilihan tidak ada!!\nMasukan pilihan sesuai dengan daftar menu" << endl;
            getch();
            break;
        }
        system("CLS");
    } while (sortMenu);
}

void menuSearch(){
    if(countLinkedList()==0){
        cout << "\nDouble Linked List belum dibuat!!!";
        getch();
        return;
    }
    bool searchMenu = true;
    char menu;
    do{
        system("CLS");
        cout << "\nSearch (Sequential Search)";
        cout << "\n1. Search Nama"
             << "\n2. Search Umur"
             << "\n3. Search Pekerjaan"
             << "\n4. Kembali"
             << "\nPilih Menu >> ";
        cin >> menu;
        switch (menu){
        case '1':
            searchNama();
            getch();
            break;
        case '2':
            searchUmur();
            getch();
            break;
        case '3':
            searchPekerjaan();
            getch();
            break;
        case '4':
            searchMenu = false;
            break;
        default:
            cout << "Pilihan tidak ada!!\nMasukan pilihan sesuai dengan daftar menu" << endl;
            getch();
            break;
        }
        system("CLS");
    } while (searchMenu);
}

int main(){
    system("CLS");
    bool isRunning = true;
    char menu;
    do{ // loop untuk menu
        system("CLS");
        cout << "\n1. Print Linked List"
             << "\n2. Menambah data dari depan/belakang"
             << "\n3. Hapus data dari depan/belakang"
             << "\n4. Search (Sequential Search)"
             << "\n5. Sort (Selection Sort)"
             << "\n6. Keluar"
             << "\nPilih Menu >> ";
        cin >> menu;
        switch (menu){
        case '1':
            printLinkedList();
            getch();
            break;
        case '2':
            menuAdd();
            break;
        case '3':
            menuDelete();
            break;
        case '4':
            menuSearch();
            break;
        case '5':
            menuSort();
            break;
        case '6':
            system("CLS");
            isRunning = false;
            cout << "\nSEKIAN TERIMA KASIH";
            exit(0);
            break;
        default:
            cout << "Pilihan tidak ada!!\nMasukan pilihan sesuai dengan daftar menu" << endl;
            getch();
            break;
        }
    } while (isRunning);
}
