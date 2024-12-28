clc %czyszczenie ekranu Command Window
I = imread('C:\Users\Krzysztof\Desktop\POC4\color\lena_512x512.bmp'); %wczytanie obrazu
%  if (size(I, 3) == 1)
%     %Convert Grayscale to RGB by duplicating I three times.
%     I = cat(3, I, I, I);
% end
liczbaBarw = 16; %nadanie liczby barw
[C, map] = rgb2ind(I,liczbaBarw); %converted RGB to indexed img
paletaBarw = map*256; %przemnozenie w celu uzyskania palety barw
%kanały RGB
Red = double(I(:,:,1)); %pierwszy poziom macierz dla kanału Red
Green = double(I(:,:,2)); %pierwszy poziom macierz dla kanału Green
Blue = double(I(:,:,3)); %pierwszy poziom macierz dla kanału Blue
%rozmiar obrazu 
x = size(I,1); %wymiar wierszy do pętli
y = size(I,2); %wymiar kolumn do pętli
%tablica błędów
I_ERROR = double(zeros(x+2,y+2,3)); %error jest macierzą powiększoną z konieczności
%Algorytm dyfuzji błędów Floyda-Steinberga
for i=1:x
    for j=1:y
        stary_pix(1) = Red(i,j) + I_ERROR(i+1,j+1,1); %błąd dla kanału Red
        stary_pix(2) = Green(i,j) + I_ERROR(i+1,j+1,2); %błąd dla kanału Green
        stary_pix(3) = Blue(i,j) + I_ERROR(i+1,j+1,3); %błąd dla kanału Blue     
        nowy_pix = find_palette_color(stary_pix, paletaBarw, liczbaBarw); %wywołanie funkcji z podanymi parametrami
        imageRed(i,j) = nowy_pix(1);
        imageGreen(i,j) = nowy_pix(2);
        imageBlue(i,j) = nowy_pix(3);
        error_Red = stary_pix(1) - nowy_pix(1);   %obliczenie erroru stary - nowy
        error_Green = stary_pix(2) - nowy_pix(2); %obliczenie erroru stary - nowy
        error_Blue = stary_pix(3) - nowy_pix(3);  %obliczenie erroru stary - nowy
        %aktualizacja błędów
        I_ERROR(i+1,j+2,1) = I_ERROR(i+1,j+2,1) + (7/16)*error_Red;
        I_ERROR(i+1,j+2,2) = I_ERROR(i+1,j+2,2) + (7/16)*error_Green;
        I_ERROR(i+1,j+2,3) = I_ERROR(i+1,j+2,3) + (7/16)*error_Blue;
        I_ERROR(i+2,j,1)   = I_ERROR(i+2,j,1)   + (3/16)*error_Red;
        I_ERROR(i+2,j,2)   = I_ERROR(i+2,j,2)   + (3/16)*error_Green;
        I_ERROR(i+2,j,3)   = I_ERROR(i+2,j,3)   + (3/16)*error_Blue;
        I_ERROR(i+2,j+1,1) = I_ERROR(i+2,j+1,1) + (5/16)*error_Red;
        I_ERROR(i+2,j+1,2) = I_ERROR(i+2,j+1,2) + (5/16)*error_Green;
        I_ERROR(i+2,j+1,3) = I_ERROR(i+2,j+1,3) + (5/16)*error_Blue;
        I_ERROR(i+2,j+2,1) = I_ERROR(i+2,j+2,1) + (1/16)*error_Red;
        I_ERROR(i+2,j+2,2) = I_ERROR(i+2,j+2,2) + (1/16)*error_Green;
        I_ERROR(i+2,j+2,3) = I_ERROR(i+2,j+2,3) + (1/16)*error_Blue;
 
    end
end
imageRed = uint8(imageRed); %konwersja kanału R na uint8
imageGreen = uint8(imageGreen); %konwersja kanału G na uint8
imageBlue = uint8(imageBlue); %konwersja kanału B na uint8
I3 = cat(3,imageRed,imageGreen,imageBlue); %składanie kanałów
imwrite(I3,'C:\Users\Krzysztof\Desktop\lena_16.png'); %zapis obrazu
function nowy_pix = find_palette_color(stary_pix, paletaBarw, liczbaBarw)
    %ustalenie odleglosci od punktu
    for k = 1 : liczbaBarw  
        near(k) = ((paletaBarw(k,1) - stary_pix(1))^2 + (paletaBarw(k,2) - stary_pix(2))^2 + (paletaBarw(k,3) - stary_pix(3))^2 );
    end
    %sprawdzenie dla ktorego koloru jest najblizej
    [var,index]= min(near); 
    nowy_pix(1) = paletaBarw(index,1); %dla kanału Red
    nowy_pix(2) = paletaBarw(index,2); %dla kanału Green
    nowy_pix(3) = paletaBarw(index,3); %dla kanału Blue
end
