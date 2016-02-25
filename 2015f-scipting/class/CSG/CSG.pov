#declare FrontCameraPos = <0,0,-10>;
#declare SideCameraPos = <0, 10, 0>;

background {
    rgb <0,1,1>
}

camera {
    location SideCameraPos
    look_at <0,0,0>
}

light_source {
    <2,2,-2>
    rgb <1,1,1>
}

#declare Ball = sphere {
    <0,0,0>
    2
};

#declare SolidBlue = texture {
    pigment {
        rgbf <0,0,1, 0.5>
    }
};

#declare SolidRed = texture {
    pigment {
        rgbf <1,0,0, 0.5>
    }
};

difference {
    object {
        Ball
     texture { SolidBlue }
    }

    object {
        Ball
        translate <1,0,0>
        texture { SolidRed }
    }
}
