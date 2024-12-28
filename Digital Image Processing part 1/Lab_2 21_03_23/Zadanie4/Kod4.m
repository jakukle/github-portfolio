I = imread('C:\Users\Krzysztof\Desktop\POC2\Bayer\CFA_sRGB\IMG_009_srgb_CFA.png');
[Nx, Ny] = size(I); 
%RGB
R = zeros(Nx,Ny); 
G = zeros(Nx,Ny);
B = zeros(Nx,Ny);
%interpolacja biszescienna
for j = 1:1:Nx  %zaczynamy od pierwszych elementow
    for i = 1:1:Ny   
        if(mod(j,2) == 1 && mod(i,2) == 1)   %jesli mamy nieparzyst wiersz albo kolumne
            R(j,i) = I(j,i);     
        end
        if(mod(j,2) == 0 && mod(i,2) == 0)   %
            B(j,i) = I(j,i);     
        end
        if(mod(j,2) == 1 && mod(i,2) == 0 || mod(j,2) == 0 && mod(i,2) == 1)
            G(j,i) = I(j,i);    
        end
    end
end
 
for j = 1:1:Nx   
    for i = 2:1:Ny-1   
        if(mod(j,2) == 1 && mod(i,2) == 0)            
            R(j,i) = (R(j,i-1) + R(j,i+1))/2;  
        end
        if(mod(j,2) == 0 && mod(i,2) == 1)   
            B(j,i) = (B(j,i-1) + B(j,i+1))/2; 
        end
    end
end
 
for j = 2:1:Nx-1  
    for i = 2:1:Ny-1 
        if(mod(j,2) == 0)   
            R(j,i) = (R(j-1,i-1)+R(j-1,i+1)+R(j+1,i-1)+R(j+1,i+1))/8;%uśrednianie 3x3
        end
        if((mod(j,2) == 1) )  
            B(j,i) = (B(j-1,i-1)+B(j-1,i+1)+B(j+1,i-1)+B(j+1,i+1))/8;%uśrednianie 3x3
        end
        if((mod(j,2) == 0 && mod(i,2) == 0) || (mod(j,2) == 1 && mod(i,2) == 1))      
            G(j,i) = (G(j,i-1)+G(j,i+1)+G(j+1,i)+G(j-1,i))/8;  %uśrednianie 3x3
        end
    end
end
R = uint8(R); %konwersja
G = uint8(G); %konwersja
B = uint8(B); %konwersja
ImBi6 = cat(3,B,G,R); %złożenie kanałów RGB
imwrite(ImBi6,'C:\Users\Krzysztof\Desktop\zad4b.png');
