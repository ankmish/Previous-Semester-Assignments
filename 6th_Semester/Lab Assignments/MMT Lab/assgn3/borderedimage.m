Img = imread('download.jpg'); 
temp = imread('download.jpg');
b=temp;
[m,n,colormap]=size(b);

%If RGB Image is given at Input 
if colormap==3
x=b(:,:,1);
y=b(:,:,2);
z=b(:,:,3);
end

mat = zeros(m+40,n+40,3,'uint8');  % 3-D matrix

for i=1:(m+20)
    for j=1:20
        mat(i,j,1) = 0;
        mat(i,j,2) = 0;
        mat(i,j,3) = 0;
    end
end
for i=1:20
    for j=1:n+20
        mat(i,j,1) = 0;
        mat(i,j,2) = 0;
        mat(i,j,3) = 0;
    end
end
for i=m+20:-1:m          %see
    for j=1:n+20
        mat(i,j,1) = 0;
        mat(i,j,2) = 0;
        mat(i,j,3) = 0;
    end
end
for i=1:m+20
    for j=n:n+20
        mat(i,j,1) = 0;
        mat(i,j,2) = 0;
        mat(i,j,3) = 0;
    end
end

for i=1:m
    for j=1:n
        mat(i+20,j+20,1) = x(i,j);
        mat(i+20,j+20,2) = y(i,j);
        mat(i+20,j+20,3) = z(i,j);
    end
end

imshow(mat),title('Border around image');

        
        