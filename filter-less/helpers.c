#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgbtgray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = rgbtgray;
            image[i][j].rgbtGreen = rgbtgray;
            image[i][j].rgbtRed = rgbtgray;
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
            int sepiaRed = round((.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE t;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            t = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = t;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }
    float totalr, totalg, totalb;
    int count = 0;
    totalr = totalg = totalb = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int arri = i - 1; arri <= i + 1; arri++)
            {
                for (int arrj = j - 1; arrj <= j + 1; arrj++)
                {
                    if (arrj < width && arri < height && arri >= 0 && arrj >= 0)
                    {
                        totalr += original[arri][arrj].rgbtRed;
                        totalg += original[arri][arrj].rgbtGreen;
                        totalb += original[arri][arrj].rgbtBlue;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round(totalr / count);
            image[i][j].rgbtGreen = round(totalg / count);
            image[i][j].rgbtBlue = round(totalb / count);
            count = 0;
            totalr = totalg = totalb = 0;
        }
    }
    return;
}
