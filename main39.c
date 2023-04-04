                    // Dizi Toplam�n� E�it Alt K�melere B�lme//
#include <stdio.h>
#include<stdlib.h>

// Alt k�melerin elemanlar� toplam�n�n hedef toplama e�it olup olmad���n� kontrol eden fonksiyon
int alt_kume_toplami(int set[], int n, int sum)
{
    if (sum == 0) // hedef toplam 0'a e�it ise alt k�me var demektir
        return 1;
    if (n == 0 || sum < 0) // alt k�me yok demektir
        return 0;
// Eleman�n dahil edilmesi veya dahil edilmemesi durumlar�na g�re alt k�melerin toplamlar�n� kontrol et
    int include = alt_kume_toplami(set, n-1, sum - set[n-1]);
    int exclude = alt_kume_toplami(set, n-1, sum);
    return include || exclude; // alt k�melerden en az birinin hedef toplama e�it oldu�u durumda 1 d�nd�r�r
}

// Dizinin iki e�it toplaml� alt k�melere b�l�nebilirli�ini kontrol eden fonksiyon
int iki_alt_kumeye_bolunebilir_mi(int set[], int n)
{
    int toplam = 0, i = 0;
    // Dizinin elemanlar�n�n toplam�n� hesaplar
    while (i < n)
    {
        toplam += set[i];
        i++;
    }
    if (toplam % 2 != 0) // Dizi toplam� �ift de�ilse, iki alt k�me e�it toplama b�l�nemez
        return 0;
    int alt_kume_toplam = 0, j = 0;
    // Diziyi iki alt k�me e�it toplaml� olacak �ekilde b�lerek kontrol et
    while (j < n)
    {
        if (alt_kume_toplam + set[j] <= toplam / 2) // Alt k�menin toplam� hedef toplama e�it olmayacak �ekilde ekle
            alt_kume_toplam += set[j];
        j++;
    }
    // �ki alt k�meye b�l�nebiliyorsa ve her bir alt k�menin toplam� hedef toplama e�it ise 1 d�nd�r�r
    return alt_kume_toplam == toplam / 2 && alt_kume_toplami(set, n, toplam/2); // Dizi, iki e�it toplaml� alt k�meye b�l�nebilir mi?
}

int main()
{
    int set[100]; //Bir dizi tan�mlan�yor ve boyutu 100 olarak belirtiliyor. 
    int n, i = 0; //n de�i�keni dizinin boyutunu tutar.i de�i�keni ise d�ng� i�inde say�c� olarak kullan�lacak. i de�i�keni ba�lang�� de�eri olarak 0 atan�yor.
    printf("Dizinin Boyutunu Girininiz: "); // Kullan�c�dan dizi boyutunu al�n�r
    scanf("%d", &n); // Kullan�c�n�n girdi�i boyut de�eri n de�i�kenine okunuyor.
    printf("Dizinin Elemanlarini Giriniz: "); // Kullan�c�dan dizi elemanlar�n� al�n�r.
    while (i < n) //i sayac� n de�erine e�it olana kadar d�ng� devam edecek.

    {
        scanf("%d", &set[i]);//Program kullan�c�s�ndan bir eleman okunuyor ve bu eleman set dizisinin i indeksine atan�yor.
        i++;
    }
    if (iki_alt_kumeye_bolunebilir_mi(set, n)) // E�er iki_alt_kumeye_bolunebilir_mi fonksiyonu set dizisini ve boyutunu (n) kullanarak 1 d�nd�r�rse (yani dizi iki e�it toplaml� alt k�melere b�l�nebilir), ko�ul do�ru olacak.
        printf("Dizi Iki Esit Toplamli Alt Kumelere Bolunebilir.\n"); //E�er ko�ul yanl��sa, yani dizi iki e�it toplaml� alt k�melere b�l�nemezse, bu blok �al��acak.
    else
        printf("Dizi Iki Esit Toplamli Alt Kumelere Bolunemez.\n"); // E�er ko�ul yanl��sa, bu yaz�y� ekrana yazd�racak.
    return 0;// Program� normal bir �ekilde sonland�r�r.
}
