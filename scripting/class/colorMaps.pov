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

#declare colorMap = color_map {
    [0.1 color Red]
    [0.2 color Orange]
    [0.3 color Yellow]
    [0.4 color Green]
    [0.5 color Blue]
    [0.6 color Purple]
}

sphere {
    <0,0,0>
    1

    texture {
        pigment { }
    }
}
