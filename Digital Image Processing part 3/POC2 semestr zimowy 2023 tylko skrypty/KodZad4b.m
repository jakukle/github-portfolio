close all
clear all
clc

Img=imread("C:\Users\Krzysztof\Desktop\woman_512x512.bmp");
filtr_gor=ones(512);
filtr_dol=ones(512);
filtr2_gor=ones(512);
filtr2_dol=ones(512);
r1=10;
r2=40;
for i=1:512
   for j=1:512
       if(sqrt((i-256).^2+(j-256).^2)>r1)
           filtr_dol(i,j)=0;
       end
       if(sqrt((i- 256).^2+(j-256).^2)<r1)
            filtr_gor(i,j)=0;
       end
       if(sqrt((i-256).^2+(j-256).^2)>r2)
           filtr2_dol(i,j)=0;
       end
       if(sqrt((i- 256).^2+(j-256).^2)<r2)
            filtr2_gor(i,j)=0;
       end
   end
end
figure(1)
subplot(2,5,1)
imshow(Img)
xlabel("O1")
subplot(2,5,6)
imshow(Img)
xlabel("O1")
subplot(2,5,2)
fazaImg =fftshift(fft2(Img));
mocImg = 20*log(1+abs(fazaImg));
widmo_mocyImg = uint8(mocImg);
imshow(widmo_mocyImg)
xlabel("Widmo mocy")
subplot(2,5,7)
imshow(widmo_mocyImg)
xlabel("Widmo mocy")
subplot(2,5,3)
imshow(filtr_dol)
xlabel("Maska 1")
subplot(2,5,8)
imshow(filtr2_dol)
xlabel("Maska 2")
for i=1:512
   for j=1:512
       faza1(i,j)=fazaImg(i,j)*filtr_dol(i,j);
       faza2(i,j)=fazaImg(i,j)*filtr2_dol(i,j);
   end
end
widmomocy1 = 20*log(1+abs(faza1));
widmomocy1 = uint8(widmomocy1);
widmomocy2 = 20*log(1+abs(faza2));
widmomocy2 = uint8(widmomocy2);
subplot(2,5,4)
imshow(widmomocy1)
xlabel("maska*|FFT2|")
subplot(2,5,9)
imshow(widmomocy2)
xlabel("maska*|FFT2|")
Imgnew = ifft2(ifftshift(faza1));
Imgnew = Imgnew./(max(max(Imgnew)));
im2new = ifft2(ifftshift(faza2));
im2new = im2new./(max(max(im2new)));
subplot(2,5,5)
imshow(real(Imgnew))
xlabel("Wynik")
subplot(2,5,10)
imshow(real(im2new))
xlabel("Wynik")


figure(2)
subplot(2,5,1)
imshow(Img)
xlabel("O1")
subplot(2,5,6)
imshow(Img)
xlabel("O1")
subplot(2,5,2)
fazaImg =fftshift(fft2(Img));
mocImg = 20*log(1+abs(fazaImg));
widmo_mocyImg = uint8(mocImg);
imshow(widmo_mocyImg)
xlabel("Widmo mocy")
subplot(2,5,7)
imshow(widmo_mocyImg)
xlabel("Widmo mocy")
subplot(2,5,3)
imshow(filtr_gor)
xlabel("Maska 1")
subplot(2,5,8)
imshow(filtr2_gor)
xlabel("Maska 2")
for i=1:512
   for j=1:512
       faza1(i,j)=fazaImg(i,j)*filtr_gor(i,j);
       faza2(i,j)=fazaImg(i,j)*filtr2_gor(i,j);
   end
end
widmomocy1 = 20*log(1+abs(faza1));
widmomocy1 = uint8(widmomocy1);
widmomocy2 = 20*log(1+abs(faza2));
widmomocy2 = uint8(widmomocy2);
subplot(2,5,4)
imshow(widmomocy1)
xlabel("maska*|FFT2|")
subplot(2,5,9)
imshow(widmomocy2)
xlabel("maska*|FFT2|")
Imgnew = ifft2(ifftshift(faza1));
Imgnew = Imgnew./(max(max(Imgnew)));
im2new = ifft2(ifftshift(faza2));
im2new = im2new./(max(max(im2new)));
subplot(2,5,5)
imshow(real(Imgnew))
xlabel("Wynik")
subplot(2,5,10)
imshow(real(im2new))
xlabel("Wynik")