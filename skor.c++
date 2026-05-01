#include"skor.h"
#include<iostream>
using namespace std;

skorEkrani::skorEkrani(float x,float y){
    skor=0;

    if (!font.loadFromFile("arial.ttf")) {
    std::cerr << "Hata: Font dosyasi yuklenemedi!" << std::endl;
}

yazi.setFont(font);
yazi.setCharacterSize(24);
yazi.setFillColor(Color::White);
yazi.setPosition(x,y);
yazi.setString("Skor: 0");
}


void skorEkrani::SkorEkle(int puan){
    skor+=puan;

    yazi.setString("Skor: "+ to_string(skor));
}


 void skorEkrani::ciz(RenderWindow& pencere){
    pencere.draw(yazi);
}