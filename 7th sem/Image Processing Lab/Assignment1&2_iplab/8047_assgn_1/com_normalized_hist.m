function f = com_normalized_hist(no_of_pixels,I)

[height,width]=size(I);

% Compute the probability of an occurrence of each gray level
prob_of_pixel = zeros(1,256);
for i = 1:256
    prob_of_pixel(i) = no_of_pixels(i) / (height * width * 1.0);
end

f = prob_of_pixel;
end
