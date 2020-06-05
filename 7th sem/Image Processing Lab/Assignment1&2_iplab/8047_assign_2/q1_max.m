%max filtering
Img = imread('im.jpg'); 
Img = rgb2gray(Img);
xx = Img;

 row = 1;
 col = 1;
	for i = row+1 : size(xx,1)-row
        for j = col+1 : size(xx,2)-col
            % 3*3 window
            window = xx(i-row : i+row, j-col : j+col);
            maxi =  max(max(window))
            output(i,j) = maxi;
        end
    end
    
 subplot(1,2,1),imshow(xx),title('Original Image');
subplot(1,2,2),imshow(output),title('Max filter'); 

