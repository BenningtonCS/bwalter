//----------------------------------------------
//--Exported with POV-Ray exporter for Blender--
//----------------------------------------------

//--Patterns Definitions--

#include "textures.inc"

#declare PAT_Tex = 
pigment {
}

#declare fPAT_Tex=
function{pigment{PAT_Tex}}

//--Material Definitions--

#default{ texture { 
//	colTexture 
	}
}
#declare shader_ = finish {  //translation of spec and mir levels for when no map influences them
    diffuse 0.8
    phong 70.0
}

#declare shader_Material = finish {  //translation of spec and mir levels for when no map influences them
    brilliance 1.8
    phong 0.5
    phong_size 25.2
    diffuse 0.8 0
    ambient 1
    emission 0
    conserve_energy
}


//--Mesh objects--

#declare DATACube =
mesh2 {
    vertex_vectors {
        8,
        <1.000000, 1.000000, -1.000000>,
        <1.000000, -1.000000, -1.000000>,
        <-1.000000, -1.000000, -1.000000>,
        <-1.000000, 1.000000, -1.000000>,
        <0.800000, 0.800000, 1.000000>,
        <0.799999, -0.800001, 1.000000>,
        <-0.800000, -0.800000, 1.000000>,
        <-0.800000, 0.800000, 1.000000>
    }
    normal_vectors {
        6,
        <0.000000, 0.000000, -1.000000>,
        <-0.995037, 0.000000, 0.099504>,
        <0.000000, -0.000000, 1.000000>,
        <0.000000, 0.995037, 0.099504>,
        <0.995037, -0.000000, 0.099504>,
        <-0.000000, -0.995037, 0.099504>
    }

	face_indices {
		12,
	    <0,1,2>, 
		<0,2,3>,
	    <4,7,6>,
		<4,6,5>,
	    <0,4,5>,
		<0,5,1>,
	    <1,5,6>,
		<1,6,2>,
	    <2,6,7>,
		<2,7,3>,
	    <4,0,3>,
		<4,3,7>
	}
	normal_indices {
		12,
	    <0,0,0>,
		<0,0,0>,
	    <2,2,2>,
		<2,2,2>,
	    <4,4,4>,
		<4,4,4>,
	    <5,5,5>,
		<5,5,5>,
	    <1,1,1>,
		<1,1,1>,
	    <3,3,3>,
		<3,3,3>
	}
	radiosity { 
		importance 0.5 
	}
}

#declare DATACube_001 =
mesh2 {
    vertex_vectors {
        8,
        <-1.000000, -1.000000, -1.000000>,
        <-1.000000, -1.000000, 1.000000>,
        <-1.000000, 1.000000, -1.000000>,
        <-1.000000, 1.000000, 1.000000>,
        <1.000000, -1.000000, -1.000000>,
        <1.000000, -1.000000, 1.000000>,
        <1.000000, 1.000000, -1.000000>,
        <1.000000, 1.000000, 1.000000>
    }
    normal_vectors {
        6,
        <-0.000000, 0.000000, -1.000000>,
        <0.000000, -1.000000, -0.000000>,
        <1.000000, 0.000000, -0.000000>,
        <-1.000000, 0.000000, -0.000000>,
        <0.000000, 1.000000, -0.000000>,
        <-0.000000, 0.000000, 1.000000>
    }
    face_indices {
        12,
        <2,0,1>,
        <2,1,3>,
        <3,7,6>,
        <3,6,2>,
        <7,5,4>,
        <7,4,6>,
        <0,4,5>,
        <0,5,1>,
        <0,2,6>,
        <0,6,4>,
        <5,7,3>,
        <5,3,1>
    }
    normal_indices {
        12,
        <3,3,3>,
        <3,3,3>,
        <4,4,4>,
        <4,4,4>,
        <2,2,2>,
        <2,2,2>,
        <1,1,1>,
        <1,1,1>,
        <0,0,0>,
        <0,0,0>,
        <5,5,5>,
        <5,5,5>
    }
    radiosity { 
        importance 0.5 
    }
}

