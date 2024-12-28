I=imread('C:\Users\Krzysztof\Desktop\POC2\Bayer\CFA_sRGB\IMG_009_srgb_CFA.png'); %sczytanie obrazu
[Nx,Ny] = size(I); %szerokość i wysokość obrazu zapisana do wektora
Sasiad=zeros(Nx, Ny, 3,'uint8');%Sasiad jest macierzą wypełnioną zerami Nx x Ny x 3 o typie danych 8-bit unsigned integer
for x=1:2:Nx %pętla co 2 elementy obrazu na szerokość
        for y=1:2:Ny %pętla co 2 elementy obrazu na wysokość
            %Nakladamy RGB na element Blue
            Sasiad(x, y, 1)=I(x+1,y+1);   %przypisawanie odpowiedniego elementu do naszego Sasiada
            Sasiad(x, y, 2)=I(x,y+1);     %Algorytm działa w następujący sposób
            Sasiad(x, y ,3)=I(x,y);       % 1 Ustaw wybrany wierzchołek jako aktualny, oznacz go jako odwiedzony
            %Nakladamy RGB na element Green
            Sasiad(x, y+1, 1)=I(x+1,y+1); % 2 Znajdź ten spośród nieodwiedzonych wierzchołków, który jest połączony z aktualnym krawędzią o najmniejszej wadze
            Sasiad(x, y+1, 2)=I(x,y+1);   % 3 Dołącz do rozwiązania krawędź łączącą aktualny wierzchołek z wierzchołkiem znalezionym w punkcie 2
            Sasiad(x, y+1, 3)=I(x,y);     % 4 Oznacz wierzchołek znaleziony w punkcie 2 jako odwiedzony i ustaw go jako aktualny
            %Nakladamy RGB na element Green        
            Sasiad(x+1 ,y, 1)=I(x+1,y+1); % 5 Jeśli pozostały jeszcze nieodwiedzone wierzchołki, przejdź do punktu 2.
            Sasiad(x+1, y, 2)=I(x,y+1);   % 6 Dołącz do rozwiązania krawędź łączącą aktualny wierzchołek z wierzchołkiem wybranym w punkcie 1, aby zamknąć cykl
            Sasiad(x+1, y, 3)=I(x,y); 
            %Nakladamy RGB na element Red
            Sasiad(x+1 ,y+1 ,1)=I(x+1,y+1);
            Sasiad(x+1, y+1 ,2)=I(x,y+1); 
            Sasiad(x+1, y+1, 3)=I(x,y);
        end
end
imwrite(Sasiad,'C:\Users\Krzysztof\Desktop\zad2b.png');%stworzenie nowego obrazu (Sasiad)
