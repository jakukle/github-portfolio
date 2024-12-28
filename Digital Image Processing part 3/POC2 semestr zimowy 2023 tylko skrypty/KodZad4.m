clc
clear all %czyszczenie cmd Window
I=imread('C:\Users\Krzysztof\Desktop\woman_512x512.bmp'); %wczytanie pliku
Obraz = fftshift ( fft2 ( I ) ) ; %Przesuń składową o zerowej częstotliwości na środek widma - trans F
Skalar_AMP = 20* log(1+abs (Obraz) ) ;FAZ = angle (Obraz) ; %AMP i FAZ
promien1=10;promien2=40;maska1 = zeros (512 , 512 ) ; %zdefiniowanie promieni
for i = 1:512
    for j = 1:512 %512 wymiar obrazu
        if ( sqrt ( ( i-256 ).^ 2 + ( j-256).^2) <= promien1 ) %promien maly maski
            maska1 ( i , j ) = 1 ; %kolor bialy
        end
    end
end
maskaDolna1 = maska1 ;maskaGorna1 = 1-maska1 ;maska2 = zeros (512 , 512 );
for i = 1:512
    for j = 1:512
        if ( sqrt ( ( i-256 ).^ 2 + ( j-256).^2) <= promien2 ) %promien duzy maski
            maska2 ( i , j ) = 1 ; %kolor bialy
        end
    end
end
maskaDolna2 = maska2 ;maskaGorna2 = 1-maska2 ;
MD1 = Skalar_AMP.*maskaDolna1 ;MG1 = Skalar_AMP.* maskaGorna1 ;
MD2= Skalar_AMP.*maskaDolna2 ;MG2 = Skalar_AMP.*maskaGorna2 ;
imwrite(uint8(Skalar_AMP),'C:\Users\Krzysztof\Desktop\1.png'); %zapis do pliku
imwrite(maskaDolna1,'C:\Users\Krzysztof\Desktop\2.png'); %zapis do pliku
imwrite(maskaGorna1,'C:\Users\Krzysztof\Desktop\3.png'); %zapis do pliku
imwrite(maskaDolna2,'C:\Users\Krzysztof\Desktop\4.png'); %zapis do pliku
imwrite(maskaGorna2,'C:\Users\Krzysztof\Desktop\5.png'); %zapis do pliku
imwrite(uint8(MD1),'C:\Users\Krzysztof\Desktop\6.png'); %zapis do pliku
imwrite(uint8(MG1),'C:\Users\Krzysztof\Desktop\7.png'); %zapis do pliku
imwrite(uint8(MD2),'C:\Users\Krzysztof\Desktop\8.png'); %zapis do pliku
imwrite(uint8(MG2),'C:\Users\Krzysztof\Desktop\9.png'); %zapis do pliku
img = fftshift( fft2 ( I ) ) ; %Przesuń składową o zerowej częstotliwości na środek widma - trans F
%PARAMETRY
W1 = img.*maskaGorna1 ;
B1 = ifft2 ( ifftshift (W1) ) ;
%B11 = uint8 ( real (B1) ) ;
FiltrGorny1 = uint8(B1) ;
W2 = img.*maskaGorna2 ;
B2 = ifft2 ( ifftshift (W2) ) ;
%B22 = uint8 ( real (B2) ) ;
FiltrGorny2 = uint8(B2) ;
W3 = img.*maskaDolna1 ;B3 = ifft2 ( ifftshift (W3) ) ;FiltrDolny1 = uint8 (B3) ;
W4 = img.*maskaDolna2 ;B4 = ifft2 ( ifftshift (W4) ) ;FiltrDolny2 = uint8 (B4) ;
figure %pokazanie obrazow
imshow(FiltrDolny1);
figure %pokazanie obrazow
imshow(FiltrGorny1);
figure %pokazanie obrazow
imshow(FiltrDolny2);
figure %pokazanie obrazow
imshow(FiltrGorny2);
imwrite(uint8(FiltrDolny1),'C:\Users\Krzysztof\Desktop\10.png'); %zapis do pliku
imwrite(uint8(FiltrGorny1),'C:\Users\Krzysztof\Desktop\11.png'); %zapis do pliku
imwrite(uint8(FiltrDolny2),'C:\Users\Krzysztof\Desktop\12.png'); %zapis do pliku
imwrite(uint8(FiltrGorny2),'C:\Users\Krzysztof\Desktop\13.png'); %zapis do pliku