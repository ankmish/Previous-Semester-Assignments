function f = cum_hist(prob_of_pixel)
    cum_prob = zeros(1,256);
    for i=1:256
        if(i==1)
            cum_prob(i) = prob_of_pixel(i);
        else
            cum_prob(i) = prob_of_pixel(i) + cum_prob(i-1);
        end
    end
    f= cum_prob;
end