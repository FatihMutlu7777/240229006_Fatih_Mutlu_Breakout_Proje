#include "oyunsonu.h"
#include<iostream>

using namespace std;

bitis_ekranı::bitis_ekranı(float x,float y){
    if (!font.loadFromFile("arial.ttf")) {
        cout<< "Hata: Font yuklenemedi!" <<endl;
    }

    arkaPlanKutusu.setSize(Vector2f(500.0f, 300.0f));
    arkaPlanKutusu.setFillColor(Color(255,128,0));
    arkaPlanKutusu.setOutlineThickness(3.0f);
    arkaPlanKutusu.setOutlineColor(Color::White);
    arkaPlanKutusu.setOrigin(250.0f, 150.0f);
    arkaPlanKutusu.setPosition(400.0f,300.0f);



    baslikMetni.setFont(font);
    baslikMetni.setString("Oyun Bitti");
    baslikMetni.setCharacterSize(45);
    baslikMetni.setFillColor(Color::Red);
    baslikMetni.setOrigin(baslikMetni.getLocalBounds().width / 2.0f, 0);
    baslikMetni.setPosition(400.0f,200.0f);


    skorMetni.setFont(font);
    skorMetni.setCharacterSize(35);
    skorMetni.setFillColor(Color::Blue);


    bilgiMetni.setFont(font);
    bilgiMetni.setString("Yeniden oynamak icin ENTER\nCikmak icin ESC tusuna basin.");
    bilgiMetni.setCharacterSize(22);
    bilgiMetni.setFillColor(Color::Black);
    bilgiMetni.setOrigin(bilgiMetni.getLocalBounds().width / 2.0f, 0);
    bilgiMetni.setPosition(400.0f, 330.0f);

}


void bitis_ekranı::skoru_ayarla(int son_skor){
    skorMetni.setString("Skorunuz: "+::to_string(son_skor));
    skorMetni.setOrigin(skorMetni.getLocalBounds().width / 2.0f, 0);
    skorMetni.setPosition(400.0f, 270.0f); // Ekran ortası 
}


void bitis_ekranı::ciz(RenderWindow& pencere){
    pencere.draw(arkaPlanKutusu);
    pencere.draw(bilgiMetni);
    pencere.draw(skorMetni);
    pencere.draw(baslikMetni);


}