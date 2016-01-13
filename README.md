Ögrenci Veri Tabanı Sistemi

Sistemde bulunacak struct yapıları: Öğrenci ve Ders<br/>
Öğrenci struct yapısında bulunacak alanlar: Ad (string), soyad (string), no (int) ve aldığı ders kodları (int dizisi).<br/>
Ders struct yapısında bulunacak alanlar: Ders adı (string) ve Ders kodu (int)<br/>
String alanlar maksimum 20 karakter alır. Öğrenci yapısındaki “aldığı ders kodları” dizisi en fazla 10 elemanlıdır. Sistemde en fazla 100 öğrenci ve 20 ders kaydı bulunacaktır.<br/>
Öğrenci no ve ders kodu tekil alanlardır. Yani aynı öğrenci numarasına sahip başka bir öğrenci olmayacaktır. Aynı şekilde aynı ders koduna sahip başka ders de olmamalıdır. Bu alanlar sistem tarafından otomatik olarak verilmelidir.<br/>
Sistemdeki Öğrenci verileri ogrenci.bin dosyasına kaydedilecek. Ders verileri ise dersler.bin dosyasına kaydedilecek. Bu iki dosya da binary dosyalar olmalı ve yukarıdaki struct yapılarını binary formatta kaydetmelidir.<br/>
Oluşturulacak menü sisteminde şu komutlar olmalı:<br/>
1. Öğrenci ekle<br/>
2. Ders ekle<br/>
3. Öğrenciyi derse kaydet<br/>
4. Öğrenci derslerini listele<br/>
5. Dersi alan öğrencileri listele<br/>
6. Çıkış<br/>
Açıklamalar:<br/>
1. Öğrenci ekle: Yeni bir öğrenci kaydı oluşturur. Kullanıcıdan ad soyad bilgilerini alır. Öğrenci numarasını program sıralı olarak otomatik atar. Kaydı ogrenci.bin dosyasına ekler.<br/>
2. Ders ekle: Yeni bir ders oluşturmak için kullanıcıdan ders adı bilgisini alıp otomatik bir ders kodu atar. Yeni dersi dersler.bin dosyasına kaydeder.<br/>
3. Öğrenciyi derse kaydet: Kullanıcıdan öğrenci numarası ve ders kodunu sorar. Öğrencinin aldığı dersler listesine girilen dersi eğer yoksa ekler. İlgili bin dosyalarına kaydedilir.<br/>
4. Öğrenci derslerini listele: Kullanıcıdan alınan öğrenci numarasına göre o öğrencinin sistemde kayıtlı olduğu tüm dersleri adı ve kodu ile birlikte listeler.<br/>
5. Dersi alan öğrencileri listele: Kullanıcıdan alınan ders koduna ait derse kayıtlı olan öğrencileri ad soyad ve öğrenci numarası bilgileriyle birlikte listeler.Dosya içerisinde rastgele erişim okuma ve yazma işlemlerinin düzgün çalışması için fopen ile açılan dosyanın doğru parametreler ile açılması gerekir.<br/>
