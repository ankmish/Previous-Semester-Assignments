x = imread('download.jpg');
x = rgb2gray(x);
[r,c] = size(x);
new = zeros(c,r,'uint8');
for i=1:r
    for j=1:c
        new(j,i) = x(r-i+1,j);
    end
end
figure,imshow(new),title('90 degree rotate');