#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* menü kýsmýna girilen hatalý deðerleri algýlayýp hata varsa tekrar deðer isteyen fonksiyon*/
int menusecmehata(int *menusecim) {
    while (*menusecim != 1 && *menusecim != 2 && *menusecim != 3) {
        printf("!!!HATALI DEGER GIRDINIZ!!!\n");
        printf("Lutfen gecerli bir sayi giriniz (1, 2 veya 3): ");
        scanf("%d",menusecim);
        continue;
    }
    return 0;
}
/* ürün kýsmýna girilen hatalý deðerleri algýlayýp hata varsa tekrar deðer isteyen fonksiyon*/
 int urunsecmehata(int *urunsecim){
     while(*urunsecim !=1 && *urunsecim !=2 && *urunsecim !=3 && *urunsecim !=4 && *urunsecim !=5 ){
        printf("!!!HATALI DEGER GIRDINIZ!!!\n");
        printf("Lutfen gecerli bir sayi giriniz (1,2,3,4 veya 5):");
        scanf("%d",urunsecim);
        continue;
     }
     return 0;
 }


int main()
{
    int menusecim,urunsecim,odeme,dizi[5]={1,2,3,4,5},i=0,fiyat,j=0;
    char urunisim[50]="";
    /* kullanýcýdan hangi menü kýsmýndan alým yapmak istediðini öðreniyoruz*/
    printf("1 soguk icecekler, 2 sicak icecekler, 3 aburcuburlar olmak uzere 1,2,3 menulerinden hangisinden alim yapmak istediginizi lutfen giriniz: ");
    scanf("%d",&menusecim);
    menusecmehata(&menusecim);

    /* seçtiði menüye göre ürün listesini gösteriyoruz.*/
    switch(menusecim) {
        case 1: printf("\n1:kola 200ml 15TL\n2:su 500ml 5TL\n3:capri sun 330ml 10TL\n4:ice tea 330ml 12TL\n5:ayran 200ml 8TL");
               break;
        case 2: printf("\n1:cay 10TL\n2:sutlu kahve 15TL\n3:sicak cikolata 12TL\n4:espresso 20TL\n5:americano 25TL");
               break;
        case 3: printf("\n1:krispi 15TL\n2:maximus 10TL\n3:browni 12TL\n4:cizi citir 18TL\n5:eti cin 5TL");
               break;
    }
    /* kullanýcýnýn hangi ürünü almak istediðini öðreniyoruz.*/
    printf("\nlutfen almak istediginiz urunun numarasini giriniz: ");
    scanf("%d",&urunsecim);
    urunsecmehata(&urunsecim);
    /* kullanýcýnýn seçtiði ürüne göre fiyat ve ürün isim deðiþkenlerini belirliyoruz.*/
    if (menusecim==1){
        switch(urunsecim) {
            case 1: fiyat =15;
                    strcpy(urunisim,"kolanizi");
                    break;

            case 2: fiyat=5;
                    strcpy(urunisim,"suyunuzu");
                    break;

            case 3: fiyat=10;
                    strcpy(urunisim,"capri sun'inizi");
                    break;

            case 4: fiyat=12;
                    strcpy(urunisim,"ice tea'nizi");
                    break;

            case 5: fiyat=8;
                    strcpy(urunisim,"ayraninizi");
                    break;
        }
    } else if (menusecim==2){
               switch(urunsecim) {
                    case 1: fiyat=10;
                            strcpy(urunisim,"cayinizi");
                            break;

                    case 2: fiyat=15;
                            strcpy(urunisim,"sutlu kahvenizi");
                            break;

                    case 3: fiyat=12;
                            strcpy(urunisim,"sicak cikolatanizi");
                            break;

                    case 4: fiyat=20;
                            strcpy(urunisim,"espressonuzu");
                            break;

                    case 5: fiyat=25;
                            strcpy(urunisim,"americanonuzu");
                            break;

               }
    } else {
          switch(urunsecim) {
              case 1:   fiyat=15;
                        strcpy(urunisim,"krispi'nizi");
                        break;

              case 2:   fiyat=10;
                        strcpy(urunisim,"maximus'nuzu");
                        break;

              case 3:   fiyat=12;
                        strcpy(urunisim,"browni'nizi");
                        break;

              case 4:   fiyat=18;
                        strcpy(urunisim,"cizi citir'inizi");
                        break;

              case 5:   fiyat=5;
                        strcpy(urunisim,"eti cin'ninizi");
                        break;

          }
    }
    /* ödenecek tutar ve ödenen tutar miktar karþýlaþtýrmasýndan yapýlacaklarý belirliyoruz*/
    printf("odenecek tutar %d TL \nlutfen odediginiz tutari sayi olarak giriniz: ",fiyat);
                    scanf("%d",&odeme);
                    /* ödeme fiyattan küçükse yetersiz bakiye yazdýrýp en sona gönderiyoruz*/
                    if(odeme<fiyat) {
                        printf("yetersiz bakiye");
                        goto end;
                    } else if (odeme==fiyat){}
                    /* eðer ödenen ödenecekten fazlaysa para üstünü hesaplayýp veriyor*/
                    else printf("lutfen para ustunuz olan %d TL degerini aliniz.",odeme-fiyat);

    printf("\nUrun hazirlaniyor...\n");
  /* ürünün hazýrlanmasý beklenirken ne zaman biteceði belli olan yani baþý ve sonu olan bir þekil oluþturuyoruz.*/
    for(i=0;i<5;i++){
        for(j=0;j<i;j++){
                printf("*");
                usleep(300000);
        }
        printf("\n");
    }

    for(i=5;i>0;i--){
        for(j=0;j<i;j++){
                printf("*");
                usleep(300000);
        }
        printf("\n");
    }
    /* ürünün ismini yazdýrýp afiyet olsun diyoruz */
    printf("\nlutfen %s  almayi unutmayin afiyet olsun :)",urunisim);
    end:
    printf("\nislem sonlanmistir.");
    return 0;
}
