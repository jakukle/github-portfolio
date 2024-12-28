clc %czyszczenie ekranu z Command Window
I = imread('C:\Users\Krzysztof\Desktop\POC3\Bayer\GT_sRGB\IMG_009_srgb.png'); %otwarcie pliku po sciezce
ImageHSV = rgb2hsv( I ) ; %konwersja RGB na HSV
X = size ( I , 1 ) ; %zwraca nam liczbe wierszy naszego obrazu
Y = size ( I , 2 ) ; %zwraca nam liczbe kolumn naszego obrazu
MacierzHSV = zeros ( 3601 , 301 , 301 ) ; %macierz wypelniona zerami 3601 x 301 x 301
LiczbaBarw = 0; %na poczatku nasza liczba barw unikalnych jest równa 0
tic ; %funckja tic rejestruje bieżący czas, współpracuje z funkcją toc która oblicza czas jaki upłynął
for i = 1:X %algorytm HSV - od 1 do liczby wierszy
    for j = 1:Y %od 1 do liczby kolumn
     H=round(ImageHSV( i , j ,1)*3600)+1; %hue - Wartość od 0 do 1, która odpowiada pozycji koloru na kole kolorów. 
     %Gdy odcień wzrasta od 0 do 1, kolor przechodzi od czerwonego do pomarańczowego, żółtego, zielonego, cyjanowego, 
     %niebieskiego, karmazynowego i na końcu z powrotem do czerwonego.
     S=round(ImageHSV( i , j ,2)*300)+1;  %saturation - Ilość odcienia lub odejście od neutralnego. 
     %0 oznacza neutralny odcień, a 1 maksymalne nasycenie.
     V=round(ImageHSV( i , j ,3)*300)+1;  %value - Maksymalna wartość spośród składowych czerwonego, zielonego 
     %i niebieskiego określonego koloru.
        if MacierzHSV (H,S,V) == 0    %jeśli taka kombinacja kolorów już wystąpiła do tego elementu macierzy Macierz zostanie przypisane 1
        MacierzHSV(H,S,V) = 1 ;       %i wtedy do tego warunku już nie wejdziemy z tym samym kolorem
        LiczbaBarw = LiczbaBarw + 1;  %a jesli weszlismy oznacza to ze taki kolor jeszcze nie wystąpił i LiczbaBarw jest inkrementowana
        end
    end
end
Czas = toc ; %przypisanie upłyniętego czasu do zmiennej Czas
ImageRGB = hsv2rgb(ImageHSV); %konwersja powrotna HSV na RGB 
imwrite(ImageHSV,'C:\Users\Krzysztof\Desktop\HSVtest.png');
imwrite(ImageRGB,'C:\Users\Krzysztof\Desktop\RGBtest.png');
LiczbaBarw %wyświetlenie liczby barw unikalnych w obrazie
Czas %wyświetlenie czasu jaki upłynął
