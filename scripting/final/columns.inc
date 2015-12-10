/*
    columns.inc
    2015 October 4
    Brendon Walter

    Include file for the columns in the cistern.
*/

#include "corinthianCapital.inc"
#include "lights.inc"

// variables for the column
#declare colHeight = 9;
#declare colRadius = .6;
#declare colSpacing = 4.9 + colRadius;	// also in cistern.inc

// variables for the column capital
#declare colCapHeight = 1; 
#declare colCapRadius = colRadius+.3;

// where the column meets the ceiling
#declare colArches =
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
	texture { ceilingTexture }
	};


// create metal beams connecting each column to each other
#declare colSupportBeams =
	union {
		cylinder {
			<0, colHeight+.1, 0>
			<colSpacing/2, colHeight+.1, 0>
			0.05
		}
		cylinder {
			<0, colHeight+.1, 0>
			<-colSpacing/2, colHeight+.1, 0>
			0.05
		}

		texture { metalTexture }	
	};

// combine arches with the metal support beams
#declare colCeiling =
	union {
		object { colArches }
		object { colSupportBeams }
		object { 
			colSupportBeams 
			rotate <0, 90, 0>
		}
	};

#declare colCapital =
	object { 
		corinthianCapital 
		scale <.7, .6, .7>
		translate <0, colHeight-2.2, 0>
	};

// column with spotlights and capital, but not connected to ceiling
#declare colBase =
    union {
		// captial
		object { colCapital }
		// column body
        cylinder {
            <0,0,0>
            <0,colHeight,0>
            colRadius
        }
		// column bottom
		box {
			<-colRadius, 0, -colRadius>
			<colRadius, .5, colRadius>
		}
		// spotlights
        light_source {
            colSpotLight
            translate <colRadius+lightToColDistance, .5, 0>
        }
        light_source {
            colSpotLight
            translate <-colRadius-lightToColDistance, .5, 0>
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
