#include <iostream>
#include <fstream>
#include <math.h>
#include "Image.h"

using namespace std;

// image to file IO functions
Image* generateImageObject(string filename);
void exportImageObject(Image* myImage, string filename);

// image modifying functions
void multiply(Image* baseImage, Image* secondImage);
void subtract(Image* baseImage, Image* secondImage);
void add(Image* baseImage, Image* secondImage);
void screen(Image* baseImage, Image* secondImage);
void overlay(Image* baseImage, Image* secondImage);
Image* combine4(Image* topLeft, Image* topRight, Image* bottomLeft, Image* bottomRight);

// testing function
string isEqual(Image* image1, Image* image2);

int main()
{
    // PART 1 - multiply two images together
        Image* layer1 = generateImageObject("input/layer1.tga");
        Image* pattern1 = generateImageObject("input/pattern1.tga");

        multiply(layer1, pattern1);

        exportImageObject(layer1, "output/part1.tga");

        delete layer1;
        delete pattern1;

        //test Part 1
        Image* test1 = generateImageObject("output/part1.tga");
        Image* test1Example = generateImageObject("examples/EXAMPLE_part1.tga");
        cout << "Test 1: " <<isEqual(test1, test1Example) << endl;

        delete test1;
        delete test1Example;

    // PART 2 - subtract two images together
        Image* layer2 = generateImageObject("input/layer2.tga");
        Image* car = generateImageObject("input/car.tga");

        subtract(layer2, car);

        exportImageObject(layer2, "output/part2.tga");

        delete layer2;
        delete car;

        //test Part 2
        Image* test2 = generateImageObject("output/part2.tga");
        Image* test2Example = generateImageObject("examples/EXAMPLE_part2.tga");
        cout << "Test 2: " << isEqual(test2, test2Example) << endl;

        delete test2;
        delete test2Example;

    //PART 3 - screen two images together
        Image* layer1_1 = generateImageObject("input/layer1.tga");
        Image* pattern2 = generateImageObject("input/pattern2.tga");
        Image* text = generateImageObject("input/text.tga");

        multiply(layer1_1, pattern2);
        screen(text, layer1_1);

        exportImageObject(text, "output/part3.tga");

        delete layer1_1;
        delete pattern2;
        delete text;

        //test Part 3
        Image* test3 = generateImageObject("output/part3.tga");
        Image* test3Example = generateImageObject("examples/EXAMPLE_part3.tga");
        cout << "Test 3: " << isEqual(test3, test3Example) << endl;

        delete test3;
        delete test3Example;

    // PART 4 - multiply two images together
        Image* layer2_1 = generateImageObject("input/layer2.tga");
        Image* circles = generateImageObject("input/circles.tga");
        Image* pattern2_1 = generateImageObject("input/pattern2.tga");

        multiply(layer2_1, circles);
        subtract(pattern2_1, layer2_1);

        exportImageObject(pattern2_1, "output/part4.tga");

        delete layer2_1;
        delete circles;
        delete pattern2_1;

        //test Part 4
        Image* test4 = generateImageObject("output/part4.tga");
        Image* test4Example = generateImageObject("examples/EXAMPLE_part4.tga");
        cout << "Test 4: " << isEqual(test4, test4Example) << endl;

        delete test4;
        delete test4Example;

    // PART 5 - overlay two images together
        Image* layer1_2 = generateImageObject("input/layer1.tga");
        Image* pattern1_1 = generateImageObject("input/pattern1.tga");

        overlay(layer1_2, pattern1_1);

        exportImageObject(layer1_2, "output/part5.tga");

        delete layer1_1;
        delete pattern1_1;

        //test Part 5
        Image* test5 = generateImageObject("output/part5.tga");
        Image* test5Example = generateImageObject("examples/EXAMPLE_part5.tga");
        cout << "Test 5: " << isEqual(test5, test5Example) << endl;

        delete test5;
        delete test5Example;

    // PART 6 - increase the green channel
        Image* car_1 = generateImageObject("input/car.tga");

        int temp;
        for(int i = 1; i < (int)car_1->imageData.size(); i+=3)
        {
            temp = car_1->imageData[i] + 200;
            if(temp > 255)
            {
                car_1->imageData[i] = 255;
            }
            else
            {
                car_1->imageData[i] = temp;
            }
        }

        exportImageObject(car_1, "output/part6.tga");

        delete car_1;

        //test Part 6
        Image* test6 = generateImageObject("output/part6.tga");
        Image* test6Example = generateImageObject("examples/EXAMPLE_part6.tga");
        cout << "Test 6: " << isEqual(test6, test6Example) << endl;

        delete test6;
        delete test6Example;

    // PART 7 - increase the red channel
        Image* car_2 = generateImageObject("input/car.tga");

        for(int i = 2; i < (int)car_2->imageData.size(); i+=3)
        {
            temp = car_2->imageData[i] * 4;
            if(temp > 255)
            {
                car_2->imageData[i] = 255;
            }
            else
            {
                car_2->imageData[i] = temp;
            }
        }

        for(int i = 0; i < (int)car_2->imageData.size(); i+=3)
        {
            car_2->imageData[i] = 0;
        }

        exportImageObject(car_2, "output/part7.tga");

        delete car_2;

        //test Part 7
        Image* test7 = generateImageObject("output/part7.tga");
        Image* test7Example = generateImageObject("examples/EXAMPLE_part7.tga");
        cout << "Test 7: " << isEqual(test7, test7Example) << endl;

        delete test7;
        delete test7Example;

    // PART 8 - extract the three RGB channels from an image
        //extract the red
        Image* car_3 = generateImageObject("input/car.tga");

        for(int i = 0; i < (int)car_3->imageData.size(); i+=3)
        {
            car_3->imageData[i] = car_3->imageData[i + 2];
        }
        for(int i = 1; i < (int)car_3->imageData.size(); i+=3)
        {
            car_3->imageData[i] = car_3->imageData[i + 1];
        }

        exportImageObject(car_3, "output/part8_r.tga");

        //extract the green
        Image* car_4 = generateImageObject("input/car.tga");

        for(int i = 0; i < (int)car_4->imageData.size(); i+=3)
        {
            car_4->imageData[i] = car_4->imageData[i + 1];
        }
        for(int i = 2; i < (int)car->imageData.size(); i+=3)
        {
            car_4->imageData[i] = car_4->imageData[i - 1];
        }

        exportImageObject(car_4, "output/part8_g.tga");

        //extract the blue
        Image* car_5 = generateImageObject("input/car.tga");

        for(int i = 1; i < (int)car_5->imageData.size(); i+=3)
        {
            car_5->imageData[i] = car_5->imageData[i - 1];
        }
        for(int i = 2; i < (int)car_5->imageData.size(); i+=3)
        {
            car_5->imageData[i] = car_5->imageData[i - 2];
        }

        exportImageObject(car_5, "output/part8_b.tga");

        delete car_3;
        delete car_4;
        delete car_5;

        //test Part 8
        Image* test8_r = generateImageObject("output/part8_r.tga");
        Image* test8_g = generateImageObject("output/part8_g.tga");
        Image* test8_b = generateImageObject("output/part8_b.tga");

        Image* test8Example_r = generateImageObject("examples/EXAMPLE_part8_r.tga");
        Image* test8Example_g = generateImageObject("examples/EXAMPLE_part8_g.tga");
        Image* test8Example_b = generateImageObject("examples/EXAMPLE_part8_b.tga");

        cout << "Test 8: " << "part r: " << isEqual(test8_r, test8Example_r) << ", part g: " << isEqual(test8_g, test8Example_g) << ", part b: " << isEqual(test8_b, test8Example_b) << endl;

        delete test8_r;
        delete test8_g;
        delete test8_b;
        delete test8Example_r;
        delete test8Example_g;
        delete test8Example_b;

    //PART 9 - combine 3 RGB channels from 3 images into one image
        Image* layer_red = generateImageObject("input/layer_red.tga");
        Image* layer_green = generateImageObject("input/layer_green.tga");
        Image* layer_blue = generateImageObject("input/layer_blue.tga");

        //pure extract the red
        for(int i = 0; i < (int)layer_red->imageData.size(); i+=3)
        {
            layer_red->imageData[i] = 0;
        }
        for(int i = 1; i < (int)layer_red->imageData.size(); i+=3)
        {
            layer_red->imageData[i] = 0;
        }

        //pure extract the green
        for(int i = 0; i < (int)layer_green->imageData.size(); i+=3)
        {
            layer_green->imageData[i] = 0;
        }
        for(int i = 2; i < (int)layer_green->imageData.size(); i+=3)
        {
            layer_green->imageData[i] = 0;
        }

        //pure extract the blue
        for(int i = 1; i < (int)layer_blue->imageData.size(); i+=3)
        {
            layer_blue->imageData[i] = 0;
        }
        for(int i = 2; i < (int)layer_blue->imageData.size(); i+=3)
        {
            layer_blue->imageData[i] = 0;
        }

        add(layer_red, layer_green);
        add(layer_red, layer_blue);

        exportImageObject(layer_red, "output/part9.tga");

        delete layer_red;
        delete layer_blue;
        delete layer_green;

        //test Part 9
        Image* test9 = generateImageObject("output/part9.tga");
        Image* test9Example = generateImageObject("examples/EXAMPLE_part9.tga");
        cout << "Test 9: " << isEqual(test9, test9Example) << endl;

        delete test9;
        delete test9Example;

    // PART 10 - rotate image 180 degrees
        Image* text2 = generateImageObject("input/text2.tga");
        unsigned char tempPixel;
        //flip the blue pixels
        for(int i = 0; i < (int)text2->imageData.size() / 2; i+=3)
        {
            tempPixel = text2->imageData[i];
            text2->imageData[i] = text2->imageData[text2->imageData.size() - (i + 3)];
            text2->imageData[text2->imageData.size() - (i + 3)] = tempPixel;
        }

        //flip the green pixels
        for(int i = 1; i < (int)text2->imageData.size() / 2; i+=3)
        {
            tempPixel = text2->imageData[i];
            text2->imageData[i] = text2->imageData[text2->imageData.size() - (i + 1)];
            text2->imageData[text2->imageData.size() - (i + 1)] = tempPixel;
        }

        //flip the red pixels
        for(int i = 2; i < (int)text2->imageData.size() / 2; i+=3)
        {
            tempPixel = text2->imageData[i];
            text2->imageData[i] = text2->imageData[text2->imageData.size() - (i - 1)];
            text2->imageData[text2->imageData.size() - (i - 1)] = tempPixel;
        }

        exportImageObject(text2, "output/part10.tga");

        delete text2;

        //test Part 10
        Image* test10 = generateImageObject("output/part10.tga");
        Image* test10Example = generateImageObject("examples/EXAMPLE_part10.tga");
        cout << "Test 10: " << isEqual(test10, test10Example) << endl;

        delete test10;
        delete test10Example;

    // Extra Credit - combine 4 images
        Image* newCar = generateImageObject("input/car.tga");
        Image* newCircles = generateImageObject("input/circles.tga");
        Image* pattern1_2 = generateImageObject("input/pattern1.tga");
        Image* text_1 = generateImageObject("input/text.tga");
        Image* exCred = combine4(newCar, newCircles, text_1, pattern1_2);

        exportImageObject(exCred, "output/extraCredit.tga");

        delete newCar;
        delete newCircles;
        delete pattern1_2;
        delete text_1;
        delete exCred;

        //test Extra Credit
        Image* testEC = generateImageObject("output/extraCredit.tga");
        Image* testECExample = generateImageObject("examples/EXAMPLE_extracredit.tga");
        cout << "Extra Credit: " << isEqual(testEC, testECExample) << endl;

        delete testEC;
        delete testECExample;

    return 0;
}//end of main()

