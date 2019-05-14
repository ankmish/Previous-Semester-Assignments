x = imread('download.jpg');
x = rgb2gray(x);
[r,c] = size(x);
m = zeros(4*(r-1), 4*(c-1),'uint16');
n = zeros(r,4*(c-1), 'uint16');

x = uint16(x);
for i=1:r
    for j=1:c-1
        op = (x(i,j+1)-x(i,j))/4;
        n(i,4*j) = x(i,j);
        n(i,4*j+1) = n(i,4*j) + op;
        n(i,4*j+2) = n(i,4*j+1) + op;
        n(i,4*j+3) = n(i,4*j+2) + op;
    end
end

for i=1:r-1
    for j=1:4*(c-1)
        op = (n(i+1,j) - n(i,j))/4;
        m(4*i,j) = n(i,j);
        m(4*i+1,j) = m(4*i,j) + op;
        m(4*i+2,j) = m(4*i+1,j) + op;
        m(4*i+3, j) = m(4*i+2,j) + op;
    end
end

m = uint8(m);
figure,imshow(m),title('k times zoom method');