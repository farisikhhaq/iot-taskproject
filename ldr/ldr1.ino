#define sensorLDR A0
int nilaiSensor;
3. Tambahkan beberapa kode untuk melakukan konfigurasi serial monitor pada fungsi setup() .
Serial.begin(115200);
Serial.println("Contoh Penggunaan Sensor LDR");
delay(3000);
4. Dan yang terakhir, membuat kode untuk membaca nilai dari sensor dan menampilkannya seperti berikut ini pada
fungsi loop() 