/***************************************************************************/

Image* generateImageObject(string const filename)
{
    Image* myImage = new Image();

    try
    {
        //OPEN the file input stream in binary mode
        ifstream inputStream(filename, ios::binary);
        inputStream.exceptions(ifstream::badbit);

        //read in all the data for the header
        inputStream.read(&myImage->imageHeader.idLength, sizeof(myImage->imageHeader.idLength));
        inputStream.read(&myImage->imageHeader.colorMapType, sizeof(myImage->imageHeader.colorMapType));
        inputStream.read(&myImage->imageHeader.dataTypeCode, sizeof(myImage->imageHeader.dataTypeCode));
        inputStream.read((char *)(&myImage->imageHeader.colorMapOrigin), sizeof(myImage->imageHeader.colorMapOrigin));
        inputStream.read((char *)&myImage->imageHeader.colorMapLength, sizeof(myImage->imageHeader.colorMapLength));
        inputStream.read(&myImage->imageHeader.colorMapDepth, sizeof(myImage->imageHeader.colorMapDepth));
        inputStream.read((char *)&myImage->imageHeader.xOrigin, sizeof(myImage->imageHeader.xOrigin));
        inputStream.read((char *)&myImage->imageHeader.yOrigin, sizeof(myImage->imageHeader.yOrigin));
        inputStream.read((char *)&myImage->imageHeader.width, sizeof(myImage->imageHeader.width));
        inputStream.read((char *)&myImage->imageHeader.height, sizeof(myImage->imageHeader.height));
        inputStream.read(&myImage->imageHeader.bitsPerPixel, sizeof(myImage->imageHeader.bitsPerPixel));
        inputStream.read(&myImage->imageHeader.imageDescriptor, sizeof(myImage->imageHeader.imageDescriptor));

        //read in the image data
        myImage->imageData = vector<unsigned char>(myImage->imageHeader.width * myImage->imageHeader.height * myImage->imageHeader.bitsPerPixel / 8);

        for(int i = 0; i < (int)myImage->imageHeader.width * myImage->imageHeader.height * myImage->imageHeader.bitsPerPixel / 8; i++)
        {
            inputStream.read((char*)(&myImage->imageData[i]), sizeof(char));
        }

        inputStream.close();//CLOSE the file input stream
    }
    catch(ifstream::failure&)
    {
        cout << "FAILED to load image from file [" << filename << "]";
    }

    return myImage;
}//end of generateImageObject()

