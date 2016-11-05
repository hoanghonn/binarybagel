int minutes = 0, hours = 0;
int m[]= {1,0,1,0};

void setup() { //set outputs and inputs
    
  pinMode(1, OUTPUT); pinMode(2, OUTPUT); pinMode(3, OUTPUT); pinMode(4, OUTPUT); pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); pinMode(7, OUTPUT); pinMode(8, OUTPUT); pinMode(9, OUTPUT); pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(0, INPUT);

  
}

   
int* toBinary(int n, int sizeArray)
{
 int* pointer;
  pointer = new int[sizeArray]; // THIS LINE HAS CHANGED
  int m = n / 2;
  int k = n % 2;
  for (int q = 0; q < sizeArray; q++){
    if (k == 0)
      pointer[q] = 0;
    else
      pointer[q] = 1;

    k = m % 2;
    m /= 2;

  }
  swap(pointer,sizeArray-1);
  return pointer;
}

void swap(int *k, int s){
  int temp;
  for (int i = 0, j = s; i < (s+1)/2; i++, j--)
  {
    temp = k[i];
    k[i] = k[j];
    k[j] = temp;
  }
}

void loop(){
 
  for (int a = 0; a < 61; a++){
    int *hourP = toBinary(0,4), *minuteP = toBinary(0,6);
    
    
    if (a == 60)
    {
      minutes += 1;
      minuteP = toBinary(minutes, 6);
      a -= 60;
  
    }
    if (minutes == 60)
    {
      hours += 1;
      minutes = 0;
      hourP = toBinary(hours, 4);
    }
    if (hours == 13)
    {
      hours =  1;
    }

   
    if (minuteP != nullptr){
    for (int i = 0; i < 6; i++){
      if (minuteP[i] == 1)
        digitalWrite(i + 5, HIGH);
      else
        digitalWrite(i + 5, LOW);
      }
    } 
    if (hourP != nullptr){
      for (int i = 0; i < 4; i++){
        if (hourP[i] == 1)
          digitalWrite(i + 1, HIGH);
        else
          digitalWrite(i + 1, LOW);
      }
    }

    if(a%2 == 0){
      digitalWrite(11, HIGH);
    } else{
      digitalWrite(11, LOW);
    }

    delete minuteP;
    delete hourP;
    delay(1000);

  }
}



  


