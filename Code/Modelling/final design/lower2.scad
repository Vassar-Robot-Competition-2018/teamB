//Unit: millimeter
//Arduino board
ABwidth = 53.34;
ABlength = 102;
ABheight = 10.0;
ABplugin1 = 2.1;
ABplugin2 = 7.0;
ABplugin2height = 10.0;
ABgap1=9.0;
ABgap2=12.0;
ABgap3=19.0;
ABgap4=9.0;

//Bread Board
BBlength = 85.0;
BBwidth = 57.0;
BBheight = 10.0;

//RGB
RGBlength = 20.44;
RGBdiameter = 2.9;
RGBA = 12.5;
RGBB = 1.0;

//Upper Base
UBlength = 140.0; //length is x-axis
UBwidth = 140.0; //y-axis
UBheight = 17.0;
UBgapCam = 8.0;
UBgap1 = (UBlength - UBgapCam - ABwidth - BBwidth) / 2;
UBholeGap = 7.0;

//Camera Attachment
CAdiameter = 6.0;
CAradius = CAdiameter/2;
CAlength = 30.0;
//Lower Base
LBlength = UBlength;
LBwidth = UBwidth;
LBheight = 9.0;
LBgap1 = 30.0;
LBtranslate = -(UBheight/2+30.0+LBheight);

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
RAheight = 20.0;  //z-axis
RAdepth = 5.0; //x-axis

//battery hole
BAlength = 5.0; //y
BAheight = 20.0; //z
BAdepth = FWwidth;

//arms attachment
AAlength = 22.0;
AAwidth = 5.0; //y-axis
AAheight = 40.0;
AAdistance = 85.0;
AAtranslate = 20.0;
AAholeHeight = AAheight/2 - (AAtranslate - FWheight/2) + LBheight;

//Columns
Clength = 8.0; 
Cheight = FWheight+10.0;
Cdiameter = 6.0;
Cradius = Cdiameter/2;
CLockHeight = 1.5;
CLockDiameter = 8.0;
Cdistance = 9.0;  //the center of the hole
holeX = UBlength/2 - Cdistance;
holeY = UBwidth/2 - Cdistance;
holeZ = LBtranslate+LBheight/2+Cheight/2;

//Back Wall
BWlength = FWlength;
BWwidth = 5.0;
BWheight = 30.0;

//Robot Servo
RSlength = 40.9;
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
SAwidth = 15.0;
SAHwidth = 4.0; //y
SAHlength = RSA;  //x
SAHheight = RSheight;


module cube_true(x, y, z){
    cube(size = [x, y, z], center = true);
}

module cylinder_base(x,y){
    cylinder(h=x,r=y,center=true,$fn=50);
}

//changing the holes to poles
module pole_base(x,y,z){
    translate([x,y,z])
    cylinder(h=Cheight,r=Cradius,center = true, $fn=50);
}

//front wheels attachement
FWAdiameter = 21.5;
FWAradius = FWAdiameter/2;
FWAheight2 = 2.5;
FWAdistance = 15.0;
FWAholeRadius = 2.0/2;

FWApoleDiameter = 8.0;
FWApoleRadius = FWApoleDiameter/2;
FWApoleheight = 20.0;

hole2X = UBlength/2 - FWAdistance;
hole2Y = UBwidth/2 - FWAdistance;
hole2Z = LBtranslate-LBheight/4;

module front_wheel_holes(){
    translate([hole2X,hole2Y,hole2Z]){
        cylinder_base(LBheight+3.0,FWApoleRadius);
    }
}

module servo_attach(){
    translate([RSlength/2+SAlength/2,LBwidth/2-SAwidth/2,LBtranslate+LBheight/2+RSheight/2]){
        difference(){
            cube_true(SAlength,SAwidth,RSheight);
            translate([-(SAlength/2-RSA/2), SAwidth/2-RSE/2+1.0,0]) cube_true(SAHlength,SAHwidth+2.0,SAHheight);
            //translate([-(SAlength/2-RSA/2)-2.0, SAwidth/2-RSE/2+1.0,0]) cube_true(SAHlength-3.0,SAHwidth+1.0,SAHheight);
            //holes
            translate([-(SAlength/2-RSradius-1.5),0,RSheight/2-RSdistance-RSradius]){
                rotate([90,0,0]) cylinder_base(SAwidth,RSradius);
            }
            translate([-(SAlength/2-RSradius-1.5),0,-(RSheight/2-RSdistance-RSradius)]){
                rotate([90,0,0]) cylinder_base(SAwidth,RSradius);
            }
        }
    }
}


difference(){
        //Lower Base
        union(){
            translate([0,0,LBtranslate]) cube_true(LBlength,LBwidth,LBheight);
            //front wall
            difference(){
                translate([LBlength/2-FWwidth/2,0,LBheight/2+FWheight/2+LBtranslate]) cube_true(FWwidth,FWlength,FWheight);
                //Battery Hole. y can be modified.
                translate([LBlength/2-FWwidth/2,0,LBtranslate+LBheight/2+FWheight]) cube_true(BAdepth, BAlength, BAheight);
            }
            //back wall
            translate([-(LBlength/2-BWwidth/2),0,LBheight/2+BWheight/2+LBtranslate]) cube_true(BWwidth,BWlength,BWheight);
            //servo attachment
            //translate([x,y,z]){} might need to move the servos to left to balance out the weight
            translate([-(UBlength/2-BWwidth-RSlength/2-SAlength),0,0]){
            servo_attach();
            mirror([1,0,0]) servo_attach();
            mirror([0,1,0]) servo_attach();
            mirror([0,1,0]) mirror([1,0,0]) servo_attach();
            }
                
            //poles
            pole_base(holeX,holeY,holeZ);
            pole_base(-holeX,holeY,holeZ);
            pole_base(holeX,-holeY,holeZ);
            pole_base(-holeX,-holeY,holeZ);
        }
        
            //arms attachment
            translate([0,0,-AAtranslate+25.0]){
            translate([LBlength/2-AAlength/2,AAdistance/2+AAwidth/2,LBtranslate+AAheight/2-LBheight/2]) cube_true(AAlength,AAwidth,AAheight-25.0);
            translate([LBlength/2-AAlength/2,-(AAdistance/2+AAwidth/2),LBtranslate-LBheight/2+AAheight/2]) cube_true(AAlength,AAwidth,AAheight-25.0);}
            
            //RGB attachment
            translate([LBlength/2-RAdepth/2-4.0,0,LBtranslate-LBheight/2+RAheight/2-3.2-1.5]) cube_true(RAdepth,RAwidth,RAheight-6.0-3.0);
            translate([LBlength/2-RAdepth/2-4.0,-55.0,LBtranslate-LBheight/2+RAheight/2-3.2-1.5]) cube_true(RAdepth,RAwidth,RAheight-6.0-3.0);
            mirror([0,1,0]) translate([LBlength/2-RAdepth/2-4.0,-55.0,LBtranslate-LBheight/2+RAheight/2-3.2-1.5]) cube_true(RAdepth,RAwidth,RAheight-6.0-3.0);
            
            //front wheels holes
            front_wheel_holes();
            mirror([0,1,0]) front_wheel_holes();
}