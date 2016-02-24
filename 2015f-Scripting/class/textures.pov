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

sphere {
    <0,0,0>
    3
    texture {
        pigment { rgb <1,0,0> }
        finish {
            ambient .05
            diffuse .6
            specular .6
            roughness .1
        }
    }
}
