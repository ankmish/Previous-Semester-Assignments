tmp = imread('download.jpg');
A = rgb2gray(tmp);

[height,width]=size(A);
figure, imshow(A),title('Original Image');
B1=bitget(A,1); figure, imshow(logical(B1)),title('Bit plane 1');
B2=bitget(A,2); figure, imshow(logical(B2)),title('Bit plane 2');
B3=bitget(A,3); figure, imshow(logical(B3)),title('Bit plane 3');
B4=bitget(A,4); figure, imshow(logical(B4)),title('Bit plane 4');
B5=bitget(A,5); figure, imshow(logical(B5)),title('Bit plane 5');
B6=bitget(A,6); figure, imshow(logical(B6)),title('Bit plane 6');
B7=bitget(A,7); figure, imshow(logical(B7)),title('Bit plane 7');
B8=bitget(A,8); figure, imshow(logical(B8)),title('Bit plane 8');

BB = (2*(2*(2*(2*(2*(2*(2*B8+B7)+ B6) + B5) + B4) + B3) + B2) + B1);
figure, imshow(BB);title('Recombined Image from extracted planes');
