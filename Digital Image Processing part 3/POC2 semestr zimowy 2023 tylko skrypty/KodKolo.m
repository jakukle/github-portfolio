%Kolo
clc;
clear all; %czyszczenie cmd window
I=imread('C:\Users\Krzysztof\Desktop\kolo.png'); %wczytanie kola z painta
Obraz_2x=imresize(I,2); %zwiekszenie obrazu 2 krotne
Obraz_3x=imresize(I,3); %zwiekszenie obrazu 3 krotne
Obraz_4x=imresize(I,4); %zwiekszenie obrazu 4 krotne
for i = 1:512 %512 wymiar
    for j=1:512 %512 wymiar
        kolo1(i,j)=Obraz_2x(i+256,j+256); %przesuniecie i przyciecie
        kolo2(i,j)=Obraz_3x(i+512,j+512); %przesuniecie i przyciecie
        kolo3(i,j)=Obraz_4x(i+768,j+768); %przesuniecie i przyciecie
    end
end
imwrite(kolo1,'C:\Users\Krzysztof\Desktop\kolo1.png'); %zapisanie obrazu
imwrite(kolo2,'C:\Users\Krzysztof\Desktop\kolo2.png'); %zapisanie obrazu
imwrite(kolo3,'C:\Users\Krzysztof\Desktop\kolo3.png'); %zapisanie obrazu
