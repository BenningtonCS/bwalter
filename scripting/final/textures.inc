/*
    texturess.inc
    2015 October 8
    Brendon Walter

    Textures for everything in the cistern
*/


#declare roomTexture =
    texture {
        pigment {
            rgb <1,.9,.8>
//            image_map { jpeg "textureImages/rough-stone-wall.jpg" } 
        }
        normal { bumps .3 scale .03 }
    };

#declare colTexture =
    texture {
        pigment { 
            image_map { jpeg "textureImages/concrete-scarpa-bologna.jpg" }
            scale 5
            warp { cylindrical }
        }
        normal { bumps .3 scale .03 }
    }

