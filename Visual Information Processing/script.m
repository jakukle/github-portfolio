clc;
clear all;
%% Wczytywane obrazy
k=0;
if k==0
    I11=imread('C:\Users\DELL\Desktop\obrazy_testowe\O1.png');
    I12=imread('C:\Users\DELL\Desktop\obrazy_testowe\O2.png');
end
if k==1
    I11=imread('C:\Users\DELL\Desktop\obrazy_testowe\O3.jpg');
    I12=imread('C:\Users\DELL\Desktop\obrazy_testowe\O4.jpg');
end
if k==2
    I12=imread('C:\Users\DELL\Desktop\obrazy_testowe\O5.jpg');
    I11=imread('C:\Users\DELL\Desktop\obrazy_testowe\O6.png');
end
if k==3
    I11=imread('C:\Users\DELL\Desktop\obrazy_testowe\O7.bmp');
    I12=imread('C:\Users\DELL\Desktop\obrazy_testowe\O8.jpg');
end
if k==4
    I11=imread('C:\Users\DELL\Desktop\obrazy_testowe\O3.jpg');
    I12=imread('C:\Users\DELL\Desktop\obrazy_testowe\O9.png');
end
if k==5
    I11=imread('C:\Users\DELL\Desktop\obrazy_testowe\O3.jpg');
    I12=imread('C:\Users\DELL\Desktop\obrazy_testowe\O10.jpg');
end
if k==6
    I11=imread('C:\Users\DELL\Desktop\obrazy_testowe\O1.png');
    I12=imread('C:\Users\DELL\Desktop\obrazy_testowe\O11.jpg');
end
if k==7
    I11=imread('C:\Users\DELL\Desktop\obrazy_testowe\O5.jpg');
    I12=imread('C:\Users\DELL\Desktop\obrazy_testowe\O10.jpg');
end
I1=im2double(I11);
I2=im2double(I12);
rozmiar1 = size ( I1 , 1 );
rozmiar2 = size ( I2 , 1 );
rozmiar3 = size ( I1 , 2 );
rozmiar4 = size ( I2 , 2 );
%% Zmienne pomocnicze
lsuma1=0;
asuma1=0;
bsuma1=0;
lsuma2=0;
asuma2=0;
bsuma2=0;
licznik1=0;
licznik2=0;
lwar1=0;
awar1=0;
bwar1=0;
lwar2=0;
awar2=0;
bwar2=0;
licznikA=0;
licznikB=0;
licznikC=0;
%% Obraz 1
for i=1:rozmiar1
    for j=1:rozmiar3
             R1(i,j)=I1(i,j,1);
             G1(i,j)=I1(i,j,2);
             B1(i,j)=I1(i,j,3);
             A1=[R1(i,j);G1(i,j);B1(i,j)];
             LMS11=[0.3811,0.5783,0.0402;0.1967,0.7244,0.0782;0.0241,0.1288,0.8444]*A1;
             LMS1=log10(LMS11);
             if LMS1(1)==-inf
                 LMS1(1)=0;
                 licznikA=licznikA+1;
             end
             if LMS1(2)==-inf
                 LMS1(2)=0;
                 licznikB=licznikB+1;
             end
             if LMS1(3)==-inf
                 LMS1(3)=0;
                 licznikC=licznikC+1;
             end
             L1(i,j)=LMS1(1);
             M1(i,j)=LMS1(2);
             S1(i,j)=LMS1(3);
             lab1=[1/sqrt(3),0,0;0,1/sqrt(6),0;0,0,1/sqrt(2)]*[1,1,1;1,1,-2;1,-1,0]*LMS1;
             l1(i,j)=lab1(1);
             a1(i,j)=lab1(2);
             b1(i,j)=lab1(3);
             lsuma1=lsuma1+l1(i,j);
             asuma1=asuma1+a1(i,j);
             bsuma1=bsuma1+b1(i,j);
             licznik1=licznik1+1;
    end
