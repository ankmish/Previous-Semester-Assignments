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

mm = m/2;
nn = n/2;


m1 = zeros(mm,nn,3,'uint8');
m2 = zeros(mm,nn,3,'uint8');
m3 = zeros(mm,nn,3,'uint8');
m4 = zeros(mm,nn,3,'uint8');

for i = 1:mm
    for j = 1:nn
        m1(i,j,1) = x(i,j);
        m1(i,j,2)= y(i,j);
        m1(i,j,3) = z(i,j);
    end
end


for i = mm+1:m
    for j = 1:nn
        m2(i-mm,j,1) = x(i,j);
        m2(i-mm,j,2)= y(i,j);
        m2(i-mm,j,3) = z(i,j);
    end
end

for i = 1:mm
    for j = nn+1:n
        m3(i,j-nn,1) = x(i,j);
        m3(i,j-nn,2)= y(i,j);
        m3(i,j-nn,3) = z(i,j);
    end
end
for i = mm+1:m
    for j = nn+1:n
        m4(i-mm,j-nn,1) = x(i,j);
        m4(i-mm,j-nn,2)= y(i,j);
        m4(i-mm,j-nn,3) = z(i,j);
    end
end
figure,title('Image in 4 parts');
subplot(2,2,1), imshow(m1);
subplot(2,2,2), imshow(m3);
subplot(2,2,3), imshow(m2);
subplot(2,2,4), imshow(m4);
