clc;
clear all; %czyszczenie cmd window
I = imread('C:\Users\Krzysztof\Desktop\O1b_szary_konwersja_matlab.png'); %wczytany obraz wejściowy
maska = input('Podaj maske: '); %wielkosc maski wprowadzona przez uzytkownika
k = input('Podaj k: '); %parametr k wprowadzony przez uzytkownika
[Obrazx, Obrazy] = size(I); %wymiary obrazu z szumem
Obraz_przefiltrowany_LUM = zeros(Obrazx, Obrazy, 'like', I); %zainicjalizowanie obrazu wejściowego
sciecie_maski_pol_dolne = floor(maska / 2); %zaokraglenie w dol 
for i = sciecie_maski_pol_dolne + 1 : Obrazx - sciecie_maski_pol_dolne %implementacja filtru LUM
    for j = sciecie_maski_pol_dolne + 1 : Obrazy - sciecie_maski_pol_dolne
        czesc_obrazu = I(i - sciecie_maski_pol_dolne : i + sciecie_maski_pol_dolne, j - sciecie_maski_pol_dolne : j + sciecie_maski_pol_dolne); %tylko czesc obrazu
        jednowymiarowa_czesc = reshape(czesc_obrazu, 1, []); %nadanie tablicy kształtu jedno-wymiarowego
        jednowymiarowa_czesc_sort = sort(jednowymiarowa_czesc); %porządkowanie elementów tablicy
        dol = ceil((maska^2 - 1) / 2) - k + 1; %wartość LUM jako mediana wartości
        gora = dol + 2 * k;
        wartosc_LUM = median(jednowymiarowa_czesc_sort(dol : gora));
        Obraz_przefiltrowany_LUM(i, j) = wartosc_LUM; %kazdy piksel w obrazie wynikowym otrzymuje pewną wartość LUM
    end
end
imwrite(Obraz_przefiltrowany_LUM,'C:\Users\Krzysztof\Desktop\30.png'); %Wyświetl obraz wyjściowy
Obliczone_PSNR = psnr(Obraz_przefiltrowany_LUM(sciecie_maski_pol_dolne + 1 : Obrazx - sciecie_maski_pol_dolne, sciecie_maski_pol_dolne + 1 : Obrazy - sciecie_maski_pol_dolne), Oryginal(sciecie_maski_pol_dolne + 1 : Obrazx - sciecie_maski_pol_dolne, sciecie_maski_pol_dolne + 1 : Obrazy - sciecie_maski_pol_dolne));
disp(['PSNR: ' num2str(Obliczone_PSNR)]);