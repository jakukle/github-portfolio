Obraz = imread("C:\Users\Krzysztof\Desktop\1_1a_VMFL1_MAN.png");
%Obraz2 = imcrop(Obraz,[263 263 80 80]);
%Obraz2 = imresize(Obraz2, [512 512]);
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\przyciety1.png')

Obraz = imread("C:\Users\Krzysztof\Desktop\2_1a_VMFL1_MAN.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\przyciety2.png')

Obraz = imread("C:\Users\Krzysztof\Desktop\3_1a_VMFL1_MAN.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\przyciety3.png')

Obraz = imread("C:\Users\Krzysztof\Desktop\1_1b_VMFL1_MAN.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\przyciety4.png')

Obraz = imread("C:\Users\Krzysztof\Desktop\2_1b_VMFL1_MAN.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\przyciety5.png')

Obraz = imread("C:\Users\Krzysztof\Desktop\3_1b_VMFL1_MAN.png");
Obraz2 = imcrop(Obraz,[163 163 187 187]);
imwrite(Obraz2,'C:\Users\Krzysztof\Desktop\przyciety6.png')
