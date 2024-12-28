clc;
clear all;
I=imread('C:\Users\Krzysztof\Desktop\POC1\O12.bmp');
I=im2double(I);
I=rgb2gray(I);
Iszum=I(250:400,250:400);
imwrite(Iszum,'C:\Users\Krzysztof\Desktop\POC1\medIszum2.bmp');
figure;
imshow(I);
[N,M,C]=size(I);
lmax = 0;
lmin = 256;
tmp = 0;
double(tmp);
lsred = sum(sum(sum(I)))/double(N*M);
for i=1:N
for j=1:M
for m=1:C
if I(i,j,m) < lmin
lmin = I (i,j,m);
end
if I(i,j,m) > lmax
lmax = I(i,j,m);
end
tmp = tmp + (double(I(i,j,m))-lsred)^2;
end
end
end
k1 = double(lmax-lmin)/255;
i=0;
j=0;
m=0;
k=k1;
mask=[3 3];
p=(mask-1)/2;
center=round((mask(1)*mask(2))+1)/2;
[imax,jmax,kmax] = size(I);
im=zeros(imax,jmax,kmax);
for channel=1:kmax
for i=1+p:(imax-p)
for j=1+p:(jmax-p)
im1= reshape(I(i-p:i+p,j-p:j+p,channel),mask(1)*mask(2),1);
x0=im1(center);
im1=sort(im1);
im3=median([im1(center-k),x0,im1(center+k)]);
im(i,j,channel)=im3;
end
end
end
out=im2double(im);
figure;
imshow(out);
I4=medfilt2(I, mask);
figure;
imshow(I4);
I5=I4(250:400,250:400);
imwrite(I5,'C:\Users\Krzysztof\Desktop\POC1\medMat32.bmp');
Iorg = imread('C:\Users\Krzysztof\Desktop\POC1\monarch_512x512.bmp');
Iorg2=Iorg(250:400,250:400);
imwrite(Iorg2,'C:\Users\Krzysztof\Desktop\POC1\medIorg2.bmp');
I3=out(250:400,250:400);
imwrite(I3,'C:\Users\Krzysztof\Desktop\POC1\medAlg32k1.bmp');
clc;
clear all;
I=imread('C:\Users\Krzysztof\Desktop\POC1\O32.bmp');
I=im2double(I);
I=rgb2gray(I);
Iszum=I(250:400,250:400);
imwrite(Iszum,'C:\Users\Krzysztof\Desktop\POC1\medIszum3.bmp');
figure;
imshow(I);
mask=[3 3];
p=(mask-1)/2;
[imax,jmax,kmax] = size(I);
im=zeros(imax,jmax,kmax);
for channel=1:kmax
for i=1+p:(imax-p)
for j=1+p:(jmax-p)
im1= median(reshape(I(i-p:i+p,j-p:j+p,channel),mask(1)*mask(2),1));
im(i,j,channel)=im1;end
end
end
out=im2double(im);
figure;
imshow(out);
I4=medfilt2(I, mask);
figure;
imshow(I4);
I5=I4(250:400,250:400);
%imwrite(I5,'C:\Users\Krzysztof\Desktop\POC1\medMat32.bmp');
Iorg = imread('C:\Users\Krzysztof\Desktop\POC1\monarch_512x512.bmp');
Iorg2=Iorg(250:400,250:400);
%imwrite(Iorg2,'C:\Users\Krzysztof\Desktop\POC1\medIorg2.bmp');
I3=out(250:400,250:400);
imwrite(I3,'C:\Users\Krzysztof\Desktop\POC1\medAlg32x15.bmp');