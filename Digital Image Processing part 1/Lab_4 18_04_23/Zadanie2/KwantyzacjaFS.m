clear
Obraz1=imread("C:\Users\Krzysztof\Desktop\POC4\color\lena_512x512.bmp");
[wiersze,kolumny,o]=size(Obraz1);
Red = double(Obraz1(:,:,1));
Green = double(Obraz1(:,:,2));
Blue = double(Obraz1(:,:,3));
r=8;g=8;b=8;
%%
for i=2:1:wiersze-1
    for j=2:1:kolumny-1
        Red_dodatkowy(i,j)=Red(i,j);
        Red(i,j)       =   floor((Red(i,j))/(256/r))*(256/r);
        Error(i,j)     =   Red_dodatkowy(i,j)-Red(i,j);
           Red(i,j+1)  =   Red(i,j+1)+double(round(7/16*Error(i,j)));
           Red(i+1,j+1)=   Red(i+1,j+1)+double(round(1/16*Error(i,j)));
           Red(i+1,j)  =   Red(i+1,j)+double(round(5/16*Error(i,j)));
           Red(i+1,j-1)=   Red(i+1,j-1)+double(round(3/16*Error(i,j)));
    end
end

for i=2:1:wiersze-1
    for j=2:1:kolumny-1
   Green_dodatkowy(i,j)  = Green(i,j);
              Green(i,j) = floor((Green(i,j))/(256/g))*(256/g);
             Error(i,j)  = Green_dodatkowy(i,j)-Green(i,j);
           Green(i,j+1)  = Green(i,j+1)+round(7/16*Error(i,j));
           Green(i+1,j+1)= Green(i+1,j+1)+round(1/16*Error(i,j));
           Green(i+1,j)  = Green(i+1,j)+round(5/16*Error(i,j));
           Green(i+1,j-1)= Green(i+1,j-1)+round(3/16*Error(i,j));

    end
end

for i=2:1:wiersze-1
    for j=2:1:kolumny-1
       Blue_dodatkowy(i,j)= Blue(i,j);
        Blue(i,j)         = floor((Blue(i,j))/(256/b))*(256/b);
        Error(i,j)        = Blue_dodatkowy(i,j)-Blue(i,j);
           Blue(i,j+1)    = Blue(i,j+1)+round(7/16*Error(i,j));
           Blue(i+1,j+1)  = Blue(i+1,j+1)+round(1/16*Error(i,j));
           Blue(i+1,j)    = Blue(i+1,j)+round(5/16*Error(i,j));
           Blue(i+1,j-1)  = Blue(i+1,j-1)+round(3/16*Error(i,j));

    end
end
Obraz1(:,:,1) = Red;
Obraz1(:,:,2) = Green;
Obraz1(:,:,3) = Blue;
Obraz_kwantyzacja = Obraz1;
imwrite(Obraz_kwantyzacja,"C:\Users\Krzysztof\Desktop\lena256FS.png")




