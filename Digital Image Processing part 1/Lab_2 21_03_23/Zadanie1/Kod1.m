I=imread('C:\Users\Krzysztof\Desktop\POC2\Bayer\CFA_sRGB\IMG_7111_srgb_CFA.png'); %sczytujemy surowy obraz
%IGT=imread('C:\Users\Krzysztof\Desktop\POC2\Bayer\GT_sRGB\IMG_7111_srgb.png'); %sczytujemy wzorcowy 

I1 = demosaic(I,'gbrg'); % green blue red green (sensorAlignment) - oko ludzkie jest szczególnie wrażliwe na zielony
I2 = demosaic(I,'grbg'); % green red blue green
I3 = demosaic(I,'bggr'); % blue green green red
I4 = demosaic(I,'rggb'); % red green green blue - from left to right, from top to bottom

figure; %stworzenie nowego obrazu
imshow(I1); title('gbrg'); %wyswietlenie obrazu w matlabie
imwrite(I1,'C:\Users\Krzysztof\Desktop\zad1a.png'); %stworzenie nowego obrazu o podanej ścieżce i nazwie
figure; %stworzenie nowego obrazu
imshow(I2); title('grbg'); %wyswietlenie obrazu w matlabie
imwrite(I2,'C:\Users\Krzysztof\Desktop\zad1b.png'); %stworzenie nowego obrazu o podanej ścieżce i nazwie
figure; %stworzenie nowego obrazu
imshow(I3); title('bggr'); %wyswietlenie obrazu w matlabie
imwrite(I3,'C:\Users\Krzysztof\Desktop\zad1c.png'); %stworzenie nowego obrazu o podanej ścieżce i nazwie
figure; %stworzenie nowego obrazu
imshow(I4); title('rggb'); %wyswietlenie obrazu w matlabie
imwrite(I4,'C:\Users\Krzysztof\Desktop\zad1d.png'); %stworzenie nowego obrazu o podanej ścieżce i nazwie
