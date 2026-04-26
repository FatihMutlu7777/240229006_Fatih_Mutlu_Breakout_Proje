#include "raket.h"

raket::raket(){
    hız=10.0f; // Raketin sağa sola gitme hızı
    sekli.setSize(Vector2f(100.0f,20.0f));
    sekli.setFillColor(Color::White);
    sekli.setPosition(340.0f, 550.0f);
}

void raket::guncelle(){
    if(Keyboard::isKeyPressed(Keyboard::Left)&& sekli.getPosition().x>0){
        sekli.move(-hız,0.0f);

    }

    if(Keyboard::isKeyPressed(Keyboard::Right)&& sekli.getPosition().x< 800 - 120){
        sekli.move(hız,0.0f);

    }


}


void raket::ciz(RenderWindow& pencere){
    pencere.draw(sekli);

}