clc
clear all
Obraz1 = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy rzeczywiste\noz.png');
Obraz1=rgb2gray(Obraz1);
%imwrite(Obraz1,'C:\Users\Krzysztof\Desktop\I1.png');

prog_hist_1= 95;  %125 %90

%% Binaryzacja O1
[x,y]=size(Obraz1);
image1=Obraz1;
for i=1:x
    for j=1:y
        if (Obraz1(i,j)>=prog_hist_1)
            image1(i,j)=0;
        else
            image1(i,j)=255;
        end
    end
end
image1=uint8(image1);
figure
imshow (image1);

[L,spoj_hist_1]=bwlabel(image1,4);
Label1=uint8(L); %L1=uint8(bwlabel(img1,4));
Label1=label2rgb(Label1, 'jet', 'w', 'shuffle');

%% Zapis
imwrite(image1,'C:\Users\Krzysztof\Desktop\zakretkax.png');