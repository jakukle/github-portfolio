clc
clear all
I=imread('C:\Users\Krzysztof\Desktop\POC2\Bayer\CFA_sRGB\IMG_009_srgb_CFA.png');
[Nx,Ny] = size(I);
ImageBiliniowy = uint8(zeros(Nx,Ny));
%stosujemy blue green green red
%Red - kanał
Red = uint8(zeros(Nx,Ny));
for i=1:2:Nx 
    for j=1:2:Ny 
    Red(i,j) = I(i+1,j+1);  %czerwone dla prawego dolnego rogu
    end
end
%Green - kanał
Green = uint8(zeros(Nx,Ny));
for i=1:2:Nx 
    for j=1:2:Ny 
    Green(i+1,j) = I(i+1,j); %zielone dla lewego dolnego rogu
    Green(i,j+1) = I(i,j+1); %zielone dla prawego gornego rogu
    end
end
%Blue - kanał
Blue = uint8(zeros(Nx,Ny));
for i=1:2:Nx 
    for j=1:2:Ny 
    Blue(i+1,j+1) = I(i,j); %niebieskie dla lewego gornego rogu
    end
end
 %Interpolacja biliniowa
ImageBiliniowy(:,:,1) = interpolationRed(Red); %pierwszy poziom dla koloru czerwonego
ImageBiliniowy(:,:,2) = interpolationGreen(Green); %drugi poziom dla koloru zielonego
ImageBiliniowy(:,:,3) = interpolationBlue(Blue); %trzeci poziom dla koloru niebieskiego (Red Green Blue)
 figure;
imshow(ImageBiliniowy); %wyswietlenie w matlabie
%zapis
imwrite(ImageBiliniowy,'C:\Users\Krzysztof\Desktop\zad3piesij.png'); %zapisanie do pliku

%funkcje interpolacyjne
%dla czerwonego
function Y = interpolationRed(I) %stworzenie funckji do interpolacji red gdzie obraz odczytany jest wejsciem
[Nx, Ny] = size(I); %wysokość na szerokość obrazu
Y = uint8(zeros(Nx,Ny)); %wyjsciem bedzie macierz Nx x Ny o typie uint8
    for i=2:1:Nx-1 %startujemy o 1 pozniej i konczymy o 1 wczesniej aby moc stworzyc przyblizenie
        for j=2:1:Ny-1 %startujemy o 1 pozniej i konczymy o 1 wczesniej aby moc stworzyc przyblizenie
        Macierz = I(i-1:i+1,j-1:j+1); %algorytm interpolacji
            if Macierz(2,2)==0 %jesli element w macierzy jest pusty
                if Macierz(2,3)~=0 %jesli element nastepny w kolumnie nie jest pusty to przyblizamy przez dwa
                Y(i,j) = round(sum(Macierz(:))/2);
                elseif Macierz(3,2)~=0 %jesli element nastepny w wierszu nie jest pusty to przyblizamy przez dwa
                Y(i,j) = round(sum(Macierz(:))/2);
                else
                Y(i,j) = round(sum(Macierz(:))/4); %potem przyblizamy jeszcze 4 elementy ktore juz przyblizylismy 
                end
            else
            Y(i,j) = Macierz(2,2);
            end
        end
    end
end
%dla zielonego  %stworzenie funckji do interpolacji green gdzie obraz odczytany jest wejsciem
function Y = interpolationGreen(I)
    [Nx, Ny] = size(I);
    Y = uint8(zeros(Nx,Ny));
    for i=2:1:Nx-1
        for j=2:1:Ny-1
        Macierz = I(i-1:i+1,j-1:j+1);
            if Macierz(2,2)==0
            Y(i,j) = round(sum(Macierz(:))/4);
            else
            Y(i,j) = Macierz(2,2);
            end
        end
    end
end
 %dla niebieskiego  %stworzenie funckji do interpolacji blue gdzie obraz odczytany jest wejsciem
function Y = interpolationBlue(I)
    [Nx, Ny] = size(I);
    Y = uint8(zeros(Nx,Ny));
    for i=2:1:Nx-1
        for j=2:1:Ny-1
        Macierz = I(i-1:i+1,j-1:j+1);
            if Macierz(2,2)==0
                if Macierz(2,3)~=0
                Y(i,j) = round(sum(Macierz(:))/2);
                elseif Macierz(3,2)~=0
                Y(i,j) = round(sum(Macierz(:))/2);
                else
                Y(i,j) = round(sum(Macierz(:))/4);
                end
            else
            Y(i,j) = Macierz(2,2);
            end
        end
    end
end
