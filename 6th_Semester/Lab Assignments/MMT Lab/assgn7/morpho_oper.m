BW = imread('download.png');
figure,imshow(BW),title('Original Image');
%Remove interior pixels to leave an outline of the shapes.
BW2 = bwmorph(BW,'remove');
figure,imshow(BW2),title('Remove interior pixels');

%Get the image skeleton
BW3 = bwmorph(BW,'skel',Inf);
figure,imshow(BW3),title('image skelton');

%erode image
se = offsetstrel('ball',5,5);
erodedI = imerode(BW,se);
figure,imshow(erodedI),title('erode image');

%dilate image
se = strel('line',11,90);
BW5 = imdilate(BW,se);
figure,imshow(BW5),title('dilate image');

% gradient of the image
[Gmag, Gdir] = imgradient(BW,'prewitt');
figure,imshowpair(Gmag, Gdir, 'montage');
title('Gradient Magnitude, Gmag (left), and Gradient Direction, Gdir (right), using Prewitt method')
