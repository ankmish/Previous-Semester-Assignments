x = imread('download.jpg');
x = rgb2gray(x);
[r,c] = size(x);
m = zeros(2*r-1,2*c-1,'uint16');
x = uint16(x);
for i=1:r
    for j=1:c
        m(2*i-1,2*j-1) = x(i,j);
        if (j~=c)
        m(2*i-1,2*j) = (x(i,j)+x(i,j+1))/2;
        end
        if (i~=r)
        m(2*i,2*j-1) = (x(i,j)+x(i+1,j))/2;
        end
        if (i~=r && j~=c)
        m(2*i,2*j) = (x(i,j+1)+x(i+1,j))/2;
        end
    end
end
n = uint8(m);
figure,imshow(n),title('zero order hold method for zooming');