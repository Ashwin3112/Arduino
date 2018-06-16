#include <LiquidCrystal.h>
#include <Keypad.h>
char data[8];
char msd[4]={'*','*','*','*'};
int i=0,t=4,q=1;;
LiquidCrystal  lcd(12, 11, 5, 4, 3, 2);
const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'0','*','#'}
};
byte rowPins[ROWS] = {8, 7, 6, 13}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 0, 10}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );
void delet(){
  lcd.setCursor(13, 1);
      for(int j=4;j<8;j++)
        {
       lcd.print(data[j]=0);
         }
}

void repeat()
{  lcd.setCursor(13, 1);
 for(int j=4;j<8;j++)
 {
  lcd.print(data[j]);
  }

  if(i<4)
{ lcd.setCursor(8, 0);
 lcd.print("SET PASSWORD");}
 
 if(i==4) 
  {
    if (q==5)
  {
    lcd.setCursor(0, 0);
 lcd.print("  YOUR PASSWORD HAVE BEEN SET   "); 
 delay(400);
 delet();
 delay(1000);
 lcd.clear();
 q++;
 }
 if (q>=6){
    lcd.setCursor(4, 0);
 lcd.print("  ENTER      PASSWORD  ");
 }
 }
// lcd.print(millis() / 1000);
/*==============================================================*/
if(q>7){
 if(i<=9)
 { 

 /*==============================================================*/
 lcd.setCursor(0, 0);
 // IF PASSWORD  MATCHED
 if(t==8){
  if(data[4]==data[0]&&data[5]==data[1]&&data[6]==data[2]&&data[7]==data[3])
   {delay(500);
    delet();
      {lcd.setCursor(4, 0);
        lcd.print("    PASSWORD     MATCHED  ");
      delay(500);
      lcd.setCursor(4, 0);
       lcd.print("                           ");
      lcd.setCursor(4, 0);
       lcd.print("       WELCOME!           ");
      delay(1500);
       lcd.setCursor(4, 0);
       lcd.print("                             ");
      }

    }
  }
 
  // lcd.setCursor(25, 1);  
    // lcd.print(q );
     //  lcd.print(t);
/*==============================================================*/
 if(t==8)
 {
  t=4;
 
  /*==============================================================*/
  // IF PASSWORD NOT MATCHE
   if(data[4]!=0||data[5]!=0||data[6]!=0||data[7]!=0)
     { delay(500);
     delet();
      lcd.setCursor(0, 0);
      lcd.print("     ACCESS DENIED DENIED        ");
     delay(500);
     lcd.setCursor(0, 0);
     lcd.print("                              ");}
/*==============================================================*/
 }
/*==============================================================*/
 
}

}
if(q==6){delet();q++; t=4;}

}


void setup()
{
 Serial.begin(9600);
 lcd.begin(32,2);
 lcd.clear();
 lcd.setCursor(2,0);
 
}

void loop() {
 
  char key = kpd.getKey();
  
  if(i<4){
   
  if (key){
    lcd.setCursor(1, 0);
    data[i]=key;
  //  lcd.print(data[i]);
     i++;
    
      
    }   
  }
  if(t>=4){
  if (key){
    lcd.setCursor(1, 0);
    data[t]=key;
  //  lcd.print(data[i]);
     t++; 
      q++;
    }   
    
 // w();
  }//lcd.setCursor(25, 1);  
     //lcd.print(q );
repeat();


}

