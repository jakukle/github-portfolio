clc %czyszczenie Command Window
I = imread('C:\Users\Krzysztof\Desktop\POC4\woman_512x512.png'); %wczytanie obrazu
I = double(I)/256; %rzutowanie na przedział 0-1
X = size(I,1); %liczba wierszy wczytanego obrazu
Y = size(I,2); %liczba kolumn wczytanego obrazu
I2 = zeros(X+2,Y+2); %tablica błędów poszerzona o dwa wzgledem oryginalu
I3 = zeros(X,Y); %tablica wynikowa
%Algorytm Floyda-Steinberga
for i=1:X
    for j=1:Y
        if( (I(i,j) + I2(i+1,j+1)) < 0.5 )
        I3(i,j) = 0; %czarne
        error = I(i,j) + I2(i+1,j+1);
        else
        I3(i,j) = 1; %białe
        error = I(i,j) + I2(i+1,j+1) - 1;
        end
    %propagacja błędu
    I2(i+1,j+2) = I2(i+1,j+2) + (7/16)*error;
    I2(i+2,j)   = I2(i+2,j)   + (3/16)*error;
    I2(i+2,j+1) = I2(i+2,j+1) + (5/16)*error;
    I2(i+2,j+2) = I2(i+2,j+2) + (1/16)*error;
    end
end
imwrite(I3,'C:\Users\Krzysztof\Desktop\obraz1.png'); %zapis obrazu