# main
- `mainwindow w` ile GUI ekranı çalışır.  

# mainwindow
Client verilerinin işlenip ekrana yazılması sağlanır.

### MainWindow
- Arayüz objelerini temsil eden `ui` nesnesi oluşturulur ve Qt Designer’da çizilen objeler pencereye eklenir.  
- Bir `QTableWidget` objesi arayüze eklenmiştir.  
- Client'lerin bağlanacağı **server class constructor**'ı çağırılır.  
- Alarm uyarısı gönderecek socket kurulur ve alarm server’ı ile bağlanır.  
- Bağlantı kesilmesini önlemek için, her bağlantı kesildiğinde yeniden bağlantı kurulacak `connect` bağlantısı kurulur.  
- Bir `QTimer` objesi kurulur. Bu obje her 10 saniyelik dilim sonunda `timeout` sinyali ile `alarmCounter` sayısının belirli bir değerden (2) büyük olma durumunda alarm uyarısı gönderir.  
  - `alarmCounter` ileride açıklanacak olup yangına dair belirli bir sinyal geldiğinde 1’er 1’er artar.  
  - Belirli bir zaman aralığında belirli bir değeri geçtikten sonra yangın olduğu anlaşılır.  
- Ardından client’lerin login, chat ve logout durumlarında gerekli fonksiyonları çağırıcı `connect` bağlantıları kurulur.  
- Son olarak GUI’de gösterilecek `tableWidget` objesinin başlık satırı ayarlanır. Bu tabloda client’lerin:  
  - ismi,  
  - türü,  
  - id’si,  
  - değeri,  
  - login zamanı,  
  - son veri zamanı,  
  - sondan bir önceki veri zamanı,  
  - logout zamanı  
  mevcuttur.

### onLoginOccured
- Bu fonksiyonu anlatmadan önce `mainwindow.h`’taki `sensorData` struct’ı ve `nameToRowMap` map’ini açıklamak lazım.  
  - `sensorData`: client’lere (sensörlere) ait `typeID`, `value`, tabloda kaçıncı satırda bulunduğu (`row`), ve en son sensör verisini ne zaman gönderdiğini (`time`) tutar.  
  - `nameToRowMap`: key’lerin client name olduğu, value’ların ise o client’e ait `sensorData` olduğu bir `QMap`.  
- Başlangıçta login’in ne zaman oluştuğunu ifade eden `time` objesi kurulur.  
- Eğer bu client geçmişte login olduysa (`nameToRowMap.contains(name)`) → `row` değişkenine bu client’in tabloda hali hazırda bulunduğu satırın numarası verilir.  
- Eğer ilk defa login oluyorsa → tabloda yeni bir yer açılır, ardından client name ve typeID tabloda gerekli yerlere doldurulur. Aynı zamanda bu değerler `nameToRowMap`’e kaydedilir (row değeri ile birlikte).  
- If-else bloğundan çıktıktan sonra tablonun geri kalan kısmı boş string ile doldurulur. (Bu, daha önce login olup sonra logout olan bir client’in verilerinin sıfırlanması için yapılır.)  
- En son olarak login time tabloya yazılır.  

### onChatReceived
- Burada da `time` objesi, sensör verisinin ne zaman geldiğini belirtir.  
- Ardından if bloğu içinde client’in var olup olmadığı (login mi değil mi) kontrol edilir.  
  - Eğer login değilse hata mesajı verilir ve `return` edilir.  
- Sonrasında client’e ait `row` değeri alınır.  
- Tabloda son verinin geldiği zaman, sondan 2. verinin geldiği zamana kaydırılır. Yeni veri zamanı son verinin geldiği zamana koyulur. Client’in ID’si tabloya yazılır.  
- Ardından bu veri ile beraber:  
  - Son iki değeri belirli bir eşik değerin üstünde,  
  - Son iki değer arasındaki zaman farkı 5 saniyeden az,  
  - `typeID == 2` (yani sıcaklık sensörü)  
  olması durumunda → `alarmCounter` 1 arttırılır.  
- `alarmCounter` bu şekilde tüm client’ler üzerinden gelen verilere göre 1’er 1’er artabilir. Eşik değerini geçince alarm verir (başta bahsettiğimiz `connect` bağlantısı ile).  
- Ardından `value` ve son verinin gelme zamanı `nameToRowMap`’e işlenir.  
- Son olarak `value` değeri tabloya işlenir.  

### onLogoutOccured
- Logout zamanı `time` değişkenine atanır.  
- Eğer daha login dahi olmamış bir client logout oluyorsa → bu ciddi bir hatadır ve `return` edilir.  
- If bloğuna girilmezse → bu client’in satırı bulunur ve logout zamanı tabloya işlenir.  

# server
Client’lerin bağlanacağı, verilerin okunup işleneceği ve client’lere cevap verecek olan server.

