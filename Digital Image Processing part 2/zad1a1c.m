clc
clear all
%wczytanie obrazu
I = imread('C:\Users\Krzysztof\Desktop\POC5\Zadanie1\Generowanie\Ex3\Grafiki\Ex3.png');
[N,M,C]=size(I);
Lmax = 0;
Lmin = 256;
for i=1:N
    for j=1:M
        for m=1:C
            if I(i,j,m) < Lmin
                Lmin = I (i,j,m);
            end
            if I(i,j,m) > Lmax
                Lmax = I(i,j,m);
            end
        end
    end
end
im2double(I);
for i=1:N
    for j=1:M
        for m=1:C
            I2(i,j,m)= (255/double(Lmax-Lmin))*(I(i,j,m)-Lmin);
        end
    end
end
[J, T] = histeq(I);
I2 = im2uint8(I2);
m1=min(min(I2));
m2=max(max(I2));
m3=min(min(J));
m4=max(max(J));
figure
imhist(I)
figure
imhist(I2)
figure
imhist(J)
imwrite(I2,'C:\Users\Krzysztof\Desktop\HSOx.png');
imwrite(J,'C:\Users\Krzysztof\Desktop\HEOx.png')