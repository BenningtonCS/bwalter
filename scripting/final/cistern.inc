/*
    cistern.inc
    2015 October 4
    Brendon Walter

    Make the cistern
*/

#include "columns.inc"

// all measurements are in meters

// room
#declare roomWidth = 138;
#declare roomLength = 64.6;
#declare roomHeight = 9;

//column spacing
#declare colRows = 12;
#declare colColumns = 28; 
#declare colSpacing = 4.9; 


#declare columns =
    union {
        #declare i = 1;
        #while (i <= colRows)
            #declare j = 1;
            #while (j <= colColumns)
                object {
                    column
                    translate <(colSpacing+colRadius)*j, 
                                0, 
                               (colSpacing+colRadius)*i>
                }
            #declare j = j+1;
            #end 
            #declare i = i+1; 
        #end
    };

#declare room = 
    box {
        <0,0,0>
        <roomWidth, roomHeight, roomLength>
        texture { roomTexture }
    };

