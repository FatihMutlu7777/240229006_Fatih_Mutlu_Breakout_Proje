#pragma once
#include <vector>
#include "raket.h"
#include "tuglalar.h"
#include "top.h"
#include "skor.h"


#include <SFML/Graphics.hpp>
using namespace sf;



using namespace sf;

class oyun{
    private:
    RenderWindow ekran;
    Event olay;
    raket raketim;
    std::vector<tugla> tuglalar;
    top topum;
    skorEkrani skorEkranım;
   

    public:
    oyun();
    
    void calisma();

    private:
    void processEvents();
    void update();
    void render();
};