void exportImageObject(Image* myImage, string const filename)
{
    try
    {
        //CREATE / OPEN a file output stream in binary mode
        ofstream outputStream(filename, ios::binary);
        outputStream.exceptions(ofstream::badbit);

        //write the header out
        outputStream.write(&myImage->imageHeader.idLength, sizeof(myImage->imageHeader.idLength));
        outputStream.write(&myImage->imageHeader.colorMapType, sizeof(myImage->imageHeader.colorMapType));
        outputStream.write(&myImage->imageHeader.dataTypeCode, sizeof(myImage->imageHeader.dataTypeCode));
        outputStream.write((char *)(&myImage->imageHeader.colorMapOrigin), sizeof(myImage->imageHeader.colorMapOrigin));
        outputStream.write((char *)&myImage->imageHeader.colorMapLength, sizeof(myImage->imageHeader.colorMapLength));
        outputStream.write(&myImage->imageHeader.colorMapDepth, sizeof(myImage->imageHeader.colorMapDepth));
        outputStream.write((char *)&myImage->imageHeader.xOrigin, sizeof(myImage->imageHeader.xOrigin));
        outputStream.write((char *)&myImage->imageHeader.yOrigin, sizeof(myImage->imageHeader.yOrigin));
        outputStream.write((char *)&myImage->imageHeader.width, sizeof(myImage->imageHeader.width));
        outputStream.write((char *)&myImage->imageHeader.height, sizeof(myImage->imageHeader.height));
        outputStream.write(&myImage->imageHeader.bitsPerPixel, sizeof(myImage->imageHeader.bitsPerPixel));
        outputStream.write(&myImage->imageHeader.imageDescriptor, sizeof(myImage->imageHeader.imageDescriptor));

        //write the rest of the file data out
        for(int i = 0; i < (int)myImage->imageHeader.width * myImage->imageHeader.height * myImage->imageHeader.bitsPerPixel / 8; i++)
        {
            outputStream.write((char*)(&myImage->imageData[i]), sizeof(char));
        }

        outputStream.close();//CLOSE the file input stream
    }
    catch(ofstream::failure&)
    {

    }

}//end of exportImageObject()

