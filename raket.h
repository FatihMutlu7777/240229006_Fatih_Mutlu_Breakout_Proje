#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class raket{

    private:

    RectangleShape sekli; // Raketimizin şekli
    float hız; //Topun hızı


    public:
    raket();
    void guncelle();
    void baslangıca_don_raket();
    void ciz(RenderWindow& pencere); //raket ekranda gözüksün diye

    FloatRect getSinirlar() { return sekli.getGlobalBounds(); }


};
