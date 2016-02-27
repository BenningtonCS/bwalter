// variables for the two spotlights on each column
#declare lightIntensity = .8;
#declare lightToColDistance = .3;
#declare lightAngledHeight = 2;     // how high up the column it looks

#declare sconceHeight = 5;	// height of the housing for the lights

// basic housing for the lights
#declare sconce =
    lathe {
        cubic_spline
        7   
        <0,0>, <3,0>, <3, sconceHeight>, 
        <2.5, sconceHeight>, <2.5, .5>, <.5, 0>,                                
        <-1, 0>

        pigment { rgb <.1,.1,.1> }

		scale .05
		rotate z*30
    };

// lights on each wall
#declare wallSconce =
	union {
		light_source {
			<0, .5, 0>
			rgb <1,.85,.6> 
			spotlight
			point_at y
			radius 15 
			falloff 20
	//        fade_distance 2 
	//        fade_power 3
		}
		object { sconce }
	};

// spot lights illuminating each column
#declare colSpotLight =
	union {
		light_source {
			<0, .5, 0>
			rgb <1,.85,.6> * lightIntensity 
			spotlight
			point_at <0, lightAngledHeight, 0>
			radius 15 
			falloff 20
			fade_distance 4 
			fade_power 4
		}
		object { sconce }
    };


