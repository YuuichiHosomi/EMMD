#include <math.h>
float p[20][2];
float beta=0;
float theta=0;
float alpha=0;
int pos;
int max_pos;
float distance;
float current_dir;
float current_pos[2];
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
    
    
    //getting current position
    current_pos[0] = get_X_GPS();
    current_pos[1] = get_Y_GPS();
    
    distance = sqrt(pow(p[pos+1][0]-current_pos[0],2)+pow(p[pos+1][1]-current_pos[1],2));    
 
    //calculate beta
    current_dir = get_Dir();
    beta = current_dir;
    //calculate alpha
    alpha=atan((p[pos+1][1]-current_pos[1])/(p[pos+1][0]-current_pos[0]));// atan((y1-y0)/(x1-x0))
    //calculate theta
    theta = alpha-beta; 
    //control algorithm
    rudder_angle = Kp * theta;
    if(distance < 5){
      pos++;
    }
  }
  
  //gohome
  while(distance<1){
    
    current_pos[0] = get_X_GPS();
    current_pos[1] = get_Y_GPS();
    
    distance = sqrt(pow(p[0][0]-current_pos[0],2)+pow(p[0][1]-current_pos[1],2));    
 
    //calculate beta
    current_dir = get_Dir();
    beta = current_dir;
    //calculate alpha
    alpha=atan((p[0][1]-current_pos[1])/(p[0][0]-current_pos[0]));// atan((y1-y0)/(x1-x0))
    //calculate theta
    theta = alpha-beta; 
    //control algorithm
    rudder_angle = Kp * theta; //proportinal control
    if(distance < 5){
      pos++;
    }
    
  }
  
  
  
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
