#include "tuglalar.h"

tugla::tugla(float x, float y ,float genislik ,float yukseklik){
    TuglaSekli.setPosition(x,y);
    TuglaSekli.setSize(Vector2f(genislik,yukseklik));
    TuglaSekli.setFillColor(Color::Yellow);
    TuglaSekli.setOutlineThickness(2);
    TuglaSekli.setOutlineColor(Color::White);

}


void tugla::ciz(RenderWindow& pencere){
    if(!KirildiMi){
        pencere.draw(TuglaSekli);

    }
    
}
