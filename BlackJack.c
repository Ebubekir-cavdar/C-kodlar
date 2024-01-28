#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int kart,kurpiyer,kurpiyertoplam=0,oyuncutoplam=0;
   char girdichar='+';

    srand(time(NULL));

    kart=(rand() % (11+1-1))+1;
    kurpiyer=(rand() % (11+1-1))+1;
    printf("ilk kartiniz: %d kurpiyer: %d\n",kart,kurpiyer);

    kurpiyertoplam+=kurpiyer;
    oyuncutoplam+=kart;

    kart=(rand() % (11+1-1))+1;
    printf("ikinci kartiniz: %d\n",kart);

    oyuncutoplam+=kart;

    if(oyuncutoplam>21) goto end;

    while(1){
        printf("toplam puaniniz: %d cekmek istiyorsaniz '+' kalmak istiyorsaniz '-' ye yaziniz\n",oyuncutoplam);
        scanf(" %c",&girdichar);

        if(girdichar=='-') break;

        kart=(rand() % (11+1-1))+1;
        oyuncutoplam+=kart;

        printf("cektiginiz kart %d\n",kart);
        if(oyuncutoplam>21) goto end;
    }

    while(kurpiyertoplam<16){
        kurpiyer=(rand() % (11+1-1))+1;
        kurpiyertoplam+=kurpiyer;
        printf("kurpiyerin cektigi kart %d, kurpiyerin toplam puani %d\n",kurpiyer,kurpiyertoplam);
    }

    printf("kurpiyerin puani %d,oyuncunun puani %d\n",kurpiyertoplam,oyuncutoplam);

    if(kurpiyertoplam>21) printf("kazandiniz.\n");

    if(oyuncutoplam>kurpiyertoplam) printf("kazandiniz.\n");

    end:
    printf("Oyun bitti");
   return 0;
}
