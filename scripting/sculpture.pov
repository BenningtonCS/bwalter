background {
    rgb<1,1,1>
}

light_source {
    <1,8,0>        // location
    rgb<1,1,1>
}

light_source {
    <-1,8,0>        // location
    rgb<1,1,1>
}

camera {
    location <0,1,-10>
    look_at <0, 5, 0>
}

plane {
    <0,1,0>         // normal vector
    0               // distance from origin

    texture {
        pigment {
            rgb<1,1,1>
        }
    }
}

/*
    While loop to generate the central sphere structure
*/
#declare vertical = 0;      // control vertical rise of spheres
//#declare horiz = 0;         // control motion in x, z axes
#while (vertical <= 15)

    // create vertical tower of red spheres
    sphere {
        <0, vertical, 3>     // center
        1                    // radius

        texture {
            pigment { 
                rgb<1,0,0> 
            }

            finish { 
                phong 1 
            }
        }
    }

/*
    // create spiral
    #if (mod(horiz, 2) = 0)
        sphere {
            <mod(horiz, 2), vertical, mod(horiz+1, 2)>
            0.5
            texture {
                pigment {
                    rgb<0,0,1>
                }
                finish {
                    phong 1
                }
            }
        }
    #else
        sphere {
            <-mod(horiz, 2), vertical, -mod(horiz+1, 2)>
            0.5
            texture {
                pigment {
                    rgb<0,0,1>
                }
                finish {
                    phong 1
                }
            }
        }
    #end
*/
    #declare vertical = vertical+2.5;
//    #declare horiz = horiz+1;
#end

torus {
    10             // major radius
    5              // minor radius

    translate<0,10,3>

    texture {
        pigment { 
            rgb<1,1,1> 
        }

        normal {
            bumps 0.9 scale 0.2
        }

        finish {
            phong 1
        }
    }
}
