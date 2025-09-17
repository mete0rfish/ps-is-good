#include <iostream>
#include <map>

using namespace std;

int N;
char arr[1001][1001];
int h_x = 0;
int h_y=0;

void find_heart() {
    for(int i=1;i<N-1;i++) {
        for(int j=1;j<N-1;j++) {
             if(arr[i][j] == '*' &&
                 arr[i-1][j] == '*' && arr[i+1][j] == '*' &&
                 arr[i][j-1] == '*' && arr[i][j+1] == '*')
            {
                h_x = i;
                h_y = j;
            }
        }
    }
}

void print_left_arm() {
    int cnt = 0;
    for(int y=h_y-1;y>=0;y--) {
        if(arr[h_x][y] != '*') break;
        cnt++;
    }
    cout << cnt << ' ';
}

void print_right_arm() {
    int cnt = 0;
    for(int y=h_y+1;y<N;y++) {
        if(arr[h_x][y] != '*') break;
        cnt++;
    }
    cout << cnt << ' ';
}

void print_leg(int sx, int sy) {
    int cnt = 0;
    for(int x = sx; x<N;x++) {
        if(arr[x][sy] != '*') break;
        cnt++;
    }
    cout << cnt << ' ';
}


void print_wrist() {
    int cnt = 0;
    int x = 0;
    for(x=h_x+1;x<N;x++) {
        if(arr[x][h_y] != '*') break;
        cnt++;
    }
    cout << cnt << ' ';

    print_leg(x, h_y-1);
    print_leg(x, h_y+1);
}


int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    find_heart();
    cout << h_x+1 << " " << h_y+1 << endl;
    print_left_arm();
    print_right_arm();
    print_wrist();
    
    return 0;
}