#include "tuglalar.h"
#include "top.h"
using namespace sf;



tugla::tugla(float x, float y ,float genislik ,float yukseklik,Color renk){
    TuglaSekli.setPosition(x,y);
    TuglaSekli.setSize(Vector2f(genislik,yukseklik));
    TuglaSekli.setFillColor(Color::Yellow);
    TuglaSekli.setOutlineThickness(5);
    TuglaSekli.setOutlineColor(Color(00,02,18));
    TuglaSekli.setFillColor(renk);

}


void tugla::ciz(RenderWindow& pencere){
    if(!KirildiMi){
        pencere.draw(TuglaSekli);

    }

}


void top::tugladansek(){
    hız_y=-hız_y;

}