#include<stdio.h>
// Queue using linked list

typedef struct{
    int nim;
    char nama[255];
    float ipk;
}mahasiswa;

typedef struct list{
    mahasiswa data;
       struct list *Next;
}queue;

queue *depan = NULL, *belakang = NULL;

void addq(mahasiswa data){
    queue *baru = new queue;
    baru->data = data;
    baru->Next = NULL;
    
    if(depan == NULL){
        depan = baru;    
    } else {
        belakang->Next = baru;
    }
    belakang = baru;
}

void deleteq(){
    if(depan == belakang){
        belakang = belakang->Next;
    }
    depan = depan->Next;    
    
}

void Tampil(){
    queue *pNow = depan;
    if(pNow == NULL){
        printf("data kosong\n");
    } else {
        printf("NIM NAMA IPK\n");
        while(pNow != NULL){
            printf("%d %s %.2f\n ", pNow->data.nim, pNow->data.nama, pNow->data.ipk);
            pNow = pNow->Next;
        }
    }
}

int main(){
    char pilihan;
    mahasiswa mhs;
    
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