@echo off
g++ main.c++ game.c++ raket.c++ tugla.c++ top.c++ -o oyun.exe -lsfml-graphics -lsfml-window -lsfml-system
.\oyun.exeif %errorlevel% equ 0 (
    echo Derleme Basarili! Oyun baslatiliyor...
    .\oyun.exe
) else (
    echo Bir hata olustu, kodlarini kontrol et Baba Pro!
    pause
)