clc
I = imread('C:\Users\Krzysztof\Desktop\POC5\Zadanie1\Porównania\M92\Grafiki\M92.png'); %wczytanie obrazu
% PRZEKSZTAŁCENIA PUNKTOWE OBRAZU 
% mnożenie
a=0.8; b=0; gamma=1;
I1A=((double(I.*a).^gamma)+b)/255; 
% dodanie/odjęcie stałej
a=1; b=-20; gamma=1;
I2A=((double(I.*a).^gamma)+b)/255; 
% potęgowanie
a=1; b=0; gamma=0.95;
I3A=((double(I.*a).^gamma)+b)/255;
 
% mnożenie
a=1.2; b=0; gamma=1;
I1B=((double(I.*a).^gamma)+b)/255; 
% dodanie/odjęcie stałej
a=1; b=20; gamma=1;
I2B=((double(I.*a).^gamma)+b)/255; 
% potęga
a=1; b=0; gamma=1.03;
I3B=((double(I.*a).^gamma)+b)/255; 
 
imwrite(I1A,'C:\Users\Krzysztof\Desktop\M92_I1A.png');
imwrite(I2A,'C:\Users\Krzysztof\Desktop\M92_I2A.png');
imwrite(I3A,'C:\Users\Krzysztof\Desktop\M92_I3A.png');
imwrite(I1B,'C:\Users\Krzysztof\Desktop\M92_I1B.png');
imwrite(I2B,'C:\Users\Krzysztof\Desktop\M92_I2B.png');
imwrite(I3B,'C:\Users\Krzysztof\Desktop\M92_I3B.png');
