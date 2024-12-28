%close all
clear all
clc
%ZAD 0, 1 i 2
im11=imread("1.jpg");
im2=imread("2.jpg");
im3=imread("3.jpg");
im4=imread("4.jpg");
im5=imread("5.jpg");
im6=imread("6.jpg");
im7=imread("7.jpg");
theta1 = 135;
im=input("Obraz (1-7)? ");
kostkanumer=input("Wartosc? ");
switch im
    case 1
        im1=im11;
    case 2
        im1=im2;
    case 3
        im1=im3;
    case 4
        im1=im4;
    case 5
        im1=im5;
    case 6
        im1=im6;
    case 7
        im1=im7;
    otherwise
        im1=im11;
end
[imlabel, ilosckostek]=bwlabel(blackwhite2(im1, theta1));
[x1,y1]=size(im1);
if ilosckostek>1
    if x1>y1 %3 w poziomie
        x=2*x1/ilosckostek;
        y=3*y1/ilosckostek;
        im1temp(:,:,1)=im1(1:x, 1:y);
        im1temp(:,:,2)=im1(x:2*x-1, 1:y);
        im1temp(:,:,3)=im1(2*x:3*x-1, 1:y);
        im1temp(:,:,4)=im1(1:x, y:2*y-1);
        im1temp(:,:,5)=im1(x:2*x-1, y:2*y-1);
        im1temp(:,:,6)=im1(2*x:3*x-1, y:2*y-1);
    elseif x1<y1 %3 w pionie
        x=3*x1/ilosckostek;
        y=2*y1/ilosckostek;
        im1temp(:,:,1)=im1(1:x, 1:y);
        im1temp(:,:,2)=im1(x:2*x-1, 1:y);
        im1temp(:,:,3)=im1(1:x, y:2*y-1);
        im1temp(:,:,4)=im1(x:2*x-1, y:2*y-1);
        im1temp(:,:,5)=im1(1:x, 2*y:3*y-1);
        im1temp(:,:,6)=im1(x:2*x-1, 2*y:3*y-1);
    end
    else
        im1temp=im1;
        endfor i=1:ilosckostek
        im1bw(:,:,i)=blackwhite(im1temp(:,:,i), theta1);
        [im1bw1label, im1bw1n]=bwlabel(im1bw(:,:,i));
        wyniki(i)=im1bw1n-1;
end
error=0;
for m=1:ilosckostek
    if wyniki(m)==kostkanumer
        break;
    end
    if m==ilosckostek
        error=1;
    break;
    end
end
imkolor=label2rgb(imlabel);
if error==0
    for i=1:x1
        for j=1:y1
            if imlabel(i,j)==m
                im1(i,j)=255;
            end
        end
    end
end
figure(1)
imshow(im1)
if error==0
xlabel("Wykryto: "+ num2str(wyniki) + ". Znaleziono wskazany numer " ...
+ num2str(kostkanumer))
else
xlabel("Wykryto: "+ num2str(wyniki) + ". Nie znaleziono wskazanej kostki")
end
function [result] = blackwhite(I, thresh)
    [x,y]=size(I);
    for i = 1:x
        for j = 1:y
            if(I(i,j)<thresh)
                result(i,j)=1;
            else
                result(i,j)=0;
            end
        end
    end
end
function [result] = blackwhite2(I, thresh)
    [x,y]=size(I);
    for i = 1:x
        for j = 1:y
            if(I(i,j)<thresh)
                result(i,j)=0;
            else
                result(i,j)=1;
            end
        end
    end
end