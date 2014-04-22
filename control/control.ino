#include <math.h>
float p[20][2];
float beta=0;
float theta=0;
float alpha=0;
int pos;
int max_pos;
float distance;
float current_dir; 
float Kp;
float rudder_angle;

void setup()
{
   max_pos=5;
   pos=0;

  
}

void loop()
{
  while(pos<max_pos){
    // put your main code here, to run repeatedly:
    if(distance < 5){
      pos++;
    }
    //user input corrdinates
    
    //getting current position
    p[0][0] = get_X_GPS();
    p[0][1] = get_Y_GPS();
    //calculate beta
    current_dir = get_Dir();
    beta = current_dir;
    //calculate alpha
    alpha=atan((p[pos+1][1]-p[pos][1])/(p[pos+1][0]-p[pos][0]));// atan((y1-y0)/(x1-x0))
    //calculate theta
    theta = alpha-beta; 
    //control algorithm
    rudder_angle = Kp * theta;
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
