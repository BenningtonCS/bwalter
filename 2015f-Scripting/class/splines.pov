background {
    rgb <.2,.2,.2>
}

camera {
    location <0,10,-12>
    look_at <0,4,0>
}

light_source {
    <20,20,-20>        // location
    rgb <1,1,1>
}

plane {
	<0,1,0>, 0
	texture {
		pigment { rgb <1,1,1> }
	}
}

#declare cup =
	lathe {
		cubic_spline
		10	
		<0,0>, <3,0>, <3,1>, 
		<1,1>, <1,3>, <3,3>, 
		<4,7>, <2,4>, <0,4>, <-1,3>

		pigment { rgbt <1,1,1, .8> }

		finish {
			ambient 0 
			roughness .005
			specular .8
			reflection {
				0.1, 1.0		// min and max reflectivity
				fresnel on
			}
			conserve_energy
		}

		interior { ior 1.5 }
	};

object { cup }
