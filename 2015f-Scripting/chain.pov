background {
    rgb<1,1,1>
}

camera {
    location <5,0,-10>
    look_at <0,0,0>
}

light_source {
    <2,5,-3>        // location
    rgb <1,1,1>
}

#declare linkRadius = 0.3;
#declare halfLinkWidth = 1;
#declare halfTorus = 
    difference {
        torus {
            halfLinkWidth, linkRadius 
            rotate <90, 0, 0>
        }

        box {
            <-1-linkRadius, -1-linkRadius, -linkRadius>
            <1+linkRadius, 0, linkRadius>
        }
    };

#declare linkLength = 3;    // must be > 2*halfLinkWidth
#declare sideLength = linkLength - 2*halfLinkWidth;
#declare halfSideLength = sideLength/2;
#declare linkSide = 
    cylinder {
        <0, halfSideLength, 0>
        <0, -halfSideLength, 0>
        linkRadius
    }

#declare chainlink =
    union {
        object {
            halfTorus
            translate <0, halfSideLength, 0>
        }
    
        object {
            halfTorus
            rotate <180,0,0>
            translate <0, -halfSideLength, 0>
        }

        object {
            linkSide
            translate <halfLinkWidth, 0, 0>
        }
        object {
            linkSide
            translate <-halfLinkWidth, 0, 0>
        }
    };

#declare twoLinks =
    union {
        object {
            chainlink
        }  
        object {
            chainlink
            rotate <0,90,0>
            translate <0, linkLength - 2*linkRadius, 0>
        }
    };

#declare numLinks = 5;

#declare fullChain = 
    union {
        #declare index = -numLinks/2;
        #while (index <= numLinks/2)
            object {
                twoLinks
                translate <0, index*(linkLength*2 - linkRadius*4), 0>
            }

            #declare index = index + 1;
        #end
    };

object {
    fullChain
   
    rotate <45, 30, 0>


    texture {

        pigment { rgb <0.1, 0.1, 0.1> }

        finish {
            phong albedo 1
            phong_size 20 
            reflection {0.3, 1}
        }

    }
}
