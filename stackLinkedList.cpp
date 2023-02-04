#include <stdio.h>
#include <stdlib.h>
// Stack using linked list

typedef struct{
    int nim;
    char nama[255];
    float ipk;
}mahasiswa;

typedef struct simpul{
    mahasiswa data;
    struct simpul *Next;
}stack;

stack *top = NULL;

void PUSH(mahasiswa data){
    stack *baru = (stack*)malloc(sizeof(stack));
    baru->data = data;
    baru->Next = NULL;
     
    if(top != NULL){
        baru->Next = top;
            
    }else{
        top = baru;
    }
}

void POP(){
    if(top == NULL){
        printf("Data Kosong\n");
    }else{
        stack *hapus = top;
        top = top->Next;
        free(hapus);
    }
}

void Tampil(){
    stack *pNow = top;
    
    if(pNow == NULL){
        printf("Data Kosong\n");
    }else{
        while(pNow != NULL){
            printf("Masukan NIM : %d\n", pNow->data.nim);
            printf("Masukan NAMA : %s\n", pNow->data.nama);
            printf("Masukan IPK : %f\n", pNow->data.ipk);
            pNow = pNow->Next;
        }printf("\n");
    }
}


int main(){
    mahasiswa mhs;
    char pilihan;
    
    do{
        printf("Masukan NIM : "); scanf("%d", &mhs.nim);
        printf("Masukan NAMA : "); scanf("%s", &mhs.nama);
        printf("Masukan IPK : "); scanf("%f", &mhs.ipk);
        PUSH(mhs);
        printf("Masukan data lagi (y/t) : ");
        fflush(stdin); scanf("%c", &pilihan);
    }while(pilihan == 'Y' || pilihan == 'y');
    
    Tampil();
    POP();
    POP();
    Tampil();
  return 0;
}