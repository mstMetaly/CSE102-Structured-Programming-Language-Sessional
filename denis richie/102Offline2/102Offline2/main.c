#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "utils.h"
Image *img_DennisRitchie;


Image *read_PPM(char *filename)
{
    /* opens a PPM file, constructs an Image object and returns a pointer to it.
    Use fopen(), fscanf(), fprintf(), and fclose().*/

    FILE *fp;

    fp=fopen("DennisRitchie.ppm","r");


    img_DennisRitchie=(Image*)malloc(sizeof(Image));

    char fileType[5];
    fscanf(fp,"%s",fileType);
    printf("%s\n",fileType);

    fscanf(fp,"%d %d",&img_DennisRitchie->cols,&img_DennisRitchie->rows);
    printf("%d %d\n",img_DennisRitchie->cols,img_DennisRitchie->rows);

    int max;
    fscanf(fp,"%d",&max);
    printf("%d\n",max);


    img_DennisRitchie->image=(Color**)malloc(img_DennisRitchie->rows * sizeof(Color*));

    for(int i=0; i<img_DennisRitchie->rows; i++)
    {
        img_DennisRitchie->image[i]=(Color*)malloc(img_DennisRitchie->cols * sizeof(Color));
    }


    for(int i=0; i<img_DennisRitchie->rows; i++)
    {
        for(int j=0; j<img_DennisRitchie->cols; j++)
        {
            Color pixel;
            fscanf(fp,"%d %d %d",&pixel.R,&pixel.G,&pixel.B);
            img_DennisRitchie->image[i][j]=pixel;


        }

    }

    fclose(fp);
    return img_DennisRitchie;

}

void write_PPM(Image *image, char *filename)
{
    /* takes an Image object and writes to filename in PPM format.*/

    FILE *fp1=fopen(filename,"w");

    fprintf(fp1,"P3\n");
    fprintf(fp1,"%d %d \n",img_DennisRitchie->cols,img_DennisRitchie->rows);
    fprintf(fp1,"%d\n",255);

    for(int i=0; i<img_DennisRitchie->rows; i++)
    {
        for(int j=0; j<img_DennisRitchie->cols; j++)
        {

            fprintf(fp1,"%3d %3d %3d   ",img_DennisRitchie->image[i][j].R, img_DennisRitchie->image[i][j].G, img_DennisRitchie->image[i][j].B);


        }

        fprintf(fp1,"\n");


    }


    fclose(fp1);

}

void free_image(Image *image)
{
    /* takes an Image object and frees all the memory associated with it.
    This involves not only calling free on image but also on the appropriate
    members of it.
    */
    for(int i=0; i<img_DennisRitchie->rows; i++)
    {
        free(img_DennisRitchie->image[i]);
    }

    free(img_DennisRitchie->image);



}


Color *evaluate_one_pixel(Image *image, int row, int col)
{
    /* Takes an Image object and returns what color the pixel at the given row/col
    should be in the secret image. This function should not change image*/

    Color *pixel2;
    pixel2=(Color*)malloc(sizeof(Color));

    pixel2->R=image->image[row][col].R;
    pixel2->G=image->image[row][col].G;
    pixel2->B=image->image[row][col].B;

    if((pixel2->B)%2==0)
    {
        pixel2->R=0;
        pixel2->G=0;
        pixel2->B=0;

    }
    else
    {
        pixel2->R=255;
        pixel2->G=255;
        pixel2->B=255;

    };

    return pixel2;

}

Image *get_secret_image(Image *image)
{
    /* takes an Image object, and constructs the secret image from it by extracting
    the LSB of the B channel. You should call evaluate_one_pixel() here. */

    for(int i=0; i<image->rows; i++)
    {
        for(int j=0; j<image->cols; j++)
        {
            Color *pixel;
            pixel=evaluate_one_pixel(image,i,j);
            image->image[i][j]=*pixel;


        }

    }

    return image;

}

int main()
{
    /* Call read_PPM(), write_PPM(), free_image(), get_secret_image() in some order
    to obtain the hidden message.*/
    //Image *read_PPM(char *DennisRitchie.ppm);

    Image *p=read_PPM("DennisRitchie.ppm");
    Image *q=get_secret_image(p);

    write_PPM(q,"new.ppm");
    free_image(q);

    return 0;
}


