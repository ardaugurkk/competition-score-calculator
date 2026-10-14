#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AD_UZUNLUK 20
#define HAKEM_SAYISI 10
#define MAX_YARISMACI 50

typedef struct {
	char isim[AD_UZUNLUK];
	char soyisim[AD_UZUNLUK];
	int yas;
	float puanlar[HAKEM_SAYISI];
	float ortalama;

}Yarismaci;

void puanaGoreSirala(Yarismaci yarismacilar[], int yarismaciSayisi) {
	for (int i = 0; i < yarismaciSayisi - 1; i++) {
		for (int j = 0; j < yarismaciSayisi - i - 1; j++) {
			if (yarismacilar[j].ortalama < yarismacilar[j + 1].ortalama) {
				Yarismaci temp = yarismacilar[j];
				yarismacilar[j] = yarismacilar[j + 1];
				yarismacilar[j + 1] = temp;
			}
		}
	}
}

float ortalamaHesapla(Yarismaci yarismaci) {

	float sonuc = 0;
	float max = yarismaci.puanlar[0];
	float min = yarismaci.puanlar[0];

	for (int i = 0; i < HAKEM_SAYISI; i++) {
		if (yarismaci.puanlar[i] <= min) {
			min = yarismaci.puanlar[i];
		}

		else if (yarismaci.puanlar[i] >= max) {
			max = yarismaci.puanlar[i];
		}

		sonuc += yarismaci.puanlar[i];
	}
	sonuc = (sonuc - max - min) / 8;
	return sonuc;
}

void yazdir(Yarismaci yarismaci, int *i) {

	if (i == 0) {
		printf("========SONUÇLAR========\n");
	}
	printf("Yarışmacı ismi: %s %s\n", yarismaci.isim, yarismaci.soyisim);
	printf("Yarışmacı yaşı: %d\n", yarismaci.yas);
	printf("Ortalama puan: %.2f\n", yarismaci.ortalama);
	printf("=========================\n");
}

int main() {
	Yarismaci yarismaci[MAX_YARISMACI];
	int yarismaciSayisi;
	int i;

	printf("Kaç kişi yarışacak? (Maksimum 50 kişi): \n");
	scanf("%d", &yarismaciSayisi);

	if (yarismaciSayisi < 1 || yarismaciSayisi > MAX_YARISMACI) {
		printf("Hata: Yarışmacı sayısı 1 ile 50 arasında olmalıdır.\n");
		return 1;
	}

	for (i = 0; i < yarismaciSayisi; i++) {
		printf("Yarışmacı %d için bilgileri giriniz: \n\n", i + 1);
		printf("Yarışmacı ismi: \n");
		scanf(" %19[^\n]", yarismaci[i].isim);

		printf("Yarışmacı soyismi: \n");
		scanf(" %19[^\n]", yarismaci[i].soyisim);

		printf("Yarışmacı yaşı: \n");
		scanf("%d", &yarismaci[i].yas);

		for (int j = 0; j < HAKEM_SAYISI; j++) {
    		do {
        		printf("%d. hakemin puanını giriniz (0-6): \n", j + 1);
        		scanf("%f", &yarismaci[i].puanlar[j]);

        	if (yarismaci[i].puanlar[j] < 0 || yarismaci[i].puanlar[j] > 6) {
            	printf("Hata: Puan 0 ile 6 arasında olmalıdır. Tekrar deneyin!\n");
        	}
    	} while (yarismaci[i].puanlar[j] < 0 || yarismaci[i].puanlar[j] > 6);
	}

	yarismaci[i].ortalama = ortalamaHesapla(yarismaci[i]);
	}
	puanaGoreSirala(yarismaci, yarismaciSayisi);
	for (i = 0; i < yarismaciSayisi; i++) {
		yazdir(yarismaci[i], &i);
	}
	return 0;
}

