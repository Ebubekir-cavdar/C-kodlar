#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char kelime[100],harf[100];
    int sayac=0,elemansayi=-1;

    fgets(kelime,100,stdin);

    for(int k=0;k<100;k++){
        if(kelime[k]=='\0') break;
        elemansayi++;

    }

    for(int i=0;i<elemansayi;i++) {
        for(int j=97;j<123;j++){
            harf[i]=j;
            if(kelime[i]==32) harf[i]=32;
            harf[i+1]='\0';
            printf("%s \n",harf);
            usleep(10000);
            if(harf[i]==kelime[i]) break;
        }
    }

    return 0;
}