//Image modifying functions
void multiply(Image* baseImage, Image* secondImage)
{
    for(int i = 0; i < (int)baseImage->imageData.size(); i++)
    {
        baseImage->imageData[i] = round((double)baseImage->imageData[i] * (double)secondImage->imageData[i] / 255.0);
    }
}//end of multiply()

void subtract(Image* baseImage, Image* secondImage)
{
    int temp;
    for(int i = 0; i < (int)baseImage->imageData.size(); i++)
    {
        temp = -1 * (int)baseImage->imageData[i] + (int)secondImage->imageData[i];
        if(temp < 0)
        {
            baseImage->imageData[i] = 0;
        }
        else
        {
            baseImage->imageData[i] = temp;
        }
    }
}//end of subtract()

void add(Image* baseImage, Image* secondImage)
{
    int temp;
    for(int i = 0; i < (int)baseImage->imageData.size(); i++)
    {
        temp = (int)baseImage->imageData[i] + (int)secondImage->imageData[i];
        if(temp > 255)
        {
            baseImage->imageData[i] = 255;
        }
        else
        {
            baseImage->imageData[i] = temp;
        }
    }
}//end of add()

void screen(Image* baseImage, Image* secondImage)
{
    for(int i = 0; i < (int)baseImage->imageData.size(); i++)
    {
        baseImage->imageData[i] = round(255.0 - (255.0 - (double)baseImage->imageData[i]) * (255.0 - (double)secondImage->imageData[i]) / 255.0);
    }
}//end of screen()

