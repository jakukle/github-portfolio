clc
clear all %czyszczenie cmd window
Obraz_szum = imread ("C:\Users\Krzysztof\Desktop\O2b.png"); %wczytanie obrazu z szumem
Oryginal = imread ("C:\Users\Krzysztof\Desktop\gold_512x512.png"); %wczytanie oryginalu
[Ix, Iy, Iz] = size(Obraz_szum); %zczytanie wymiaru obrazu - tym razem 3-wymiarowego
R = double(Obraz_szum( : , : , 1))/255; %rzutowanie na double
G = double(Obraz_szum( : , : , 2 ))/255; B = double (Obraz_szum( : , : , 3 )) /255;
maska = input ( "podaj maske " ); %wymiary maski
pol_MaskiG = ceil (maska/2); pol_MaskiD = floor (maska/2); %pol maski w gore i pol maski w dol
for i = pol_MaskiG : Ix - pol_MaskiD
    for j = pol_MaskiG : Iy - pol_MaskiD
        czesc_obrazu = double ( R ( i - pol_MaskiD : i + pol_MaskiD , j - pol_MaskiD : j +pol_MaskiD )); %tylko czesc obrazu oraz R
        czesc_obrazu = reshape(czesc_obrazu , 1 , []); %nadanie tablicy kształtu jedno-wymiarowego
        czesc_obrazu = sort(czesc_obrazu); %porządkowanie elementów tablicy
        liczba_maska_gora = ceil (maska*maska/2); %zaleznosc indeksow od maski
        Rwynik(i , j) = czesc_obrazu (liczba_maska_gora); %przypisanie wyniku barwy R z danej czesci obrazu to danego elementu
    end
end
for i = pol_MaskiG : Ix - pol_MaskiD
    for j = pol_MaskiG : Iy - pol_MaskiD
        czesc_obrazu = double ( G ( i - pol_MaskiD : i +pol_MaskiD , j - pol_MaskiD : j +pol_MaskiD));
        czesc_obrazu = reshape (czesc_obrazu , 1 , [] ); czesc_obrazu = sort (czesc_obrazu) ;
        liczba_maska_gora = ceil (maska*maska/2); Gwynik(i , j) = czesc_obrazu (liczba_maska_gora);
    end
end
for i = pol_MaskiG : Ix - pol_MaskiD
    for j =pol_MaskiG : Iy - pol_MaskiD
        czesc_obrazu = double ( B ( i - pol_MaskiD : i +pol_MaskiD , j - pol_MaskiD : j +pol_MaskiD ) ) ;
        czesc_obrazu = reshape (czesc_obrazu , 1 , []); czesc_obrazu = sort (czesc_obrazu);
        liczba_maska_gora = ceil (maska*maska/2); Bwynik(i , j) =czesc_obrazu(liczba_maska_gora);
    end
end
Obraz_ostateczny = cat (3 , Rwynik , Gwynik , Bwynik) ; Obraz_ostateczny = im2uint8 (Obraz_ostateczny); %łączenie i rzutowanie
ps=psnr (Obraz_ostateczny ( pol_MaskiG : Ix - pol_MaskiD , pol_MaskiG : Iy - pol_MaskiD ) , Oryginal ( pol_MaskiG : Ix - pol_MaskiD , pol_MaskiG : Iy - pol_MaskiD ) ) ;
imwrite (Obraz_ostateczny , "C:\Users\Krzysztof\Desktop\Mediana2b.png");
%imwrite (Obraz_osteteczny (163 :350 ,163 :350 , :) , "C:\Users\Krzysztof\Desktop\Mediana2a_close.png" );
disp(['PSNR: ' num2str(ps)]);