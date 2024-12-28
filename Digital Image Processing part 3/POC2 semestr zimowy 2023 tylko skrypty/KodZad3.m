clc;
clear all; %czyszczenie cmd Window
I=imread('C:\Users\Krzysztof\Desktop\woman_512x512.bmp'); %wczytanie bmp
imwrite(I,'C:\Users\Krzysztof\Desktop\woman0.png'); %zapis do png
Obraz1=fftshift(fft2(I)); %Przesuń składową o zerowej częstotliwości na środek widma - trans F
figure %podtrzymanie
imshow(log(abs(Obraz1)+1),[]); %pokazanie obrazu
xlabel('Widmo mocy 0'); %podpis osi x
%imwrite(uint8(L1),'C:\Users\Krzysztof\Desktop\0widmo.png');
%h=fspecial('motion'); %filtracja dolnoprzepustowa
h=[0 -1 0; %filtracja gornoprzepustowa
   -1 5 -1;
   0 -1 0];
for i=1:10
    I=imfilter(I,h);
    if(i==1)
        figure %podtrzymanie
        imshow(I); %pokazanie
        Obraz1=fftshift(fft2(I)); %Przesuń składową o zerowej częstotliwości na środek widma - trans F
        figure %podtrzymanie
        imshow(log(abs(Obraz1)+1),[]); %pokazanie
        xlabel('Widmo mocy 1'); %podpis osi x
        imwrite(I,'C:\Users\Krzysztof\Desktop\woman1.png'); %zapis do pliku
    end
    if(i==2)
        figure
        imshow(I);
        Obraz1=fftshift(fft2(I));
        figure
        imshow(log(abs(Obraz1)+1),[]);
        xlabel('Widmo mocy 2');
        imwrite(I,'C:\Users\Krzysztof\Desktop\woman2.png');
    end
    if(i==5)
        figure
        imshow(I);
        Obraz1=fftshift(fft2(I));
        figure
        imshow(log(abs(Obraz1)+1),[]);
        xlabel('Widmo mocy 5');
        imwrite(I,'C:\Users\Krzysztof\Desktop\woman5.png');
    end
    if(i==10)
        figure
        imshow(I);
        Obraz1=fftshift(fft2(I));
        figure
        imshow(log(abs(Obraz1)+1),[]);
        xlabel('Widmo mocy 10');
        imwrite(I,'C:\Users\Krzysztof\Desktop\woman10.png');
    end
end