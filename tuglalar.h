#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class tugla{
    public:

    RectangleShape TuglaSekli;
    bool KirildiMi=false; //Tuğşa kırıldımı diye kontrol

    
    FloatRect getSinirlar() { return TuglaSekli.getGlobalBounds(); }

    tugla(float x, float y ,float genislik ,float yukseklik);
    void ciz(RenderWindow& pencere); // NOT RenderWindow& pencere bu kısım detaylı araştırılacak

    
    
};
