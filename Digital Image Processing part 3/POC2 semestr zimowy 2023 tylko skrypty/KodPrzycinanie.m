Obraz = imread("C:\Users\Krzysztof\Desktop\Maska10.png");
Obraz2 = imcrop(Obraz,[92 33 511 511]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\Maska10.png');