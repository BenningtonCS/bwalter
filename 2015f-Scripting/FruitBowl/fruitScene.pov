#include "fruitModels.inc" //Geometry

background { color rgb<0,0,0> }

camera {
        location <0,8,-13>
        look_at <0,0,0>  
} 

// key light
light_source {
    <-3,10,-10>
    rgb <1,1,1>
    spotlight
    point_at <0,-1.3,0>
    radius 25
    falloff 35 
}

// fill light
light_source {
    <3,8,-13>
    rgb <1,1,1> * .4
    shadowless
}

object{
      fruit_
      rotate <0,-90,0>
      translate <-2,-1,10> //Moved to center the fruit at <0,0,0>
}
