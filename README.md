# Triversi - C Programlama Oyunu

[cite_start]Bu proje, 3 oyuncunun (Kırmızı, Sarı, Mavi) değişken boyutlu bir tahta üzerinde stratejik olarak taş yerleştirdiği bir masa oyunudur. [cite: 1, 4]

## Oyun Kuralları
* [cite_start]**Tahta Boyutu:** Maksimum 23x23 olabilir. [cite: 34]
* [cite_start]**Başlangıç:** İlk taş tahtanın tam ortasına yerleştirilir. [cite: 8, 37]
* [cite_start]**Hamleler:** Yeni konulan taş, mevcut taşlarla bitişik olmalıdır. [cite: 9, 135]
* [cite_start]**Dönüşüm:** Aynı renk iki taş arasında kalan rakip taşlar, hamleyi yapan oyuncunun rengine dönüşür (8 yönde kontrol yapılır). [cite: 10, 143]
* [cite_start]**Kazanma:** Tahta dolduğunda en çok taşı olan oyuncu kazanır. [cite: 11]

## Kurulum ve Çalıştırma
Kodu derlemek için terminale şu komutu yazabilirsiniz:
`gcc main.c -o triversi`
`./triversi`
