x=imread('im.jpg');
%J = imcomplement(x)
xx = imread('im.jpg');
xx = rgb2gray(xx);
[r c]=size(xx);
output=zeros(r,c,3,'uint8');
for i=1:r
    for j=1:c
        output(i,j,1) = 255 - x(i,j,1);
        output(i,j,2) = 255 - x(i,j,2);
        output(i,j,3) = 255 - x(i,j,3);
    end
end
subplot(1,2,1),imshow(x),title('original image');
subplot(1,2,2),imshow(output),title('negative of image');
