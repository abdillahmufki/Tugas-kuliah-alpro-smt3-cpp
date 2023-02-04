#include<stdio.h>
// Binary tree using linked list

typedef struct pohon{
    int data;    
    struct pohon *Kiri;
    struct pohon *Kanan;
}tree;

tree *baru(int data){
    tree *b = new tree;
    b->data = data;
    b->Kanan = NULL;
    b->Kiri = NULL;
    return b;    
}

void SisipSimpulNonRekursif(tree **Akar, int data){
    tree *Baru, *pNow, *temp;
    
    Baru = baru(data);
    if(*Akar == NULL){
        *Akar = Baru;
    }else{
        pNow = *Akar; temp = *Akar;
        while(data != pNow->data && temp != NULL){
            pNow = temp;
            if(data > pNow->data){
                temp = pNow->Kanan;
            }else{
                temp = pNow->Kiri;
            }
        }
        if(data == pNow->data){
            printf("data sudah ada\n");
        }else{
            if(data < pNow->data){
                pNow->Kiri = Baru;
            }else{
                pNow->Kanan = Baru;
            }
        }
    }
}

void SisipSimpulRekursif(tree **Pohon, int data){
    if(*Pohon == NULL){
        *Pohon = baru(data);
    }else{
        if((*Pohon)->data == data){
            printf("data sudah ada\n");
        } else if(data < (*Pohon)->data){
            SisipSimpulRekursif(&(*Pohon)->Kiri, data);
        }else{
            SisipSimpulRekursif(&(*Pohon)->Kanan, data);
        }
    }
}

void RPreorder(tree *Akar){
    if(Akar != NULL){
        printf("%d ", Akar->data);
        RPreorder(Akar->Kiri);
        RPreorder(Akar->Kanan);
    }
}

int main(){
    tree *pohon = NULL;
    SisipSimpulNonRekursif(&pohon, 35);
    SisipSimpulRekursif(&pohon, 50);
    SisipSimpulNonRekursif(&pohon, 20);
    SisipSimpulRekursif(&pohon, 5);
    SisipSimpulNonRekursif(&pohon, 45);
    SisipSimpulRekursif(&pohon, 30);
    SisipSimpulNonRekursif(&pohon, 60);
    SisipSimpulRekursif(&pohon, 55);
    SisipSimpulNonRekursif(&pohon, 10);
    RPreorder(pohon);
    
    return 0;
}