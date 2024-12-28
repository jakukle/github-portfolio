clc %czyszczenie ekranu Command Window
I = imread('C:\Users\Krzysztof\Desktop\POC5\Zadanie1\Generowanie\M92\Grafiki\M92_I3B.png'); %wczytanie obrazu
imhist(I) %wyswietlenie histogramu
[N,M,C]=size(I); %trojwymiarowa macierz
lmax = 0; %poziomy szarosci pixela
lmin = 256; %poziomy szarosci pixela
tmp = 0; 
double(tmp); %rzutowanie na double
lsred = sum(sum(sum(I)))/double(N*M); %policzenie wartosci l sredniego
for i=1:N %rozdzielczosc obrazu wczytanego
    for j=1:M %rozdielczosc obrazu wczytanego
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
k1 = double(lmax-lmin)/255; %policzenie miary kontrastu k1
k2 = double(lmax-lmin)/lsred; %policzenie miary kontrastu k2
k3 = double(lmax-lmin)/double(lmin+lmax); %policzenie miary kontrastu k3
k4 = double(4/(double(M)*double(N)*255^2))*double(tmp); %policzenie miary kontrastu k4
