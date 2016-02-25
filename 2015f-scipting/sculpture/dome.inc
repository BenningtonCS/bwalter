/*
    dome.inc
    2015 September 20
    Brendon Walter

    include file for the dome stucture

*/

#declare wallHeight = 10;       // height of the walls
#declare domeRadius = 15;       // radius of the building
#declare aperatureRadius = 6;   // radius of the aperature

/*
    The aperature is the hole in the top of the dome
*/
#declare aperature =
    cylinder {
        <0, wallHeight, 0>
        <0, wallHeight + domeRadius, 0>
        aperatureRadius
        open
    };

#declare walls =
     cylinder {
         <0, 0, 0>
         <0, wallHeight, 0>
         domeRadius
         open
     };

/*
    Create the dome 
*/
#declare dome =
    difference {
        difference {
            // cut the sphere in half to make the dome
            difference {
                sphere {
                    <0, wallHeight, 0>
                    domeRadius
                }

                cylinder {
                    <0, wallHeight, 0>
                    <0, wallHeight - domeRadius, 0>
                    domeRadius
                    open
                }
            
            }
            // cut out the aperature
            object { aperature }
        }
        // remove aperature leftovers
        object { aperature }
    };

/*
    Combine the dome with the walls
*/
#declare building =
    union {
        object { dome }
        object { walls }
    };
