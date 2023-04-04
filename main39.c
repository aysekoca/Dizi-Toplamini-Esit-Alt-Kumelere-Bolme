                    // Dizi Toplamýný Eþit Alt Kümelere Bölme//
#include <stdio.h>
#include<stdlib.h>

// Alt kümelerin elemanlarý toplamýnýn hedef toplama eþit olup olmadýðýný kontrol eden fonksiyon
int alt_kume_toplami(int set[], int n, int sum)
{
    if (sum == 0) // hedef toplam 0'a eþit ise alt küme var demektir
        return 1;
    if (n == 0 || sum < 0) // alt küme yok demektir
        return 0;
// Elemanýn dahil edilmesi veya dahil edilmemesi durumlarýna göre alt kümelerin toplamlarýný kontrol et
    int include = alt_kume_toplami(set, n-1, sum - set[n-1]);
    int exclude = alt_kume_toplami(set, n-1, sum);
    return include || exclude; // alt kümelerden en az birinin hedef toplama eþit olduðu durumda 1 döndürür
}

// Dizinin iki eþit toplamlý alt kümelere bölünebilirliðini kontrol eden fonksiyon
int iki_alt_kumeye_bolunebilir_mi(int set[], int n)
{
    int toplam = 0, i = 0;
    // Dizinin elemanlarýnýn toplamýný hesaplar
    while (i < n)
    {
        toplam += set[i];
        i++;
    }
    if (toplam % 2 != 0) // Dizi toplamý çift deðilse, iki alt küme eþit toplama bölünemez
        return 0;
    int alt_kume_toplam = 0, j = 0;
    // Diziyi iki alt küme eþit toplamlý olacak þekilde bölerek kontrol et
    while (j < n)
    {
        if (alt_kume_toplam + set[j] <= toplam / 2) // Alt kümenin toplamý hedef toplama eþit olmayacak þekilde ekle
            alt_kume_toplam += set[j];
        j++;
    }
    // Ýki alt kümeye bölünebiliyorsa ve her bir alt kümenin toplamý hedef toplama eþit ise 1 döndürür
    return alt_kume_toplam == toplam / 2 && alt_kume_toplami(set, n, toplam/2); // Dizi, iki eþit toplamlý alt kümeye bölünebilir mi?
}

int main()
{
    int set[100]; //Bir dizi tanýmlanýyor ve boyutu 100 olarak belirtiliyor. 
    int n, i = 0; //n deðiþkeni dizinin boyutunu tutar.i deðiþkeni ise döngü içinde sayýcý olarak kullanýlacak. i deðiþkeni baþlangýç deðeri olarak 0 atanýyor.
    printf("Dizinin Boyutunu Girininiz: "); // Kullanýcýdan dizi boyutunu alýnýr
    scanf("%d", &n); // Kullanýcýnýn girdiði boyut deðeri n deðiþkenine okunuyor.
    printf("Dizinin Elemanlarini Giriniz: "); // Kullanýcýdan dizi elemanlarýný alýnýr.
    while (i < n) //i sayacý n deðerine eþit olana kadar döngü devam edecek.

    {
        scanf("%d", &set[i]);//Program kullanýcýsýndan bir eleman okunuyor ve bu eleman set dizisinin i indeksine atanýyor.
        i++;
    }
    if (iki_alt_kumeye_bolunebilir_mi(set, n)) // Eðer iki_alt_kumeye_bolunebilir_mi fonksiyonu set dizisini ve boyutunu (n) kullanarak 1 döndürürse (yani dizi iki eþit toplamlý alt kümelere bölünebilir), koþul doðru olacak.
        printf("Dizi Iki Esit Toplamli Alt Kumelere Bolunebilir.\n"); //Eðer koþul yanlýþsa, yani dizi iki eþit toplamlý alt kümelere bölünemezse, bu blok çalýþacak.
    else
        printf("Dizi Iki Esit Toplamli Alt Kumelere Bolunemez.\n"); // Eðer koþul yanlýþsa, bu yazýyý ekrana yazdýracak.
    return 0;// Programý normal bir þekilde sonlandýrýr.
}
