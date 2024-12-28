clc %czyszczenie ekranu z Command Window
I = imread('C:\Users\Krzysztof\Desktop\POC3\Bayer\GT_sRGB\IMG_009_srgb.png'); %otwarcie pliku po sciezce
I = uint16 ( I ) ; %od 9 do 16 bitow na piksel - PNG 16 - na 16 bitach aby moglo byc 256
X = size ( I , 1 ) ; %zwraca nam liczbe wierszy naszego obrazu
Y = size ( I , 2 ) ; %zwraca nam liczbe kolumn naszego obrazu
Macierz = zeros ( 256 , 256 , 256 ) ; %macierz wypelniona zerami 256 x 256 x 256
LiczbaBarw = 0; %na poczatku nasza liczba barw unikalnych jest równa 0
tic ; %funckja tic rejestruje bieżący czas, współpracuje z funkcją toc która oblicza czas jaki upłynął
for i = 1:X %algorytm RGB - od 1 do liczby wierszy
    for j = 1:Y %od 1 do liczby kolumn
    Red = I( i , j , 1) + 1; %czerwony dla pierwszego poziomu - przypisuje tutaj pewną ilość barwy powiększoną o 1 w celu zgodności wymiarów
    Green = I( i , j , 2 ) + 1; %zielony dla drugiego poziomu
    Blue = I( i , j , 3) + 1; %niebieski dla trzeciego poziomu - na pewno w moim przypadku tu jest to + 1 potrzebne
        if Macierz(Red,Green,Blue) == 0 %jeśli taka kombinacja kolorów już wystąpiła do tego elementu macierzy Macierz zostanie przypisane 1
        Macierz(Red,Green,Blue) = 1 ;   %i wtedy do tego warunku już nie wejdziemy z tym samym kolorem
        LiczbaBarw = LiczbaBarw + 1;    %a jesli weszlismy oznacza to ze taki kolor jeszcze nie wystąpił i LiczbaBarw jest inkrementowana
        end
    end
end
Czas = toc ; %przypisanie upłyniętego czasu do zmiennej Czas
LiczbaBarw %wyświetlenie liczby barw unikalnych w obrazie
Czas  %wyświetlenie czasu jaki upłynął
