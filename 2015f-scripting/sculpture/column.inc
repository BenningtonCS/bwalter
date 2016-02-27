/*
    column.inc
    2015 September 20
    Brendon Walter

    Include file for the column structure
*/

#declare colHeight = 10;
#declare colRad = 1;

#declare column = 
    union {
        // top
        box {
            <-colRad, colHeight, colRad>
            <colRad, colHeight+colHeight/20, -colRad>
             texture {
                pigment { rgb <1,1,1> }
            }   
        }

        // center
        cylinder {
            <0,0,0>
            <0,colHeight,0>
            colRad
            texture {
                pigment { rgb <1,1,1> }
            }
        }

        // base
        box {
            <-colRad, 0, colRad>
            <colRad, colHeight/20, -colRad>
            texture {
                pigment { rgb <1,1,1> }
            }
        }
    };
