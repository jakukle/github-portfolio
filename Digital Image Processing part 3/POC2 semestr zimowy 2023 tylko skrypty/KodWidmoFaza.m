%Widmo i faza
clc;
clear all; %czyszczenie cmd window
I=imread('C:\Users\Krzysztof\Desktop\prostokat8.png'); %wczytanie obrazu
I=rgb2gray(I);
L1=fftshift(fft2(I));
figure %podtrzymanie
imshow(log(abs(L1)+1),[]); %pokazanie obrazu widma
%xlabel('Widmo mocy');
figure %podtrzymanie
imshow(angle(L1),[]); %pokazanie obrazu fazy
%xlabel('Faza');
L2=angle(L1);
%imwrite(uint8(L1),'C:\Users\Krzysztof\Desktop\widmo_t1.png');
%imwrite(L2,'C:\Users\Krzysztof\Desktop\faza_t1.png');