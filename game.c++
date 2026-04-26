#include "game.h"
using namespace sf;



// Ekran gözükmesi için

oyun::oyun(){
    ekran.create(VideoMode(800,600), "Breakout");

    ekran.setFramerateLimit(60);
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            tuglalar.push_back(tugla(j * 80.0f, i * 30.0f, 78.0f,18.0f)); //80 px yana dizilir, 30px aşağı kayar,78px genişlik,18px yükseklik
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

}

// Ekran tasarımı ve ekrana çizim(render)


void oyun::render(){  

    ekran.clear(Color(00,00,22));

    raketim.ciz(ekran);
    
    for (auto& t : tuglalar) {
        t.ciz(ekran);
    }

    ekran.display();   // çizilen her şeyi anında ekranımızda görmemizi sağlar
}
