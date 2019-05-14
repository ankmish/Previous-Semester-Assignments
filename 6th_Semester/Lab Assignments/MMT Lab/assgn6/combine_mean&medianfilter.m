Img = imread('download.jpg'); 
Img = rgb2gray(Img);
temp = imread('download.jpg');
temp = imnoise(temp,'salt & pepper',0.05);  % adding salt and pepper noise 
b=temp;

prompt = 'Enter your choice :\n1.Mean Filter \n2.Median Filter \n';
xx = input(prompt);
if(xx==1)

    % mean filter using builtin function 
    Kaverage = filter2(fspecial('average',3),Img)/255;
    figure,imshow(Kaverage),title('Mean filer from builtin function');
    mean(b);
    disp('Filtering is almost same from both functions');
 
else
    %median filer using builtin function
    Kmedian = medfilt2(Img);
    imshow(Kmedian),title('Median filer from builtin function');
    median(b);
    disp('Filtering is almost similar from both functions'); 
end