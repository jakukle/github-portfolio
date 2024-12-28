clc %czyszczenie Command Window
%wczytanie obrazów
O = imread('D:\Dysk_moje_Kuba\1. 6 semestr\POC\Lab_6 13_06_23\POC6\Zadanie2\lenna_512x512.bmp');
Os= imnoise(O, 'gaussian'); %dodanie szumu do obrazu
imshow(Os); %pokazanie obrazu po dodaniu do niego szumu
Os=double(Os); %rzutowanie zaszumionego obrazu na double
O=double(O); %rzutowanie obrazu wyjsciowego na double
maskLow=[1 1 1; %zdefiniowanie maski dla filtra dolnoprzepustowego
        1 4 1;
        1 1 1];
Id=Funkcja_filtracja_liniowa(Os,maskLow); %wywolanie funkcji
maskHigh=[0 -1 0; %zdefiniowanie maski dla filtra gornoprzepustowego
        -1 5 -1;
        0 -1 0];
I=Funkcja_filtracja_liniowa(Id,maskHigh); %wywolanie funkcji
OId=O-Id;
OI=O-I;
Os=uint8(Os); %rzutowanie na uint8
Id=uint8(Id); %rzutowanie na uint8
I=uint8(I); %rzutowanie na uint8
%OId=uint8(OId);
%OI=uint8(OI);
imwrite(Os,'C:\Users\Krzysztof\Desktop\Os.png');
imwrite(Id,'C:\Users\Krzysztof\Desktop\Id.png');
imwrite(I,'C:\Users\Krzysztof\Desktop\I.png');
imwrite(OId,'C:\Users\Krzysztof\Desktop\OId.png');
imwrite(OI,'C:\Users\Krzysztof\Desktop\OI.png');
function y=Funkcja_filtracja_liniowa(I,mask)
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