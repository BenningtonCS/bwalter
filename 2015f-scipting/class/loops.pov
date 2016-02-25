background {
    rgb<1,1,1>
}

camera {
    location <5,0,-15>
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
            <-1- linkRadius, -1-linkRadius, -linkRadius>
            <1+linkRadius, 0, linkRadius>
        }
    };

#declare linkLength = 4;    // must be > halfLinkWidth
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

object {
    twoLinks 
    texture {
        pigment { rgb<1,0,0> }
    }
}


#declare numLinks = 10;
#declare index = -numLinks/2;
#while (index <= numLinks/2)
    object {
        twoLinks
        translate <0, index*(linkLength*2 - linkRadius), 0>
    }

    #declare index = index + 1;
#end
