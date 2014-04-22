#include <math.h>
float p[20][2];
int pos;
int max_pos;
float distance;
float Kp;
float rudder_angle;

void setup()
{
   max_pos=10;
   pos=0;
   p[0][0] = get_X_GPS();
   p[0][1] = get_Y_GPS();
   //user input corrdinates   
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  while(pos<max_pos){
    
    rudder_angle = control(p[pos+1][0],p[pos+1][1]); //float control(float dest_x,float dest_y)
   
    if(distance < 5){
      pos++;
    }
  }
  
  //gohome
  while(distance>1){
    rudder_angle = control(p[0][0],p[0][1]);
   
  }
  
  while(true){}
 
}

float control(float dest_x,float dest_y){
  
  float current_pos[2];
  float current_dir;
  float beta;
  float alpha;
  float theta;
  float rudder;
  
  //getting current position
    current_pos[0] = get_X_GPS();
    current_pos[1] = get_Y_GPS();
    
    distance = sqrt(pow(dest_x-current_pos[0],2)+pow(dest_y-current_pos[1],2));    
 
    //calculate beta
    current_dir = get_Dir();
    beta = current_dir;
    //calculate alpha
    alpha=atan((dest_y-current_pos[1])/(dest_x-current_pos[0]));// atan((y1-y0)/(x1-x0))
    //calculate theta
    theta = alpha-beta; 
    //control algorithm
    rudder = Kp * theta;  
    return rudder;
}

float get_X_GPS(){
  float x;
  return x;
}
float get_Y_GPS(){
  float y;
  return y;
}
float get_Dir(){
  float dir;
  return dir;
}
