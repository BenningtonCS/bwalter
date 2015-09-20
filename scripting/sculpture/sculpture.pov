/*
    sculpture.pov
    Brendon Walter
    2015 September
*/

#include "dome.inc"
#include "spheres.inc"
#include "column.inc"

// camera positions
#declare InsideCameraView = <0,.1,-domeRadius+1>;
#declare FarawayCameraView = <0, 1, -40>;
#declare TopView = <0, 50, 0>;

#declare buildingTexture = 
    texture {
        pigment { rgb <1,1,1> }
        normal { bumps 0.1 scale 0.1 }
        finish { phong 1 }
    };

background { rgb <1,1,1> }

camera {
    location InsideCameraView
//    location FarawayCameraView
//    location TopView

    up <1.5,0,0>
    right<1,0,0>
    look_at <0, wallHeight, 0>
}

// the sun
light_source {
    <70,90,-70>     
    rgb <1,1,1>
}

// light on the inside of the building
light_source {
    InsideCameraView
    rgb <.2,.2,.2>
}

/*
light_source {
    <0,0,0>
    rgb<.2,.2,.2>
}
*/
plane {             
    <0,1,0>, 0  
    texture { buildingTexture }
}

// place the red spheres in the picture
object { sphereTower }

// place the building
object {
    building
    texture { buildingTexture }
}
