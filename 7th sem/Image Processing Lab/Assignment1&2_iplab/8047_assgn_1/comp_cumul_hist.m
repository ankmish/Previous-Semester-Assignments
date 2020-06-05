function f = comp_cumul_hist(prob_of_pixel)

% Compute the cumulative distribution function
cum_pixel = zeros(1,256);
for i = 1:256
    if (i == 1)
        cum_pixel(i) = prob_of_pixel(i);
    else
        cum_pixel(i) = cum_pixel(i-1) + prob_of_pixel(i);
    end
end

f = cum_pixel;
end