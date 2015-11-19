/*
    texturess.inc
    2015 October 8
    Brendon Walter

    Textures for everything in the cistern
*/


#declare roomTexture =
    texture {
		uv_mapping

        pigment {
            image_map { jpeg "textureImages/Seamless_Texture_18_by_AGF81.jpg" }
			scale 0.1
        }

    };

#declare colTexture =
    texture {
        pigment { 
            image_map { jpeg "textureImages/concrete-scarpa-bologna.jpg" }
            scale 6 
            warp { cylindrical }
        }
    };

#declare ceilingTexture =
	texture {
		pigment {
			image_map { jpeg "textureImages/brick.jpg" }
			rotate <90, 0, 0>
		}
	};

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
