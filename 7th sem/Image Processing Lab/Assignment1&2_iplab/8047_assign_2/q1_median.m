Img = imread('im.jpg'); 
temp = imread('im.jpg');
temp = imnoise(temp,'salt & pepper',0.05);  % adding salt and pepper noise 
b=temp;
[m,n,colormap]=size(b);

%If RGB Image is given at Input 
if colormap==3
x=b(:,:,1);
y=b(:,:,2);
z=b(:,:,3);
end
c = zeros(m,n,3,'uint8');
% for 3 * 3 running window
for i=1:m-2
    for j=1:n-2
        tt1 = zeros(1, 9);
        tt2 = zeros(1, 9);
        tt3 = zeros(1, 9);
        kk  = 1;
        for r=i:(i+2)
            for s=j:(j+2)
               tt1(kk) = x(r,s);
               tt2(kk) = y(r,s);
               tt3(kk) = z(r,s);
               kk = kk + 1;
            end
        end
        
        t1 = sort(tt1);
        t2 = sort(tt2);
        t3 = sort(tt3);
                
        x(i+1,j+1) = t1(5);
        y(i+1,j+1) = t2(5);
        z(i+1,j+1) = t3(5);
    end
end
c(:,:,1)=x;
c(:,:,2)=y;
c(:,:,3)=z;

subplot(1,2, 1); 
imshow(temp); 
title('Original Image'); 

subplot(1, 2, 2); 
imshow(c);
title('3*3 median filtering');