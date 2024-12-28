clc
clear all
Obraz1 = imread('C:\Users\Krzysztof\Desktop\podstawka.jpg');
Obraz1=rgb2gray(Obraz1);
%% Szum i histogram
Obraz1=imnoise(Obraz1,'salt & pepper',0.05);
%Obraz1=imnoise(Obraz1,'gaussian');
figure
imhist(Obraz1);
imwrite(Obraz1,'C:\Users\Krzysztof\Desktop\nike_gauss.png');
%% Binaryzacja
prog_zaklocony=graythresh(Obraz1);
prog_zaklocony=prog_zaklocony*255;
[x,y]=size(Obraz1);
image1=Obraz1;
for i=1:x
    for j=1:y
        if (Obraz1(i,j)>=prog_zaklocony)
            image1(i,j)=255;
        else
            image1(i,j)=0;
        end
    end
end
image1=uint8(image1);
figure
imshow (image1);
%% pscolor
[L1,obszary1]=(bwlabel(image1,4));
L1=label2rgb(L1, 'jet', 'w', 'shuffle');
figure
imshow (L1);
imwrite(image1,'C:\Users\Krzysztof\Desktop\progzaklocony.png');
imwrite(L1,'C:\Users\Krzysztof\Desktop\pscolorzaklocony.png');
%% Filtracja
mask=[7 7];
Obraz1=medfilt2(Obraz1,mask);
imwrite(Obraz1,'C:\Users\Krzysztof\Desktop\obraz_filtracja.png');
figure
imhist(Obraz1);
%% Binaryzacja po filtracji
prog_filtracja=graythresh(Obraz1);
prog_filtracja=prog_filtracja*255;
[x,y]=size(Obraz1);
image2=Obraz1;
for i=1:x
    for j=1:y
        if (Obraz1(i,j)>=prog_filtracja)
            image2(i,j)=255;
        else
            image2(i,j)=0;
        end
    end
end
image2=uint8(image2);
figure
imshow (image2);
%% pscolor po filtracji
[L2,obszary2]=(bwlabel(image2,4));
L2=label2rgb(L2, 'jet', 'w', 'shuffle');
figure
imshow (L2);
imwrite(image2,'C:\Users\Krzysztof\Desktop\progfiltracja.png');
imwrite(L2,'C:\Users\Krzysztof\Desktop\pscolorfiltracja.png');