#include "helpers.h"
#include <math.h>

// Convert image to grayscale
/*
-------------------- greyscale ------------------------
A function to greyscale a image.

-This function takes height and width and a image file.
-For each pixel in the image, it takes it's rgb values
-and averages them. The averaged value then is updated
-as the value of that pixel.

params:
    (height, width, image)
    height - it is to know how many rows there are
    width - It is to know how many columns there are
    image - The image file

returns: Void
-------------------------------------------------------
*/

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)            //For every row in the image
    {
        for (int j = 0; j < width; j++)         //For every column in the image
        {
            float add = 0;

            //Getting the rgb values of a perticular pixel
            add += image[i][j].rgbtBlue;
            add += image[i][j].rgbtGreen;
            add += image[i][j].rgbtRed;

            //Averageing the values
            BYTE avg = round(add / 3);

            //Updating every pixel's rgb values
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
/*
------------------ sepia ------------------
A function
-------------------------------------------
*/
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = blue;
            }

            if (green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = green;
            }

            if (red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = red;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < round(width / 2); column++)
        {
            RGBTRIPLE temp = image[row][column];
            image[row][column] = image[row][width - column - 1];
            image[row][width - column - 1] = temp;
        }
    }
    return;
}

RGBTRIPLE box(int posX, int posY, int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];


    for (int rows = 0; rows < height; rows++)
    {
        for (int column = 0; column < width; column++)
        {
            newImage[rows][column] = image[rows][column];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j] = box(i, j, height, width, image);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = newImage[i][j];
        }
    }

    return;
}


RGBTRIPLE box(int posX, int posY, int height, int width, RGBTRIPLE image[height][width])
{
    int num = 0;
    float blue = 0, green = 0, red = 0;

    if (posX - 1 < 0)
    {
        for (int i = posX; i <= posX + 1; i++)
        {
            if (posY - 1 < 0)
            {
                for (int j = posY; j <= posY + 1; j++)
                {
                    blue += image[i][j].rgbtBlue;
                    green += image[i][j].rgbtGreen;
                    red += image[i][j].rgbtRed;

                    num++;
                }
            }
            else if (posY + 1 >= height)
            {
                for (int j = posY - 1; j <= posY; j++)
                {
                    blue += image[i][j].rgbtBlue;
                    green += image[i][j].rgbtGreen;
                    red += image[i][j].rgbtRed;

                    num++;
                }
            }
            else
            {
                for (int j = posY - 1; j <= posY + 1; j++)
                {
                    blue += image[i][j].rgbtBlue;
                    green += image[i][j].rgbtGreen;
                    red += image[i][j].rgbtRed;

                    num++;
                }
            }
        }
    }
    else if (posX + 1 >= width)
    {
        for (int i = posX - 1; i <= posX; i++)
        {
            if (posY - 1 < 0)
            {
                for (int j = posY; j <= posY + 1; j++)
                {
                    blue += image[i][j].rgbtBlue;
                    green += image[i][j].rgbtGreen;
                    red += image[i][j].rgbtRed;

                    num++;
                }
            }
            else if (posY + 1 >= height)
            {
                for (int j = posY - 1; j <= posY; j++)
                {
                    blue += image[i][j].rgbtBlue;
                    green += image[i][j].rgbtGreen;
                    red += image[i][j].rgbtRed;

                    num++;
                }
            }
            else
            {
                for (int j = posY - 1; j <= posY + 1; j++)
                {
                    blue += image[i][j].rgbtBlue;
                    green += image[i][j].rgbtGreen;
                    red += image[i][j].rgbtRed;

                    num++;
                }
            }
        }
    }
    else
    {
        for (int i = posX - 1; i <= posX + 1; i++)
        {
            if (posY - 1 < 0)
            {
                for (int j = posY; j <= posY + 1; j++)
                {
                    blue += image[i][j].rgbtBlue;
                    green += image[i][j].rgbtGreen;
                    red += image[i][j].rgbtRed;

                    num++;
                }
            }
            else if (posY + 1 >= height)
            {
                for (int j = posY - 1; j <= posY; j++)
                {
                    blue += image[i][j].rgbtBlue;
                    green += image[i][j].rgbtGreen;
                    red += image[i][j].rgbtRed;

                    num++;
                }
            }
            else
            {
                for (int j = posY - 1; j <= posY + 1; j++)
                {
                    blue += image[i][j].rgbtBlue;
                    green += image[i][j].rgbtGreen;
                    red += image[i][j].rgbtRed;

                    num++;
                }
            }
        }
    }

    RGBTRIPLE blur_pixel;
    blur_pixel.rgbtBlue = round(blue / num);
    blur_pixel.rgbtGreen = round(green / num);
    blur_pixel.rgbtRed = round(red / num);

    return blur_pixel;

}

