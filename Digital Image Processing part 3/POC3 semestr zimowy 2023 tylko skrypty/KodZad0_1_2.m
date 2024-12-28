clc
clear all
Obraz1 = imread('C:\Users\Krzysztof\Desktop\podstawka.jpg');
Obraz2 = imread('C:\Users\Krzysztof\Desktop\nike.jpg');
Obraz1=rgb2gray(Obraz1);
Obraz2=rgb2gray(Obraz2);
imwrite(Obraz1,'C:\Users\Krzysztof\Desktop\I1.png');
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\I2.png');
%% Histogram
figure
imhist(Obraz1);
figure
imhist(Obraz2);
%% Mediana
%median1=median(Obraz1);
prog_hist_1= 80; % median(median1);
median2=median(Obraz2);
prog_hist_2=median(median2);
%% Binaryzacja O1
[x,y]=size(Obraz1);
image1=Obraz1;
for i=1:x
    for j=1:y
        if (Obraz1(i,j)>=prog_hist_1)
            image1(i,j)=255;
        else
            image1(i,j)=0;
        end
    end
end
image1=uint8(image1);
figure
imshow (image1);
%% Etykietowanie O1
[L,spoj_hist_1]=bwlabel(image1,4);
Label1=uint8(L); %L1=uint8(bwlabel(img1,4));
Label1=label2rgb(Label1, 'jet', 'w', 'shuffle');
figure
imshow (Label1);
%% Binaryzacja O2
[x,y]=size(Obraz2);
image2=Obraz2;
for i=1:x
    for j=1:y
        if (Obraz2(i,j)>=prog_hist_2)
            image2(i,j)=255;
        else
            image2(i,j)=0;
        end
    end
end
image2=uint8(image2);
figure
imshow (image2);
%% Etykietowanie O2
[L,spoj_hist_2]=bwlabel(image2,4);
Label2=uint8(L); %L2=uint8(bwlabel(img2,4));
Label2=label2rgb(Label2, 'jet', 'w', 'shuffle');
figure
imshow (Label2);
%% Metoda Otsu O1
prog_otsu_1=graythresh(Obraz1);
prog_otsu_2=graythresh(Obraz2);
prog_otsu_1=prog_otsu_1*255;
[x,y]=size(Obraz1);
image3=Obraz1;
for i=1:x
    for j=1:y
        if (Obraz1(i,j)>=prog_otsu_1)
            image3(i,j)=255;
        else
            image3(i,j)=0;
        end
    end
end
image3=uint8(image3);
figure
imshow (image3);
%% Etykietowanie O1
[L,spoj_otsu_1]=bwlabel(image3,4);
Label3=uint8(L); %L3=uint8(bwlabel(img3,4));
Label3=label2rgb(Label3, 'jet', 'w', 'shuffle');
figure
imshow (Label3);
%% Metoda Otsu O2
prog_otsu_2=prog_otsu_2*255;
[x,y]=size(Obraz2);
image4=Obraz2;
for i=1:x
    for j=1:y
        if (Obraz2(i,j)>=prog_otsu_2)
            image4(i,j)=255;
        else
            image4(i,j)=0;
        end
    end
end
image4=uint8(image4);
figure
imshow (image4);
%% Etykietowanie O2
[L,spoj_otsu_2]=bwlabel(image4,4);
Label4=uint8(L); %L4=uint8(bwlabel(img4,4));
Label4=label2rgb(Label4, 'jet', 'w', 'shuffle');
figure
imshow (Label4);
%% Zapis
imwrite(image1,'C:\Users\Krzysztof\Desktop\hist1.png');
imwrite(image2,'C:\Users\Krzysztof\Desktop\hist2.png');
imwrite(image3,'C:\Users\Krzysztof\Desktop\otsu1.png');
imwrite(image4,'C:\Users\Krzysztof\Desktop\otsu2.png');
imwrite(Label1,'C:\Users\Krzysztof\Desktop\Label_hist1.png');
imwrite(Label2,'C:\Users\Krzysztof\Desktop\Label_hist2.png');
imwrite(Label3,'C:\Users\Krzysztof\Desktop\Label_otsu3.png');
imwrite(Label4,'C:\Users\Krzysztof\Desktop\Label_otsu4.png');
%imwrite(img1,'C:\Users\Krzysztof\Desktop\img1.png');
%imwrite(img1,'C:\Users\Krzysztof\Desktop\img1.png');