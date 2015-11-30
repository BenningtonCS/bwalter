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
	location endRoomView
//    location centerRoomView
//    location singleColumnView
//	location <15, 5, 5>
    look_at <roomWidth, 5, 0>
//	look_at <0, 8, 5>
//	look_at <0, 0, 5>

//	look_at <roomWidth, 10, roomLength/2>

	angle 60

	focal_point <10, 5, roomLength/2>  
	aperture .2
	blur_samples 10 
}

/*
light_source {
    <20, 8, 7>
    rgb <1,1,1> * .5
}
*/
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

/*
object { 
    column 
    translate <5, 0, 5>
}
object {
	column
	translate <5, 0, 5+colSpacing>	
}
*/
