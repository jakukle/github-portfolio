clc %czyszczenie ekranu z Command Window
I = imread('C:\Users\Krzysztof\Desktop\POC3\Bayer\GT_sRGB\IMG_009_srgb.png'); %otwarcie pliku po sciezce
[Iq] = Kwantyzacja( I , 4 , 6 , 4 ) ; %wywołanie funkcji z podanymi parametrami
imwrite(Iq,'C:\Users\Krzysztof\Desktop\zad3_2c.png'); %stworzenie pliku
function [Iq] = Kwantyzacja( I,podanyRed,podanyGreen,podanyBlue) %stworzenie funkcji do kwantyzacji
Red = I( : , : , 1 ); %czerwony przejmuje pierwsza plaszczyzne w RGB
Green = I( : , : , 2 ); %zielony przejmuje druga plaszczyzne w RGB
Blue = I( : , : , 3 ); %niebieski przejmuje trzecia plaszczyzne w RGB
red_podzielone = 256/podanyRed; %dzielimy przez wywołane parametry
green_podzielone = 256/podanyGreen; %dzielimy przez wywołane parametry
blue_podzielone = 256/podanyBlue; %dzielimy przez wywołane parametry
X = size ( I , 1 ); %zwraca nam liczbe wierszy naszego obrazu
Y = size ( I , 2 ); %zwraca nam liczbe kolumn naszego obrazu
for i = 1:X %algorytm kwantyzacji - od 1 do liczby wierszy
    for j = 1:Y %od 1 do liczby kolumn
    KwantyzowanyRed = floor(double (Red( i , j))/red_podzielone); %zaokrąglanie w dół - wiekszy podanyRed, mniej dzielimy
    KwantyzowanyGreen = floor ( double (Green( i , j ) ) / green_podzielone ); %zaokrąglanie w dół
    KwantyzowanyBlue = floor ( double (Blue( i , j ) ) / blue_podzielone ); %zaokrąglanie w dół
Red( i , j ) = ( KwantyzowanyRed +0.5)*red_podzielone; %wracamy do zbliżonej początkowej wartości
Green( i , j ) = ( KwantyzowanyGreen +0.5)*green_podzielone; %wracamy do zbliżonej początkowej wartości
Blue( i , j ) = ( KwantyzowanyBlue +0.5)*blue_podzielone; %wracamy do zbliżonej początkowej wartości
    end
end
Iq = cat (3,Red,Green,Blue); %łączymy tablice funkcją cat
end
