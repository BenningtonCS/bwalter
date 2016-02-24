background {
    rgb<.9, .9, .9>
}

camera {
    location <0,10, -20>
    look_at <0,0,0>
}

light_source {
    <2,10,-3>        // location
    rgb <1,1,1>
}

box {
	<-10, 0, 10>
	<10, 1, -10>

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

	interior { ior 1.3 }

}
