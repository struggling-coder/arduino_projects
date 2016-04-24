//According to morse code standards and all that
String data[] = {"TS", "STTT", "STST", "STT", "T", "TTST", "SST", "TTTT", "TT", "TSSS", "STS", "TSTT", "SS", "ST", "SSS", "TSST", "SSTS", "TST", "TTT", "S", "TTS", "TTTS", "TSS", "STTS", "STSS", "SSTT"};

void _pause() {
  delay(150);              // wait for a second  
}

void _longpause() {
  delay(350);              // wait for a second
}

void inw() {
  delay(50);
}

void dot() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW              // wait for a second
}

void dash() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(150);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW              // wait for a second
}

void disp(int k){
  String letter = data[k];
  for (int q=0; q<letter.length(); q++){
    if (letter.charAt(q) == 'T') {dot(); inw();}
    else {dash(); inw();}
    _pause();
  }
}

void interpret(int _pos)
{
  if (_pos == 40) 
  {
    _longpause();
  }
  else if (_pos > 96) 
  {
      _pos = _pos - 97;
      disp(_pos);
  }
  else { _pos = _pos - 65;
      disp(_pos);
  }  
}

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(5000);
  String message="i am aditya";
  
  for(int j=0; j < message.length(); j++)
  {
    int pos = message.charAt(j);
    //Check if it is a capital or small letter
    interpret(pos);
  }
}
