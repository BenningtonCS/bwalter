/*
    sculpture.pov
    Brendon Walter
    2015 September
*/

#include "stone.inc"

#include "dome.inc"
#include "spheres.inc"
#include "column.inc"

// camera positions
#declare SphereFocus = <2, .1, 2>;
#declare InsideCameraView = <0,3,-domeRadius+1>;
#declare FarawayCameraView = <0, 1, -40>;
#declare TopView = <0, 50, 0>;

#declare buildingTexture = 
    texture {
        T_Stone2
//        pigment { rgb <1,1,1> }
        normal { bumps 0.1 scale 0.1 }
        finish { phong 1 }
    };

/*
    S C E N E   S E T U P 
*/

background { rgb <1,1,1> }

camera {
    location SphereFocus
//    location InsideCameraView
//    location FarawayCameraView
//    location TopView

    up <1,0,0>
    right<1,0,0>
    look_at <0, 1, 0>
    
    focal_point <0,0,0>
    aperture 0.2
    blur_samples 40
}

// the sun
light_source {
    <5,50,-5>     
    rgb <1,1,1>
}

// light on the inside of the building
light_source {
    InsideCameraView
    rgb <.2,.2,.2>
}

plane {             
    <0,1,0>, 0  
    texture { buildingTexture }
}


/*
    P L A C E   O B J E C T S
*/

// place the building
object {
    building
    texture { buildingTexture }
}

// place the red spheres in the picture
object { sphereTower }

// attempt to place the columns evenly around the dome
#declare theta = 0;
#while (theta < 360)
    object {
        column
        rotate <0, theta, 0>
        translate <domeRadius*sin(theta), 0, domeRadius*cos(theta)>
    }
    #declare theta = theta + 45;
#end
