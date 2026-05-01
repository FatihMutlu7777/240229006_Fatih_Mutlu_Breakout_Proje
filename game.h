#pragma once
#include <vector>
#include "raket.h"
#include "tuglalar.h"
#include "top.h"
#include "skor.h"
#include "oyunsonu.h"



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
    bitis_ekranı bitis_ekranım;
    bool oyun_bittimi;

    
   

    public:
    oyun();
    
    void calisma();
    void oyunu_sıfırla();

    private:
    void processEvents();
    void update();
    void render();
};
