@echo off
echo Proje derleniyor, lutfen bekleyiniz...

g++ main.c++ game.c++ raket.c++ top.c++ tugla.c++ skor.c++ oyunsonu.c++ -o oyun.exe -lsfml-graphics -lsfml-window -lsfml-system
if %errorlevel% neq 0 (
    echo.
    echo DERLEME HATASI! Lutfen yukaridaki hata mesajlarini kontrol ediniz.
    pause
) else (
    echo.
    echo Derleme basarili! Oyun baslatiliyor...
    oyun.exe
)