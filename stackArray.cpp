#include <stdio.h>
#define MAX 2
//Tumpukan with array

typedef struct{
    int nim;
    char nama[255];
    float ipk;
}mahasiswa;

typedef struct{
    mahasiswa data[MAX];
    int top;    
}tumpukan;

tumpukan stack;
void init(){
    stack.top = 0;    
}

void PUSH(mahasiswa data){
    if(stack.top < MAX){
        stack.data[stack.top] = data;
        stack.top++;
    }else{
        printf("Data Penuh\n");
    }
}

void POP(){
    if(stack.top == 0){
        printf("Data Kosong\n");
    }else{
        stack.top--;    
    }
}

void Tampil(){
    if(stack.top == 0){
        printf("Data Kosong\n");
    }else{
        for(int i = 0; i < stack.top; i++){
            printf("Masukan NIM : %d\n", stack.data[i].nim);
            printf("Masukan NAMA : %s\n", stack.data[i].nama);
            printf("Masukan IPK : %f\n", stack.data[i].ipk);
        }
    }
}

int main() {
    mahasiswa mhs;
    char pilihan;
    
    init();
    
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