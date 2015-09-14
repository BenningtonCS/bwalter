/*
    sculpture.pov
    Brendon Walter
    2015 September
*/

// basic colors
#declare SolidRed = pigment { rgb<1,0,0> };
#declare SolidGreen = pigment { rgb<0,1,0> };
#declare SolidBlue = pigment { rgb<0,0,1> };
#declare SolidWhite = pigment { rgb<1,1,1> };
#declare SolidBlack = pigment { rgb<0,0,0> };

// camera positions
#declare InsideCameraView = <0,1,-10>;
#declare FarawayCameraView = <0, 1, -40>;

background {
    rgb <1,1,1>
}

light_source {
    <5, 15,-5>        // location
    rgb <1,1,1>
}

light_source {
    InsideCameraView
    rgb <0.2,0.2,0.2>
}

camera {
    location InsideCameraView
//    location FarawayCameraView
    look_at <0, 4.5, 0>
}


// While loop to make the column of spheres
#declare vertical = 0;      // control vertical rise of spheres
#while (vertical <= 20)

    // create vertical tower of red spheres
    sphere {
        <0, vertical, 3>     // center
        1                    // radius

        texture {
            SolidRed
            finish { 
                phong 1 
                reflection 1
            }
        }
    }

    #declare vertical = vertical+3;
#end

// texture of the building
#declare BuildingTexture = texture {
    SolidWhite
    normal { bumps 0.1 scale 0.1 }
    finish { phong 1 }
};
    
plane {             // floor of room
    <0,1,0>         // normal vector
    0               // distance from origin

    texture { 
        BuildingTexture
    }
}

torus {             // ceiling of room
    12              // major radius
    7.5             // minor radius

    scale<1, .1, 1>
    translate<0,10,3>

    texture {
        BuildingTexture
    }
    
}

cylinder {          // walls of room
    <0, 0, 3>
    <0, 10, 3>
    15
    open

    texture {
        BuildingTexture
    } 
}