#declare DATACube_002 =
mesh2 {
    vertex_vectors {
        8,
        <-1.000000, -1.000000, -1.000000>,
        <-1.000000, -1.000000, 1.000000>,
        <-1.000000, 1.000000, -1.000000>,
        <-1.000000, 1.000000, 1.000000>,
        <1.000000, -1.000000, -1.000000>,
        <1.000000, -1.000000, 1.000000>,
        <1.000000, 1.000000, -1.000000>,
        <1.000000, 1.000000, 1.000000>
    }
    normal_vectors {
        6,
        <-0.000000, 0.000000, -1.000000>,
        <0.000000, -1.000000, -0.000000>,
        <1.000000, 0.000000, -0.000000>,
        <-1.000000, 0.000000, -0.000000>,
        <0.000000, 1.000000, -0.000000>,
        <-0.000000, 0.000000, 1.000000>
    }
    face_indices {
        12,
        <2,0,1>,
        <2,1,3>,
        <3,7,6>,
        <3,6,2>,
        <7,5,4>,
        <7,4,6>,
        <0,4,5>,
        <0,5,1>,
        <0,2,6>,
        <0,6,4>,
        <5,7,3>,
        <5,3,1>
    }
    normal_indices {
        12,
        <3,3,3>,
        <3,3,3>,
        <4,4,4>,
        <4,4,4>,
        <2,2,2>,
        <2,2,2>,
        <1,1,1>,
        <1,1,1>,
        <0,0,0>,
        <0,0,0>,
        <5,5,5>,
        <5,5,5>
    }
    radiosity { 
        importance 0.5 
    }
}

#declare DATACube_003 =
mesh2 {
    vertex_vectors {
        8,
        <-1.000000, -1.000000, -1.000000>,
        <-1.000000, -1.000000, 1.000000>,
        <-1.000000, 1.000000, -1.000000>,
        <-1.000000, 1.000000, 1.000000>,
        <1.000000, -1.000000, -1.000000>,
        <1.000000, -1.000000, 1.000000>,
        <1.000000, 1.000000, -1.000000>,
        <1.000000, 1.000000, 1.000000>
    }
    normal_vectors {
        6,
        <-0.000000, 0.000000, -1.000000>,
        <0.000000, -1.000000, -0.000000>,
        <1.000000, 0.000000, -0.000000>,
        <-1.000000, 0.000000, -0.000000>,
        <0.000000, 1.000000, -0.000000>,
        <-0.000000, 0.000000, 1.000000>
    }
    face_indices {
        12,
        <2,0,1>,
        <2,1,3>,
        <3,7,6>,
        <3,6,2>,
        <7,5,4>,
        <7,4,6>,
        <0,4,5>,
        <0,5,1>,
        <0,2,6>,
        <0,6,4>,
        <5,7,3>,
        <5,3,1>
    }
    normal_indices {
        12,
        <3,3,3>,
        <3,3,3>,
        <4,4,4>,
        <4,4,4>,
        <2,2,2>,
        <2,2,2>,
        <1,1,1>,
        <1,1,1>,
        <0,0,0>,
        <0,0,0>,
        <5,5,5>,
        <5,5,5>
    }
    radiosity { 
        importance 0.5 
    }
}

#declare corinthianCapital = union {
//----Blender Object Name:OBCube_002----
object { 
    DATACube_002
    matrix <1.129778, 0.000000, 0.000000,  0.000000, -0.000000, -1.138076,  0.000000, 0.050000, -0.000000,  -0.002959, 1.119192, 0.000001>

}
//----Blender Object Name:OBCube_003----
object { 
    DATACube_003
    matrix <0.840000, 0.000000, 0.000000,  0.000000, -0.000000, -0.846969,  0.000000, 0.030000, -0.000000,  -0.002959, -1.042251, 0.000001>

}
//----Blender Object Name:OBCube----
object { 
    DATACube
    matrix <1.000000, 0.000000, 0.000000,  0.000000, -0.000000, -1.000000,  0.000000, -1.000566, 0.000000,  0.000000, 0.000000, 0.000000>

}
//----Blender Object Name:OBCube_001----
object { 
    DATACube_001
    matrix <1.063587, 0.000000, 0.000000,  0.000000, -0.000000, -1.061056,  0.000000, 0.026373, -0.000000,  -0.004498, 1.038818, -0.000000>

}
}