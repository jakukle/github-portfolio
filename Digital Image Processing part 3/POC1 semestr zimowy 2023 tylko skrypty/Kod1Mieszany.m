clc;
clear all; %czyszczenie cmd window
I = imread('C:\Users\Krzysztof\Desktop\Sprawozdanie_POC1\Obrazy oryginalne\gold_512x512.bmp');
%wczytanie obrazu
%I = rgb2gray(I); %konwersja na rgb na szary
Obraz1 = imnoise(I,'salt & pepper',0.01); %dodanie szumu 1%
Obraz2 = imnoise(I,'salt & pepper',0.02); %dodanie szumu 2%
Obraz3 = imnoise(I,'salt & pepper',0.10); %dodanie szumu 10%
Obraz11 = imnoise(Obraz1,'gaussian', 0, 0.01); %dodanie szumu o domyślnej średniej szumu Gaussa i wariancji 0.01
Obraz22 = imnoise(Obraz2,'gaussian', 0, 0.02); %dodanie szumu o domyślnej średniej szumu Gaussa i wariancji 0.02
Obraz33 = imnoise(Obraz3,'gaussian', 0, 0.10); %dodanie szumu o domyślnej średniej szumu Gaussa i wariancji 0.1
Obraz_zlaczony=[I(250:400,250:400,:),Obraz11(250:400,250:400,:),Obraz22(250:400,250:400,:),Obraz33(250:400,250:400,:)];
%przyciecie obrazu
Obraz_przyciety=imresize(Obraz_zlaczony,3,'nearest'); %powiekszenie 3-krotne metodą interpolacji najbliższego sąsiada
imwrite(Obraz_przyciety,'C:\Users\Krzysztof\Desktop\im1b.bmp'); %wyświetlenie
imwrite(Obraz11,'C:\Users\Krzysztof\Desktop\O1b.bmp'); %wyświetlenie
imwrite(Obraz22,'C:\Users\Krzysztof\Desktop\O2b.bmp'); %wyświetlenie
imwrite(Obraz33,'C:\Users\Krzysztof\Desktop\O3b.bmp'); %wyświetlenie
%_szary_konwersja_matlab