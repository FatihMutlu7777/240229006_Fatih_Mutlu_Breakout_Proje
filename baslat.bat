@echo off
g++ main.c++ game.c++ raket.c++ -o oyun.exe -lsfml-graphics -lsfml-window -lsfml-system
if %errorlevel% equ 0 (
    echo Derleme Basarili! Oyun baslatiliyor...
    .\oyun.exe
) else (
    echo Bir hata olustu, kodlarini kontrol et Baba Pro!
    pause
)