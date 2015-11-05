//----------------------------------------------
//--Exported with POV-Ray exporter for Blender--
//----------------------------------------------

#version 3.7;

//--Global settings--

global_settings {
    assumed_gamma 1.0
    max_trace_level 4
    ambient_light rgbt<0, 0, 0,1>
}

//--Custom Code--

#declare CURFRAMENUM = 1;
//#include "/home/user/directory/animation_include_file.inc"

//--Patterns Definitions--


 #declare PAT_Tex = 
pigment {
}

#declare fPAT_Tex=
function{pigment{PAT_Tex}}



//--Background--

background {rgbt<0.0509, 0.0509, 0.0509, 0>}

//--Cameras--

#declare camLocation  = <7.481132, 5.343666, 6.507640>;
#declare camLookAt = <-27.098163, 46.688390, -0.903519>;
camera {
    location  <0, 0, 0>
    look_at  <0, 0, -1>
    right <-1.7777777777777777, 0, 0>
    up <0, 1, 0>
    angle  49.134343
    rotate  <-27.098163, 46.688390, -0.903519>
    translate <7.481132, 5.343666, 6.507640>
}

//--Lamps--

light_source {
    < 0,0,0 >
    color rgb<2, 2, 2>
    fade_distance 14.999991
    fade_power 2
    matrix <-0.290865, -0.055189, -0.955171,  -0.771101, 0.604525, 0.199883,  0.566393, 0.794672, -0.218391,  4.076245, 5.903862, -1.005454>
}
#declare lampTarget1= vrotate(<-4.076,-1.005,-5.904>,<0.6503,0.05522,1.866>);

//--Material Definitions--

#default{ pigment{ color rgb 0.8 }}
#declare shader_ = finish {  //translation of spec and mir levels for when no map influences them
    diffuse 0.8
    phong 70.0
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
    texture_list {
        1