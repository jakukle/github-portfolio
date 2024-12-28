clc %czyszczenie Command Window
%wczytanie obrazów
O = imread('C:\Users\Krzysztof\Desktop\Ex3.png');
O=im2gray(O); %konwersja rgb(im) na gray
O=double(O); %rzutowanie na double
maska1=[1 1 1; %zdefiniowanie maski
       1 1 1;
       1 1 1];
obraz11=Funkcja_filtracja_liniowa(O,maska1); %wywolanie funkcji
obraz11=double(obraz11); %rzutowanie na double
O2=O-obraz11;
O3=O+O2;
%zapis obrazów
obraz11=uint8(obraz11); %rzutowanie na uint8
%%O2=uint8(O2);
O3=uint8(O3); %rzutowanie na uint8
imwrite(obraz11,'C:\Users\Krzysztof\Desktop\img11zad3.png');
imwrite(O2,'C:\Users\Krzysztof\Desktop\O2.png');
imwrite(O3,'C:\Users\Krzysztof\Desktop\O3.png');
function y=Funkcja_filtracja_liniowa(I,mask)
    [Nx,Ny]=size(I); %rozmiar obrazu
    [Mx,My]=size(mask); %rozmiar maski
    y=I; %przypisanie
    x=floor(Mx/2); %zaokraglenie w dol
    p=1+x; %dodanie jedynki
    k=Nx-x; %k do petli
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