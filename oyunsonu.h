#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;


class bitis_ekranı{
    private:
    Font font;
    RectangleShape arkaPlanKutusu;
    Text baslikMetni;
    Text skorMetni;
    Text bilgiMetni;

    public:
 
    bitis_ekranı(float x,float y);
    void skoru_ayarla(int son_skor);
    void ciz (RenderWindow& pencere);

};