void overlay(Image* baseImage, Image* secondImage)
{
    int temp;
    for(int i = 0; i < (int)baseImage->imageData.size(); i++)
    {
        if(secondImage->imageData[i] < 127.5)
        {
            temp = round(2.0 * (double)baseImage->imageData[i] * (double)secondImage->imageData[i] / 255.0);
            if(temp > 255)
            {
                baseImage->imageData[i] = 255;
            }
            else
            {
                baseImage->imageData[i] = temp;
            }
        }
        else
        {
            temp = baseImage->imageData[i] = round(255.0 - 2.0 * (255.0 - (double)baseImage->imageData[i]) * (255.0 - (double)secondImage->imageData[i]) / 255.0);
            if(temp < 0)
            {
                baseImage->imageData[i] = 0;
            }
            else
            {
                baseImage->imageData[i] = temp;
            }
        }
    }
}//end of overlay()

Image* combine4(Image* topLeft, Image* topRight, Image* bottomLeft, Image* bottomRight)
{
    //generate new left, right, and combined image objects from a default car image
    Image* leftImage = generateImageObject("input/car.tga");
    Image* rightImage = generateImageObject("input/car.tga");
    Image* combinedImage = generateImageObject("input/car.tga");

    //double the normal height of an image to get the new height
    leftImage->imageHeader.height = leftImage->imageHeader.height * 2;
    rightImage->imageHeader.height = rightImage->imageHeader.height * 2;

    //create new vectors for the imagedata of the left and right images
    leftImage->imageData = vector<unsigned char>(leftImage->imageHeader.height * leftImage->imageHeader.width * 3);
    rightImage->imageData = vector<unsigned char>(rightImage->imageHeader.height * rightImage->imageHeader.width * 3);

    //add the bottom right and left images to the left and right images
    for(int i = 0; i < (int)bottomRight->imageData.size(); i++)
    {
        leftImage->imageData[i] = bottomLeft->imageData[i];
        rightImage->imageData[i] = bottomRight->imageData[i];
    }

    //add the top right and left images to the left and right images
    for(int i = bottomRight->imageData.size(); i < (int)leftImage->imageData.size(); i++)
    {
        leftImage->imageData[i] = topLeft->imageData[i - bottomLeft->imageData.size()];
        rightImage->imageData[i] = topRight->imageData[i - bottomRight->imageData.size()];
    }

    //double the normal height and width values of the default image to get the new combined image dimensions
    combinedImage->imageHeader.height = combinedImage->imageHeader.height * 2;//make sure to double the height
    combinedImage->imageHeader.width = combinedImage->imageHeader.width * 2;//make sure to double the width

    //start combining the image data
    int count;
    combinedImage->imageData = vector<unsigned char>(combinedImage->imageHeader.height * combinedImage->imageHeader.width * 3);

    for(int i = 0; i < (int)combinedImage->imageData.size(); i++)
    {
        combinedImage->imageData[i] = 0;
    }

    //copy over the two left and right tall images
    for(int i = 0; i < (int)combinedImage->imageHeader.height; i++)
    {
            //copy over a single row of the left image
            count = i * bottomLeft->imageHeader.width * 3;
            for(int j = i * combinedImage->imageHeader.width * 3; j < i * combinedImage->imageHeader.width * 3 + combinedImage->imageHeader.width * 3 / 2; j++)
            {
                combinedImage->imageData[j] = leftImage->imageData[count];
                count++;
            }

            //copy over a single row of the right image
            count = i * bottomRight->imageHeader.width * 3;
            for(int j = i * combinedImage->imageHeader.width * 3 + combinedImage->imageHeader.width * 3 / 2; j < i * combinedImage->imageHeader.width * 3 + combinedImage->imageHeader.width * 3; j++)
            {
                combinedImage->imageData[j] = rightImage->imageData[count];
                count++;
            }
    }

    delete leftImage;
    delete rightImage;

    return combinedImage;
}//end of combine4()

