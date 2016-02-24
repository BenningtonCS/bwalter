background {
    rgb<1,1,1>
}

camera {
    location <0,3,-10>
    look_at <0,0,0>
}

light_source {
    <2,5,-3>        // location
    rgb <1,1,1>
}

plane {
    <0, 1, 0>       // normal vector
    0               // distance from origin

    texture {
        pigment {  rgb <1,1,1> }
    }
}
