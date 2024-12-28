clc %czyszczenie Command Window
%wczytanie obrazów
I1 = imread('C:\Users\Krzysztof\Desktop\POC6\Zadanie1\boat_512x512.bmp');
I2 = imread('C:\Users\Krzysztof\Desktop\POC6\Zadanie1\lenna_512x512.bmp');
I1=double(I1); %rzutowanie na double
I2=double(I2); %rzutowanie na double
maska1=[1 1 1; %zdefiniowanie macierzy pierwszej maski
       1 4 1;
       1 1 1];
maska2=[0 0 -1 0 0; %zdefiniowanie macierzy drugiej maski
       0 -1 -1 -1 0; %pamietamy o nieparzystej dlugosci bokow
       -1 -1 12 -1 -1;
       0 -1 -1 -1 0;
       0 0 -1 0 0];
obraz1a=Funkcja_filtracja_liniowa(I1,maska1); %zastosowanie stworzonej funkcji
obraz1b=Funkcja_filtracja_liniowa(I1,maska2); %zastosowanie stworzonej funkcji
obraz2a=Funkcja_filtracja_liniowa(I2,maska1); %zastosowanie stworzonej funkcji
obraz2b=Funkcja_filtracja_liniowa(I2,maska2); %zastosowanie stworzonej funkcji
%zapis obrazów
obraz1a=uint8(obraz1a); %rzutowanie na uint8
obraz1b=uint8(obraz1b); %rzutowanie na uint8
obraz2a=uint8(obraz2a); %rzutowanie na uint8
obraz2b=uint8(obraz2b); %rzutowanie na uint8
imwrite(obraz1a,'C:\Users\Krzysztof\Desktop\boat3na3.png'); %zapis wszystkich 4 obrazow
imwrite(obraz1b,'C:\Users\Krzysztof\Desktop\boat5na5.png');
imwrite(obraz2a,'C:\Users\Krzysztof\Desktop\lenna3na3.png');
imwrite(obraz2b,'C:\Users\Krzysztof\Desktop\lenna5na5.png');
function y=Funkcja_filtracja_liniowa(I,mask) %funkcja do liniowej filtracji
    [Nx,Ny]=size(I); %rozmiar obrazu
    [Mx,My]=size(mask); %rozmiar maski
    y=I; %przypisanie
    x=floor(Mx/2); %zaokraglenie w dol
    p=1+x; %dodanie jedynki
    k=Nx-x; %krok k do petli
    for i=p:k %idziemy od p do k
        for j=p:k %idziemy od p do k
            Ciety_obraz=I(i-x:i+x,j-x:j+x);
            Obraz_po_konwersji=double(mask.*Ciety_obraz); %konwersja obrazu zmniejszonego z maska
            suma_obraz=sum(Obraz_po_konwersji(:)); %sumowanie elementów
            suma_maska=sum(mask(:)); %sumowanie elementów (maska)
            if suma_maska==0
                suma_maska=1; %warunek spełniony
            end
            Podzielony_obraz=suma_obraz/suma_maska; %dzielenie obu sum
            y(i,j)=Podzielony_obraz; %przypisanie do y
        end
    end
end