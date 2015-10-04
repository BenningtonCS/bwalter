#declare lightIntensity = .8;
#declare lightToColDistance = .3;
#declare lightAngledHeight = 2;     // how high up the column it looks
#declare lightRadius = 15;
#declare lightFalloff = 20;

#declare colHeight = 9;
#declare colRadius = .6;

#declare colTexture =
    texture {
        pigment { rgb <1,1,1> }
        normal { bumps .3 scale .03 }
    }

#declare column =
    union {
        cylinder {
            <0,0,0>
            <0,colHeight,0>
            colRadius
            texture { colTexture }
        }

        light_source {
            <colRadius+lightToColDistance, 0, 0>
            rgb <1,.95,.85> * lightIntensity 
            spotlight
            point_at <0, lightAngledHeight, 0>
            radius lightRadius 
            falloff lightFalloff 
        }
        light_source {
            <-colRadius-lightToColDistance, 0, 0>
            rgb <1,.95,.85> * lightIntensity 
            spotlight
            point_at <0, lightAngledHeight, 0>
            radius lightRadius 
            falloff lightFalloff 
        }
    };
