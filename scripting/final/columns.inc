/*
    columns.inc
    2015 October 4
    Brendon Walter

    Include file for the columns in the cistern.
*/

// variables for the two spotlights on each column
#declare lightIntensity = .8;
#declare lightToColDistance = .3;
#declare lightAngledHeight = 2;     // how high up the column it looks

// variables for the column
#declare colHeight = 9;
#declare colRadius = .6;

// variables for the column capital
#declare colCapHeight = 1; 
#declare colCapRadius = colRadius+.4;

#declare colTexture =
    texture {
        pigment { rgb <1,1,1> }
        normal { bumps .3 scale .03 }
    }

#declare colSpotLight =
     light_source {
        <0, 0, 0>
        rgb <1,.85,.6> * lightIntensity 
        spotlight
        point_at <0, lightAngledHeight, 0>
        radius 15 
        falloff 20
        fade_distance 2 
        fade_power 3
        };

#declare colCapital =
    cone {
        <0, colHeight-colCapHeight, 0>, colRadius
        <0, colHeight, 0>, colCapRadius
    };

#declare column =
    union {
        object { colCapital }
        cylinder {
            <0,0,0>
            <0,colHeight,0>
            colRadius
        }
        light_source {
            colSpotLight
            translate <colRadius+lightToColDistance, 0, 0>
        }
        light_source {
            colSpotLight
            translate <-colRadius-lightToColDistance, 0, 0>
        }
        texture { colTexture }
    };
