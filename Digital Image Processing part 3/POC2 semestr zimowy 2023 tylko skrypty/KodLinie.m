%Linie
clc;
clear all; %czyszczenie cmd window
I=imread('C:\Users\Krzysztof\Desktop\linie.png'); %wczytanie linii z painta
I1=imrotate(I,45); %rotacja o 45 stopni
I2=imrotate(I,90); %rotacja o 90 stopni
I3=imrotate(I,120); %rotacja o 120 stopni
imwrite(I1,'C:\Users\Krzysztof\Desktop\linie1.png'); %zapisanie obrazu
imwrite(I2,'C:\Users\Krzysztof\Desktop\linie2.png'); %zapisanie obrazu
imwrite(I3,'C:\Users\Krzysztof\Desktop\linie3.png'); %zapisanie obrazu
