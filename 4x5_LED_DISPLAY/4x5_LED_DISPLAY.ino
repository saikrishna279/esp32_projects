int A[] = {2,3,5,8,9,10,11,12,13,16,17,20,0};

#define column1 8
#define column2 9
#define column3 10
#define column4 11

#define column5 12

#define row1 3
#define row2 4
#define row3 5
#define row4 6
#define row5 7

int row[] = {row1, row2, row3, row4, row5};
int column[] = {column1, column2, column3, column4, column5};

void setup() {
  for(int i = 0; i <5; i++ ){
    pinMode(row[i], OUTPUT);
    pinMode(column[i], OUTPUT);
    digitalWrite(column[i], LOW);
    digitalWrite(row[i], HIGH);
  }
}

void loop() {
  resetAll();
  int i = 0;
  int x = 1;
  int y;
  while(A[i]!=0){
    while(A[i] > (x * 4)){
      x++;
      resetAll();
    }
    y = (A[i]-((x-1) * 4));
    ledActivate(x, y);
    i++;
  }

}

void ledActivate(int x, int y){
  digitalWrite(row[x-1], LOW);
  digitalWrite(column[y-1], HIGH);
}

void resetAll(){
  for(int i = 0; i <5; i++ ){
    digitalWrite(column[i], LOW);
    digitalWrite(row[i], HIGH);
  }
}

