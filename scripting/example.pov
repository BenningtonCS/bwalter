background {
    rgb<0,1,1>
}

camera {
    location <0,3,-10>
    look_at <0,0,0>
}

light_source {
    <2,5,-3>    // location
    rgb <1,1,1>
}

plane {
    <0, 1, 0>   // normal vector
    0           // distance from origin

    texture {
        pigment {
            rgb <1,1,1>
        }
    }
}

/*
sphere {
    <0,2.5,0>     // center
    1           // radius

    texture {
        pigment {
            rgb <1,0,1>
        }
    }
}
*/

box {
    <-3, 0, -1> //near lower left
    <-1, 2, 1>  // far upper right
    texture {
        pigment {
            rgb<1,0,0>
        }
    }
}

box {
    <-1, 0, -1> // near lower left corner
    <1, 2, 1>   // far upper right corner

    texture {
        pigment {
            rgb <0,1,0>
        }
    }
}

box {
    <1, 0, -1>
    <3, 2, 1>

    texture {
        pigment {
            rgb <0,0,1>
        }
    }
}


/*
cone {
    <0,1,0>     // point 1
    0.3         // radius of point 1
    <1,2,3>     // point 2
    1           // radius of point 2

    texture {
        pigment {
            rgb <0, 1, 0>
        }
    }
}

torus {
    4           // outer radius
    1           // inner radius

    texture {
        pigment {
            rgb <0, 1, 0>
        }
    }
}
*/
