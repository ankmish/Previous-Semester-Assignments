x = imread('download.jpg');
x = rgb2gray(x);
[r,c] = size(x);
m = zeros(2*r,2*c,'uint8');
for i=1:r
    for j=1:c
        m(2*i-1,2*j-1) = x(i,j);
        m(2*i,2*j) = x(i,j);
        m(2*i-1,2*j) = x(i,j);
        m(2*i,2*j-1) = x(i,j);
    end
end
figure,imshow(m),title('Pixel Replication method for zooming');