string isEqual(Image* image1, Image* image2)
{
    if(
            //check all image header data against one another
            image1->imageHeader.bitsPerPixel == image2->imageHeader.bitsPerPixel &&
            image1->imageHeader.height == image2->imageHeader.height &&
            image1->imageHeader.width == image2->imageHeader.width &&
            image1->imageHeader.idLength == image2->imageHeader.idLength &&
            image1->imageHeader.colorMapDepth == image2->imageHeader.colorMapDepth &&
            image1->imageHeader.colorMapLength == image2->imageHeader.colorMapLength &&
            image1->imageHeader.colorMapOrigin == image2->imageHeader.colorMapOrigin &&
            image1->imageHeader.colorMapType == image2->imageHeader.colorMapType &&
            image1->imageHeader.dataTypeCode == image2->imageHeader.dataTypeCode &&
            image1->imageHeader.imageDescriptor == image2->imageHeader.imageDescriptor &&
            image1->imageHeader.xOrigin == image2->imageHeader.xOrigin &&
            image1->imageHeader.yOrigin == image2->imageHeader.yOrigin &&

            //check image data sizes against one another
            image1->imageData.size() == image2->imageData.size()
      )
    {
        //check to make sure all pixels are exactly the same
        for(int i = 0; i < (int)image1->imageData.size(); i++)
        {
            if(image1->imageData[i] != image2->imageData[i])
            {
                cout << "Image 1 data at index [" << i << "] is: " << (int)image1->imageData[i] << endl;
                cout << "Image 2 data at index [" << i << "] is: " << (int)image2->imageData[i] << endl;
                return "Failed";
            }
        }
        return "Passed";
    }
    else
    {
        return "Failed";
    }
}//end of isEqual()
