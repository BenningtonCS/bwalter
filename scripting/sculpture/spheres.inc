/*
    spheres.inc
    2015 September 20
    Brendon Walter
    
    include file for the tower of spheres
*/

#declare num = 10;      // number of spheres
#declare rad = 1;       // radius of spheres
#declare space = 8;     // space between spheres

#declare sphereTower = 
    union {
        #declare index = 0;
        #declare vertical = 0;      // control vertical rise of spheres

        // While loop to make the column of spheres
        #while (index < num)
            // create vertical tower of red spheres
            sphere {
                <0, vertical, 0>, rad

                texture {
                    pigment { rgbf <.8, .1, .1, .8> } 
                } 
                
                finish {
                    phong .9 phong_size 40 
                    reflection 0.5
                }
                interior { ior 1.5 }
            }
            #declare vertical = vertical + space;
            #declare index = index + 1;
        #end
    };
