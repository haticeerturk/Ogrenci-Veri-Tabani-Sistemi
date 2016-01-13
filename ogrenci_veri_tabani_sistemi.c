#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci{
        char ad[20],soyad[20];
        int no;
        int ders_kodlari[10];
};
struct ders{
    char ders_adi[20];
    int ders_kodu;
};

void cikis(){
    int cevap;
    do
    {
        printf("Cikis yapmak istediginize emin misiniz?(E/e/H/h) ");
        cevap=getchar();
        scanf("%c", &cevap);
    }
    while(cevap!='e' && cevap!='E' && cevap!='h' && cevap!='H');
        if(cevap=='e' || cevap=='E'){
        return 0;
        }
    else{
       return main();
       }
}

int main()
{
    FILE *dosya;
    int secim,o_sayac = 0;//o_sayac : öğrenci numaralarını atamak için dosya satırlarını saymada kullanılacak değişken.
    int d_sayac = 1000;//ders kodlarını atamak için kullanılan değişken.Öğrenci numaraları ile karışmaması için 1000 den başlıyor.
    int aranan_ogrenci,aranan_ders;
    int i;
    char satir[100];

    char tempDersKodlari[100];
    char * tempDersKodlariDizi;

    struct ogrenci Ogrenci;
    struct ders Ders;

    printf("1. Öğrenci Ekle\n");
    printf("2. Ders Ekle\n");
    printf("3. Öğrenciyi Derse Kaydet\n");
    printf("4. Öğrenci Derslerini Listele\n");
    printf("5. Dersi Alan Öğrencileri Listele\n");
    printf("6. Çıkış\n\n");
    printf("\t\tLütfen yapmak istediğiniz işlemi seçiniz.\n");
    scanf("%d",&secim);

    switch(secim){
        case 1:
            dosya = fopen("ogrenci.bin","r");
            if(dosya == NULL) printf("404\n");

            while(!feof(dosya)){
                if(fgetc(dosya) == '\n'){//Dosyada kaç satır olduğunu bulmak için.
                    o_sayac += 1;
                }
            }
            fclose(dosya);

            if(o_sayac == 100){//Eğer sistemde ki öğrenci sayısı 100 e ulaştıysa daha fazla öğrenci ekleyemeyip kullanıcıya mesaj geri gönderilecek.
                printf("Yapabileceğiniz öğrenci ekleme sınırına ulaştınız.Daha fazla öğrenci ekleyemezsiniz!\n");
                break;
            }

            Ogrenci.no = o_sayac + 1;

            printf("Lütfen öğrencinin adını ve soyadını giriniz : \n");
            scanf("%s %s",Ogrenci.ad,Ogrenci.soyad);

            if( (strlen(Ogrenci.ad) || strlen(Ogrenci.soyad)) > 20){
                break;
            }

            dosya = fopen("ogrenci.bin","a");
            if(dosya == NULL) printf("404\n");

            fprintf(dosya,"%d %s %s %d\n",Ogrenci.no,Ogrenci.ad,Ogrenci.soyad,&Ogrenci.ders_kodlari);
            fclose(dosya);

            printf("Öğrenci kaydınız başarılı bir şekilde yapılmıştır!\n");
            break;
        case 2:
            dosya = fopen("dersler.bin","r");
            if(dosya == NULL) printf("404\n");

            while(!feof(dosya)){
                if(fgetc(dosya) == '\n'){
                    d_sayac += 1;
                }
            }

            fclose(dosya);

            if(d_sayac == 1020){//Eğer sistemde ki ders sayısı 20 ye ulaştıysa kullanıcıya uyarı verip yeni ders ekleme yapmayacak.
                printf("Yapabileceğiniz ders ekleme sınırına ulaştınız.Daha fazla ders ekleyemezsiniz!\n");
                break;
            }

            Ders.ders_kodu = d_sayac + 1;

            printf("Lütfen eklenecek olan dersin adını giriniz : \n");
            scanf("%s",Ders.ders_adi);

            if( strlen(Ders.ders_adi) > 20 ) break;

            dosya = fopen("dersler.bin","a");
            if(dosya == NULL) printf("NULL\n");

            fprintf(dosya,"%d %s\n",Ders.ders_kodu,Ders.ders_adi);
            fclose(dosya);

            printf("Ders kaydı başarılı bir şekilde yapılmıştır!\n");
            break;

        case 3:
            printf("Kayıt edilecek dersin ders kodunu giriniz : \n");
            scanf("%d",&aranan_ders);
            printf("%d kodlu derse kayıt edilecek öğrencinin numarasını girin : \n",aranan_ders);
            scanf("%d",&aranan_ogrenci);

            char tempDersKodlari[100];
            char * tempDersKodlariDizi;
            int i = 0;

            dosya = fopen("ogrenci.bin","r");
            while(!feof(dosya)){
                fscanf(dosya,"%d %s %s %s\n",&Ogrenci.no,Ogrenci.ad,Ogrenci.soyad,&tempDersKodlari);
                //printf("derskodlari : %s\n", &tempDersKodlari);
                if(aranan_ogrenci == Ogrenci.no){
                    break; // Aranilan ogrenci bulundugunda donguden cikilir.
                }
            }
			fclose(dosya);
            //printf("derskodlari : %s\n", &tempDersKodlari);
            tempDersKodlariDizi = strtok(tempDersKodlari, ",");

            while( tempDersKodlariDizi != NULL )
            {
               //printf( " %s\n", tempDersKodlariDizi);
                Ogrenci.ders_kodlari[i] = atoi(tempDersKodlariDizi);
                i++;
                tempDersKodlariDizi = strtok(NULL, ",");
            }
            // i kac tane ders tuttugunun bilgisini verir.
            int varmi = 0;
            int j;


            for (j = 0; j < i; j++)
            {
                if( Ogrenci.ders_kodlari[j] == aranan_ders ){
                    varmi = 1;
                    break;
                }
            }
            if( varmi == 0 ){
                dosya = fopen("ogrenci.bin","r+");
                while(!feof(dosya)){
                    fscanf(dosya,"%d %s %s %s\n",&Ogrenci.no,Ogrenci.ad,Ogrenci.soyad,&tempDersKodlari);
                    if( Ogrenci.no == aranan_ogrenci ){
                        fseek(dosya,(Ogrenci.no-1)*sizeof(struct ogrenci),SEEK_SET);
                    }
                }
            }


            break;
        case 4:
            printf("Öğrencinin numarasını girin : \n");
            scanf("%d",&aranan_ogrenci);

            dosya = fopen("ogrenci.bin","r");
            while(!feof(dosya)){
                fscanf(dosya,"%d %s %s %s\n",&Ogrenci.no,Ogrenci.ad,Ogrenci.soyad,&tempDersKodlari);
                //printf("derskodlari : %s\n", &tempDersKodlari);
                if(aranan_ogrenci == Ogrenci.no){
                    break; // Aranilan ogrenci bulundugunda donguden cikilir.
                }
            }

            //printf("derskodlari : %s\n", &tempDersKodlari);
            tempDersKodlariDizi = strtok(tempDersKodlari, ",");

            i = 0;
            while( tempDersKodlariDizi != NULL )
            {
               //printf( " %s\n", tempDersKodlariDizi);
                Ogrenci.ders_kodlari[i] = atoi(tempDersKodlariDizi);
                i++;
                tempDersKodlariDizi = strtok(NULL, ",");
            }
            // i kac tane ders tuttugunun bilgisini verir.
            j = 0;
            for (j = 0; j < i; j++)
            {
                printf("%s %s ogrencisinin aldigi %d. dersi :%d\n", Ogrenci.ad, Ogrenci.soyad, j, Ogrenci.ders_kodlari[j]);
            }
            break;
        case 5:
            printf("Bilgi almak istediğiniz derse ait ders kodunu giriniz : \n");
            scanf("%d",&aranan_ders);

            dosya = fopen("ogrenci.bin","r");

            while(!feof(dosya)){
                fscanf(dosya,"%d %s %s %s\n",&Ogrenci.no,Ogrenci.ad,Ogrenci.soyad,&tempDersKodlari);
               	tempDersKodlariDizi = strtok(tempDersKodlari, ",");

                i = 0;
                while( tempDersKodlariDizi != NULL )
                {
                    //printf( " %s\n", tempDersKodlariDizi);
                    Ogrenci.ders_kodlari[i] = atoi(tempDersKodlariDizi);
                    i++;
                    tempDersKodlariDizi = strtok(NULL, ",");
                }

            	j = 0;
            	for(j=0; j<i; j++){
                	if( Ogrenci.ders_kodlari[j] == aranan_ders ){
                   	 printf("Öğrencinin Adı Soyadı Numarası : %s %s %d\n",Ogrenci.ad,Ogrenci.soyad,Ogrenci.no);
                	}
           		 }
            }
            break;
        case 6:
            cikis();
            break;
    }

    return 0;
}
