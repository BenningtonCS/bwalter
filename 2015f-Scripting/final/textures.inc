/*
    texturess.inc
    2015 October 8
    Brendon Walter

    Textures for everything in the cistern
*/

// walls of the cistern
#declare roomTexture =
    texture {
		uv_mapping

        pigment {
            image_map { jpeg "textureImages/Seamless_Texture_18_by_AGF81.jpg" }
			scale 0.1
        }
    };

// column texture
#declare colTexture =
    texture {
        pigment { 
            image_map { jpeg "textureImages/concrete-scarpa-bologna.jpg" }
            scale 6
			rotate <0, -90, 0> 
//            warp { cylindrical }
        }
    };

// brick ceiling
#declare ceilingTexture =
	texture {
		pigment {
			image_map { jpeg "textureImages/brick.jpg" }
			rotate <90, 0, 0>
		}
	};

// metal texture of support beams
#declare metalTexture =
	texture {
		pigment {
			image_map { jpeg "textureImages/rustyMetal.jpg" }
		}
	};

// water on the floor of the cistern
#declare waterTexture =
	texture {
	    pigment { rgbt <.95,.95,1, .8> }
    
	    finish {
		    ambient 0
			specular 0.3
	        roughness 0.005
		    reflection {
			    0, 1
	            fresnel on
		    }
	    }

		normal { bumps 0.1 scale 0.3 }
	};
