#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //When implementing the grayscale function, you’ll need to average the values of 3 integers. Why might you want to divide the sum of these integers by 3.0 and not 3?
    int avg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0 );
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
                // even if the value is higher than 255, the highet we can assign is 255
            }
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //you’ll need to swap the values of pixels on opposite sides of a row. Recall from lecture how we implemented swapping two values with a temporary variable. No need to use a separate function for swapping unless you would like to
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // we dont want to go through the whole row, its enough to go through the first half, otherwise we will be erasing what we have done
            int tempRed = image[i][j].rgbtRed;
            int tempGreen = image[i][j].rgbtGreen;
            int tempBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed; // arrays start at 0. minus 1 keeps us from segmentation fails
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = tempRed;
            image[i][width - j - 1].rgbtGreen = tempGreen;
            image[i][width - j - 1].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
// be careful not to use the corrected first pixel - and so on- after first calc

//When implementing the blur function, you might find that blurring one pixel ends up affecting the blur of another pixel. Perhaps create a copy of image (the function’s third argument) by declaring a new (two-dimensional) array with code like RGBTRIPLE copy[height][width]; and copying image into copy, pixel by pixel, with nested for loops? And then read pixels’ colors from copy but write (i.e., change) pixels’ colors in image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a copy of the image
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // loop through the image and find the neighbour pixels, check if they are valid
    //https://www.youtube.com/watch?v=eoHIX_PNGcE youtube video suggests relative position for each pixel. x and y values that go through -1 and 1
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            float counter = 0.00;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;
                    //invalid if x or y is tless than 0, if x is greater than heigt-1 or y is greater than width - 1
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue; //do nothing just continue to check other cells
                    }
                    // if no invalid cells then continue totaling the rgb values and add them into total RGB
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    // add that pixel into counter
                    counter ++;
                }
                // now that we added every value of these pixels, we can divide them into counter to find average
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
            }
        }
    }
    //copy copied pixels into old one
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}
// I cannot believe I understood how this blur thing works, really all thanks to the youtube video
