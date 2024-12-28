clc
clear all %czyszczenie cmd window
I = imread ("C:\Users\Krzysztof\Desktop\3b_VMFL1_MAN.png"); Oryginal = imread ("C:\Users\Krzysztof\Desktop\gold_512x512.png");
[Ix , Iy , Iz]= size(I); maska = input ( "podaj maske "); %pobranie maski
Inicjacja = uint8 (zeros(Ix , Iy , 3)); %inicjacja obrazu zerami
MedianL2EUK = Inicjacja ; MedianL1MAN = Inicjacja;
pol_maski_gora = ceil (maska/2); pol_maski_dol = floor (maska/2); %maska pol gora oraz maska pol dol
odniesienie_x = 1; odniesienie_y = 1; %odniesienie do liczby
for i = pol_maski_gora : Ix - pol_maski_dol %petla bez maski
    for j = pol_maski_gora : Iy - pol_maski_dol %petla bez maski
        czesc_obrazu = (I( i - pol_maski_dol : i +pol_maski_dol , j - pol_maski_dol : j + pol_maski_dol , : )); %wziecie tylko czesci obrazu z maski do chwilowego przetworzenia
        czesc_obrazu_double = double ( czesc_obrazu ) /255; granica = inf; %rzutowanie na double i nieskonczonosc do sumy
        for ix = 1 : maska %wylacznie dla rozmiaru maski
            for iy = 1 :maska %wylacznie dla rozmiaru maski
                suma = 0; kwadrat = 0; %suma i kwadraty
                for l = 1 : maska %wylacznie dla rozmiaru maski
                    for t = 1 :maska %wylacznie dla rozmiaru maski i wzor do EUK
                        kwadrat=[kwadrat sqrt((czesc_obrazu_double(ix,iy,1)-czesc_obrazu_double(l,t,1))^2+(czesc_obrazu_double(ix,iy,2)-czesc_obrazu_double(l,t,2))^2+(czesc_obrazu_double(ix,iy,3)-czesc_obrazu_double(l,t,3))^2)];
                    end
                end
                suma = sum( kwadrat ( 1 , : ));
                if suma < granica %jesli suma jest mniejsza od minimalnej granicy
                    granica = suma; odniesienie_x = ix; odniesienie_y = iy; %przypisanie mniejszej sumy do aktualnej i odniesienia do parametru obrazu
                end
            end
        end
        MedianL2EUK( i , j , : ) =czesc_obrazu (odniesienie_x , odniesienie_y , : ); %obraz wynikowy
    end
end
czesc_obrazu =0; czesc_obrazu_double =0; odniesienie_x = 1; odniesienie_y = 1; %przygotowanie do dalszych zabiegow
for i =pol_maski_gora : Ix - pol_maski_dol
    for j =pol_maski_gora : Iy - pol_maski_dol
        czesc_obrazu =( I ( i - pol_maski_dol : i +pol_maski_dol , j - pol_maski_dol : j +pol_maski_dol , : )); %wziecie tylko czesci obrazu z maski do chwilowego przetworzenia
        czesc_obrazu_double = double ( czesc_obrazu ) /255; granica= inf;
        for ix = 1 : maska
            for iy = 1 :maska
                suma = 0 ; absolute = 0 ; %suma i absolutna
                for l = 1 : maska
                    for t = 1 :maska %wzor do MAN
                        absolute =[absolute abs(czesc_obrazu_double(ix,iy,1)-czesc_obrazu_double(l,t,1))+abs(czesc_obrazu_double(ix,iy,2)-czesc_obrazu_double(l,t,2))+abs(czesc_obrazu_double(ix,iy,3)-czesc_obrazu_double(l,t,3))];
                    end
                end
                suma = sum( absolute ( 1 , : ));
                if suma < granica
                    granica = suma; odniesienie_x = ix; odniesienie_y = iy; %przypisanie mniejszej sumy do aktualnej i odniesienia do parametru obrazu
                end
            end
        end
        MedianL1MAN(i,j,:) = czesc_obrazu(odniesienie_x,odniesienie_y, :); %obraz wynikowy
    end
end
%imshow (NowyMedEuk);
%figure
%imshow (NowyMedMan);
imwrite (MedianL1MAN, "C:\Users\Krzysztof\Desktop\3_1b_VMFL1_MAN.png");
%imwrite (MedianL2EUK, "C:\Users\Krzysztof\Desktop\3b_VMFL2_EUK.png");
%imwrite (MedianL1MAN(163 : 350, 163 : 350, :) , "C:\Users\Krzysztof\Desktop\3b_VMFL1_MAN_close.png");
%imwrite (MedianL2EUK(163 : 350, 163 : 350, :) , "C:\Users\Krzysztof\Desktop\3b_VMFL2_EUK_close.png");
psMAN=psnr (MedianL1MAN( pol_maski_gora : Ix - pol_maski_dol , pol_maski_gora : Iy - pol_maski_dol ) , Oryginal ( pol_maski_gora : Ix - pol_maski_dol , pol_maski_gora : Iy - pol_maski_dol ));
psEUK=psnr (MedianL2EUK( pol_maski_gora : Ix - pol_maski_dol , pol_maski_gora : Iy - pol_maski_dol ) , Oryginal ( pol_maski_gora : Ix - pol_maski_dol , pol_maski_gora : Iy - pol_maski_dol ));
disp(['PSNR L1 MAN: ' num2str(psMAN)]);
disp(['PSNR L2 EUK: ' num2str(psEUK)]);