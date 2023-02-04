#include <stdio.h>
#define MAX 5
#include <stdlib.h>
// Queue using array

typedef struct{
    int nim;
    char nama[255];
    float ipk;
}mahasiswa;

typedef struct{
    mahasiswa data[MAX];
    int depan; // inisialisasi data paling depan
    int belakang; // inisialisasi data paling belakang
}queue;
queue antrian;

void init(){
    antrian.depan = 0;
    antrian.belakang = 0;
}

void addq(mahasiswa data){
    if(antrian.belakang == MAX){
        printf("antrian penuh\n");
    }else{
        antrian.data[antrian.belakang] = data;
        antrian.belakang++;
    }
}

void deleteq(){
    if(antrian.depan == antrian.belakang){
        printf("antrian kosong\n");
    } else {
        antrian.depan++;
        for(int i = antrian.depan; i < antrian.belakang; i++){
            antrian.data[i - 1] = antrian.data[i];
        }
            antrian.depan--;
            antrian.belakang--; 
    }
}

void Tampil(){
    if(antrian.depan == antrian.belakang){
        printf("antrian kosong\n");
    } else {
        printf("NIM NAMA IPK\n");
        for(int i = antrian.depan; i < antrian.belakang; i++){
              printf("%d %s %f\n ", antrian.data[i].nim, antrian.data[i].nama, antrian.data[i].ipk); 
          }                
    }
  
}

int main(){
    char pilihan;
    mahasiswa mhs;
    init();
    
    do{
        printf("Masukan NIM : "); scanf("%d", &mhs.nim);
        printf("Masukan NAMA : "); scanf("%s", &mhs.nama);
        printf("Masukan IPK : "); scanf("%f", &mhs.ipk);
        addq(mhs);
        printf("Masukan data lagi (y/t)?"); fflush(stdin); scanf("%c", &pilihan);
    }while(pilihan == 'Y' || pilihan == 'y');
    
    Tampil();
    deleteq();
    Tampil();
  return 0;
}