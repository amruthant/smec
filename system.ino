
const int led3=11,led2=12,led1=13,led4=9,sw=7,sw1=3;
int prev_swstatus1=0,pres_swstatus1=0, pres_swstatus2=0,prev_swstatus2=0,count=0;
int ledstatus=0;
void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);

pinMode(sw,INPUT);
pinMode(sw1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
pres_swstatus1=digitalRead(sw1);


if(prev_swstatus1==0&&  pres_swstatus1==1)
{
  ledstatus=(ledstatus==1)?0:1;
  digitalWrite(led4,ledstatus);
}
prev_swstatus1=pres_swstatus1;
if(ledstatus==1)
{
 pres_swstatus2=digitalRead(sw);
 if(prev_swstatus2==0&&  pres_swstatus2==1){
      count++;
      switch(count)
    {case 1 : digitalWrite(led1,ledstatus);
                    
                     break;
       case 2:    digitalWrite(led2,ledstatus);
                     break;  
       case 3   :digitalWrite(led3,ledstatus);
                      
                      break;
                      
       case 4:    digitalWrite(led1,0);
                  digitalWrite(led2,0);
                  digitalWrite(led3,0); 
                  count=0; 
                  break;                                    
    }
    
  }
   
 }
 if(ledstatus==0)
 {count=0;
  
  digitalWrite(led1,ledstatus);
  digitalWrite(led2,ledstatus);
  digitalWrite(led3,ledstatus);
  
 }
 prev_swstatus2=pres_swstatus2;


}
