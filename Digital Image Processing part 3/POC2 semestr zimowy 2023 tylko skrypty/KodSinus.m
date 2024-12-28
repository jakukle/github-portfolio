%Sinus
a = 10*[5 -1 2 -40]; %wybor parametrow
b = 3* [8 -12 1 -2]; %wybor parametrow
obraz_kolejnosc = 0; %inicjalizacja
for i=1:4 %petla dla 4 sinusow
    for u = 1:512 %petla for 512
        for v=1:512 %petla for 512
            obraz(u,v)=uint8(127+128*sin(u/a(i)+v/b(i))); 
            %konwersja na uint i obliczenie piksela z parametrow wejsciowych
        end
    end
    obraz_kolejnosc = obraz_kolejnosc + 1; %inkrementacja do wyswietlenia
    subplot(1,4,obraz_kolejnosc) %zlaczenie wyswietlania
    string1=strcat('a,b=',num2str(a(i)),',',num2str(b(i)));
    imshow(obraz,[]) %pokazanie obrazu na ekranie
    title(string1);
    if(obraz_kolejnosc==1)
        imwrite(obraz,'C:\Users\Krzysztof\Desktop\sin1.png'); %zapis obrazu
    end
    if(obraz_kolejnosc==2)
        imwrite(obraz,'C:\Users\Krzysztof\Desktop\sin2.png'); %zapis obrazu
    end
    if(obraz_kolejnosc==3)
        imwrite(obraz,'C:\Users\Krzysztof\Desktop\sin3.png'); %zapis obrazu
    end
    if(obraz_kolejnosc==4)
        imwrite(obraz,'C:\Users\Krzysztof\Desktop\sin4.png'); %zapis obrazu
    end
end