#include "colors.inc"

background {
    rgb<1,1,1>
}

camera {
    location <0,3,-5>
    look_at <0,0,0>
}

light_source {
    <2,5,-3>        // location
    rgb <1,1,1>
}

#declare brickTexture =
    pigment { 
        brick
        color White
        color Red
        scale 0.01
        warp {
            spherical 
            orientation <1,0,0>
        }
        turbulence .1 
    };

#declare checkerPigment =
    pigment {
        checker
        color Green
        color White
        scale .05
        warp {
            cylindrical
            orientation <0,0,1>
        }
    };

#declare hexagonPigment =
    pigment {
        hexagon
        color Blue
        color Red
        color White

        warp {
            toroidal
            orientation <0,1,0>
        }
    }

sphere {
    <0,0,0>
    1

    texture { 
        pigment { brickTexture } 
    }
}

cylinder {
    <2,0,0>
    <2,1,0>
    1

    texture {
        pigment { checkerPigment }
    }
}

torus {
    .75, .4 

    texture {
        pigment { hexagonPigment }
    }

    translate <-2.5,0,0>
}
