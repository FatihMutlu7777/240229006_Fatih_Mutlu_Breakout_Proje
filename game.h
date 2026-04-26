#pragma once
#include "raket.h"
#include <SFML/Graphics.hpp>


using namespace sf;

class oyun{
    private:
    RenderWindow ekran;
    Event olay;
    raket raketim;
   

    public:
    oyun();
    
    void calisma();

    private:
    void processEvents();
    void update();
    void render();
};
