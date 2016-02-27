//==================================================
#declare Cherries1_ColorMap = color_map {
    [0.0 color rgb <.9, .1, .1> ]
    [0.5 color rgb <.9, .1, .1> ]
    [0.5 color rgb <.5, .27, .01> ]
};

#declare Cherries1_MappedPigment = pigment { 
    gradient y 
    color_map { Cherries1_ColorMap }
};

#declare Cherries1_Finish = finish {
	specular 0.8 //Max highlight intensity: 0 -> 1
    roughness 0.05 //surface roughness: 0.0005 -> 1             
};

#declare Cherries1_Material_ = material {
	texture {
		pigment { uv_mapping Cherries1_MappedPigment }
		finish { Cherries1_Finish }
	}
}
//==================================================
#declare Cherries2_ColorMap = color_map {
    [0.0 color rgb <.5, 0, .1> ]
    [0.5 color rgb <.5, 0. .1> ]
    [0.5 color rgb <.5, .27, .01> ]
}

#declare Cherries2_MappedPigment = pigment { 
    gradient y
    color_map {Cherries2_ColorMap }
};

#declare Cherries2_Finish = finish {
	specular 0.8 //Max highlight intensity: 0 -> 1
      roughness 0.05 //surface roughness: 0.0005 -> 1             
};

#declare Cherries2_Material_ = material {
	texture {
		pigment { uv_mapping Cherries2_MappedPigment }
		finish { Cherries2_Finish }
	}
}
//==================================================
#declare Plate_MappedPigment = pigment { color rgbf <1,1,1, .8> }

#declare Plate_Finish = finish {
	specular 1 //Max highlight intensity: 0 -> 1
    roughness .05 //surface roughness: 0.0005 -> 1            
    reflection 0.1 
};

#declare Plate_Material_ = material {
	texture {
		pigment { uv_mapping Plate_MappedPigment }
		finish { Plate_Finish }
	}
    interior { ior 1.5 }
}
//==================================================
#declare GrapeStem_MappedPigment = pigment { color rgb <.5,.27,.01> }

#declare GrapeStem_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
      roughness 0.1 //surface roughness: 0.0005 -> 1             
};

#declare GrapeStem_Material_ = material {
	texture {
		pigment { uv_mapping GrapeStem_MappedPigment }
		finish { GrapeStem_Finish }
	}
}
//==================================================
#declare Sheet_MappedPigment = pigment { color rgb <0.60,0.20,0.34> }

#declare Sheet_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
      roughness 0.1 //surface roughness: 0.0005 -> 1             
};

#declare Sheet_Material_ = material {
	texture {
		pigment { uv_mapping Sheet_MappedPigment }
		finish { Sheet_Finish }
	}
}

//=================================================
#declare Plum_ColorMap = color_map {
    [0.1 color rgb <0.62, 0.17, 0.42>*.2 ]
    [0.5 color rgb <0.62, 0.15, 0.42>*.8]
};

#declare Plum_MappedPigment = pigment { 
    gradient y 
    color_map { Plum_ColorMap }
};

#declare Plum_Finish = finish {
    specular 0.8
    roughness 0.05
};

//==================================================
#declare Plum1_Material_ = material {
	texture {
		pigment { uv_mapping Plum_MappedPigment }
		finish { Plum_Finish }
	}
}
//==================================================
#declare Plum2_Material_ = material {
	texture {
		pigment { uv_mapping Plum_MappedPigment }
		finish { Plum_Finish }
	}
}
//==================================================
#declare Plum3_Material_ = material {
	texture {
		pigment { uv_mapping Plum_MappedPigment }
		finish { Plum_Finish }
	}
}
//==================================================
#declare Plum4_Material_ = material {
	texture {
		pigment { uv_mapping Plum_MappedPigment }
		finish { Plum_Finish }
	}
}
//==================================================
#declare Plum5_Material_ = material {
	texture {
		pigment { uv_mapping Plum_MappedPigment }
		finish { Plum_Finish }
	}
}
//==================================================
#declare Plum6_Material_ = material {
	texture {
		pigment { uv_mapping Plum_MappedPigment }
		finish { Plum_Finish }
	}
}
//==================================================
#declare Orange_MappedPigment = pigment { color rgb <1,.5,.1> }

#declare Orange_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
      roughness 0.1 //surface roughness: 0.0005 -> 1             
};

#declare Orange_Material_ = material {
	texture {
		pigment { uv_mapping Orange_MappedPigment }
		finish { Orange_Finish }
	}
}
//==================================================
#declare OrangeStem_MappedPigment = pigment { color rgb <0.20,0.86,0.40> }

#declare OrangeStem_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
      roughness 0.1 //surface roughness: 0.0005 -> 1             
};

#declare OrangeStem_Material_ = material {
	texture {
		pigment { uv_mapping OrangeStem_MappedPigment }
		finish { OrangeStem_Finish }
	}
}
//==================================================
#declare Pear_MappedPigment = pigment { color rgb <0.62,.46,.15> }

#declare Pear_Finish = finish {
	specular 0.6 //Max highlight intensity: 0 -> 1
      roughness 0.1 //surface roughness: 0.0005 -> 1             
};

