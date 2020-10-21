char user_passcode[15],passcode[]="pass123";
int index;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("welcome");
}

void loop() {
  char ch ;
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  ch=Serial.read();
  if(ch=='*')
 {
    index=0;
do{
    if(Serial.available()>0)
    {
      user_passcode[index]=Serial.read();
      if(user_passcode[index]!='#')
      {
        if(user_passcode[index]=='\b')
        {
          Serial.print("\b");
        index=index-2;
       // index--;  
    
        }

        else{
          Serial.print("*");
          
        }
        
      }
   index++;
    
    }
    
}while(user_passcode[index-1]!= '#');
  user_passcode[index-1]='\0';
  
 
  if(strcmp(user_passcode,"pass123")==0)
  {
    Serial.println(" ");
    Serial.println("USER ACCES GRANTED");
     Serial.println("VIEW DATA.....");
  }
else
  {
    Serial.println(" ");
    Serial.println("USER ACCES DENIED");
  }
 
    
   
 }
}
}
