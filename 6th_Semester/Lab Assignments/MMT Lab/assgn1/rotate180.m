x = imread('download.jpg');
x = rgb2gray(x);
[r,c] = size(x);
m = zeros(r, c, 'uint8');
for i=1:r
    for j=1:c
        m(i, j) = x(r-i+1, c-j+1);
    end
end
imshow(m),title('180degree');
        