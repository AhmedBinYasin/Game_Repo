/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//

void fallingPiece(float& timer, float& delay, int& colorNum){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;  //How much units downward
        }
        if(!anamoly()) //i.e. anamoly=0, then it runs because !0=1
        {
          for(int i=0; i<4; ++i)
          {  gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;  }
          
          colorNum=1+rand()%7;
          int n=rand()%7;
          
          for(int i=0; i<4; ++i)
            {
              point_1[i][0]=BLOCKS[n][i]%2;
              point_1[i][1]=BLOCKS[n][i]/2;
            }
        }
        timer=0;
        
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

void movingx(int delta_x)
{
  if(delta_x!=0) // i.e. if a key is pressed
  {
    for(int i=0; i<4; ++i)
    {  point_2[i][0]=point_1[i][0];  } // saving our og point_1 coordinates for anamoly checking later
          
    for(int i=0;i<4; ++i)
    {  point_1[i][0]=point_1[i][0]+delta_x;  } // adding +1/-1 into our x-axis coordinate
          
    if(!anamoly())
    {    for(int i=0; i<4; ++i)
         {  point_1[i][0]=point_2[i][0];  } // if anamoly present (i.e. boundary) then last-saved coordinates in point_2 are printed back into point_1 and block doesn't move
    }
  }
}


void spacebar()
{
  for(int i=0; i<4; ++i)
    {  point_2[i][1]=point_1[i][1];  } // saving last coordinates of point_1 into point_2
  while(anamoly())
  {
    for(int i=0; i<4; ++i)
    {  point_1[i][1]=point_1[i][1]+1;  } // while there is no anamoly, we keep adding one to the y-axis coordinates
  }
  
  for(int i=0; i<4; ++i)
  {  point_1[i][1]=point_1[i][1]-1;  } // we reverse the last plus 1 that made an anamoly appear
}


void rotation (bool rotate)
{
  for(int i=0; i<4; ++i)
    {  point_2[i][1]=point_1[i][1];
       point_2[i][0]=point_1[i][0];}
  
  if (rotate)
        {
          
          int px = point_1[1][0]; 
          int py = point_1[1][1]; 
         
        //center of rotation
            for (int i = 0; i < 4; i++)
            {
                int x = point_1[i][1] - py;
                int y = point_1[i][0] - px;
                point_1[i][0] = px - x;
                point_1[i][1] = py + y;
            }
            
        }
  if(!anamoly())
    {    for(int i=0; i<4; ++i)
         {  point_1[i][0]=point_2[i][0];
            point_1[i][1]=point_2[i][1];} }
  }

void removeFull(){
  int M=20;
  int N=10;
  int mark_for_delete[20]={0};
  for(int i=0;i<20;i++){
    for(int j=0;j<10;j++){
      if(j!=0){
        mark_for_delete[j]=1;
      }
      else{
        mark_for_delete[j]=0;
        break;
      }
    }
  }
}
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////