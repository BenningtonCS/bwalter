background {
    rgb<1,1,1>
}

camera {
    location <5,5,-10>
    look_at <0,0,0>
}

light_source {
    <2,5,-3>        // location
    rgb <1,1,1>
}


#declare leaf = 
	mesh {
		triangle {
			<0,0,0>
			<2,4,0>
			<2,3,-1>
		}
		triangle {
			<0,0,0>
			<2,4,0>
			<2,3,1>
		}
		triangle {
			<6,3,0>
			<2,4,0>
			<2,3,1>
		}
		triangle {
			<6,3,0>
			<2,4,0>
			<2,3,-1>
		}
	};


#declare leaf2 =
	mesh2 {
		vertex_vectors {
			5
			<0,0,0>		// 0
			<2,4,0>		// 1
			<2,3,-1>	// 2
			<2,3,1>		// 3
			<6,3,0>		// 4
		}

		face_indices {
			4
			<0,1,2>
			<0,1,3>
			<4,1,2>
			<4,1,3>
		}
	}



union {
	#declare i = 0;
	# while (i < 360)
		object { 
			leaf2
			rotate <0, i, 0>
		}
		object {
			leaf
			scale .8
			rotate <0, 0, 30>
			rotate <0, i+25, 0>
		}
		#declare i = i+50;
	#end

	texture {
		pigment { rgb <.3,.6,.35> }
	}
}
