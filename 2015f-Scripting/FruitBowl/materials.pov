#include "colors.inc"

camera {
    location <0,3,-5>
    look_at <0,0,0>
}

background {
    <.2,.2,.2>
}

light_source {
    <3,3,-5>
    <1,1,1>
}

#declare colorMap = 
    color_map {
      [0.1  color Red]
      [0.3  color Yellow]
      [0.4 color Red]
    }

sphere {
    <0,0,0>
    2 
    
    pigment {
        gradient x
        color_map { colorMap }
        turbulence .2
    }
}
