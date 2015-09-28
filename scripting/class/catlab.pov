/*
    catlab.pov
    2015 September 24
    
    model of the catlab, done in class.

    all measurements are done in centimeters
 */

#declare roomWidth = 632;
#declare roomLength = 1016;
#declare roomHeight = 335;
#declare halfRoomWidth = roomWidth/2;
#declare halfRoomLength = roomLength/2;

#declare catlab = 
    box {
        <0,0,0>
        <roomWidth, roomHeight, roomLength>
    };


#declare doorWidth = 91;
#declare doorHeight = 236;
#declare doorDepth = 16;
#declare doorDistanceRight = 188;   // distance from the right wall

#declare doorwayCutout = 
    box {
        <0,0.01,-doorDepth>
        <doorWidth, doorHeight, doorDepth>
        translate <roomWidth-doorDistanceRight, 0, roomLength>
    };

#declare windowHeight = 150.5;
#declare windowDistanceFromGround = 89;
#declare windowCutout =
    box {
        <0,0,-doorDepth>
        <roomWidth, windowHeight, doorDepth>
        translate <0, windowDistanceFromGround, 0>
    };

#declare chairWidth = 54;
#declare chairHeight = 81.5;
#declare chairDepth = 54;
#declare chairSeatHeight = 41;

#declare chairBack = 
    box {
        <0,chairSeatHeight,0>
        <chairWidth, chairHeight, 5> 
    };

#declare chairSeat = 
    box {
        <0, chairSeatHeight, 0>
        <chairWidth, chairSeatHeight+5, chairDepth>
    };

#declare chairLeg =
    cylinder {
        <0,0,0>
        <0, chairSeatHeight, 0>
        1
    };  

#declare chair =
    union {
        object { chairBack }
        object { chairSeat }

        // place the four chair legs
        object {
            chairLeg
            translate <chairWidth, 0, 0>
        }
        object {
            chairLeg
            translate <chairWidth, 0, chairDepth>
        }
        object {
            chairLeg
            translate <0, 0, 0>
        }
        object {
            chairLeg
            translate <0, 0, chairDepth>
        }
    
        texture {
            pigment { rgb <.5,.5,.5> } 
        }
    };


#declare seatedEyeHeight = 112;
#declare Margaret = <halfRoomWidth, seatedEyeHeight, 40>;
#declare Justin = <halfRoomWidth, seatedEyeHeight, roomLength>;

camera {
    location <halfRoomWidth, seatedEyeHeight, 200> 
    look_at <halfRoomWidth, seatedEyeHeight, roomLength>
//    look_at <0,0,0>
}

light_source {
    <halfRoomWidth, seatedEyeHeight, halfRoomLength>
    rgb <1,1,1>
}

background { rgb <1,1,1> }

/*
    Create the room
*/
difference {
    object {
        catlab
        scale 1.001
    }
    object { catlab }
    object { doorwayCutout }
    object { windowCutout }

    texture {
        pigment { rgb <1,1,1> }
    }
}

// place the chair
object { 
    chair 
    rotate <0, -135, 0>
    translate <halfRoomWidth, 0, halfRoomLength>
}

object {
    chair
    rotate <0, 180, 0>
    translate <roomWidth-doorDistanceRight-10, 0, roomLength>
}
