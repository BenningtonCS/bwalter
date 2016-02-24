/*
    These are from the stones.inc include file from povray. But, there were undeclared terms in that file so it would not compile. I took the parts that I wanted from that file and put them here so that I can actually use them.
*/

//--------- Gray Tan with Rose
#declare T_Grnt0 =
texture {
pigment
 {granite
  turbulence 0.4
  color_map
   {[0.000, 0.153   color rgbt <0.729, 0.502, 0.451, 0.000>
                    color rgbt <0.769, 0.686, 0.592, 0.000>]
    [0.153, 0.398   color rgbt <0.769, 0.686, 0.592, 0.000>
                    color rgbt <0.843, 0.753, 0.718, 0.000>]
    [0.398, 0.559   color rgbt <0.843, 0.753, 0.718, 0.000>
                    color rgbt <0.780, 0.667, 0.561, 0.000>]
    [0.559, 0.729   color rgbt <0.780, 0.667, 0.561, 0.000>
                    color rgbt <0.741, 0.659, 0.576, 0.000>]
    [0.729, 1.001   color rgbt <0.741, 0.659, 0.576, 0.000>
                    color rgbt <0.729, 0.502, 0.451, 0.000>]
   }
 }
 }

//-----Translucent T_Grnt7
#declare T_Grnt7a =                                                             
texture {
pigment
 {granite
  turbulence 0.6
  color_map
   {[0.000, 0.119   color rgbt <0.439, 0.310, 0.282, 0.631>
                    color rgbt <0.463, 0.369, 0.259, 0.847>]
    [0.119, 0.322   color rgbt <0.463, 0.369, 0.259, 0.847>
                    color rgbt <0.541, 0.369, 0.298, 0.549>]
    [0.322, 0.449   color rgbt <0.541, 0.369, 0.298, 0.549>
                    color rgbt <0.573, 0.424, 0.286, 0.965>]
    [0.449, 0.729   color rgbt <0.573, 0.424, 0.286, 0.965>
                    color rgbt <0.494, 0.396, 0.306, 0.741>]
    [0.729, 1.001   color rgbt <0.494, 0.396, 0.306, 0.741>
                    color rgbt <0.439, 0.310, 0.282, 0.631>]
   }
 }
 }


#declare T_Stone2 =
texture{T_Grnt0  scale <2, 3, 2> rotate <0, 0, 40>}
texture{T_Grnt7a scale <1.3, 2, 1.3> rotate <0, 0, -30> rotate <40, 0, 0>
        finish{phong 1.0 phong_size 90 ambient 0.2 }
}

