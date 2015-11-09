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
#declare roomHeight = 16;

//column spacing
#declare colRows = 12;
#declare colColumns = 28; 
#declare colSpacing = 4.9; 

// place columns in grid
#declare columns =
    union {
        #declare i = 1;
        #while (i <= colRows)
            #declare j = 1;
            #while (j <= colColumns)
                object {
                    column
                    translate <colSpacing*j, 0, colSpacing*i>
                }
            #declare j = j+1;
            #end 
            #declare i = i+1; 
        #end
    };

#declare wallSconce =
	light_source {
        <0, 0, 0>
        rgb <1,.85,.6> 
        spotlight
        point_at y
        radius 15 
        falloff 20
//        fade_distance 2 
//        fade_power 3
	};

#declare roomLights = 
	union {
		#declare i = 1;
	    #while (i < colRows)
			object { 
				wallSconce
				translate <0, roomHeight/4, colSpacing/2 + colSpacing*i>
			}
			object {
				wallSconce
				translate <roomWidth, roomHeight/4, colSpacing/2 + colSpacing*i>
			}
			#declare i = i+1;
		#end
		
		#declare i = 1;
		#while (i < colColumns)
			object {
				wallSconce
				translate<colSpacing/2 + colSpacing*i, roomHeight/4, 0>
			}		
			object {
				wallSconce
				translate<colSpacing/2 + colSpacing*i, roomHeight/4, roomLength>
			}
			#declare i = i+1;
		#end
	};

#declare room =
    box {
        <0,0,0>
        <roomWidth, roomHeight, roomLength>
        texture { roomTexture }
    };

#declare water =
	box {
		<0, 0, 0>
		<roomWidth, .5, roomLength>

		texture { waterTexture }
		interior { ior 1.3 }
	};
