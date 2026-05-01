#include "game.h"
using namespace sf;



// Ekran gözükmesi için

oyun::oyun():topum(400.0f, 450.0f),skorEkranım(20.f,20.f){
    ekran.create(VideoMode(800,600), "Breakout");

    ekran.setFramerateLimit(60);

// 8 farklı küme için 2x4'lük bir renk matrisi oluşturuyoruz
sf::Color kumeRenkleri[2][4] = {
    {sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan},
    {sf::Color(163,66,86), sf::Color(70,76,15), sf::Color(0,153,76), sf::Color(255, 165, 0)},
    
};

// Toplam 8 satır ve 20 sütunluk döngü
for (int i = 0; i < 8; i++) { 
    for (int j = 0; j < 20; j++) { 
        
        // 1. STANDART ARALIK HESABI 
        float xPozisyonu = j * 25.0f; 
        float yPozisyonu = i * 25.0f; 

        // 2. DİKEY KORİDORLAR (Sütunları 4 Kümeye Ayırma)
        if (j >= 5) xPozisyonu += 40.0f; 
        if (j >= 10) xPozisyonu += 40.0f; 
        if (j >= 15) xPozisyonu += 40.0f; 

        // 3. YATAY KORİDORLAR (Satırları 2 Kümeye Ayırma)
        if (i >= 4) yPozisyonu += 40.0f; 
       

        // 4. EKRAN BAŞLANGIÇ NOKTALARI
        xPozisyonu += 92.5f; 
        yPozisyonu += 50.0f; 

        // 5. KÜME RENGİNİ TESPİT ETME (Mantıksal Gruplama)
        // C++ tam sayıları bölerken ondalıkları atar. 
        // Örneğin j=0,1,2,3,4 için (j/5) her zaman 0 sonucunu verir.
        int kumeSatiri = i / 4; // 0, 1 veya 2 değerini üretir
        int kumeSutunu = j / 5; // 0, 1, 2 veya 3 değerini üretir
        
        // Matristen ilgili rengi seç
        sf::Color gecerliRenk = kumeRenkleri[kumeSatiri][kumeSutunu];

        // 6. TUĞLAYI OLUŞTUR VE LİSTEYE EKLE (Rengi parametre olarak yolluyoruz)
        tuglalar.push_back(tugla(xPozisyonu, yPozisyonu, 20.0f, 20.0f, gecerliRenk)); 
    }
}
}

// Run time da olay kontrolü için

void oyun::calisma(){
    while (ekran.isOpen())
    {
        processEvents();
        update();        
        render();
    }
    
}

// Oyun bitince ekranı kapatsın diye

void oyun::processEvents(){
    while (ekran.pollEvent(olay))
    {
        if(olay.type==Event::Closed){
            ekran.close();
        }
    }
    
}

void oyun::update(){
    raketim.guncelle();
    topum.guncelle();


     for (auto& t : tuglalar) {
        if(!t.KirildiMi && topum.getSinirlar().intersects(t.getSinirlar())){ // Burda top tuğla sınırlarına çarpmışmı baılır eğer true dönerse aşağıda tuğlaları kaldırma işlemi olur ardından top -hız_y olur ve break yapıp döngüyü bitiririz yoksa sonsuz döngü olup hepsini silebilir
            t.KirildiMi=true;
        
        topum.tugladansek();
        skorEkranım.SkorEkle(1);
        break;
        }


    if(topum.getSinirlar().intersects(raketim.getSinirlar())){ //Topun sınırı raketin sınırıyla kesiştimi demek
       
        float RaketMerkezi=raketim.getSinirlar().left +(raketim.getSinirlar().width / 2.0f); // 2 ye bölüyoz çünü merkezini eklicez x in başlangıcına böylece tam orta nokta bulcaz neden .left yaptık çünkü SFML de right yok left top width height var right yapıncada açılıyo çalışıyor ama hata veriyor neden burda yaptık burası yönetici topu değiştircez top.c++ da yapsam include lar ve fazla fonksyonlar gerekicekti bizde yöneticide yaptık ara işlemi ve değeri top.c++ a aktardık 
        
        topum.rakettensek(RaketMerkezi);// Merkeze göre nasıl sektiği merkez koordinatını veririz buna göre ne kadar sapma varsa -hız_x ona göre belirlenir sekmede
    }
}

}

// Ekran tasarımı ve ekrana çizim(render)


void oyun::render(){  

    ekran.clear(Color(00,00,22));
    raketim.ciz(ekran);
    topum.ciz(ekran);


    for (auto& t : tuglalar) {
        // SİZİN TESPİTİNİZ: Sadece kırılmamış olanları ekrana çiz!
        if(!t.KirildiMi) {
            t.ciz(ekran);
        }
    }


    
    topum.ciz(ekran);
    skorEkranım.ciz(ekran);

    ekran.display();   // çizilen her şeyi anında ekranımızda görmemizi sağlar
}