end
%% Obraz 2
for i=1:rozmiar2
    for j=1:rozmiar4
             R2(i,j)=I2(i,j,1);
             G2(i,j)=I2(i,j,2);
             B2(i,j)=I2(i,j,3);
             A2=[R2(i,j);G2(i,j);B2(i,j)];
             LMS22=[0.3811,0.5783,0.0402;0.1967,0.7244,0.0782;0.0241,0.1288,0.8444]*A2;
             LMS2=log10(LMS22);
             if LMS2(1)==-inf
                 LMS2(1)=0;
             end
             if LMS2(2)==-inf
                 LMS2(2)=0;
             end
             if LMS2(3)==-inf
                 LMS2(3)=0;
             end
             L2(i,j)=LMS2(1);
             M2(i,j)=LMS2(2);
             S2(i,j)=LMS2(3);
             lab2=[1/sqrt(3),0,0;0,1/sqrt(6),0;0,0,1/sqrt(2)]*[1,1,1;1,1,-2;1,-1,0]*LMS2;
             l2(i,j)=lab2(1);
             a2(i,j)=lab2(2);
             b2(i,j)=lab2(3);
             lsuma2=lsuma2+l2(i,j);
             asuma2=asuma2+a2(i,j);
             bsuma2=bsuma2+b2(i,j);
             licznik2=licznik2+1;
    end
end
%% Średnia i wariancja
for i=1:rozmiar1
    for j=1:rozmiar3
        lsr1(i,j)=l1(i,j)-lsuma1/licznik1;
        asr1(i,j)=a1(i,j)-asuma1/licznik1;
        bsr1(i,j)=b1(i,j)-bsuma1/licznik1;
        lwar1=lwar1+(l1(i,j)-lsuma1/licznik1)^2;
        awar1=awar1+(a1(i,j)-asuma1/licznik1)^2;
        bwar1=bwar1+(b1(i,j)-bsuma1/licznik1)^2;
    end
end
for i=1:rozmiar2
    for j=1:rozmiar4
        lsr2(i,j)=l2(i,j)-lsuma2/licznik2;
        asr2(i,j)=a2(i,j)-asuma2/licznik2;
        bsr2(i,j)=b2(i,j)-bsuma2/licznik2;
        lwar2=lwar2+(l2(i,j)-lsuma2/licznik2)^2;
        awar2=awar2+(a2(i,j)-asuma2/licznik2)^2;
        bwar2=bwar2+(b2(i,j)-bsuma2/licznik2)^2;
    end
end
%% Odchylenie
lodch1=sqrt(lwar1/licznik1);
aodch1=sqrt(awar1/licznik1);
bodch1=sqrt(bwar1/licznik1);
lodch2=sqrt(lwar2/licznik2);
aodch2=sqrt(awar2/licznik2);
bodch2=sqrt(bwar2/licznik2);
%% Przekształcenia w przestrzeni lab
for i=1:rozmiar1
    for j=1:rozmiar3
        lprim(i,j)=lodch2/lodch1*lsr1(i,j)+lsuma2/licznik2;
        aprim(i,j)=aodch2/aodch1*asr1(i,j)+asuma2/licznik2;
        bprim(i,j)=bodch2/bodch1*bsr1(i,j)+bsuma2/licznik2;
        %% Powrót obrazu 1
             LAB=[lprim(i,j);aprim(i,j);bprim(i,j)];
             newLMS11=[1,1,1;1,1,-1;1,-2,0]*[sqrt(3)/3,0,0;0,sqrt(6)/6,0;0,0,sqrt(2)/2]*LAB;
             newLMS1=10.^(newLMS11);
             if newLMS1(1)==1
                 newLMS1(1)=0;
             end
             if newLMS1(2)==1
                 newLMS1(2)=0;
             end
             if newLMS1(3)==1
                 newLMS1(3)=0;
             end
             newL1(i,j)=newLMS1(1);
             newM1(i,j)=newLMS1(2);
             newS1(i,j)=newLMS1(3);
             newRGB1=[4.4679,-3.5873,0.1193;-1.2186,2.3809,-0.1624;0.0497,-0.2439,1.2045]*newLMS1;
             newR1(i,j)=newRGB1(1);
             newG1(i,j)=newRGB1(2);
             newB1(i,j)=newRGB1(3);
    end
end
%% Scalenie i pokazanie obrazu
Iq = cat (3,R1,G1,B1);
Iq2 = cat (3,R2,G2,B2);
Iq3 = cat (3,newR1,newG1,newB1);
figure
imshow(Iq);
figure
imshow(Iq2);
figure
imshow(Iq3);