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
    sum1 = 0;
    sum2 = 0;
    sum3=0;
    for j=1:n-2
        for r=i:(i+2)
            for s=j:(j+2)
                sum1 = int16(sum1) + int16(x(r,s));
                sum2 = int16(sum2) + int16(y(r,s));
                sum3 = int16(sum3) + int16(z(r,s));
            end
        end
            avg1 = int16(sum1 / 9);
            avg2 = int16(sum2 / 9);
            avg3 = int16(sum3 / 9);
            
            x(i+1,j+1) = avg1;
            y(i+1,j+1) = avg2;
            z(i+1,j+1) = avg3;
            sum1=0;sum2=0; sum3 = 0;
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
title('3*3 mean filtering');

%for 5*5       
for i=1:m-4
    sum1 = 0;
    sum2 = 0;
    sum3=0;
    for j=1:n-4
        for r=i:(i+4)
            for s=j:(j+4)
                sum1 = int16(sum1) + int16(x1(r,s));
                sum2 = int16(sum2) + int16(y1(r,s));
                sum3 = int16(sum3) + int16(z1(r,s));
            end
        end
            avg1 = int16(sum1 / 25);
            avg2 = int16(sum2 / 25);
            avg3 = int16(sum3 / 25);
            
            x1(i+2,j+2) = avg1;
            y1(i+2,j+2) = avg2;
            z1(i+2,j+2) = avg3;
            sum1=0;sum2=0; sum3 = 0;
    end
end
cc(:,:,1)=x1;
cc(:,:,2)=y1;
cc(:,:,3)=z1;    

subplot(4, 4, 3);
imshow(Img);
title('Original Image');
subplot(4, 4, 4);
imshow(cc);
title('5*5 mean filtering');

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



            