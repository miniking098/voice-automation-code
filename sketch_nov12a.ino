String voice;
int bulb = 4;
int fan = 5;
void RedOn(){
digitalWrite (bulb, LOW);
}
void RedOff(){
digitalWrite (bulb, HIGH);
}
void YellowOn(){
digitalWrite (fan, LOW);
}
void YellowOff(){
digitalWrite (fan, HIGH);
}
void allon() {
digitalWrite (bulb, LOW);
digitalWrite (fan, LOW);
}
void alloff() {
digitalWrite (bulb, HIGH);
digitalWrite (fan, HIGH);
}
void setup() {
Serial.begin(9600);
pinMode(bulb, OUTPUT);
pinMode(fan, OUTPUT);
digitalWrite (bulb, HIGH);
digitalWrite (fan, HIGH);
}
void loop() {
while(Serial.available()) {
delay(10);
char c=Serial.read();
if(c=='#')
{
break; 
}
voice += c;
}
if (voice.length() > 0) {
Serial.println(voice);
if (voice == "on" || voice== "all on")
{
allon() ;
}
else if (voice == "of" || voice=="all of")
{
alloff() ;
}
else if(voice =="bulb" || voice =="bulb on"){
RedOn();
}
else if(voice =="bulb off"||voice=="bulb of"){
RedOff();
}
else if(voice =="fan" || voice =="fan on"){
YellowOn();
}
else if(voice =="fan off"||voice=="fan of"){
YellowOff();
}
voice="";
}
}
