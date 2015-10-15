/*
    camera.pov
    2015 October 15
    
*/

background {
    rgb<1,1,1>
}

camera {
//    orthographic
//    fisheye
    perspective 
    location <0,3,-10>
    look_at <0,0,0>
    angle 90 
}

light_source {
    <2,5,-3>        // location
    rgb <1,1,1>
}

sphere {
    <0,0,0>, 1
    texture {
        pigment { rgb <1,1,1> }
    }
}

cylinder {
    <0, 0, 0>, <0, 5, 0>, 2
    texture {
        pigment { rgb <1,1,1> }
    }

    translate <3, 0, 5>
}
