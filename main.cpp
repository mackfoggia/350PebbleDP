#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


#define XSIZE 6
#define YSIZE 5

int graph[XSIZE][YSIZE];
int T[XSIZE][YSIZE];

int robot(int, int);
int robotM(int, int);

int count = 0;
int countM = 0;

int main(){
  srand(time(NULL));

  for(int x = 0; x < XSIZE; ++x){
    for(int y = 0; y < YSIZE; ++y){
      graph[x][y] = (rand() % 100) > 70 ? 1:0;
      T[x][y] = -1;
      cout << graph[x][y] << " ";
    }
    cout << endl;
  }

  cout << endl << "Robot can find: " << robot(0, 0) << " and did 4,4 " << count << " times." << endl;
  cout << endl << "RobotM can find: " << robotM(0, 0) << " and did 4,4 " << countM << " time." << endl;

  return 0;
}


int robot(int x, int y){
  int right = graph[x][y];
  int down = right;
  
  if(x == 4 && y == 4) ++count;
  if(x < XSIZE - 1) right += robot(x+1, y);
  if(y < YSIZE - 1) down += robot(x, y+1);

  return max(right, down);
}

int robotM(int x, int y){
  int right = graph[x][y];
  int down = right;

  if(x == 4 && y == 4) ++countM;
  if(x < XSIZE - 1){
    if(T[x+1][y] == -1) T[x+1][y] = robotM(x+1, y);
    right += T[x+1][y];
  }

  if(y < YSIZE - 1){
    if(T[x][y+1] == -1) T[x][y+1] = robotM(x, y+1);
    down += T[x][y+1];
  }

  return max(right, down);
}
