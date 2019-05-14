Img = imread('download.jpg'); 
temp = imread('download.jpg');
temp = imnoise(temp,'salt & pepper',0.05);  % adding salt and pepper noise 
b=temp;
[m,n,colormap]=size(b);

%If RGB Image is given at Input 
if colormap==3
x=b(:,:,1);
y=b(:,:,2);
z=b(:,:,3);
x1=b(:,:,1);
y1=b(:,:,2);
z1=b(:,:,3);
end


% for 3 * 3
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

subplot(4,4, 1); 
imshow(temp); 
title('Original Image'); 

subplot(4, 4, 2); 
imshow(c);
title('3*3 median_filtering');

%for 5*5    
for i=1:m-4
    for j=1:n-4
        tt1 = zeros(1, 25);
        tt2 = zeros(1, 25);
        tt3 = zeros(1, 25);
        kk  = 1;
        for r=i:(i+4)
            for s=j:(j+4)
               tt1(kk) = x1(r,s);
               tt2(kk) = y1(r,s);
               tt3(kk) = z1(r,s);
               kk = kk + 1;
            end
        end
        
        t1 = sort(tt1);
        t2 = sort(tt2);
        t3 = sort(tt3);
                
        x1(i+2,j+2) = t1(13);
        y1(i+2,j+2) = t2(13);
        z1(i+2,j+2) = t3(13);
    end
end
cc(:,:,1)=x1;
cc(:,:,2)=y1;
cc(:,:,3)=z1;

subplot(4,4, 3); 
imshow(Img); 
title('Original Image'); 

subplot(4, 4, 4); 
imshow(cc);
title('5*5 median_filtering');


Img = rgb2gray(Img);
c = rgb2gray(c);
cc = rgb2gray(cc);

subplot(4,4,5);
imhist(Img);
title('Original Image Histogram');
subplot(4, 4, 6);
imhist(c);
title('3*3 histogram');

subplot(4,4,7);
imhist(Img);
title('Original Image Histogram');
subplot(4, 4, 8);
imhist(cc);
title('5*5 histogram');
