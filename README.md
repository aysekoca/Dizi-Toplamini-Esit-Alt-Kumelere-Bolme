# Dizi-Toplamini-Esit-Alt-Kumelere-Bolme
# PROJEDE KULLANILAN ALGORİTMALAR VE AMAÇLARI 
Bu program, verilen bir tamsayı dizisini iki eşit toplamlı alt kümeye bölebilir olup olmadığını kontrol eder.
Program, bir dizi ve dizinin boyutunu alır. İlk olarak, dizinin toplamını hesaplar ve toplamın çift olup olmadığını kontrol eder. Toplam çift değilse, dizinin iki alt küme eşit toplama bölünemez ve program çıktı olarak "Dizi iki eşit toplamlı alt kümelere bölünemez." mesajını verir.
Eğer toplam çift ise, program, dizi elemanlarının toplamının yarısına eşit bir toplama sahip iki alt küme oluşturulup oluşturulamayacağını belirlemek için "alt_kume_toplami" adlı bir fonksiyon kullanır. Bu fonksiyon, alt kümelerin elemanlarının toplamının hedef toplama eşit olup olmadığını kontrol eder.
"alt_kume_toplami" fonksiyonu, dizinin son elemanına kadar her elemanı ele alarak özyinelemeli (recursive) bir şekilde çağrılır. Fonksiyon, son elemana gelindiğinde hedef toplama ulaşılmışsa 1, ulaşılamamışsa 0 değerini döndürür.

Program, "alt_kume_toplami" fonksiyonunu iki defa çağırarak her iki alt kümeye de ayrı ayrı bakar ve her bir alt kümenin elemanlarının toplamının hedef toplama eşit olup olmadığını kontrol eder. Eğer iki alt kümenin elemanları toplamı eşitse, program "Dizi iki eşit toplamlı alt kümelere bölünebilir." mesajını verir. Aksi takdirde, program "Dizi iki eşit toplamlı alt kümelere bölünemez." mesajını verir.
Bu program, dizi elemanlarının toplamının yarısına eşit iki alt küme oluşturup oluşturamayacağını belirlemek için alt kümelerin elemanlarının toplamını kontrol eden bir özyinelemeli algoritma kullanır. Bu algoritma, büyük boyutlu dizilerde performans sorunlarına neden olabilir, ancak küçük boyutlu dizilerde genellikle hızlı çalışır.

## Kullanılan Fonksiyonlar
**1.alt_kume_toplami(int set[], int n, int sum):** Bu fonksiyon, verilen set dizisindeki elemanlar arasından toplamı sum olan alt kümelerin var olup olmadığını kontrol eder. Bu amaçla, özyinelemeli (recursive) bir yaklaşım kullanır. Fonksiyon, verilen toplama ulaşılması durumunda 1 döndürür ve verilen toplama ulaşılamaması durumunda 0 döndürür. Fonksiyon, set dizisindeki elemanları sırasıyla dahil ederek ve dahil etmeden alt kümelerin toplamlarını hesaplayarak tüm alt küme toplamlarını kontrol eder.

**2.iki_alt_kumeye_bolunebilir_mi(int set[], int n):** Bu fonksiyon, verilen set dizisinin iki eşit toplamlı alt kümelere bölünebilir olup olmadığını kontrol eder. Bu amaçla, alt_kume_toplami fonksiyonunu kullanır. Fonksiyon, set dizisindeki elemanların toplamını hesaplar ve toplamın çift sayı olup olmadığını kontrol eder. Eğer toplam çift sayı ise, toplamın yarısına eşit olan bir hedef toplam belirler ve alt_kume_toplami fonksiyonunu kullanarak bu hedef toplama ulaşılabilir mi diye kontrol eder.
Programın çalışma mantığı, verilen dizinin iki eşit toplamlı alt kümelere bölünebilir olup olmadığını kontrol etmek üzere iki_alt_kumeye_bolunebilir_mi fonksiyonunu kullanmaktır. Bu fonksiyon, özyinelemeli bir fonksiyon olan alt_kume_toplami fonksiyonunu kullanarak alt kümelerin toplamlarını hesaplar. Eğer verilen dizinin toplamı çift sayı ise, iki_alt_kumeye_bolunebilir_mi fonksiyonu, dizinin elemanlarının toplamının yarısına eşit olan bir hedef toplam belirler ve alt_kume_toplami fonksiyonunu kullanarak bu hedef toplama ulaşılabilir mi diye kontrol eder. Eğer hedef toplama ulaşılabilirse, o zaman verilen dizi iki eşit toplamlı alt kümelere bölünebilir demektir. Aksi takdirde, dizi iki eşit toplamlı alt kümelere bölünemez.
# KOD NASIL KULLANILIR , NASIL TEST EDİLİR? 
Bu kod, bir dizinin iki eşit toplamlı alt kümelere bölünebilirliğini kontrol eder. Kodun çalışması için öncelikle bir dizi boyutu ve elemanları kullanıcı tarafından girilmelidir. Kodun nasıl kullanılacağına ilişkin bir örnek aşağıda verilmiştir.

Örnek kullanım:
Dizinin Boyutunu Girininiz: 6

Dizinin Elemanlarini Giriniz: 2 4 8 9 12 15

Dizi Iki Esit Toplamli Alt Kumelere Bolunemez.

Bu örnekte, kullanıcı tarafından girilen 6 elemanlı bir dizi var. Dizinin iki eşit toplamlı alt kümelere bölünebilirliği kontrol edildi ve sonuç olarak "Dizi Iki Esit Toplamli Alt Kumelere Bolunemez." yazısı ekrana yazdırıldı.

Bu kodu farklı dizi boyutları ve elemanları ile test ederek doğru bir şekilde çalıştırılabiilir.
