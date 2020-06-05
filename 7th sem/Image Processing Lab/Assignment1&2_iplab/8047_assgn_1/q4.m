xx = imread('im.jpg');
xx = rgb2gray(xx);
[r c]=size(xx);
con = input('Enter the constant factor c = ');
gamma = input('Enter the gamma correction gamma = ');
xx = im2double(xx);
for i=1:r
    for j=1:c
        output(i,j) = con * xx(i, j).^ gamma * 256;
    end
end
output= uint8(output);
subplot(1,2,1),imshow(xx),title('Original Image');
subplot(1,2,2),imshow(output),title('Power transform');     