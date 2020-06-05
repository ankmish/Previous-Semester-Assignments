tmp = imread('im.jpg'); 
I = tmp;
[height,width, colormap]=size(tmp);
I = rgb2gray(tmp);

% show the original image
subplot(1,2,1)
imshow(I)
title('Original Image');

% no_of_pixels is the number of occurrences of each gray level
no_of_pixels = com_hist(I,'Histogram of Original Image');

% prob_of_pixel is the probability of an occurrence of each gray level
prob_of_pixel = com_normalized_hist(no_of_pixels,I);

% cum_pixel is the cumulative distribution function
cum_pixel = comp_cumul_hist(prob_of_pixel);

% cum_pixel convert to new gray levels
mapping = zeros(1,256);
for i = 1:256
    mapping(i) = uint8(255*cum_pixel(i) + 0.5);
end
for i = 1:height
    for j = 1:width
        I(i,j)=mapping(I(i,j) + 1);
    end
end
% show the new image
subplot(1,2,2)
imshow(I)
title('Enhanced Image');
%imsave