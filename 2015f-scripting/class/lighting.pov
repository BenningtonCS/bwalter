background { rgb<1,1,1> }

camera {
    location <0, 2, -5>
    look_at <0,0,0>
}

/*
// point light
light_source {
    <2, 5, -5>
    rgb <1,1,1>
}
*/

/*
// spot light
light_source{
    <2, 5, -5>
    rgb <1,1,1>
    spotlight
    radius 0
    falloff 90
    tightness 0
    point_at <0,0,0>
}
*/

/*
// directional light
light_source {
    <100,100,-100>
    rgb <1,1,1>
    parallel
    point_at <0,0,0>
}
*/

/*
// area light
light_source {
    <20,20,-20>
    rgb<1,1,1>
    area_light
    <1,0,1>, <0,1,1>    // dimensions 
    4, 4                // number of point lights in it
}
*/

plane {
    <0,1,0>
    0
    texture { 
        pigment {rgb<1,1,1>}
    }
}

sphere {
    <0,1,0>
    1
    texture {
        pigment { rgb <1,0,0> }
    }
}
