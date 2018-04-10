//Camera Attachment
CAdiameter = 5.0;
CAradius = CAdiameter/2;
CAlength = 30.0;

//Camera Board
CamDistance1 = 3.175;
CamDistance2 = 3.81;
CamDistance3 = 12.7;
CamDistance4 = 10.414;
CamHeight = 50.8; //z
CamHeight2 = 44.45;
CamLength = 53.848; //y
CamWidth = 4.0; //x
CamHoleDiameter = 3.048;
CamHoleRadius = CamHoleDiameter/2;

module cube_true(x, y, z){
    cube(size = [x, y, z], center = true);
}

module cylinder_base(x,y){
    cylinder(h=x,r=y,center=true,$fn=50);
}

module cylinder_base2(){
    rotate([0,90,0])
    cylinder(h=CamWidth,r=CamHoleRadius,center=true,$fn=50);
}

module camera_board(){
    translate([CAlength/2,0,0])
    difference(){
        cube_true(CamWidth,CamLength,CamHeight);
        //hole:top left
        translate([0,CamDistance4,CamHeight/2-CamDistance1]) cylinder_base2();
        //hole:top right
        mirror([0,1,0]) translate([0,CamDistance4,CamHeight/2-CamDistance1]) cylinder_base2();
        //hole: bottom left
        translate([0,CamLength/2-CamDistance1,-CamHeight/2+CamDistance1]) cylinder_base2();
        //hole: bottom right
        mirror([0,1,0]) translate([0,CamLength/2-CamDistance1,-CamHeight/2+CamDistance1]) cylinder_base2();
    }
}

//depending on where we wanna put the camera, board CBheight can be changed. 
CBdistance = CAdiameter;
CBlength = 18.0; //y
CBwidth = CamWidth; //x
CBheight = 30.0; //z

//cylinder extension
CElength = 30.0;
CEradius = CAradius;

difference(){
    cube_true(CamWidth,CamLength,CamHeight);
    cylinder_base2();
}

/*
union(){
    //board!!
    //translate([CAlength/2,0,CBdistance - CBheight/2]) cube_true(CBwidth,CBlength,CBheight);
    //camera board
    translate([0,0,-CBheight]) camera_board();
    rotate([0,90,0]) cylinder_base(CAlength, CAradius);
    //longer cylinder?? depending on where you wanna put the camera
    translate([-CAlength/2,0,0]) rotate([0,90,0]) cylinder_base(CElength,CEradius);
}