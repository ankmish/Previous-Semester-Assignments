tmp = imread('download.jpg');
A = rgb2gray(tmp);
tmp2 = imread('Krishna.jpg');
tmp2 = rgb2gray(tmp2);

[h,w] = size(tmp2);
[height,width]=size(A);

%figure, imshow(A);title('Original Image'); 

mb8=bitget(tmp2,8);
mb7=bitget(tmp2,7);
mb6=bitget(tmp2,6);

new_mat = zeros(h,w,'uint8');
for i=1:height
    for j=1:width
        new_mat(i,j) = A(i,j);
    end
end

B1=bitget(new_mat,1);  
B2=bitget(new_mat,2);  
B3=bitget(new_mat,3);  
B4=bitget(new_mat,4); 
B5=bitget(new_mat,5); 
B6=bitget(new_mat,6); 
B7=bitget(new_mat,7); 
B8=bitget(new_mat,8);

B1 = mb8;
B2 = mb7;
B3 = mb6;



BB = (2*(2*(2*(2*(2*(2*(2*B8+B7)+ B6)+B5)+B4)+B3)+B2)+B1);
xx = zeros(height,width,'uint8');
for i=1:height
    for j=1:width
        xx(i,j) = BB(i,j);
    end
end
figure,imshow(xx),title('original Image');
BB2 = (2^7*B1) + (2^6*B2) + (2^5*B3);
figure,imshow(BB2),title('hidden image');
