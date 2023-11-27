#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <iomanip>
using namespace std;

int array_hit[1][2]={0,0};

void Clear(int arr_size, int **arr)    //grid ��l��
{
    for(int i=0; i <arr_size; i++)
    {
        for(int j=0; j < arr_size; j++)
        {
            arr[i][j] = 0;
        }
    }
}


void gridDisplay(int arr_size, int **arr){     //�L�Xgrid

    cout << "Y" << endl;
    for(int i = arr_size-1; i >= 0; i--) {
        cout << i+1 << "\t";
        for(int j = 0; j<arr_size; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for(int j = 0; j <= arr_size; ++j)
        cout << j << "\t";
    cout << "X";
    cout << endl;

}


int gridsizeEntry(){               //��J�ѽL�j�p
    int n;
    do
    {cout << "Input size of grid:";
    cin >> n;
    if (n<=0)
      cout << "Wrong!" <<endl;
    }
    while(n<=0);
    return n;
}

int shipsizeEntry(){                 //��J��j�p
    int n;
    do{
    cout << "Input size of ship:";
    cin >> n;
    if (n<=0)
      cout << "Wrong!" <<endl;
    }
    while(n<=0);
    return n;
}

int shipPositionEntry(int sizeofship,  int **arr, int gridsizeEntry){     //��J���V
    int x,y,w,t;
    cout << "Input amount of ship: ";
    cin >> t;
    for(int i=0;i<t;i++){
    bool position2 = true;
    while(position2){
    bool position = true;
    while(position){
      cout << "Input position of x and y (boat" << i+1 << "):";
      cin >> x >> y;
      cout << "Input the direction of ship(up=1;right=2;left=3;down=4): ";
      cin >> w;
    if(x>=1 && x<= gridsizeEntry && y>=1 && y<= gridsizeEntry){
      if(w==1 && y+sizeofship-1 <= gridsizeEntry)
            position = false;
      else if(w==2 && x+sizeofship-1 <= gridsizeEntry)
            position = false;
      else if(w==3 && x-sizeofship >= 0)
            position = false;
      else if(w==4 && y-sizeofship >= 0)
            position = false;
      else cout << "Wrong!\n";
      }
    else cout << "Wrong!\n";}
    if(w==1){
     for(int i=0;i<sizeofship;i++){
      if(arr[y-1][x-1]!=9){
        position2 = false;
        arr[y-1][x-1]=9;
        y++;
      }
      else {cout << "Wrong!\n";
            break;}
     }
    }
    else if(w==2){
     for(int i=0;i<sizeofship;i++){
      if(arr[y-1][x-1]!=9){
        position2 = false;
      arr[y-1][x-1]=9;
      x++;
      }
      else {cout << "Wrong!\n";
            break;}
     }
    }
    else if(w==3){
     for(int i=0;i<sizeofship;i++){
      if(arr[y-1][x-1]!=9){
        position2 = false;
      arr[y-1][x-1]=9;
      x--;
      }
      else {cout << "Wrong!\n";
            break;}
     }
    }
    else if(w==4){
     for(int i=0;i<sizeofship;i++){
      if(arr[y-1][x-1]!=9){
        position2 = false;
      arr[y-1][x-1]=9;
      y--;
      }
      else {cout << "Wrong!\n";
            break;}
     }
    }
}
}
}

bool gameExiting(int **arr){      
    int n;
    cout << "1. Start to battle " << endl;
    cout << "2. Absort (restart) " << endl;
    cout << "Are you ready to battle ?(1 to start) " ;
    cin >> n;
    if(n == 1)
       return true;
    else
       return false;
}

int WhereYouHit(int **arr2,int x,int y,int yn,int j,double &hit2,double round){
    srand(time(0));
    int random_emoticon=rand()%5;
    static const char *enum_str1[] =
        { "_(�{�u�{??)_", "�U?(?? ?; )?", "�U(???�F�ݡF???)", "�z|��o��|�}" ,"?(?*?*?)?!!"};
    static const char *enum_str2[] =
        { "(????)?*:???", "???(????? ? ????)???", "(�����s����)?", "???�E??�E???" ,"?(?u?)?"};
    if(yn==1){
        x=x-1;
        y=y-1;
        hit2++;
        arr2[y][x]=1;
        cout << "hit " <<enum_str2[random_emoticon]<< "  Hit rate:" << setprecision(4) << fixed << hit2/round*100 << "%"  << endl;
        j--;
    }
    else if(yn==2){
        x=x-1;
        y=y-1;
        arr2[y][x]=2;
        cout << "miss" <<enum_str1[random_emoticon]<< "  Hit rate:" << setprecision(4) << fixed << hit2/round*100 << "%" << endl;
    }
    return j;
}

int HittingDetection(int **arr,int x,int y,double &hit,double round){
    srand(time(0));
    int random_emoticon=rand()%5;
    static const char *enum_str1[] =
        { "_(�{�u�{??)_", "�U?(?? ?; )?", "�U(???�F�ݡF???)", "�z|��o��|�}" ,"?(?*?*?)?!!"};
    static const char *enum_str2[] =
        { "(????)?*:???", "???(????? ? ????)???", "(�����s����)?", "???�E??�E???" ,"?(?u?)?"};
    x=x-1;
    y=y-1;
    if(arr[y][x] == 9){
        hit++;
        cout << "hit " <<enum_str1[random_emoticon]<< "  Hit rate:" << setprecision(4) << fixed << hit/round*100 << "%" <<endl;
        arr[y][x]=1; 
    }
    else{
        cout << "miss" <<enum_str2[random_emoticon]<< "  Hit rate:" << setprecision(4) << fixed << hit/round*100 << "%" << endl;
        arr[y][x]=2;
    }
}

int HittingpositionEntry(int **arr,double &round)
{
    int x,y;
    cout << "ROUND:" << static_cast<int>(round) << "  Input position to fire the missle: ";
    cin >> x >> y;
    array_hit[0][0]=x;
    array_hit[0][1]=y;
}

bool LosingDetection(int **arr,int arr_size){

    for(int i=0; i <arr_size; i++)
    {
        for(int j=0; j < arr_size; j++)
            if(arr[i][j]==9)
                return true;
    }
    return false;
}

int Enemy_ship_size(){
    int n;
    cout << "Input size of enemy ship:";
    cin >> n;
    return n;
}



int main(){
    int j; //�ĤH�Ѧh�ֲ
    int sizeofship; //��j�p
    int n; //��J�ѽL�j�p
    int ** array; //�ڤ�ѽL
    int ** array2; //�Ĥ�ѽL
    int x=0,y,yn; //�ŧiX�y�СAY�y�СA����(���Ĥ誺)
    int First; //������
    double hit=0; //�Ĥ襴��ۤv�X��
    double hit2=0; //�ۤv����Ĥ�X��
    double round=1; //�^�X
    double round2=0; //�`����
    double i=0;
    
    while(x!=-1){
      hit=0;
      hit2=0;
      round=1;
      round2++;
      n=gridsizeEntry();
      array = new int * [n];
      for (int i=0; i<n; i++)
      {
          array[i] = new int [n];
      }
      array2 = new int * [n];

      for (int i=0; i<n; i++)
      {
          array2[i] = new int [n];
      }

      //�L�ѽL1
      cout << "Your grid" << endl;; 
      Clear(n,array);
      gridDisplay(n,array);

      //�L�ѽL2
      cout << "Enemy's grid" << endl; 
      Clear(n,array2);
      gridDisplay(n,array2);

      //��j�p��V��m
      sizeofship=shipsizeEntry(); 
      shipPositionEntry(sizeofship,array,n);
      cout << "The position of your ship: " << endl;
      gridDisplay(n,array);

      //�Ĥ��j�p
      j=Enemy_ship_size();

      //�ǳƶ}�l
      bool entry = gameExiting(array); 

      //������
      if(entry==true){
        cout<<"Who attack first?(1:You,2:Enemy)";
        cin>>First;
      }

      //�p�G����
      if(First==1){
        while(entry==true){
          //���Ĥ��
          cout<<"ROUND:" << static_cast<int>(round) << "  Where do you like to hit your enemy? ( x=-1 to quit )";
          cin>>x;
          if(x==-1){break;}
          cin>>y;
          cout<<"Hit or not�H�]1�GYes�A2�GNo�^";
          cin>>yn;

          //���S��Ĺ
          j=WhereYouHit(array2,x,y,yn,j,hit2,round); 
          cout<<"Enemy's grid" << endl;
          gridDisplay(n,array2);
          if(j==0){
            cout<<"you win"<<"�i( ?��??)�e�k�h�h?�e�k??���@"<<endl;
            i++;
            break;
          }

          //�Ĥ襴�ۤv��
          HittingpositionEntry(array,round);
          HittingDetection(array,array_hit[0][0],array_hit[0][1],hit,round);
          cout<<"Your grid" << endl;
          gridDisplay(n,array); 

          //���S����
          if(LosingDetection(array,n)==false){
              cout << "You lose! "<<"?(�X?�X??��?�ݡݡ�(��?;;;�ݡݡ�";
              break;
          }
          round++;
        }
      }
      else{//�p�G���
        while(entry==true){
          
          //�Ĥ襴�ۤv��
          HittingpositionEntry(array,round);
          HittingDetection(array,array_hit[0][0],array_hit[0][1],hit,round);
          cout<<"Your grid" << endl;
          gridDisplay(n,array); 

          //���S����
          if(LosingDetection(array,n)==false){
              cout << "You lose! "<<"?(�X?�X??��?�ݡݡ�(��?;;;�ݡݡ�"<<endl;
              break;
          }
        
          //���Ĥ��
          cout<<"Where do you like to hit your enemy? ( x=-1 to quit )";
          cin>>x;
          if(x==-1){break;}
          cin>>y;
          cout<<"Hit or not�H�]1�GYes�A2�GNo�^";
          cin>>yn;

          //���S��Ĺ
          j=WhereYouHit(array2,x,y,yn,j,hit2,round); 
          cout<<"Enemy's grid" << endl;
          gridDisplay(n,array2);
          if(j==0){
            cout<<"you win"<<"�i( ?��??)�e�k�h�h?�e�k??���@"<<endl;
            i++;
            break;
          }
          round++;
        }
      }

      for (int i=0; i<n; i++)
      {
          delete [] array[i];
          delete [] array2[i];
      }
      delete [] array;
      delete [] array2;

      cout<<"Play again?(1:yes,-1:no):";
      cin>>x;
    }
    cout<<"Game Over!\n"<<"The winning rate is: "<<i/round2*100<<"%";

    return 0;

 }
