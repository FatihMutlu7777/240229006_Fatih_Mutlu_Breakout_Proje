#include "game.h"
using namespace sf;



// Ekran gözükmesi için

oyun::oyun():topum(400.0f, 300.0f){
    ekran.create(VideoMode(800,600), "Breakout");

    ekran.setFramerateLimit(60);
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            float ekstraKoridor = (j / 2) * 80.0f; // 2 sütünda bir ekstra 40px boşluk
            float xPozisyonu = (j * 80.0f) + ekstraKoridor; // Burda ekstra mesafeyi ekledik
            tuglalar.push_back(tugla(xPozisyonu + 15.0f, i * 70.0f + 50.0f, 70.0f, 18.0f)); //80 px yana dizilir, 30px aşağı kayar,78px genişlik,18px yükseklik
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
    if(topum.getSinirlar().intersects(raketim.getSinirlar())){ //Topun sınırı raketin sınırıyla kesiştimi demek
       
        float RaketMerkezi=raketim.getSinirlar().left +(raketim.getSinirlar().width / 2.0f); // 2 ye bölüyoz çünü merkezini eklicez x in başlangıcına böylece tam orta nokta bulcaz neden .left yaptık çünkü SFML de right yok left top width height var right yapıncada açılıyo çalışıyor ama hata veriyor neden burda yaptık burası yönetici topu değiştircez top.c++ da yapsam include lar ve fazla fonksyonlar gerekicekti bizde yöneticide yaptık ara işlemi ve değeri top.c++ a aktardık 
        
        topum.rakettensek(RaketMerkezi);// Merkeze göre nasıl sektiği merkez koordinatını veririz buna göre ne kadar sapma varsa -hız_x ona göre belirlenir sekmede
    }
    

}

// Ekran tasarımı ve ekrana çizim(render)


void oyun::render(){  

    ekran.clear(Color(00,00,22));

    raketim.ciz(ekran);
    
    for (auto& t : tuglalar) {
        if(!t.KirildiMi && topum.getSinirlar().intersects(t.getSinirlar())){ // Burda top tuğla sınırlarına çarpmışmı baılır eğer true dönerse aşağıda tuğlaları kaldırma işlemi olur ardından top -hız_y olur ve break yapıp döngüyü bitiririz yoksa sonsuz döngü olup hepsini silebilir
            t.KirildiMi=true;
        
        topum.tugladansek();
        break;
        }
        t.ciz(ekran);
    }
    topum.ciz(ekran);

    ekran.display();   // çizilen her şeyi anında ekranımızda görmemizi sağlar
}
