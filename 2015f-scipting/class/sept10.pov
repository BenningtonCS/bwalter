#declare Box = box {
    <-1, -1, -1>        // first corner 
    <1, 1, 1>          // second corner
};

#declare SolidRed = texture {
    pigment { rgb <1,0,1> }
}

background {
    rgb<0,1,1>
}

camera {
    location <0,3,-10>
    look_at <0,0,0>
}

light_source {
    <2,5,-3>        // location
    rgb <1,1,1>
}

object {
    Box
    scale <1, 2, 1>
    rotate <0, 0, 45>
    translate <0, 0, 1>
    texture { SolidRed }
}
