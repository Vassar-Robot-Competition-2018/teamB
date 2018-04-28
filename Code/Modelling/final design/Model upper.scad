//Unit: millimeter
//Arduino board
ABwidth = 53.7;
ABlength = 102.2;
ABheight = 10.0;
ABplugin1 = 2.1;
ABplugin2 = 7.0;
ABplugin2height = 10.0;
ABgap1=8.5;
ABgap2=13.0;
ABgap3=18.0;
ABgap4=9.5;

//Bread Board
BBlength = 85.2;
BBwidth = 57.2;
BBheight = 10.0;

//RGB
RGBlength = 20.44;
RGBdiameter = 2.9;
RGBA = 12.5;
RGBB = 1.0;


//Upper Base
UBlength = 140.0; //length is x-axis
UBwidth = 140.0; //y-axis
UBheight = 15.0;
UBgapCam = 7.0;
UBgap1 = (UBlength - UBgapCam - ABwidth - BBwidth) / 2;
UBholeGap = 7.0;

//Camera Attachment
CAdiameter = 6.0;
CAradius = CAdiameter/2;
CAlength = 30.0;

//Lower Base
LBlength = UBlength;
LBwidth = UBwidth;
LBheight = 7.0;
LBgap1 = 30.0;
LBtranslate = -60.0;

//Front Wall
FWlength = LBwidth; //y-axis
FWwidth = 25.0;  //x-axis
FWheight = 30.0;
FWhole = 25.0;
FWgap1 = (FWlength - FWhole)/2;  //distance to the gap
FWgap2 = (FWlength - RGBlength)/2;

//RGB
RGBlength = 20.44;
RGBdiameter = 2.9;
RGBA = 12.5;
RGBB = 1.0;

//RGB attachment
RAwidth = RGBlength; //y-axis
RAheight = 15.0;  //z-axis
RAdepth = 5.0; //x-axis

//battery hole
BAlength = 5.0; //y
BAheight = 20.0; //z
BAdepth = FWwidth;

//arms attachment
AAlength = 20.0;
AAwidth = 5.0; //y-axis
AAheight = 40.0;
AAdistance = 90.0;
AAtranslate = 30.0;
AAholeHeight = AAheight/2 - (AAtranslate - FWheight/2) + LBheight;

//Columns
Clength = 8.0; 
Cheight = 11.0;
Cdiameter = 6.0;
Cradius = Cdiameter/2;
CLockHeight = 1.5;
CLockDiameter = 8.0;
Cdistance = 9.0;  //the center of the hole
holeX = UBlength/2 - Cdistance;
holeY = UBwidth/2 - Cdistance;
holeZ = UBheight/2 - UBheight + Cheight - Cheight/2;

//Back Wall
BWlength = FWlength;
BWwidth = 5.0;
BWheight = 30.0;

//Robot Servo
RSlength = 40.6;
RSwidth = 36.6;  //not the exact width
RSheight = 19.8;
RSdiameter = 4.0;
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


module cube_true(x, y, z){
    cube(size = [x, y, z], center = true);
}

module cylinder_base(x,y){
    cylinder(h=x,r=y,center=true,$fn=50);
}

module hole_base(x,y,z){
    translate([x,y,z])
    cylinder(h=Cheight,r=Cradius,center = true, $fn=50);
}

module servo_attach(){
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
}


difference(){
    //combine upper and lower bases
        rotate([0,0,180])
        difference(){
            cube_true(UBlength,UBwidth,UBheight);
            //arduino board
            translate([UBlength/2-ABlength/2-ABplugin2, UBgapCam/2+ABwidth/2,UBheight/4]) cube_true(ABlength,ABwidth,ABheight);
            //plugin1
            translate([UBlength/2-ABplugin2/2, UBgapCam/2+ABgap1+ABgap2/2,UBheight/4]) cube_true(ABplugin2,ABgap2,ABplugin2height);
            //plugin2
            translate([UBlength/2-ABplugin2/2, UBgapCam/2+ABgap1+ABgap2+ABgap3+ABgap4/2,UBheight/4]) cube_true(ABplugin2,ABgap4,ABplugin2height);
            //bread board
            translate([UBlength/2-ABlength/2-ABplugin2,-(UBgapCam/2+BBwidth/2),UBheight/4]) cube_true(BBlength,BBwidth,BBheight);
            //camera attachment
            rotate([0,0,180])
            translate([UBlength/2-CAlength/2,0,0]){
                rotate([0,90,0]) cylinder_base(CAlength, CAradius);
            }
        }
    
    //holes
    hole_base(holeX,holeY,holeZ);
    hole_base(-holeX,holeY,holeZ);
    hole_base(holeX,-holeY,holeZ);
    hole_base(-holeX,-holeY,holeZ);
}