//
// Created by Ari on 3/22/17.
// Represents one color (for each a vertex or an edge)
//

#ifndef HW5_COLOR_H
#define HW5_COLOR_H
#include <sstream>

class Color {
public:
    /**
     * Construct the #theColor -th color
     * @param theColor An index of the color among a list of possible colors.
     */
    Color(int theColor=0) : myColor(theColor) {}
    bool operator==(const Color &other) const { return myColor==other.myColor; }

    // friends
    /**
     * Prints a human-readable version of the vertex onto the output stream
     */
    friend std::ostream & operator<<(std::ostream& stream, const Color& col);

 private:
    Color(); // no default constructor
    int myColor;
};
#endif //HW5_COLOR_H
