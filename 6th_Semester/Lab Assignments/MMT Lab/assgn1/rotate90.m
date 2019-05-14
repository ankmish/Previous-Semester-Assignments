x = imread('download.jpg');
x = rgb2gray(x);
[r,c] = size(x);
m = zeros(c, r, 'uint8');
for i=1:r
    for j=1:c
        m(j, i) = x(r-i+1, j);
    end
end
imshow(m),title('90degree');
        

