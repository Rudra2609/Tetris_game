#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

int width,height,score=0,highScore=0,level=1,spd=230;
vector<vector<int>>board;

class Point{
    public:
        int x,y;
};

class Tetromino{
    public:
        vector<Point>blocks;
        int id;
};

vector<Tetromino>tetrominoes={
    {{{0,0},{1,0},{0,1},{1,1}},1},  // O
    {{{0,0},{1,0},{2,0},{3,0}},2},  // I
    {{{0,0},{1,0},{2,0},{2,1}},3},  // L
    {{{0,0},{1,0},{2,0},{0,1}},4},  // J
    {{{0,0},{1,0},{1,1},{2,1}},5},  // S
    {{{1,0},{2,0},{0,1},{1,1}},6},  // Z
    {{{0,0},{1,0},{2,0},{1,1}},7}   // T
};

Tetromino current;
Point position;

void hideCursor() {
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole,&cursorInfo);
    cursorInfo.bVisible=false;
    SetConsoleCursorInfo(hConsole,&cursorInfo);
}

void setColor(int id){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    int colors[]={7,14,11,6,9,10,12,13};
    SetConsoleTextAttribute(hConsole,colors[id]);
}

void drawBoard(){
    HANDLE hConsole =GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos ={0,0};
    SetConsoleCursorPosition(hConsole, cursorPos);

    for (int i=0;i<height; i++) {
        for (int j=0;j<width; j++) {
            bool isBlock =false;
            for (Point p :current.blocks){
                if (position.y + p.y==i&& position.x + p.x==j){
                    setColor(current.id);
                    cout<<"# ";
                    SetConsoleTextAttribute(hConsole, 7);
                    isBlock =true;
                    break;
                }
            }
            if (!isBlock) {
                if(board[i][j]){
                    setColor(board[i][j]);
                    cout<<"# ";
                    SetConsoleTextAttribute(hConsole, 7);
                } else {
                    cout << ". ";
                }
            }
        }
        cout<<endl;
    }
    cout<<"\t\t"<<"LEVEL: "<<level<<endl;
    cout<<"Score: "<<score<<"\t\t\t"<<"High Score: "<<highScore<<endl;
}

bool canMove(int dx, int dy){
    for (Point p : current.blocks){
        int newX=position.x + p.x + dx;
        int newY=position.y + p.y + dy;
        if(newX<0 || newX>=width || newY>=height || (newY>=0 && board[newY][newX])){
            return false;
        }
    }
    return true;
}

void mrg(){
    for(Point p : current.blocks){
        board[position.y+p.y][position.x+p.x]=current.id;
    }
}

void clearLines(){
    int linesCleared=0;
    for(int i=height-1;i>=0;i--){
        bool full=true;
        for(int j=0;j<width;j++){
            if (board[i][j]==0) {
                full=false;
                break;
            }
        }
        if(full){
            board.erase(board.begin()+i);
            board.insert(board.begin(),vector<int>(width,0));
            linesCleared++;
        }
    }
    score+=linesCleared*10;
    if(score>highScore){
        spd-=10;
        level++;
        highScore=score;
    }
}

void rotate(){
    vector<Point>rotated;
    for (Point p:current.blocks) {
        rotated.push_back({-p.y,p.x});
    }
    for (Point p:rotated) {
        int newX=position.x + p.x;
        int newY=position.y + p.y;
        if (newX<0|| newX>=width || newY>=height || (newY>=0 && board[newY][newX])) {
            return;
        }
    }
    current.blocks=rotated;
}

void input(){
    if(_kbhit()){
        char key=_getch();
        if(key=='a'&&canMove(-1,0))position.x--;
        if(key=='d'&&canMove(1,0))position.x++;
        if(key=='s'&&canMove(0,1))position.y++;
        if(key=='r')rotate();
        if(key==' '){
            while(canMove(0, 1)){
                position.y++;
            }
        }
    }
}

void gameLoop(){
    while(true){
        Sleep(spd);
        if(canMove(0, 1)){
            position.y++;
        } 
        else{
            mrg();
            clearLines();
            current=tetrominoes[rand()%tetrominoes.size()];
            position={width/2,0};
            if(!canMove(0, 0)){
                cout<<"Game Over!"<<endl;
                cout<<"Final Score: "<<score<<endl;
                cout<<"Play again? (y/n): ";
                char choice;
                cin>>choice;
                if(choice=='y'||choice =='Y'){
                    board.assign(height, vector<int>(width, 0));
                    score=0;
                    current=tetrominoes[rand()%tetrominoes.size()];
                    position={width/2,0};
                    continue;
                } 
                else{
                    break;
                }
            }
        }
        input();
        drawBoard();
    }
}

int main(){
    srand(time(0));
    cout<<"Enter grid width: ";
    cin>>width;
    cout<<"Enter grid height: ";
    cin>>height;
    board.assign(height, vector<int>(width, 0));
    current=tetrominoes[rand() % tetrominoes.size()];
    position={width/2,0};
    hideCursor();
    gameLoop();
    return 0;
}
