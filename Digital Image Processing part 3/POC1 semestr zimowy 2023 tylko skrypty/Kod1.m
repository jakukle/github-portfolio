clc;
clear all; %czyszczenie cmd window
I = imread('C:\Users\Krzysztof\Desktop\Sprawozdanie_POC1\Obrazy oryginalne\gold_512x512.bmp');
%wczytanie obrazu
%I = rgb2gray(I); %konwersja na rgb na szary
Obraz1 = imnoise(I,'salt & pepper',0.01); %dodanie szumu 1%
Obraz2 = imnoise(I,'salt & pepper',0.02); %dodanie szumu 2%
Obraz3 = imnoise(I,'salt & pepper',0.10); %dodanie szumu 10%
Obraz_zlaczony=[I(250:400,250:400,:),Obraz1(250:400,250:400,:),Obraz2(250:400,250:400,:),Obraz3(250:400,250:400,:)];
%przyciecie obrazu
Obraz_przyciety=imresize(Obraz_zlaczony,3,'nearest'); %powiekszenie 3-krotne metodą interpolacji najbliższego sąsiada
imwrite(Obraz_przyciety,'C:\Users\Krzysztof\Desktop\im1b.bmp'); %wyświetlenie
imwrite(Obraz1,'C:\Users\Krzysztof\Desktop\O1b.bmp'); %wyświetlenie
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\O2b.bmp'); %wyświetlenie
imwrite(Obraz3,'C:\Users\Krzysztof\Desktop\O3b.bmp'); %wyświetlenie