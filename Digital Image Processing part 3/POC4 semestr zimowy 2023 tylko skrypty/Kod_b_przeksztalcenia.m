clc
clear all
a = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy rzeczywiste\zakretkax.png');
% a = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy rzeczywiste\ladowarka.png');
% a = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy rzeczywiste\moneta.png');
% a = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy rzeczywiste\kontakt.png');
imtr1 = im2bw(a);
im_rot = imrotate(imtr1, -30);
im_res = imresize(im_rot, 0.8);
im1 = imtranslate(im_res, [100,2]);
for i = 1:700
    for j=1:700
        a1(i,j)=0;
    end
end
for i = 1:560
    for j=1:560
        a1(i,j)=im1(i,j);
    end
end
im_rot2 = imrotate(imtr1, 60);
im_res2 = imresize(im_rot2, 1);
a2 = imtranslate(im_res2, [-100,50]);

im_rot3 = imrotate(imtr1, 90);
im_res3 = imresize(im_rot3, 0.5);
im3 = imtranslate(im_res3, [-50,-50]);
for i = 1:700
    for j=1:700
        a3(i,j)=0;
    end
end
for i = 1:256
    for j=1:256
        a3(i,j)=im3(i,j);
    end
end

im_rot4 = imrotate(imtr1, 105);
im_res4 = imresize(im_rot4, 0.5);
im4 = imtranslate(im_res4, [50,50]);
for i = 1:700
    for j=1:700
        a4(i,j)=0;
    end
end
for i = 1:314
    for j=1:314
        a4(i+386,j+386)=im4(i,j);
    end
end
figure
imshow(a1);
figure
imshow(a2);
figure
imshow(a3);
figure
imshow(a4);
%imwrite(a1,'C:\Users\Krzysztof\Desktop\obudowa2.png');
%imwrite(a2,'C:\Users\Krzysztof\Desktop\obudowa3.png');
%imwrite(a3,'C:\Users\Krzysztof\Desktop\obudowa4.png');
%imwrite(a4,'C:\Users\Krzysztof\Desktop\obudowa5.png');
%imwrite(a1,'C:\Users\Krzysztof\Desktop\noz2.png');
%imwrite(a2,'C:\Users\Krzysztof\Desktop\noz3.png');
%imwrite(a3,'C:\Users\Krzysztof\Desktop\noz4.png');
%imwrite(a4,'C:\Users\Krzysztof\Desktop\noz5.png');
imwrite(a1,'C:\Users\Krzysztof\Desktop\zakretka2.png');
imwrite(a2,'C:\Users\Krzysztof\Desktop\zakretka3.png');
imwrite(a3,'C:\Users\Krzysztof\Desktop\zakretka4.png');
imwrite(a4,'C:\Users\Krzysztof\Desktop\zakretka5.png');