// Slow Motion

#include <Servo.h>

Servo m_grip; // 30: 그립 최대로 열기, 110: 그립 최대로 닫기, 동작 범위 벗어나지 않도록.
Servo m_wristRotate; // CW 0 ~ CCW180
Servo m_wristTilt; // 앞 0 ~ 뒤 180
Servo m_elbowTilt1; // 앞 180 ~ 뒤 0
Servo m_elbowTilt2; // 앞 180 ~ 뒤 0
Servo m_bodyRotate; // CW 0 ~ CCW180

int val_grip = 90; 
int val_wristRotate = 90; 
int val_wristTilt = 90; 
int val_elbowTilt1 = 90; 
int val_elbowTilt2 = 90; 
int val_bodyRotate = 90; 

int t_val_grip = 0; 
int t_val_wristRotate = 0; 
int t_val_wristTilt = 0; 
int t_val_elbowTilt1 = 0; 
int t_val_elbowTilt2 = 0; 
int t_val_bodyRotate = 0; 

int dist_val_grip = 0; 
int dist_val_wristRotate = 0; 
int dist_val_wristTilt = 0; 
int dist_val_elbowTilt1 = 0; 
int dist_val_elbowTilt2 = 0; 
int dist_val_bodyRotate = 0; 

int initialPosition = 90;   

void setup() {
  m_grip.attach(3); 
  m_wristRotate.attach(5); 
  m_wristTilt.attach(6); 
  m_elbowTilt1.attach(9); 
  m_elbowTilt2.attach(10); 
  m_bodyRotate.attach(11); 

  //Openning
  m_grip.write(initialPosition); 
  m_wristRotate.write(initialPosition); 
  m_wristTilt.write(initialPosition); 
  m_elbowTilt1.write(initialPosition); 
  m_elbowTilt2.write(initialPosition); 
  m_bodyRotate.write(initialPosition);   
  delay(500);
  m_grip.write(30); 
  m_wristRotate.write(0); 
  delay(500);
  m_grip.write(110); 
  m_wristRotate.write(180); 
  delay(700);

  //Initialize
  m_grip.write(initialPosition); 
  m_wristRotate.write(initialPosition); 
  m_wristTilt.write(initialPosition); 
  m_elbowTilt1.write(initialPosition); 
  m_elbowTilt2.write(initialPosition); 
  m_bodyRotate.write(initialPosition); 
  delay(1000);

  Serial.begin(9600);
  Serial.println("Program Start..");
}

void loop() {
  
}

void serialEvent() {
  t_val_grip = val_grip;
  t_val_wristRotate = val_wristRotate;
  t_val_wristTilt = val_wristTilt;
  t_val_elbowTilt1 = val_elbowTilt1;
  t_val_elbowTilt2 = val_elbowTilt2;
  t_val_bodyRotate = val_bodyRotate;
    
  if(Serial.available()){
    val_grip = Serial.parseInt();
    val_wristRotate = Serial.parseInt();
    val_wristTilt = Serial.parseInt();
    val_elbowTilt1 = Serial.parseInt(); 
    val_elbowTilt2 = Serial.parseInt();
    val_bodyRotate = Serial.parseInt();
  }    
  Serial.println(val_grip);
  Serial.println(val_wristRotate);
  Serial.println(val_wristTilt);
  Serial.println(val_elbowTilt1);
  Serial.println(val_elbowTilt2);
  Serial.println(val_bodyRotate);

  dist_val_grip = t_val_grip - val_grip;
  dist_val_wristRotate = t_val_wristRotate - val_wristRotate;
  dist_val_wristTilt = t_val_wristTilt - val_wristTilt;
  dist_val_elbowTilt1 = t_val_elbowTilt1 - val_elbowTilt1;
  dist_val_elbowTilt2 = t_val_elbowTilt2 - val_elbowTilt2;
  dist_val_bodyRotate = t_val_bodyRotate - val_bodyRotate;  

  //abs함수는 헷갈려서 지웠슴당
  
  Serial.println(dist_val_grip);
  Serial.println(dist_val_wristRotate);
  Serial.println(dist_val_wristTilt);
  Serial.println(dist_val_elbowTilt1);
  Serial.println(dist_val_elbowTilt2);
  Serial.println(dist_val_bodyRotate);

    test(val_grip, val_wristRotate, val_wristTilt, val_elbowTilt1, val_elbowTilt2,val_bodyRotate); 
    // 똑바로 세우기 : 90 90 90 90 90 90
    // 기본자세 : 90 90 150 0 30 90
}


