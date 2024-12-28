clc %czyszczenie ekranu z Command Window
I = imread('C:\Users\Krzysztof\Desktop\POC3\Bayer\GT_sRGB\IMG_009_srgb.png'); %otwarcie pliku po sciezce
[Iq] = Kwantyzacja( I , 4 , 8 , 4 , 6 ); %wywołanie funkcji z podanymi parametrami
imwrite(Iq,'C:\Users\Krzysztof\Desktop\zad4_2c.png'); %stworzenie pliku
function [Iq] = Kwantyzacja( I ,podanyHue,podanySaturation, podanyValue, podanyAchromatyczny) %stworzenie funkcji do kwantyzacji
ImageHSV = rgb2hsv(I); %konwersja RGB na HSV
H=ImageHSV ( : , : , 1 ) ; %H przejmuje pierwszy poziom w macierzy - odcień światła
S=ImageHSV ( : , : , 2 ) ; %S przejmuje drugi poziom w macierzy - nasycenie koloru
V=ImageHSV ( : , : , 3 ) ; %V przejmuje trzeci poziom w macierzy - moc światła białego
hue = 1/podanyHue; %dzielimy 1 przez wywołane parametry
saturation = 1/podanySaturation; %dzielimy 1 przez wywołane parametry
value = 1/podanyValue; %dzielimy 1 przez wywołane parametry
achromatyczny = 1/podanyAchromatyczny; %dzielimy 1 przez wywołane parametry
X = size ( I , 1 ); %zwraca nam liczbe wierszy naszego obrazu
Y = size ( I , 2 ); %zwraca nam liczbe kolumn naszego obrazu
for i = 1:X %algorytm kwantyzacji - od 1 do liczby wierszy
    for j = 1:Y %od 1 do liczby kolumn
    KwantyzowanyHue = floor (double (H( i , j )) / hue); %zaokrąglanie w dół - wiekszy podanyHue, mniej dzielimy
    KwantyzowanySaturation = floor (double (S( i , j )) / saturation); %wiekszy podanySaturation, mniej dzielimy
    KwantyzowanyValue = floor (double (V( i , j )) / value);%wiekszy podanyValue, mniej dzielimy
    H( i , j ) = KwantyzowanyHue * hue; %wracamy do zbliżonej początkowej wartości
        if (S( i , j ) == 0 && podanyAchromatyczny > 1 ) %jesli element S jest rowny zero i podanyAchromatyczny > 1 (u nas jest)
        KwantyzowanyValue = floor (double (V( i , j )) / achromatyczny); %to inaczej kwantyzujemy Value
        V( i , j ) = KwantyzowanyValue * value; %wracamy do zbliżonej początkowej wartości
        else
        S( i , j ) = KwantyzowanySaturation * saturation ; %wracamy do zbliżonej początkowej wartości
        V( i , j ) = KwantyzowanyValue * value ; %wracamy do zbliżonej początkowej wartości
        end
    end
end
Iq = cat (3,H,S,V); %łączymy tablice funkcją cat
Iq = hsv2rgb(Iq); %konwersja odwrotna
end
