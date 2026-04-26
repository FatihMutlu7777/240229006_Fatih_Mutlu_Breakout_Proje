#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class oyun{
    private:
    RenderWindow ekran;
    Event olay;

    public:
    oyun();
    
    void calisma();

    private:
    void processEvents();
    void update();
    void render();
};
