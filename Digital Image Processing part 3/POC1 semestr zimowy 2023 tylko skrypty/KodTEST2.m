clc
clear all %czyszczenie cmd window
I = imread ("C:\Users\Krzysztof\Desktop\O3b_szary_konwersja_matlab.png"); %wczytany obraz wejściowy
Oryginal = imread ("C:\Users\Krzysztof\Desktop\Sprawozdanie_POC1\Obrazy oryginalne kolor-szary konwersja\Ib_szary.png");
[Obrazx , Obrazy]= size(I); %rozmiar obraz wczytanego
I = double(I)/255; %rzutowanie na double
maska = input ( "podaj wymmiar maski "); %podanie wartosci maski
k = input ( "podaj wartosc k "); %podanie wartosci k
obraz_LUM = zeros(Obrazx , Obrazy); %zainicjalizowanie zerami tablicy
wymiar_maski = floor (maska/2); %zaokraglenie w dol
for i = wymiar_maski + 1 : Obrazx - wymiar_maski %krotnosc petli
    for j = wymiar_maski + 1 : Obrazy - wymiar_maski %krotnosc petli
        czesc_obrazu = double(I(i - wymiar_maski : i + wymiar_maski , j - wymiar_maski : j + wymiar_maski)); %tylko pewna czesc obrazu
        czesc_obrazu = reshape(czesc_obrazu, 1, []);  %nadanie tablicy kształtu jedno-wymiarowego
        czesc_obrazu = sort(czesc_obrazu); %porządkowanie elementów tablicy
        indeks = ceil (maska*maska/2) ; indeks_dolny = indeks - k; indeks_gorny = indeks + k; %zaleznosc indeksow od maski i k
        x_odniesienia = I( i , j ); x_dolne = czesc_obrazu(indeks_dolny); x_gorne = czesc_obrazu(indeks_gorny); %nadanie granic
        LUM_wektor = [x_dolne , x_gorne , x_odniesienia]; LUM_wektor = sort(LUM_wektor); %utworzenie wektora
        obraz_LUM(i, j) = LUM_wektor(2); %przypisanie wektora do obrazu (3 elementy to 2 jest medianą)
    end
end
poczatek = ceil(maska/2); %zaokraglenie w gore
obraz_LUM = im2uint8 (obraz_LUM); %konwersja obrazu na 8-bit unsigned int
imwrite (obraz_LUM(163:350,163:350,:),"C:\Users\Krzysztof\Desktop\LUM2_3.png"); %przyblizenie i zapisanie

ps=psnr (obraz_LUM( poczatek : Obrazx - wymiar_maski , poczatek : Obrazy - wymiar_maski ) , Oryginal ( poczatek : Obrazx - wymiar_maski , poczatek : Obrazy - wymiar_maski ) ) ;
disp(['PSNR: ' num2str(ps)]);
