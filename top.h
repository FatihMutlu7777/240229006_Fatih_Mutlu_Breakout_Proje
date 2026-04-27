#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class top{
    private:
    CircleShape TopSekli;

    float hız_x;
    float hız_y;

    public:
    top(float x, float y);
    void guncelle();
    void ciz(RenderWindow& pencere);
    void rakettensek();

    FloatRect getSinirlar() { return TopSekli.getGlobalBounds(); } // Bu kısım araştırılacak

    

    
};