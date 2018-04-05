//Robot Servo
RSlength = 41.0;  //x
RSwidth = 36.6;  //not the exact width, y
RSheight = 19.8;
RSdiameter = 5.0;
RSradius = RSdiameter/2;
RSdistance = (RSheight - 2*RSdiameter)/4;
RSA = 7.0;
RSB = 1.5;
RSC = 2.5;
RSD = 4.0;
RSE = 6.5;
RSF = 10.0;

//Servo Attachement
SAlength = 20.0;
SAwidth = RSwidth-RSC-RSD;
SAHwidth = RSF-RSE; //y
SAHlength = RSA;  //x
SAHheight = RSheight;

//Upper Base
UBlength = 150.0; //length is x-axis
UBwidth = 165.0; //y-axis
UBheight = 17.0;
UBgapCam = 12.0;
UBholeGap = 7.0;

LBlength = UBlength;
LBwidth = UBwidth;
LBheight = 7.0;
LBgap1 = 30.0;
LBtranslate = -80.0;

module cube_true(x, y, z){
    cube(size = [x, y, z], center = true);
}

module cylinder_base(x,y){
    cylinder(h=x,r=y,center=true,$fn=20);
}

translate([RSlength/2+SAlength/2,LBwidth/2-SAwidth/2,LBtranslate+LBheight/2+RSheight/2]){
    difference(){
        cube_true(SAlength,SAwidth,RSheight);
        translate([-(SAlength/2-RSA/2), SAwidth/2-RSE/2,0]) cube_true(SAHlength,SAHwidth,SAHheight);
        //holes
        translate([-(SAlength/2-RSradius),0,RSheight/2-RSdistance-RSradius]){
            rotate([90,0,0]) cylinder_base(SAwidth,RSradius);
        }
        translate([-(SAlength/2-RSradius),0,-(RSheight/2-RSdistance-RSradius)]){
            rotate([90,0,0]) cylinder_base(SAwidth,RSradius);
        }
    }
}
