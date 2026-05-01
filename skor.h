#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;


class skorEkrani{

    private:
    int skor;
    Font font;
    Text yazi;


    public:

    skorEkrani(float x,float y);

    void SkorEkle(int puan);

    void ciz(RenderWindow& pencere);

};

