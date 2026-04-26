#include "game.h"


// Ekran gözükmesi için

oyun::oyun(){
    ekran.create(VideoMode(800,600), "Breakout");

    ekran.setFramerateLimit(60);
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
    ekran.display();   // çizilen her şeyi anında ekranımızda görmemizi sağlar
}