`server.h`’ta tanımlanmış bazı yapılar:
- **clients listesi** → client socket’lerini taşır (bu projede önemsiz, kullanılmıyor).  
- **ClientData struct** → client’e ait `name`, `typeID`, `buffer` (socket’ten gelen veri), `expectedSize` (verinin uzunluğu), `timer` (client’in mesaj atması için sınırlı süre) değerlerini tutar.  
- **clientdatas QMap** → key: client socket, value: `ClientData` struct.  
- **loginController QMap** → key: client socket, value: bool. Client’in login olup olmadığını kontrol eder.  

### Server
- `mainwindow`’da server constructor çağırıldıktan sonra bu kısım devreye girer.  
- Bir `QTcpServer` oluşturulur ve local IP üzerinden porta bağlanır.  
- Yeni bir connection olduğunda ve bekleyen connection olduğunda bağlı olan client için bir `QTcpSocket` oluşturulur (`client`). Ardından sıradaki bekleyen connection bu sockete atanır.  
- `clients` listesine bu client eklenir ve `clientdatas`’a default veriler atanır.  
- Timer `connect` bağlantısı ile timeout olduğunda client’in logout olması gerekir.  
  - `loginController`’da gerekli değişiklik yapılır.  
  - `logoutOccured` sinyali verilir → bu sinyal `mainwindow`’da kullanılacaktır.  
  - Client’in host ile bağlantısı kesilir.  
- Client okumaya hazır olduğunda → `clientdatas[client].buffer`’a veri okuması başlanır.  
  - Buffer’da veri kalmayana kadar ve ilk 4 byte okunana kadar (burada `expectedSize == 0` olduğu sürece ilk 4 byte okunmamış demektir) veri okunmaya devam eder.  
  - İlk 4 byte üzerinden buffer’daki verinin uzunluğu `expectedSize` olarak çekilir ve bu kısım buffer’dan silinir.  
  - Buffer size, `expectedSize`’dan küçük olduğu sürece `return` edilir ve döngü tekrar girilir.  
- En son durumda buffer’dan `expectedSize` kadar veri çekilip `message` `QByteArray`’ine atanır.  
  - Buffer’dan `expectedSize` kadar byte silinir.  
  - `clientdatas[client].expectedSize` yeniden 0 yapılır.  
  - `handleMessage(client, copy(message))` fonksiyonu çağırılır.  
- Client disconnected olduğunda → `clients` ve `clientdatas`’tan silinir, en son `client->deleteLater()` ile yok edilir.  

### handleMessage
- Burada gelen mesaj işlenecek ve çeşitli uygulamalar yapılacaktır.  
- Başlangıçta bir `wrapper` ve `m_serializer` nesnesi oluşturulup, wrapper’a `data` (yani message) deserialize edilir. Hata olursa hata bildirimi yapılır.  
- Wrapper login ise ve client daha login olmadıysa if bloğu içinde kontrol edilir.  
  - Eğer doğru ise `clientdatas[client]`’e client’e ait veriler atanır.  
  - Ardından `loginOccured` sinyali gönderilir.  
- Timer objesi çalıştırılır.  
- Cevap için `response` wrapper oluşturulur ve içine bir chat set edilir. Bu chat’e sender set edilir.  
- `payload` ile `response` serialize edilir. Payload’ın başına size eklenmesi için `QDataStream` kullanılır.  
- En son olarak bu oluşan packet client socket üzerinden client’e yazılıp yayınlanır.  
- Eğer wrapper chat ise ve login olunmuşsa → client timer başlatılır, `chatReceived` sinyali emit edilir ve gerekli argümanlar bu sinyalle taşınır.  

---

📌 **Genel olarak server’ın amacı:**  
Verileri hafızaya almak ve sinyal ile `mainwindow`’a göndermektir.
# message.proto
- Bu dosya, client ve server arasındaki mesajlaşma protokolünü tanımlar.  
Kullanılan sözdizimi **Protocol Buffers v3 (proto3)**’tür.

## Paket
- **package chat;**  
  Tüm mesajlar `chat` paketine ait.

## Mesajlar

### Login
- `string name = 1;` → Client’in ismi  
- `int64 time = 2;` → Login zamanı (timestamp)  
- `int64 typeID = 3;` → Client türü (ör. sensör tipi)

### Sensor
- `string iD = 1;` → Sensör ID’si  
- `int64 value = 2;` → Ölçülen değer  
- `int64 typeID = 3;` → Sensör türü (`1 = nem (humi)`, `2 = sıcaklık (temp)`)

### Chat
- `string sender = 1;` → Mesajı gönderen client  
- `Sensor sensors = 2;` → Mesaj içindeki sensör verisi

### Wrapper
- **oneof payload** → Paket tipini belirler:  
  - `Login login = 1;` → Login mesajı  
  - `Chat chat = 2;` → Chat/sensör verisi mesajı

---

## Özet
- `Login` → Client’in sisteme bağlanma bilgileri  
- `Chat` → Sensör verilerinin gönderimi  
- `Wrapper` → Dış katman, mesaj türünü ayırt etmek için kullanılır.  

Bu yapı sayesinde client ve server arasındaki haberleşme standart ve tip güvenli hale getirilir.
