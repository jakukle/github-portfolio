clc;
clear all;
I = imread('C:\Users\Krzysztof\Desktop\POC1\monarch_512x512.bmp');
O1kuba = imnoise(I,'salt & pepper',0.01);
O2kuba = imnoise(I,'salt & pepper',0.03);
O3kuba = imnoise(I,'salt & pepper',0.15);
[PSNR, snr]=psnr(O1kuba,I);
r1=10^(0.1*snr);
r1=1/r1;
[PSNR, snr]=psnr(O2kuba,I);
r2=10^(0.1*snr);
r2=1/r2;
[PSNR, snr]=psnr(O3kuba,I);
r3=10^(0.1*snr);
r3=1/r3;
x1=abs(I-O1kuba);
x2=abs(I-O2kuba);
x3=abs(I-O3kuba);
c1=0;
c2=0;
c3=0;
z=0;
[imax,jmax,kmax] = size(x1);
for i=1:imax
for j=1:jmax
for k=1:kmax
z=z+1;
if x1(i,j,k)~=0
c1=c1+1;
end
if x2(i,j,k)~=0
c2=c2+1;
end
if x3(i,j,k)~=0
c3=c3+1;
end
end
end
end
a1=c1/z;
a2=c2/z;
a3=c3/z;
im1zkuba=[I(250:400,250:400,:),O1kuba(250:400,250:400,:),O2kuba(250:400,250:400,:),O3kuba(250:400,250:400,:)];
im1aKuba=imresize(im1zkuba,3,'nearest');
imwrite(im1aKuba, 'C:\Users\Krzysztof\Desktop\zad12.bmp');