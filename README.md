1. Write a program to read and display the digital image

a=imread('file path\filename.jpg');
imshow(a);


2. Write a program to read multiple images from the inputfile and write the same images in output file

close all;
clear all;

for k = 1:5
            
        close all;
        

        im = strcat('C:\Users\Divyashreenivas\OneDrive\Documents\Divya Chilli Disease photos\cp0\',num2str(k),'.jpg');
        a= imread(im);

im = strcat('C:\Users\Divyashreenivas\OneDrive\Documents\outputs\',num2str(k),'.jpg');
        imwrite(a, im);
end


3. write a program to convert RGB image to Gray scale and binary. Display original, gray scale and binary images in the single figure
a=imread('C:\Users\Divyashreenivas\OneDrive\Desktop\Ammu mrg\family photo.jpg');
imshow(a);

b=rgb2gray(a);
c=im2bw(b);

figure,
subplot(2,2,1); imshow(a); title('RGBimage');
subplot(2,2,2); imshow(b); title('grayimage');
subplot(2,2,3); imshow(c); title('binaryimage');


4. Write a program to read the image, plot the histogram for the image and display.

a=imread('file path\filename.jpg');
imshow(a);
b=imhist(a);
figure,
imshow(b);


5.Write a program to read RGB image and split the R channel, G channel and B channel separately and display

close all;
clear all;
original=imread("C:\Users\Divyashreenivas\OneDrive\Desktop\Ammu mrg\family photo.jpg");

    redchannel = original(:,:, 1);
        greenchannel = original(:,:, 2);
        bluechannel = original(:,:, 3);
        figure,
        subplot(2,2,1), imshow(original); title('image');
        subplot(2,2,2), imshow(greenchannel); title('rimage');
        subplot(2,2,3), imshow(greenchannel); title('gimage');
        subplot(2,2,4), imshow(greenchannel); title('bimage');



6. Write a Program to read a digital image. Split and display image into 4
quadrants, up, down, right and left.

img = imread('C:\Users\Divyashreenivas\OneDrive\Documents\Divya Chilli Disease photos\cp0\1.jpg');
% Display the original image
figure;
imshow(img);
title('Original Image');

% Get the dimensions of the image
[rows, cols, channels] = size(img);

% Calculate the split points for rows and columns
% Use floor to handle cases with odd dimensions, ensuring integer indices
mid_row = floor(rows / 2);
mid_col = floor(cols / 2);

% --- Split the image into four quadrants ---

% Quadrant 1: Top-Left (Up-Left)
% Rows 1 to mid_row, Columns 1 to mid_col
quad1 = img(1:mid_row, 1:mid_col, :);

% Quadrant 2: Top-Right (Up-Right)
% Rows 1 to mid_row, Columns mid_col+1 to end
quad2 = img(1:mid_row, mid_col+1:end, :);

1. Write a Program to read a digital image. Split and display image into 4
quadrants, up, down, right and left.

% Quadrant 3: Bottom-Left (Down-Left)
% Rows mid_row+1 to end, Columns 1 to mid_col
quad3 = img(mid_row+1:end, 1:mid_col, :);

% Quadrant 4: Bottom-Right (Down-Right)
% Rows mid_row+1 to end, Columns mid_col+1 to end
quad4 = img(mid_row+1:end, mid_col+1:end, :);

% --- Display the four quadrants ---

figure;

% Display Top-Left (Up)
subplot(2, 2, 1);
imshow(quad1);
title('Top-Left Quadrant (Up)');

% Display Top-Right (Right side of top half)
subplot(2, 2, 2);
imshow(quad2);
title('Top-Right Quadrant (Right)');

% Display Bottom-Left (Left side of bottom half)
subplot(2, 2, 3);
imshow(quad3);
title('Bottom-Left Quadrant (Left)');

% Display Bottom-Right (Down)
subplot(2, 2, 4);
imshow(quad4);
title('Bottom-Right Quadrant (Down)');
