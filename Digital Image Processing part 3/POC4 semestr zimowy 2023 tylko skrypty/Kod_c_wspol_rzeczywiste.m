clc
clear all
imtr1z = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy rzeczywiste\obudowax.png');
imtr1 = im2bw(imtr1z);
imtr2z = imread('C:\Users\Krzysztof\Desktop\obudowa2.png');
imtr2 = im2bw(imtr2z);
imtr3z = imread('C:\Users\Krzysztof\Desktop\obudowa3.png');
imtr3 = im2bw(imtr3z);
imtr4z = imread('C:\Users\Krzysztof\Desktop\obudowa4.png');
imtr4 = im2bw(imtr4z);
imtr5z = imread('C:\Users\Krzysztof\Desktop\obudowa5.png');
imtr5 = im2bw(imtr5z);
imkolo1z = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy rzeczywiste\zakretkax.png');
imkolo1 = im2bw(imkolo1z);
imkolo2z = imread('C:\Users\Krzysztof\Desktop\zakretka2.png');
imkolo2 = im2bw(imkolo2z);
imkolo3z = imread('C:\Users\Krzysztof\Desktop\zakretka3.png');
imkolo3 = im2bw(imkolo3z);
imkolo4z = imread('C:\Users\Krzysztof\Desktop\zakretka4.png');
imkolo4 = im2bw(imkolo4z);
imkolo5z = imread('C:\Users\Krzysztof\Desktop\zakretka5.png');
imkolo5 = im2bw(imkolo5z);
imkwad1z = imread('C:\Users\Krzysztof\Desktop\POC4\Zad1_2\Obrazy rzeczywiste\nozx.png');
imkwad1 = im2bw(imkwad1z);
imkwad2z = imread('C:\Users\Krzysztof\Desktop\noz2.png');
imkwad2 = im2bw(imkwad2z);
imkwad3z = imread('C:\Users\Krzysztof\Desktop\noz3.png');
imkwad3 = im2bw(imkwad3z);
imkwad4z = imread('C:\Users\Krzysztof\Desktop\noz4.png');
imkwad4 = im2bw(imkwad4z);
imkwad5z = imread('C:\Users\Krzysztof\Desktop\noz5.png');
imkwad5 = im2bw(imkwad5z);
imtr1wsp=wspolczynniki(imtr1);
imtr2wsp=wspolczynniki(imtr2);
imtr3wsp=wspolczynniki(imtr3);
imtr4wsp=wspolczynniki(imtr4);
imtr5wsp=wspolczynniki(imtr5);
imtr_K=[imtr1wsp(1) imtr2wsp(1) imtr3wsp(1) imtr4wsp(1) imtr5wsp(1)];
imtr_Mz=[imtr1wsp(2) imtr2wsp(2) imtr3wsp(2) imtr4wsp(2) imtr5wsp(2)];
imtr_Mal=[imtr1wsp(3) imtr2wsp(3) imtr3wsp(3) imtr4wsp(3) imtr5wsp(3)];
imkolo1wsp=wspolczynniki(imkolo1);
imkolo2wsp=wspolczynniki(imkolo2);
imkolo3wsp=wspolczynniki(imkolo3);
imkolo4wsp=wspolczynniki(imkolo4);
imkolo5wsp=wspolczynniki(imkolo5);
imkolo_K=[imkolo1wsp(1) imkolo2wsp(1) imkolo3wsp(1) imkolo4wsp(1) imkolo5wsp(1)];
imkolo_Mz=[imkolo1wsp(2) imkolo2wsp(2) imkolo3wsp(2) imkolo4wsp(2) imkolo5wsp(2)];
imkolo_Mal=[imkolo1wsp(3) imkolo2wsp(3) imkolo3wsp(3) imkolo4wsp(3) imkolo5wsp(3)];
imkwad1wsp=wspolczynniki(imkwad1);
imkwad2wsp=wspolczynniki(imkwad2);
imkwad3wsp=wspolczynniki(imkwad3);
imkwad4wsp=wspolczynniki(imkwad4);
imkwad5wsp=wspolczynniki(imkwad5);
imkwad_K=[imkwad1wsp(1) imkwad2wsp(1) imkwad3wsp(1) imkwad4wsp(1) imkwad5wsp(1)];
imkwad_Mz=[imkwad1wsp(2) imkwad2wsp(2) imkwad3wsp(2) imkwad4wsp(2) imkwad5wsp(2)];
imkwad_Mal=[imkwad1wsp(3) imkwad2wsp(3) imkwad3wsp(3) imkwad4wsp(3) imkwad5wsp(3)];
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imtr1wsp(1),imtr1wsp(2),imtr1wsp(3)); %%obudowa ladowarki
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imtr2wsp(1),imtr2wsp(2),imtr2wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imtr3wsp(1),imtr3wsp(2),imtr3wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imtr4wsp(1),imtr4wsp(2),imtr4wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f\n',imtr5wsp(1),imtr5wsp(2),imtr5wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imkwad1wsp(1),imkwad1wsp(2),imkwad1wsp(3)); %%noz
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imkwad2wsp(1),imkwad2wsp(2),imkwad2wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imkwad3wsp(1),imkwad3wsp(2),imkwad3wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imkwad4wsp(1),imkwad4wsp(2),imkwad4wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f\n',imkwad5wsp(1),imkwad5wsp(2),imkwad5wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imkolo1wsp(1),imkolo1wsp(2),imkolo1wsp(3)); %%zakretka
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imkolo2wsp(1),imkolo2wsp(2),imkolo2wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imkolo3wsp(1),imkolo3wsp(2),imkolo3wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f ',imkolo4wsp(1),imkolo4wsp(2),imkolo4wsp(3));
fprintf('K1=%.2f,K2=%.2f,K3=%.2f',imkolo5wsp(1),imkolo5wsp(2),imkolo5wsp(3));

function y = wspolczynniki(im)
im = uint8(im);
Image = regionprops(im,'all');
L = Image.Perimeter;
S = Image.Area;
C= Image.Centroid;
%r = dist ( PixelList ,C ) ;
K = 4*pi*S/(L^2);
Mz = 2*sqrt(pi*S) / L;
M = L/(2*sqrt(pi*S))-1;
y = [K,Mz,M];
end