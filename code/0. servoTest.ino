//서보모터 라이브러리 참조
#include <Servo.h>
// 시리얼 통신 속도 및 서보모터 핀 설정
#define BUADRATE 9600
#define SERVO 3
// myServo : 서보모터 클래스 변수 생성, 
// strAngle : 시리얼 통신으로 입력 받을 angle 각도 저장
Servo myServo;
String strAngle;
 
// angle : 서보모터 제어에 사용할 실제 angle 값
// flag : 시리얼 통신으로 angle 입력시 이벤트를 발생 flag
int angle;
boolean flag = false;
 
void setup() {
    myServo.attach(SERVO);
    Serial.begin(BUADRATE);
    while(!Serial){
        ;
    }
    delay(500);
    Serial.println("Program Start..");
    Serial.print("Input Servo Angle >> ");
}
 
void loop() {
    // 입력된 문자열이 유효값인지 판단을 위한 temp 변수
    if(flag == true){
        flag = false;
        angle = strAngle.toInt();
        strAngle = "";
        // 입력된 값이 0 ~ 180 일때만 Servo 모터 제어
        if (angle >= 0 && angle <= 180)
        {
            // angle 값 변경 후, read() 함수가 재대로 동작하도록 write() 함수 1회 실행
            myServo.write(angle);
            Serial.print("Servo Angle : ");
            Serial.println(myServo.read());
            Serial.print("Input Servo Angle >> ");
        }
        else
        {
            ErrorHadler();
        }
    }
    delay(20);
}
 
// 시리얼 통신으로 문자 수신 되면 발생하는 함수
// PC 에서 엔터가 눌러지면(캐리지 리턴 발생), flag 를 1 입력
void serialEvent()
{
    char cTemp = (char)Serial.read();
    if (isDigit(cTemp) || cTemp == '\b'){
        strAngle += cTemp;
    }
    else if(cTemp == '\n'){
        flag = true;
    }
    else if(cTemp == '\r'){
        if (strAngle == "") ErrorHadler();
    }
    else{ /* if (cTemp < '0' || cTemp > '9') */
        ErrorHadler();
    }
}
 
// 시리얼 모니터에서 0 ~ 180 이외의 값 입력시 안내 메세지 출력
void ErrorHadler()
{
    Serial.println("Error! Input Angle Number 0 to 180..");
    strAngle = "";
    Serial.print("Input Servo Angle >> ");
}

