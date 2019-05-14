I = imread('download.jpg'); 
temp = imread('download.jpg');
b=temp;
[m,n,colormap]=size(b);

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

% zoom out
tmp = zeros(m,n,3,'uint8');
a = 1;
b = 1;
for i = 1:2:2*m            % see
    for j = 1:2:2*n
        tmp(a,b,1) = new_mat(i,j,1);
        tmp(a,b,2) = new_mat(i,j,2);
        tmp(a,b,3) = new_mat(i,j,3);
        b = b + 1;
    end
    b = 1;
    a = a + 1;
end

imshow(tmp),title('zoom out image');
    
        
