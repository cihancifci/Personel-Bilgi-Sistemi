#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

 typedef struct {

 char isim[100];
 char TCKimlikNo[100];
 char telefon[100];
char eposta[100];
char adres[100];

 } personel ;

 personel calisan ;
 personel calisan2 ;
 personel calisan3;

int main()
{


setlocale(LC_ALL, "Turkish");

    printf("PERSONEL BÝLGÝ SÝSTEMÝ \n");
    anamenu();

    return 0;
}

void anamenu()
{

printf("\nÝÞLEMLER \n");
printf("\n1. Kayýt Ekle\n");
printf("2. Personel Listele\n");
printf("3. Kaydý Düzenle\n");
printf("4. TC Kimlik No ile Kayýt Bul\n");
printf("5. Ýsim ile Kayýt Bul\n");
printf("6. Kayýt Sil\n");
printf("0. Çýkýþ\n");
secimm();

}

void secimm() {

int secim ;
printf("\nSeçiminizi girin : \n");
scanf("%d",&secim);



switch (secim)
{
    case 1:
    kayitekle();
        break;

    case 2:
    prsnllistele();
        break;

    case 3:
    kayitduzenle();
        break;

    case 4:
    tcilebul();
        break;

    case 5:
    isimilebul();
        break;

    case 6:
    kayitsil();
        break;

    case 0:
    cikis();
        break;

    default : {
    printf("Hatalý giriþ yaptýnýz !!! \a\n");
    anamenu();

    }

    break;
}
}

