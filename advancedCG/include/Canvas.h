#ifndef CANVAS_H
#define CANVAS_H

#include <Image.h>

class Canvas: public TGAImage {

  protected:
    string fileName;        // name of file to write to

  public:

    Canvas();
    Canvas(unsigned int, unsigned int, std::string);

    /*
        Setters and Getters
    */
    void setName(std::string);
    std::string getName();

    /*
        Class methods
    */
    void writeToFile();
};

#endif
