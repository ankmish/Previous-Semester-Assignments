function f = com_hist(I,title1)
%compute_histogram 

[height,width]=size(I);
% Compute the number of occurrences of each gray level
no_of_pixels = zeros(1,256);                      % saare pixels ke occurance nikal lo
for i = 1:height
    for j = 1:width
        no_of_pixels( I(i,j) + 1 ) = no_of_pixels( I(i,j) + 1 ) + 1;
    end
end

%subplot(2,4,position)
%bar(no_of_pixels)
%title(title1);
f = no_of_pixels;
end

