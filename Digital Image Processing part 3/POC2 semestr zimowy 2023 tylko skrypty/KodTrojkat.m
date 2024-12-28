%Trojkat
clc;
clear all; %czyszczenie cmd Window
I=imread('C:\Users\Krzysztof\Desktop\prostokat.png');
j=0;
for i=1:25:91 %co kat 25 do 90
    j=j+1;
    trojkat_rotacja=imrotate(I,i-1,'crop');
    funkcja=fftshift(fft2(trojkat_rotacja));
    subplot(2,4,j) %wyswietlenie
    string1=strcat('kąt=',num2str(i-1));
    imshow(trojkat_rotacja,[])
    if(j==1)
        imwrite(trojkat_rotacja,'C:\Users\Krzysztof\Desktop\prostokat1.png');
    end
    if(j==2)
        imwrite(trojkat_rotacja,'C:\Users\Krzysztof\Desktop\prostokat2.png');
    end
    if(j==3)
        imwrite(trojkat_rotacja,'C:\Users\Krzysztof\Desktop\prostokat3.png');
    end
    if(j==4)
        imwrite(trojkat_rotacja,'C:\Users\Krzysztof\Desktop\prostokat4.png');
    end
    title(string1);
end
subplot(2,4,1) %wyswietlenie zlaczone
%ylabel('Trójkąty rotacja');
parametry= int8(-120 + 250.*rand(4,2)); %parametry translacji trojkątów
for i=1:4
    j=j+1;
    trojkat_translacja=imtranslate(I,parametry(i,:));
    funkcja=fftshift(fft2(trojkat_translacja));
    subplot(2,4,j) %wyswietlenie
    imshow(trojkat_translacja,[])
    if(j==5)
        imwrite(trojkat_translacja,'C:\Users\Krzysztof\Desktop\prostokat5.png');
    end
    if(j==6)
        imwrite(trojkat_translacja,'C:\Users\Krzysztof\Desktop\prostokat6.png');
    end
    if(j==7)
        imwrite(trojkat_translacja,'C:\Users\Krzysztof\Desktop\prostokat7.png');
    end
    if(j==8)
        imwrite(trojkat_translacja,'C:\Users\Krzysztof\Desktop\prostokat8.png');
    end
end
subplot(2,4,5) %wyswietlenie zlaczone
%ylabel('Trójkąty translacja');

