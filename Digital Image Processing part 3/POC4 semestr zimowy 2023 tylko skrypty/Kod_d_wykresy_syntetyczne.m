clc
clear all
imtr1z = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy syntetyczne\triangle1.png');
imtr1 = im2bw(imtr1z);
imkolo1z = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy syntetyczne\circle1.png');
imkolo1 = im2bw(imkolo1z);
imkwad1z = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy syntetyczne\square1.png');
imkwad1 = im2bw(imkwad1z);
for i = 1:36
rotation(i) = i*10;
im_trrot = imrotate(imtr1, -(rotation(i)));
im_trrott = wspolczynniki(im_trrot);
trrot_K(i) = im_trrott(1);
trrot_Mz(i) = im_trrott(2);
trrot_Mal(i) = im_trrott(3);
resize(i) = 1 - (i*0.01);
im_trres = imresize(imtr1, resize(i));
im_trrest = wspolczynniki(im_trres);
trres_K(i) = im_trrest(1);
trres_Mz(i) = im_trrest(2);
trres_Mal(i) = im_trrest(3);
translate(i) = 1 + i;
im_trtrans = imtranslate(imtr1, [translate(i),2]);
im_trtranst = wspolczynniki(im_trtrans);
trtrans_K(i) = im_trtranst(1);
trtrans_Mz(i) = im_trtranst(2);
trtrans_Mal(i) = im_trtranst(3);
end
for i = 1:36
rotation(i) = i*10;
im_kwadrot = imrotate(imkwad1, -(rotation(i)));
im_kwadrott = wspolczynniki(im_kwadrot);
kwadrot_K(i) = im_kwadrott(1);
kwadrot_Mz(i) = im_kwadrott(2);
kwadrot_Mal(i) = im_kwadrott(3);
resize(i) = 1 - (i*0.01);
im_kwadres = imresize(imkwad1, resize(i));
im_kwadrest = wspolczynniki(im_kwadres);
kwadres_K(i) = im_kwadrest(1);
kwadres_Mz(i) = im_kwadrest(2);
kwadres_Mal(i) = im_kwadrest(3);
translate(i) = 1 + i;
im_kwadtrans = imtranslate(imkwad1, [translate(i),2]);
im_kwadtranst = wspolczynniki(im_kwadtrans);
kwadtrans_K(i) = im_kwadtranst(1);
kwadtrans_Mz(i) = im_kwadtranst(2);
kwadtrans_Mal(i) = im_kwadtranst(3);
end
for i = 1:36
rotation(i) = i*10;
im_kolorot = imrotate(imkolo1, -(rotation(i)));
im_kolorott = wspolczynniki(im_kolorot);
kolorot_K(i) = im_kolorott(1);
kolorot_Mz(i) = im_kolorott(2);
kolorot_Mal(i) = im_kolorott(3);
resize(i) = 1 - (i*0.01);
im_kolores = imresize(imkolo1, resize(i));
im_kolorest = wspolczynniki(im_kolores);
kolores_K(i) = im_kolorest(1);
kolores_Mz(i) = im_kolorest(2);
kolores_Mal(i) = im_kolorest(3);
translate(i) = 1 + i;
im_kolotrans = imtranslate(imkolo1, [translate(i),2]);
im_kolotranst = wspolczynniki(im_kolotrans);
kolotrans_K(i) = im_kolotranst(1);
kolotrans_Mz(i) = im_kolotranst(2);
kolotrans_Mal(i) = im_kolotranst(3);
end
figure
subplot(3,3,1)
plot(rotation,trrot_K)
hold on
plot(rotation,kolorot_K)
hold on
plot(rotation,kwadrot_K)
legend('Trójkąt', 'Koło', 'Prostokąt', 'Location','southoutside','Orientation','horizontal');
title('Rotacja - współczynnik Kompaktowości')
axis([0,400,0.5,1.1]);
subplot(3,3,4)
plot(rotation,trrot_Mz)
hold on
plot(rotation,kolorot_Mz)
hold on
plot(rotation,kwadrot_Mz)
legend('Trójkąt', 'Koło', 'Prostokąt', 'Location','southoutside','Orientation','horizontal');
title('Rotacja - współczynnik Mz')
axis([0,400,0.7,1.1]);
subplot(3,3,7)
plot(rotation,trrot_Mal)
hold on
plot(rotation,kolorot_Mal)
hold on
plot(rotation,kwadrot_Mal)
legend('Trójkąt', 'Koło', 'Prostokąt', 'Location','southoutside','Orientation','horizontal');
title('Rotacja - współczynnik Malinowskiej')
axis([0,400,-0.1,0.4]);
subplot(3,3,2)
plot(resize,trres_K)
hold on
plot(resize,kolores_K)
hold on
plot(resize,kwadres_K)
legend('Trójkąt', 'Koło', 'Prostokąt', 'Location','southoutside','Orientation','horizontal');
title('Przeskalowanie - współczynnik Kompaktowości')
axis([0.6,1,0.6,1.1]);
subplot(3,3,5)
plot(resize,trres_Mz)
hold on
plot(resize,kolores_Mz)
hold on
plot(resize,kwadres_Mz)
legend('Trójkąt', 'Koło', 'Prostokąt', 'Location','southoutside','Orientation','horizontal');
title('Przeskalowanie - współczynnik Mz')
axis([0.6,1,0.7,1.1]);
subplot(3,3,8)
plot(resize,trres_Mal)
hold on
plot(resize,kolores_Mal)
hold on
plot(resize,kwadres_Mal)
legend('Trójkąt', 'Koło', 'Prostokąt', 'Location','southoutside','Orientation','horizontal');
title('Przeskalowanie - współczynnik Malinowskiej')
axis([0.6,1,-0.1,0.3]);
subplot(3,3,3)
plot(translate,trtrans_K)
hold on
plot(translate,kolotrans_K)
hold on
plot(translate,kwadtrans_K)
legend('Trójkąt', 'Koło', 'Prostokąt', 'Location','southoutside','Orientation','horizontal');
title('Translacja - współczynnik Kompaktowości')
axis([0,40,0.5,1.1]);
subplot(3,3,6)
plot(translate,trtrans_Mz)
hold on
plot(translate,kolotrans_Mz)
hold on
plot(translate,kwadtrans_Mz)
legend('Trójkąt', 'Koło', 'Prostokąt', 'Location','southoutside','Orientation','horizontal');
title('Translacja - współczynnik Mz')
axis([0,40,0.7,1.1]);
subplot(3,3,9)
plot(translate,trtrans_Mal)
hold on
plot(translate,kolotrans_Mal)
hold on
plot(translate,kwadtrans_Mal)
legend('Trójkąt', 'Koło', 'Prostokąt', 'Location','southoutside','Orientation','horizontal');
title('Translacja - współczynnik Malinowskiej')
axis([0,40,-0.1,0.3]);
function y = wspolczynniki(im)
im = uint8(im);
Image = regionprops(im,'all');
L = Image.Perimeter;
S = Image.Area;
K = 4*pi*S/(L^2);
Mz = 2*sqrt(pi*S) / L;
M = L/(2*sqrt(pi*S))-1;
y = [K,Mz,M];
end