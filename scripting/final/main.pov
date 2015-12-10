/*
    main.pov
    2015 October 4
    Brendon Walter

    Final project for Scripting for Computer Graphics

    Model of the Basilica Cistern in Istanbul, Turkey. From wikipedia: "This 
    cathedral-size cistern is an underground chamber approximately 138 metres
    by 64.6 meters - about 9,800 square metres in area - capable of holding 
    80,000 cubic metres of water. The ceiling is supported by a forest of 336
    marble columns, each 9 metres high, arranged in 12 rows of 28 columns each 
    spaced 4.9 metres apart. The capitals of the columns are mainly Ionic and
    Corinthian styles, with the exception of a few Doric style with no 
    engravings."

    There are a few unique columns - namely the hens eye and the two sitting
    on top of Medusa heads - which are not present in this model. There is also
    a wooden boardwalk going through the cistern which is not modeled either.
 */

#version 3.7;

#include "rad_def.inc"
#include "textures.inc"
#include "cistern.inc"

global_settings {
	radiosity {
		Rad_Settings(Radiosity_Default, off, off)
	}
}

#declare singleColumnView = <15,5,5>;
#declare centerRoomView = <roomWidth/2, 1, roomLength/2>;
#declare endRoomView = <1, 5, roomLength/2 - 1>;

background {
    rgb<1,1,1>
}

camera {
// camera position 1
	location endRoomView
	look_at <roomWidth, 1, 0>

// camera position 2
/*
	location centerRoomView
	look_at <0, 1, 0>
*/

// camera position 3
/*
	location centerRoomView
	look_at <roomWidth, 30, 0>
*/

// camera position 4
/*
	location endRoomView
	look_at <roomWidth, 5, 0>

	angle 60
	focal_point <10, 5, roomLength/2>  
	aperture .2
	blur_samples 10 
*/

// camera position 5
/*
	location <2, colHeight+1, roomLength/2-1>
	look_at <roomWidth, 0, 0>	
*/
}

/*
light_source {
	centerRoomView
	rgb <1,1,1> *.5
}
*/
object { room }
object { roomLights } 
object { columns }
object { water }
