#include <stdio.h>

/*
  Isim Soyisim:  Elif Altaş
  Ogrenci Numarasi:  2420161078
  BTK Akademi Sertifika Baglantisi:  https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=jK1hGAEM2w
*/

// Bubble Sort (Baloncuk / Kabarcik)
void bubbleSort(int dizi[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        // siralananlari atla
        for (j = 0; j < n - 1 - i; j++) {
            // buyukse yer degis
            if (dizi[j] > dizi[j + 1]) {
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

// Arama fonksiyonu (rekursif) – ikili arama yapar
int binarySearch(int dizi[], int n, int aranan, int ilk_ind, int son_ind) {
    int orta_ind = (ilk_ind + son_ind) / 2;

    if (aranan == dizi[orta_ind]) {
        return orta_ind;
    }
    else if (aranan > dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
        return binarySearch(dizi, n, aranan, orta_ind + 1, son_ind);
    }
    else if (aranan < dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
        return binarySearch(dizi, n, aranan, ilk_ind, orta_ind - 1);
    }
    else {
        return -1;
    }
}

int main() {
    int A[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int aranan, sonuc;
    int N = (int)(sizeof(A) / sizeof(A[0]));

    // 1) Once sirala
    bubbleSort(A, N);

    printf("Aramak istediginiz deger: ");
    scanf("%d", &aranan);

    // 2) Sonra ikili arama yap
    sonuc = binarySearch(A, N, aranan, 0, N - 1);

    if (sonuc == -1) {
        printf("Aradiginiz deger %d, dizide bulunamadi!\n", aranan);
    } else {
        printf("Aradiginiz deger %d, dizinin %d. indisinde bulundu\n", aranan, sonuc);
    }

    return 0;
}
