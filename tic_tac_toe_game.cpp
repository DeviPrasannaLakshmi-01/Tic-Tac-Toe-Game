#include <iostream>
using namespace std;

char b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char p='X';

void show(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool win(){
    for(int i=0;i<3;i++){
        if(b[i][0]==p&&b[i][1]==p&&b[i][2]==p) return true;
        if(b[0][i]==p&&b[1][i]==p&&b[2][i]==p) return true;
    }
    if(b[0][0]==p&&b[1][1]==p&&b[2][2]==p) return true;
    if(b[0][2]==p&&b[1][1]==p&&b[2][0]==p) return true;
    return false;
}

int main(){
    int c;
    for(int i=0;i<9;i++){
        show();
        cout<<"Player "<<p<<": ";
        cin>>c;

        int r=(c-1)/3, col=(c-1)%3;

        if(b[r][col]!='X'&&b[r][col]!='O'){
            b[r][col]=p;
            if(win()){
                show();
                cout<<"Player "<<p<<" wins!";
                return 0;
            }
            p=(p=='X')?'O':'X';
        } else i--;
    }
    cout<<"Draw!";
}