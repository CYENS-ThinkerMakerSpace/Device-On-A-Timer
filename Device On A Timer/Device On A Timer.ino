int counter;
int initTime;
double startTime, endTime;

void setup()
{
  pinMode(13, OUTPUT);
  counter = 1;
  initTime = 9.5; // The time this program starts in a 24h clock
  startTime = 8;
  endTime = 22;
}

void loop()
{
  if (returnTimeFromCounter(counter) >= startTime && returnTimeFromCounter(counter) <= endTime)
  {
    digitalWrite(13, HIGH);
    delay(4*60*1000);
    digitalWrite(13, LOW);
    delay(8*60*1000);
  }
  else  
  {
    delay((4+8)*60*1000);
  }

  counter = counter + 1;
  if (counter > 24*60/(4+8))
  {
    // counter = [1, 120] *in Math notation
   counter = 1;
  }
}

int returnTimeFromCounter(int counterVal)
{  
  double myTime, myTimeWithCompensationForInitTime;
  myTime = 12*counterVal/60;
  myTimeWithCompensationForInitTime = myTime + initTime;
  if (myTimeWithCompensationForInitTime > 24)
  {
    myTimeWithCompensationForInitTime = myTimeWithCompensationForInitTime - 24;
  }
  return myTimeWithCompensationForInitTime;
}


