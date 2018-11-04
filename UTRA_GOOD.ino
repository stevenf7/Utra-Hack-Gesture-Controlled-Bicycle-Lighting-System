
const int Leftflex = A0;
const int Rightflex = A3;
const int LeftLED = 10;
const int CenterLED = 9;
const int RightLED = 11;

//not enough pins- removed backlight. (mention this)
//const int BackLight = 12;

int bright = 220;
int dim = 120;

//set up mpu6050/gy-521 accelerometer 
/*
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
*/

void setup() {
  //initialize digital pin
  pinMode(LeftLED,OUTPUT);
  pinMode(RightLED,OUTPUT);
  pinMode(CenterLED,OUTPUT);
  Serial.begin(9600);
  //pinMode(BackLight,OUTPUT);

}

void left (){
analogWrite(LeftLED, bright);
analogWrite(CenterLED, bright);
digitalWrite(RightLED, LOW); 

 delay(500);
 digitalWrite(LeftLED, LOW);
 digitalWrite(CenterLED, LOW);

 delay(500);
}

void right (){
analogWrite(RightLED, bright);
analogWrite(CenterLED, bright);
digitalWrite(LeftLED, LOW);

 delay(500);
 digitalWrite(RightLED, LOW);
 digitalWrite(CenterLED, LOW);

 delay(500);
} 

void center(){
  
 analogWrite(RightLED, dim);
 analogWrite(CenterLED, dim);
 analogWrite(LeftLED, dim);


}



void loop() {
  int flexL= 0;
  int flexR = 0;
  flexL = analogRead(Leftflex);
  flexR = analogRead(Rightflex);
  if (flexL< 560){
    left();
   
  }
//testing with one flex sensor
  else if (flexR <160){

   right();

  }
  
  else{
    center();
    
  }
 Serial.println(flexR,DEC);

  delay(300);
}
