#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int en_buyuk2(int dizi[],int eleman);

int main(){

int eleman;

printf("lutfen dizi eleman sayisini giriniz: ");
scanf("%d",&eleman);

int dizi[eleman];

for(int i=0;i<eleman;i++){
    printf("lutfen dizinin %d elemanini giriniz: ",i+1);
    scanf("%d",&dizi[i]);
}

printf("dizinin en buyuk 2. elemani %d degeridir.",en_buyuk2(dizi,eleman));
return 0;
}

int en_buyuk2(int dizi[],int eleman){
    int max=dizi[0],a;

    for(int i=0;i<eleman;i++){

    if(dizi[i]>max) {
            max=dizi[i];
            a=i;
    }
    }

    dizi[a]=INT_MIN;

    max=INT_MIN;

     for(int i=0;i<eleman;i++){

    if(dizi[i]>max) max=dizi[i];

    }

  return max;
}
