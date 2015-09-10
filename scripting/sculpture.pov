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

#declare i = 0;
#while (i <= 15)
    sphere {
        <0, i, 3>     // center
        1               // radius

        texture {
            pigment { 
                rgb<1,0,0> 
            }

            finish { 
                phong 1 
            }
        }
    }
    #declare i = i+2.5;
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
