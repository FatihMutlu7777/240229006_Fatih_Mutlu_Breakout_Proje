#include "top.h"

top::top(float x,float y){
    TopSekli.setRadius(5.0f);
    TopSekli.setFillColor(Color(153,204,255));
    TopSekli.setPosition(x,y);
    
    hız_x=5.0f;
    hız_y=5.0f;

}


void top::guncelle(){
    TopSekli.move(hız_x,hız_y);

    if(TopSekli.getPosition().x<=0|| TopSekli.getPosition().x >= 800 - 20){
        hız_x=-hız_x;

    }
    if(TopSekli.getPosition().y<=0){
        hız_y=-hız_y;

    }
    

}

void top::rakettensek(float raketMerkezi){
    if(hız_y>0){
        hız_y=-hız_y; // Yukarı fırlatcak

        float TopMerkezi=TopSekli.getPosition().x + TopSekli.getRadius();


        float fark=TopMerkezi-raketMerkezi;

        hız_x=fark*0.15f;
    }

}

void top::ciz(RenderWindow& pencere){
    pencere.draw(TopSekli);
}