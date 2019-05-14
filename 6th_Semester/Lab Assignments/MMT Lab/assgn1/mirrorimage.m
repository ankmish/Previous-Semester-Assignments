x = imread('download.jpg');
x = rgb2gray(x);
[r,c] = size(x);
m = zeros(r, c, 'uint8');
for i=1:r
    for j=1:c
        m(i, j) = x(i, c-j+1);
    end
end
imshow(x),title('Original Image');
imshow(m),title('mirror image');
        

