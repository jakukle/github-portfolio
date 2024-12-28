clear all
clc
obraz = imread("3.jpg");
Obraz_binarny = im2bw(obraz, 0.5); %binaryzacja z progiem 127
[Obraz_Label, liczbaKostek]=bwlabel(Obraz_binarny);
Centrum_obszaru = regionprops(Obraz_binarny, 'Centroid'); %funkcja z lab4 POC - zwraca srodki z obszarow spojnych
figure; imshow(obraz); hold on; %przytrzymuje obraz i na nim dziala
for i = 1:numel(Centrum_obszaru) %liczy obszary czyli petla leci do 6 dla 6 kostek
    srodek_ciezkosci = Centrum_obszaru(i).Centroid; %zmienna w petli
    plot(srodek_ciezkosci(1), srodek_ciezkosci(2), 'go', 'MarkerSize', 130, 'LineWidth', 2); % Zielony okrag zakresla obraz
end
hold off; %konczy przytrzymanie obrazu