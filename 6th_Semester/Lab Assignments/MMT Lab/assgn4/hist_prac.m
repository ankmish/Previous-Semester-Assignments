I = imread('download.jpg');
I = rgb2gray(I);

subplot(2,4,1),imshow(I),title('Original Image');

subplot(2,4,2),imhist(I),title('Histogram of Original Image');

% calculate frequency of each gray level ... total posible is 256
no_of_pixels = com_hist(I,'Histogram of Oringal Image without inbuilt function',3);

% calculate probabilty of each gray level
prob_of_pixel = com_normalized_hist(no_of_pixels,I);

%cumlative probabilty
cum_prob = cum_hist(prob_of_pixel);

% now we have got CDF.... just calcuate new gray level
mapping = zeros(1,256);
for i=1:256
    mapping(i) = uint8(255*cum_prob(i) + 0.5);
end

[height,width] = size(I);
for i = 1:height
    for j=1:width
        I(i,j) = mapping( I(i,j) + 1);
    end
end
subplot(2,4,5),imshow(I),title('New Image');



