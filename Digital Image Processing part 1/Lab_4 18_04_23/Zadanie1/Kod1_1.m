clc %czyszczenie Command Window
I = imread('C:\Users\Krzysztof\Desktop\POC4\woman_512x512.png'); %wczytanie obrazu
prog = graythresh(I); %Global image threshold using Otsu's method
I_Otsu = imbinarize(I,prog); %Binarize 2-D grayscale image or 3-D volume by thresholding
imwrite(I_Otsu,'C:\Users\Krzysztof\Desktop\POC4\zadanie1\zad1_1b.png'); %zapis obrazu