void kayitekle()
{
    system("cls");
    FILE *fp;

    if ((fp=fopen("Personel.txt","ab+"))== NULL)
    {
        printf("Dosya açýlmadý !\a\n");
        exit(1);
    }

    printf("\n---------- PERSONEL BÝLGÝLERÝ ----------\n");


        printf("ÝSÝM : ");
        scanf("%s",&calisan.isim);
        printf("TC KÝMLÝK NO : ");
        scanf("%s",&calisan.TCKimlikNo);
        printf("TELEFON  : ");
        scanf("%s",&calisan.telefon);
        printf("E POSTA : ");
        scanf("%s",&calisan.eposta);
        printf("ADRES : ");
        scanf("%s",&calisan.adres);

        if (fwrite(&calisan,sizeof(calisan),1,fp)!= 1)
        {
            printf("Yazma hatasý !\a\n");
            exit(1);
        }
        printf("\n");
        printf("PERSONEL KAYIT EDÝLDÝ ...\n");

    fclose(fp);

    tekrarkayit();

}
void tekrarkayit()
{
char harf;
    printf("\nBaþka kayýt yapmak istiyor musunuz ? \n");
    printf("Evet icin E veya e girin\n");
    printf("Ana menüye dönmek icin H veya h girin\n");
    scanf("%s",&harf);

    if (harf=='E' || harf=='e') {

        kayitekle();

}
      else if (harf=='H' || harf=='h')
      {
          system("cls");
          anamenu();
      }


      else {
        printf("Gecerli bir harf giriniz!!!!\a\n");
        tekrarkayit();
}
}
void prsnllistele()
{
    system("cls");
    FILE *fp;
    if ((fp=fopen("Personel.txt","ab+"))== NULL)
    {
        printf("Dosya açýlmadý !\a\n");
        exit(1);
    }
    int bulunan=0;

    printf("\n---------- CALÝSAN LÝSTESÝ ----------\n");
    while(fread(&calisan2,sizeof(calisan2),1,fp)==1)
    {
        printf("ÝSÝM : %s\n",calisan2.isim);
        printf("TC KÝMLÝK NO : %s\n",calisan2.TCKimlikNo);
        printf("TELEFON : %s\n",calisan2.telefon);
        printf("E POSTA : %s\n",calisan2.eposta);
        printf("ADRES : %s\n",calisan2.adres);
        printf("\n\n");
        bulunan++;
    }
    if (bulunan==0) printf("KAYIT BULUNAMADI !!\n");

    fclose(fp);
    anamenu();
}
void kayitduzenle()
{
    system("cls");
    char isim[100];
    int bulunan=0;
    int kayit=0,kayit2=0;

    printf("\nDüzenlenecek kaydýn ismini girin :");
    scanf("%s",&isim);

    FILE *fp;

    if ((fp=fopen("Personel.txt","rb+"))== NULL)
    {
        printf("Dosya açýlmadý !\a\n");
        exit(1);
    }

     while(fread(&calisan2,sizeof(calisan2),1,fp)==1)
    {
        if (strcmp(isim,calisan2.isim)==0)
        {
        printf("\n----------Bulunan kayýt----------\n");
        printf("ÝSÝM : %s\n",calisan2.isim);
        printf("TC KÝMLÝK NO : %s\n",calisan2.TCKimlikNo);
        printf("TELEFON : %s\n",calisan2.telefon);
        printf("E POSTA : %s\n",calisan2.eposta);
        printf("ADRES : %s\n",calisan2.adres);
        printf("\n\n");
        bulunan++;
        }
        kayit++;
        if (bulunan==1){
            kayit2=kayit2+kayit;
            bulunan=2;
        }
    }

    if (bulunan==0)
    {
        fclose(fp);
        tekrarduzenle();
    }

        printf("Lütfen personelin yeni bilgilerini girin :\n");
        printf("ÝSÝM : ");
        scanf("%s",&calisan3.isim);
        printf("TC KÝMLÝK NO : ");
        scanf("%s",&calisan3.TCKimlikNo);
        printf("TELEFON : ");
        scanf("%s",&calisan3.telefon);
        printf("E POSTA : ");
        scanf("%s",&calisan3.eposta);
        printf("ADRES : ");
        scanf("%s",&calisan3.adres);


    fseek(fp,(kayit2-1)*sizeof(calisan3),SEEK_SET);

     if (fwrite(&calisan3,sizeof(calisan3),1,fp)!= 1)
        {
            printf("Yazma hatasý !\a\n");
            exit(1);
        }
    rewind(fp);
    printf("\nKayýt baþarý ile deðiþtirildi .\n");
    printf("Ana menüye yönlendiriliyorsunuz ...\n");
    bekle(2);
    fclose(fp);
    system("cls");
    anamenu();
}
void tekrarduzenle()
{
      char sec;
        printf("Kayýt bulunamadý !!!\n");
        printf("Tekrar arama yapmak istiyor musunuz ? (E/H)\n");
        scanf("%s",&sec);
        if (sec=='e' || sec=='E')
        {

            kayitduzenle();
        }
        else if (sec=='h' || sec=='H')
        {
            system("cls");
            anamenu();
        }
        else tekrarduzenle();
}
void tcilebul()
{
    system("cls");
    char tc[100];
    int bulunan=0;
    printf("\nAradýðýnýz tc yi girin :");
    scanf("%s",tc);

    FILE *fp;
    if ((fp=fopen("Personel.txt","rb+"))== NULL)
    {
        printf("Dosya açýlmadý !\a\n");
        exit(1);
    }

    printf("\n----------BULUNAN KAYIT---------- \n\n");
    while(fread(&calisan2,sizeof(calisan2),1,fp)==1)
    {
        if (strcmp(tc,calisan2.TCKimlikNo)==0)
        {
        printf("ÝSÝM : %s\n",calisan2.isim);
        printf("TC KÝMLÝK NO : %s\n",calisan2.TCKimlikNo);
        printf("TELEFON : %s\n",calisan2.telefon);
        printf("E POSTA : %s\n",calisan2.eposta);
        printf("ADRES : %s\n",calisan2.adres);
        printf("\n");
        bulunan++;
        }

    }
    if (bulunan==0){
        printf("Personel bulunamadý !!!\a\n");
    }
    else
    printf("%d tane personel bulundu ...\n",bulunan);

    fclose(fp);
    tekrartcbul();
}
void tekrartcbul()
{
    char harf;
    printf("\nBaþka bir tc ile arama yapmak istiyor musunuz ? \n");
    printf("Evet icin E/e girin\n");
    printf("Ana menüye dönmek icin H/h girin\n");
    scanf("%s",&harf);

    if (harf=='E' || harf=='e') {
        tcilebul();

}
      else if (harf=='H' || harf=='h'){
        system("cls");
        anamenu();}

      else {
        printf("Gecerli bir harf giriniz!!!!\a\n");
        tekrartcbul();
}
}
void isimilebul()
{
    system("cls");
    char isim[100];
    int bulunan=0;
    printf("\nAradýðýnýz  ismi girin :");
    scanf("%s",&isim);

    FILE *fp;
    if ((fp=fopen("Personel.txt","rb+"))== NULL)
    {
        printf("Dosya açýlmadý !\a\n");
        exit(1);
    }
    printf("\n----------BULUNAN KAYIT---------- \n\n");
    while(fread(&calisan2,sizeof(calisan2),1,fp)==1)
    {
        if (strcmp(isim,calisan2.isim)==0)
        {
        printf("ÝSÝM : %s\n",calisan2.isim);
        printf("TC KÝMLÝK NO : %s\n",calisan2.TCKimlikNo);
        printf("TELEFON : %s\n",calisan2.telefon);
        printf("E POSTA : %s\n",calisan2.eposta);
        printf("ADRES : %s\n",calisan2.adres);
        printf("\n");
        bulunan++;
        }

    }
    if (bulunan==0){
        printf("Personel bulunamadý !!!\a\n");
    }
    else
    printf("%d tane personel bulundu ...\n",bulunan);
    fclose(fp);
    tekrarisimbul();

}
void tekrarisimbul()
{
    char harf;
    printf("\nBaþka isim aramak istiyor musunuz ? \n");
    printf("Evet icin E/e girin\n");
    printf("Ana menüye dönmek icin H/h girin\n");
    scanf("%s",&harf);

    if (harf=='E' || harf=='e') {
        isimilebul();

}
      else if (harf=='H' || harf=='h'){
        system("cls");
        anamenu();}

      else {
        printf("Gecerli bir harf giriniz!!!!\a\n");
        tekrarisimbul();
}
}
void kayitsil()
{
    system("cls");
    char tc[100];
    int bulunan=0;
    int kayit=0,kayit2=0;

    printf("\nSilinecek kaydýn tc sini girin :");
    scanf("%s",&tc);

    FILE *fp;
    FILE *yeni;

    if ((fp=fopen("Personel.txt","rb+"))== NULL)
    {
        printf("Dosya açýlmadý !\a\n");
        exit(1);
    }
       if ((yeni=fopen("gecici.txt","wb+"))== NULL)
    {
        printf("Dosya açýlmadý !\a\n");
        exit(1);
    }


     while(fread(&calisan2,sizeof(calisan2),1,fp)==1)
    {

        if (strcmp(tc,calisan2.TCKimlikNo)!=0)
        {
             fwrite(&calisan2,sizeof(calisan2),1,yeni);
        }

        else
        {
            bulunan++;
        }
    }



    if (bulunan==0)
    {
        printf("Kayýt bulunamadý !!!\n");
        fclose(fp);
        fclose(yeni);
        tekrarsil();
    }


    fclose(fp);
    fclose(yeni);
    remove("Personel.txt");
    rename("gecici.txt","Personel.txt");

    printf("\nKayýt baþarý ile silindi ...\n");
    printf("Ana menüye yönlendiriliyorsunuz ...\n");

    bekle(2);
    system("cls");
    anamenu();


}
void tekrarsil()
{
     char sec;

        printf("Kayýt silmek için tekrar arama yapmak istiyor musunuz ? (E/H)\n");
        scanf("%s",&sec);
        if (sec=='e' || sec=='E')
        {

            kayitsil();
        }
        else if (sec=='h' || sec=='H')
        {
            system("cls");
            anamenu();
        }
        else {
                printf("Hatalý giriþ yaptýnýz ...\a\n");
                tekrarsil();
        }
}
void cikis()
{
    system("cls");
    char harf;
      printf("\nCikis Yapmak Istiyor musunuz?:\n");
      printf("Evet icin E veya e girin\n");
      printf("Hayir icin H veya h girin\n");
      scanf("%s",&harf);

      if (harf=='E' || harf=='e') {
        printf("Cikis Yapildi...");
        exit(0);
}
      else if (harf=='H' || harf=='h')
      {
            system("cls");
            anamenu();
      }


      else {
        printf("Gecerli bir harf giriniz!!!!\a\n");
        cikis();
}
}
void bekle(int sure)
{
    clock_t son;
    son = clock() + sure * CLK_TCK;
    while(clock() < son){}
}



