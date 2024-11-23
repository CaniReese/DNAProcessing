# DNAProcessing
Bu proje, bağlı listeler kullanarak gen, kromozom ve DNA işlemlerini gerçekleştiren bir uygulamadır.

Projenin temel özellikleri:
- Çaprazlama: İki kromozomun orta noktalarından parçaların birleştirilmesiyle yeni kromozomlar oluşturulur.
- Mutasyon: Belirtilen kromozom ve gen `X` ile değiştirilir.
- Otomatik İşlemler: `Islemler.txt` dosyasından işlemler okunarak otomatik olarak gerçekleştirilir.
- Ekrana Yazma: Her kromozom için uygun gen mantığa göre seçilip ekrana yazdırılır.

### **Menü Seçenekleri ve Açıklamaları**
Program çalıştırıldığında kullanıcı aşağıdaki menüden bir işlem seçebilir:

1. **Display Population (Popülasyonu Görüntüle):**
   - Şu anda programda kayıtlı olan tüm kromozomları ve genlerini ekrana yazdırır.

2. **Crossover (Çaprazlama):**
   - Kullanıcıdan iki kromozom indeksi alır.
   - Seçilen kromozomların orta noktalarından parçalar birleştirilerek iki yeni kromozom oluşturulur.
   - Yeni kromozomlar popülasyona eklenir.

3. **Mutate (Mutasyon):**
   - Kullanıcıdan bir kromozom ve bir gen indeksi alır.
   - Belirtilen kromozomun ilgili genini `X` karakterine dönüştürür.

4. **Process Automatic Instructions (Otomatik İşlemleri Gerçekleştir):**
   - `Islemler.txt` dosyasını okuyarak dosyadaki talimatlara göre çaprazlama ve mutasyon işlemlerini otomatik olarak gerçekleştirir.
   - Örneğin, `C 0 1` çaprazlama, `M 2 3` mutasyon anlamına gelir.

5. **Display Smallest Genes (En Küçük Genleri Görüntüle):**
   - Her kromozomda sağdan sola doğru giderek, ilk geninden daha küçük bir gen bulursa onu ekrana yazdırır.
   - Eğer küçük bir gen bulunamazsa, ilk geni yazdırır.

6. **Exit (Çıkış):**
   - Programdan çıkış komutudur.

---

### **Klasör Yapısı**
Proje, şu klasör yapısına sahiptir:

Veri_Yapilari/
├── src/                 # Kaynak dosyalar (.cpp)

├── include/             # Başlık dosyaları (.h)

├── bin/                 # Çalıştırılabilir dosya

├── lib/                 # Nesne dosyaları (.o)

├── doc/                 # Rapor dosyası (Rapor.pdf)

├── Dna.txt              # Dna veri dosyası

├── Islemler.txt         # İşlem dosyası

├── Makefile             # Derleme için Makefile

├── benioku.txt          # Proje hakkında kısa bilgi


### **Makefile Komutları**
Projenin derlenmesi ve çalıştırılması için `Makefile` kullanılmıştır. Aşağıdaki komutları komut isteminde çalıştırabilirsiniz:

1. **Projenin Derlenmesi**:
make
Bu komut, `bin/` dizininde çalıştırılabilir dosya (`DNAProcessing.exe`) oluşturur.

2. **Programı Çalıştırma**:
bin\DNAProcessing
Çalıştırılabilir dosyayı başlatır.

3. **Geçici Dosyaların Temizlenmesi**:
make clean
`lib/` ve `bin/` dizinlerinde oluşturulan tüm nesne ve çalıştırılabilir dosyaları temizler.

4. **Tam Yeniden Derleme**:
make rebuild
Tüm dosyaları temizler ve projeyi sıfırdan yeniden derler.

### **Notlar**
- Programın çalıştırılabilmesi için `Dna.txt` ve `Islemler.txt` dosyalarının ana dizinde bulunması gerekmektedir.
- MinGW ortamında çalıştığından emin olun. `g++` ve `make` komutlarının PATH'e doğru eklendiğini kontrol edin.