void test(int _val_grip, int _val_wristRotate, int _val_wristTilt, int _val_elbowTilt1, int _val_elbowTilt2, int _val_bodyRotate) {

  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;
  int f = 0;
  
  
  while(1) {
    m_grip.write(t_val_grip); 
    m_wristRotate.write(t_val_wristRotate); 
    m_wristTilt.write(t_val_wristTilt); 
    m_elbowTilt1.write(t_val_elbowTilt1); 
    m_elbowTilt2.write(t_val_elbowTilt2); 
    m_bodyRotate.write(t_val_bodyRotate);
    
    //grip
    if(a < 1) {
    if(t_val_grip - _val_grip <= 0) {
      if(t_val_grip != _val_grip) {
       t_val_grip++;
      } else {
        a++;
      }
    } else {
      if(t_val_grip != _val_grip) {
       t_val_grip--;
      } else {
        a++;
      }
    }
    }
  
    //wristRotate
    if(b < 1) {
    if(t_val_wristRotate - _val_wristRotate <= 0) {
      if(t_val_wristRotate != _val_wristRotate) {
       t_val_wristRotate++;
      } else {
        b++;
      }
    } else {
      if(t_val_wristRotate != _val_wristRotate) {
       t_val_wristRotate--;
      } else {
        b++;
      }
    }
    }
    
    
    //wristTilt
    if(c < 1) {
    if(t_val_wristTilt - _val_wristTilt <= 0) {
      if(t_val_wristTilt != _val_wristTilt) {
       t_val_wristTilt++;
      } else {
        c++;
      }
    } else {
      if(t_val_wristTilt != _val_wristTilt) {
       t_val_wristTilt--;
      } else {
        c++;
      }
    }
    }
    
    //elbowTilt1
    if(d < 1) {
    if(t_val_elbowTilt1 - _val_elbowTilt1 <= 0) {
      if(t_val_elbowTilt1 != _val_elbowTilt1) {
       t_val_elbowTilt1++;
      } else {
        d++;
      }
    } else {
      if(t_val_elbowTilt1 != _val_elbowTilt1) {
       t_val_elbowTilt1--;
       

      } else {
        d++;
      }
    }
    }
    
    //elbowTilt2
    if(e < 1) {
    if(t_val_elbowTilt2 - _val_elbowTilt2 <= 0) {
      if(t_val_elbowTilt2 != _val_elbowTilt2) {
       t_val_elbowTilt2++;
      } else {
        e++;
      }
    } else {
      if(t_val_elbowTilt2 != _val_elbowTilt2) {
       t_val_elbowTilt2--;
      } else {
        e++;
      } 
    }
    }
    
    //bodyRotate
    if(f < 1) {
    if(t_val_bodyRotate - _val_bodyRotate <= 0) {
      if(t_val_bodyRotate != _val_bodyRotate) {
       t_val_bodyRotate++;
      } else {
        f++;
      }
    } else {
      if(t_val_bodyRotate != _val_bodyRotate) {
       t_val_bodyRotate--;
      } else {
        f++;
      }
    }
    }
    
     if((a + b + c + d + e + f) == 6) {
      break;
  }
    delay(15);
  }
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  e = 0;
  f = 0;

  delay(500);
}
