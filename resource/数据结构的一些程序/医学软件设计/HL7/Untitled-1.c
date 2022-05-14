#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
#define S1 13
#define S2 12
#define S3 11
#define S4 10
#define S5 9
#define S6 8
#define number_of_vote 3
Adafruit_SSD1306 display(OLED_RESET);
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);//模拟串口，2，3脚
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int i=0;
int fingerprintID = -1;//编号
int vote_number[number_of_vote]={0,0,0};//记票数
String be_vote_er[number_of_vote]={"Geralt","Yenneferof","Cirilla"};//被投票人
String IDname;//显示的名字
boolean list_of_voter[128];

void setup() {
//Fingerprint sensor module setup
Serial.begin(9600);//串口传输速度
// set the data rate for the sensor serial port
finger.begin(57600);  //指纹芯片传输速度
if (finger.verifyPassword()) {//判断是否找到了指纹模块
Serial.println("Found fingerprint sensor!");
}
else {//没找到则挂起
Serial.println("Did not find fingerprint sensor ");
while (1) {
delay(1);
}
}
  pinMode(S1, INPUT);//初始化四个按键
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(S4,INPUT);
  pinMode(S5,INPUT);
  pinMode(S6,INPUT);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  digitalWrite(S4, HIGH);
  digitalWrite(S5, HIGH);
  digitalWrite(S6, HIGH);
  //！！！！！！！！！！！！！！！！！要初始化指纹引脚触摸判断引脚
//OLED display setup
Wire.begin();//屏幕的初始化
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
displayMainScreen();//显示主界面
}
void loop() {
displayMainScreen();
for (i=0;i<6;i++)
//！！！！！！！！！！！！！！！这里按键按下触发，设置为高电平指纹模块的触摸控制控制引脚 打开
{
  if(digitalRead(i+8)==0)
  {
    if(i==3){
      show_max();
      for (int j=0;j<number_of_vote;j++)vote_number[j]=0;
      continue;
      }
      else if(i==4){//改，加
        add_point();
      continue;
      }
       else if(i==5){//删   
      delete_piont();
      continue;
      }
      else{
  display.clearDisplay();//清干净
  display.setTextSize(1);//文本字号
  display.setTextColor(WHITE);//文本颜色
  display.setCursor(7, 5);
  display.println("wait for your fingerpoint input");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(52, 20);//再次设置位置
  display.println("...");
  display.display();//显示的意思
  while(  fingerprintID == -1){//查找到指纹后
  fingerprintID = getFingerprintIDez();//判断指纹是否在库中，-3为不在这个库里
  delay(50);
  }
  }
  c(fingerprintID);//将手指编号传输到c，由c做判断
  }
}
}

//就是-1为没指纹，-3为没找到，找到了就返回改指纹的id
int getFingerprintIDez() {
uint8_t p = finger.getImage();
if (p != FINGERPRINT_OK) return -1;
 
p = finger.image2Tz();
if (p != FINGERPRINT_OK) return -1;

p = finger.fingerFastSearch();//这里显然是搜索
if (p != FINGERPRINT_OK) return -3;

// 找到了就串口打印一下
Serial.print("Found ID #");
Serial.print(finger.fingerID);
Serial.print(" with confidence of ");
Serial.println(finger.confidence);
return finger.fingerID;//把指纹编号返回
}

void displayMainScreen(void) {//屏幕的输出等待指纹输出字样的配置函数，显示当前可投票的人，和目前的投票数目，此为主界面故把指纹编号置为初始化状态。
  display.clearDisplay();//清干净
  display.setTextSize(1);//文本字号
  display.setTextColor(WHITE);//文本颜色
  display.setCursor(0, 0);//再次设置位置
  display.println(be_vote_er[0]+':'+vote_number[0]);
  display.println(be_vote_er[1]+':'+vote_number[1]);
  display.println(be_vote_er[2]+':'+vote_number[2]);
  display.display();//显示的意思
  delay(2000);
  fingerprintID = -1;
}

void displayUserGreeting(String Name) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);//顶首
  display.print("hello");
  display.setCursor(0, 15);
  display.print(Name);
  display.display();
  delay(5000);
}
void c(int fingerprintID ){
    if (fingerprintID == -3 ) {
      display.clearDisplay();//清干净
      display.setTextSize(1);//文本字号
      display.setTextColor(WHITE);//文本颜色
      display.setCursor(7, 5);
      display.println("don't find your point!!");
      display.display();//显示的意思
      delay(5000);
      return;
      }
      if(!list_of_voter[fingerprintID])
      {
      list_of_voter[fingerprintID]=1;      
      vote_number[i]++;
      displayUserGreeting(be_vote_er[i]);//把IDname显示在OLED屏幕上
      }
      else
      {
        display.clearDisplay();//清干净
        display.setTextSize(1);//文本字号
        display.setTextColor(WHITE);//文本颜色
        display.setCursor(0, 0);
        display.println("you have voted already ID:");
        display.print(fingerprintID);
        display.display();//显示的意思
        delay(5000);
        }
}
      

void show_max(void){
  int tmp;
  tmp=0;
  for(int i=1;i<number_of_vote;i++){
    if(vote_number[i]>vote_number[0])tmp=i;
    }
    for (i=0;i<128;++i)
    {
    list_of_voter[i]=0;
    }
      display.clearDisplay();//清干净
      display.setTextSize(1);//文本字号
      display.setTextColor(WHITE);//文本颜色
      display.setCursor(0, 0);
      display.println(be_vote_er[tmp]+':'+vote_number[tmp]);//这里输出要仔细看一下，":"+TMP直接字符转换数字输出了
      display.display();//显示的意思
      delay(5000);
  }
void add_point(void){
  Serial.println("Please enroll ID");
  uint8_t id = readnumber();
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  Serial.print("ENROLL ID #");
  Serial.println(id);
  while (!  getFingerprintEnroll(id) );
  }
uint8_t getFingerprintEnroll(uint8_t id ) {
    display.clearDisplay();//清干净
      display.setTextSize(1);//文本字号
      display.setTextColor(WHITE);//文本颜色
      display.setCursor(0, 0);
      display.println("Please type in the ID # (from 1 to 127) you want to  enroll...");//这里输出要仔细看一下，":"+TMP直接字符转换数字输出了
      display.display();//显示的意思
      delay(5000);
  int p = -1;
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
     }
  // OK success!
  p = finger.image2Tz(1);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
   p = -1;
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
  }
  // OK success!
  p = finger.image2Tz(2);
  // OK converted!
  p = finger.createModel();
  p = finger.storeModel(id);
  return true;
}
void delete_piont(void){
      display.clearDisplay();//清干净
      display.setTextSize(1);//文本字号
      display.setTextColor(WHITE);//文本颜色
      display.setCursor(0, 0);
      display.println("Please type in the ID # (from 1 to 127) you want to delete...");//这里输出要仔细看一下，":"+TMP直接字符转换数字输出了
      display.display();//显示的意思
      delay(5000);
   Serial.println("Please type in the ID # (from 1 to 127) you want to delete...");
  uint8_t id = readnumber();
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }

  Serial.print("Deleting ID #");
  Serial.println(id);

  deleteFingerprint(id);
  }
  
uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

  uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;

  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK) {
    Serial.println("Deleted!");
  } 
}