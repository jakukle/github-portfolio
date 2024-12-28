clc;
clear all; %czyszczenie cmd window
Obraz = imread("C:\Users\Krzysztof\Desktop\boats_512x512.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\O1.png');

Obraz = imread("C:\Users\Krzysztof\Desktop\O1a.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\O1_1.png');

Obraz = imread("C:\Users\Krzysztof\Desktop\O2a.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\O1_2.png');

Obraz = imread("C:\Users\Krzysztof\Desktop\O3a.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\O1_10.png');

Obraz = imread("C:\Users\Krzysztof\Desktop\gold_512x512.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\O2.png');

Obraz = imread("C:\Users\Krzysztof\Desktop\O1b.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\O2_1.png');

Obraz = imread("C:\Users\Krzysztof\Desktop\O2b.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\O2_2.png');

Obraz = imread("C:\Users\Krzysztof\Desktop\O3b.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\O2_10.png');