
function f = com_hist(I,title1,pos)
    
    [height,width] = size(I);
    no_of_pixels = zeros(1,256);
    for i=1:height
        for j=1:width
            no_of_pixels(I(i,j) + 1) = no_of_pixels(I(i,j)+1) + 1;
        end
    end
    subplot(2,4,pos),bar(no_of_pixels),title(title1);
    f = no_of_pixels;
end