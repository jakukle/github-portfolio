clc
%wczytanie obrazu
I = imread('C:\Users\Krzysztof\Desktop\POC5\Zadanie1\Generowanie\Ex3\Grafiki\Ex3.png');
[N,M,C]=size(I);
M1=min(min(I));
M2=max(max(I));
if(M2~=255)
    I(1,1,1)=255;
end
if(M1~=0)
    I(1,2,1)=0;
end
p=1000;
Lmax = 0;
Lmin = 255;
[counts,x] = imhist(I);
for i=1:256
    if counts(i) > p && i<Lmin
        Lmin = i;
    end
    if counts(i) > p && i>Lmax
        Lmax = i;
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
I2 = im2uint8(I2);
m1=min(min(I2));
m2=max(max(I2));
figure
imhist(I)
figure
imhist(I2)
imwrite(I2,'C:\Users\Krzysztof\Desktop\HScp2_p1000.png');