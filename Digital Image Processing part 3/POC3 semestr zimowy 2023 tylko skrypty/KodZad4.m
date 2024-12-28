clc
clear all
I1 = imread('C:\Users\Krzysztof\Desktop\POC3\Zad0_1_2\Poprawki\otsu1.png');
%figure
%imshow (I1);
% sferyczne z promieniem 15 pixeli lub liniowe

se = strel('disk',2); %strel('line',8,180);
I1 = imclose(I1,se);
figure
imshow (I1);
[L3,spoj0_close]=(bwlabel(I1,4));
L3=label2rgb(L3);
figure
imshow (L3);
imwrite(I1,'C:\Users\Krzysztof\Desktop\close.png')
imwrite(L3,'C:\Users\Krzysztof\Desktop\closea.png');

se = strel('line',15,180); %strel('line',15,180); se = strel('sphere',15);
I1 = imdilate(I1,se);
figure
imshow (I1);
[L3,spoj1_dilate]=(bwlabel(I1,4));
L3=label2rgb(L3);
figure
imshow (L3);
imwrite(I1,'C:\Users\Krzysztof\Desktop\dilate.png')
imwrite(L3,'C:\Users\Krzysztof\Desktop\dilatea.png');

se = strel('line',15,60);
I1 = imopen(I1,se);
figure
imshow (I1);
[L3,spoj2_open]=(bwlabel(I1,4));
L3=label2rgb(L3);
figure
imshow (L3);
imwrite(I1,'C:\Users\Krzysztof\Desktop\open.png')
imwrite(L3,'C:\Users\Krzysztof\Desktop\opena.png');
 
se = strel('line',15,30);
I1 = imerode(I1,se);
figure
imshow (I1);
[L3,spoj3_erode]=(bwlabel(I1,4));
L3=label2rgb(L3);
figure
imshow (L3);
imwrite(I1,'C:\Users\Krzysztof\Desktop\erode.png')
imwrite(L3,'C:\Users\Krzysztof\Desktop\erodea.png');

 

