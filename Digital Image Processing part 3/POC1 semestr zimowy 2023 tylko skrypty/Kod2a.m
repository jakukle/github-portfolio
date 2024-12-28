clc;
clear all; %czyszczenie cmd window
Obraz_szum = imread("C:\Users\Krzysztof\Desktop\O3b_szary_konwersja_matlab.png");
Oryginal = imread("C:\Users\Krzysztof\Desktop\Sprawozdanie_POC1\Obrazy oryginalne kolor-szary konwersja\Ib_szary.png");
%wczytanie obraz z szumem oraz obrazu oryginalnego szarego
[Obrazx, Obrazy] = size(Obraz_szum); %wymiary obrazu z szumem
maska = input("Podaj maske: "); %uzytkownik podaje wymiar maski
sciecie_maski_pol_dolne = floor(maska / 2); %zaokraglenie w dol 
Obraz_po_filtrze_medianowym = uint8(zeros(Obrazx, Obrazy)); %inicjacja obrazu ostatecznego
for i = sciecie_maski_pol_dolne + 1 : Obrazx - sciecie_maski_pol_dolne %implementacja filtru medianowego
    for j = sciecie_maski_pol_dolne + 1 : Obrazy - sciecie_maski_pol_dolne %petle skrocone do maski
        czesc_obrazu = Obraz_szum(i - sciecie_maski_pol_dolne : i + sciecie_maski_pol_dolne, j - sciecie_maski_pol_dolne : j + sciecie_maski_pol_dolne);  %tylko pewna czesc obrazu
        Obraz_po_filtrze_medianowym(i, j) = median(czesc_obrazu(:)); %obliczenie mediany dla danej czesci obrazu
    end
end
imwrite(Obraz_po_filtrze_medianowym(163:350, 163:350), "C:\Users\Krzysztof\Desktop\Obraz_po_filtrze_median_przyciety33.png");
%imwrite(Obraz_po_filtrze_medianowym, 'C:\Users\Krzysztof\Desktop\Obraz_po_filtrze_median33.png')

matlab = medfilt2(Obraz_szum, [3 3]);
%imwrite(matlab(163:350, 163:350),'C:\Users\Krzysztof\Desktop\matlab7.png');
%imwrite(Oryginal(163:350, 163:350), 'C:\Users\Krzysztof\Desktop\ory.png')

% Oblicz i wyświetl PSNR
Obliczone_PSNR = psnr(Obraz_po_filtrze_medianowym(sciecie_maski_pol_dolne + 1 : Obrazx - sciecie_maski_pol_dolne, sciecie_maski_pol_dolne + 1 : Obrazy - sciecie_maski_pol_dolne), Oryginal(sciecie_maski_pol_dolne + 1 : Obrazx - sciecie_maski_pol_dolne, sciecie_maski_pol_dolne + 1 : Obrazy - sciecie_maski_pol_dolne));
disp(['PSNR: ' num2str(Obliczone_PSNR)]);
