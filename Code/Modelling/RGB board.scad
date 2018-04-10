//RGB
RGBlength = 20.44;
RGBdiameter = 2.9;
RGBradius = RGBdiameter/2;
RGBA = 12.5;
RGBdistance = RGBA/2;
RGBB = 1.0;

//RGB attachment
RAwidth = RGBlength; //y-axis
RAheight = 15.0;  //z-axis
RAdepth = 5.0; //x-axis

//RGB board
RBwidth = RAwidth; //y
RBdepth = RAdepth; //x
RBheight = 40.0;  //depending on the desired distance between RGB and the ground. z

//the part that's attached to the RGB
RB2height = RBdepth; //z
RB2length = 20.0; //x. depending on the distance
RB2width = RBwidth; //y

module cube_true(x, y, z){
    cube(size = [x, y, z], center = true);
}

module cylinder_base(x,y){
    cylinder(h=x,r=y,center=true,$fn=50);
}

difference(){
    union(){
    cube_true(RBdepth,RBwidth,RBheight);
    translate([RBdepth/2+RB2length/2,0,-RBheight/2+RB2height/2]) cube_true(RB2length,RB2width,RB2height);
    }
    translate([RB2length-RGBB-RGBradius,RGBdistance+RGBradius,-RBheight/2+RB2height/2])cylinder_base(RB2height,RGBradius);
    mirror([0,1,0]) translate([RB2length-RGBB-RGBradius,RGBdistance+RGBradius,-RBheight/2+RB2height/2])cylinder_base(RB2height,RGBradius);
}

