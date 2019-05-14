openImage = rgb2gray(imread('apple.jpg'));
openImage = im2double(openImage); %// Convert to double

%// Corrected masks
b=[-1 -1 -1;0 0 0;1 1 1]/6;
c=[-1 0 1; -1 0 1; -1 0 1]/6;
Gx=abs(conv2(openImage,c,'same'));
Gy=abs(conv2(openImage,b,'same'));
G = sqrt( Gx.^2 + Gy.^2);
out = G > 0.08995; %// Threshold image
figure;
imshow(out),title('prewit operator');

