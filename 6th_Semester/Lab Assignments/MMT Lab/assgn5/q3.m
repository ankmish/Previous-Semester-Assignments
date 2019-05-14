I = imread('download.jpg'); 
temp = imread('download.jpg');
b=temp;
tt = I;
[m,n,colormap]=size(b);
%imshow(I);
%If RGB Image is given at Input 
if colormap==3
x=b(:,:,1);
y=b(:,:,2);
z=b(:,:,3);
end
new_mat=zeros(m*2,n*2,3,'uint8');
a = 1;
b = 1;
c = 0;
for i=1:m
    for j=1:n
        new_mat(a,b,1) =  x(i,j);
        new_mat(a,b+1,1) =x(i,j);
        new_mat(a+1,b,1) =x(i,j);
        new_mat(a+1,b+1,1) =x(i,j);
 
        new_mat(a,b,2) =  y(i,j);
        new_mat(a,b+1,2) =y(i,j);
        new_mat(a+1,b,2) = y(i,j);
        new_mat(a+1,b+1,2) =y(i,j);
        
        new_mat(a,b,3) =  z(i,j);
        new_mat(a,b+1,3) =z(i,j);
        new_mat(a+1,b,3) = z(i,j);
        new_mat(a+1,b+1,3) = z(i,j);
        
        b = b + 2;
    end
    b = 1;
    a = a + 2;
end
%imshow(new_mat);
% brightness
II = brightness(tt);  
figure,imshow(tt),title('original Image');
figure,imshow(II),title('Brighter Image');
