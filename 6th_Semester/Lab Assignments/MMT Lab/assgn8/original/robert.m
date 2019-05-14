a=imread('apple.jpg');
a = rgb2gray(a);
b=im2double(a);
[m,n]=size(a);

L(1:m,1:n)=0;
for i=1:m-1
    for j=1:n-1
        L(i,j)=1*b(i,j)+0+0-1*b(i+1,j+1);
    end
end

M(1:m,1:n)=0;
for i=1:m-1
    for j=1:n-1
        M(i,j)=0-1*b(i,j+1)+1*b(i+1,j)+0;
    end
end
N(1:m,1:n)=0;
for i=1:m
    for j=1:n
        N(i,j) = M(i,j) + L(i,j);
    end
end

figure,subplot(2,2,1),imshow(L),title('Robert    Gx');
subplot(2,2,2),imshow(M),title('Robert    Gy');
subplot(2,2,3),imshow(N),title('Robert    Gx+Gy');
subplot(2,2,4),imshow(b),title('Original Image');