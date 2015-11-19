/*
    columns.inc
    2015 October 4
    Brendon Walter

    Include file for the columns in the cistern.
*/

#include "corinthianCapital.inc"

// variables for the two spotlights on each column
#declare lightIntensity = .8;
#declare lightToColDistance = .3;
#declare lightAngledHeight = 2;     // how high up the column it looks

// variables for the column
#declare colHeight = 9;
#declare colRadius = .6;
#declare colSpacing = 4.9 + colRadius;	// also in cistern.inc

// variables for the column capital
#declare colCapHeight = 1.5; 
#declare colCapRadius = colRadius+.3;

// where the column meets the ceiling
#declare colCeiling =
	union {
		// create arches
		difference {
			box {
				<-colSpacing/2, colHeight, colSpacing/2>
				<colSpacing/2, colHeight+3, -colSpacing/2>
			}
			sphere {
				<colSpacing/2, colHeight, colSpacing/2>
				colSpacing/2.2
			}
			sphere {
				<-colSpacing/2, colHeight, colSpacing/2>
				colSpacing/2.2
			}
			sphere {
				<-colSpacing/2, colHeight, -colSpacing/2>
				colSpacing/2.2
			}
			sphere {
				<colSpacing/2, colHeight, -colSpacing/2>
				colSpacing/2.2
			}
			union {		// cut out cylinders to create arch
				cylinder {
					<-colSpacing/2, colHeight, colSpacing/2>
					<colSpacing/2, colHeight, colSpacing/2>
					colSpacing/3
					open
				}
				cylinder {
					<colSpacing/2, colHeight, colSpacing/2>
					<colSpacing/2, colHeight, -colSpacing/2>
					colSpacing/3
					open
				}
				cylinder {
					<-colSpacing/2, colHeight, -colSpacing/2>
					<colSpacing/2, colHeight, -colSpacing/2>
					colSpacing/3
					open
				}
				cylinder {
					<-colSpacing/2, colHeight, colSpacing/2>
					<-colSpacing/2, colHeight, -colSpacing/2>
					colSpacing/3
				}
			}
		}
		texture { ceilingTexture }
	};

// spot lights illuminating each column
#declare colSpotLight =
     light_source {
        <0, 0, 0>
        rgb <1,.85,.6> * lightIntensity 
        spotlight
        point_at <0, lightAngledHeight, 0>
        radius 15 
        falloff 20
        fade_distance 4 
        fade_power 4
        };

// column with spotlights and capital, but not connected to ceiling
#declare colBase =
    union {
		// captial
        object { 
			corinthianCapital 
			scale <.8, .6, .8>
			translate <0, colHeight-.7, 0>
		}
		// column body
        cylinder {
            <0,0,0>
            <0,colHeight,0>
            colRadius
        }
		// spotlights
        light_source {
            colSpotLight
            translate <colRadius+lightToColDistance, 0, 0>
        }
        light_source {
            colSpotLight
            translate <-colRadius-lightToColDistance, 0, 0>
        }
		// set texture for column
        texture { colTexture }
    };

// full column, connected to ceiling
#declare column =
	union {
		object { colCeiling }
		object { colBase }
	};	