#declare Pear_Material_ = material {
	texture {
		pigment { uv_mapping Pear_MappedPigment }
		normal { bumps 0.05 scale 0.05 }
        finish { Pear_Finish }
	}
}
//==================================================
#declare LeftGrapeStems_MappedPigment = pigment { color rgb <.5,.27,.01> }

#declare LeftGrapeStems_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
    roughness 0.01 //surface roughness: 0.0005 -> 1             
};

#declare LeftGrapeStems_Material_ = material {
	texture {
		pigment { uv_mapping LeftGrapeStems_MappedPigment }
		finish { LeftGrapeStems_Finish }
	}
}
//==================================================
#declare LeftGrapes_MappedPigment = pigment { color rgb <0.5,0.1,0.2>*1.5 }

#declare LeftGrapes_Finish = finish {
	specular 0.8 //Max highlight intensity: 0 -> 1
      roughness 0.05 //surface roughness: 0.0005 -> 1             
};

#declare LeftGrapes_Material_ = material {
	texture {
		pigment { uv_mapping LeftGrapes_MappedPigment }
		finish { LeftGrapes_Finish }
	}
}
//==================================================
#declare Apple_ColorMap = color_map {
    [0.0 color rgb <0.83, 0.49, 0.28>]
    [0.6 color rgb <0.94, 0.05, 0.20>]
    [0.85 color rgb <0.94, 0.05, 0.20>]
    [0.9 color rgb <0.83, 0.76, 0.28> ]
};

#declare Apple_MappedPigment = pigment {
    gradient x
    turbulence 0.3 
    color_map { Apple_ColorMap }
}

#declare Apple_Finish = finish {
    reflection .02
    diffuse albedo .5
	specular 0.8 //Max highlight intensity: 0 -> 1
    roughness 0.05 //surface roughness: 0.0005 -> 1             
};

#declare Apple_Material_ = material {
	texture {
		pigment { uv_mapping Apple_MappedPigment }
		finish { Apple_Finish }
	}
}
//==================================================
#declare RightGrapes_MappedPigment = pigment { color rgb <.69,.83,.22> }

#declare RightGrapes_Finish = finish {
	specular 0.8 //Max highlight intensity: 0 -> 1
      roughness 0.05 //surface roughness: 0.0005 -> 1             
};

#declare RightGrapes_Material_ = material {
	texture {
		pigment { uv_mapping RightGrapes_MappedPigment }
		finish { RightGrapes_Finish }
	}
}
//==================================================
#declare RightGrapeStems_MappedPigment = pigment { color rgb <0.46,0.81,0.63> }

#declare RightGrapeStems_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
      roughness 0.1 //surface roughness: 0.0005 -> 1             
};

#declare RightGrapeStems_Material_ = material {
	texture {
		pigment { uv_mapping RightGrapeStems_MappedPigment }
		finish { RightGrapeStems_Finish }
	}
}
//==================================================
#declare AppleLeaf_MappedPigment = pigment { color rgb <.2,.6,.2> }

#declare AppleLeaf_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
    roughness .5 //surface roughness: 0.0005 -> 1             
};

#declare AppleLeaf_Material_ = material {
	texture {
		pigment { uv_mapping AppleLeaf_MappedPigment }
		finish { AppleLeaf_Finish }
	}
}
//==================================================
#declare AppleStem_MappedPigment = pigment { color rgb <0.40,0.75,0.21> }

#declare AppleStem_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
      roughness 0.1 //surface roughness: 0.0005 -> 1             
};

#declare AppleStem_Material_ = material {
	texture {
		pigment { uv_mapping AppleStem_MappedPigment }
		finish { AppleStem_Finish }
	}
}
//==================================================
#declare Banana_ColorMap = color_map {
    [0.0 color rgb <0.5, 0.27, 0.01> ]
    [0.05 color rgb <0.5, 0.27, 0.01> ]
    [0.05 color rgb <0.98, .8, .13> ]
    [0.83 color rgb <0.98, .8, .13> ]
    [0.86 color rgb <0.3, 0.42, 0.02> ]
    [0.98 color rgb <0.5, 0.27, 0.01> ]
    [1 color rgb <0.5, 0.27, 0.01> ]
    
};

#declare Banana1_MappedPigment = pigment { 
    gradient y
    color_map { Banana_ColorMap }
};

#declare Banana1_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
      roughness 0.1 //surface roughness: 0.0005 -> 1             
};

#declare Banana1_Material_ = material {
	texture {
		pigment { uv_mapping Banana1_MappedPigment }
		finish { Banana1_Finish }
	}
}
//==================================================
#declare Banana2_MappedPigment = pigment {
    gradient y
    color_map { Banana_ColorMap }
}; 

#declare Banana2_Finish = finish {
	specular 0.5 //Max highlight intensity: 0 -> 1
      roughness 0.1 //surface roughness: 0.0005 -> 1             
};

#declare Banana2_Material_ = material {
	texture {
		pigment { uv_mapping Banana2_MappedPigment }
		finish { Banana2_Finish }
	}
}//==================================================
