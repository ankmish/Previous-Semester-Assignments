xx = imread('im.jpg');
xx = rgb2gray(xx);
[r c]=size(xx);
con = input('Enter the constant factor c = ');
xx = im2double(xx);
output = con.*log(1+xx)*256;  % add 1 to avoid log(0)   % .* to perform element wise multiplication in array
output= uint8(output);
subplot(1,2,1),imshow(xx),title('Original Image');
subplot(1,2,2),imshow(output),title('Log transform');     