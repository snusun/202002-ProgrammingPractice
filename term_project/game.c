#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>

void setBufferedInput(bool enable) {
	static bool enabled = true;
	static struct termios old;
	struct termios new;

	if (enable && !enabled) {
		tcsetattr(STDIN_FILENO,TCSANOW,&old);
		enabled = true;
	} else if (!enable && enabled) {
		tcgetattr(STDIN_FILENO,&new);
		old = new;
		new.c_lflag &=(~ICANON & ~ECHO);
		tcsetattr(STDIN_FILENO,TCSANOW,&new);
		enabled = false;
	}
}

int findTarget(int arr[4],int n,int stop) {
	if (!n) return n;
	for(int i=n-1; ; i--) {
		if (arr[i]) {
			if (arr[i]!=arr[n]) return i+1;
			return i;
		} else {
        if (i==stop) return i;
		}
	}
	return n;
}

bool slideArray(int arr[4]) {
	bool slide = false;
	int t,stop=0;

	for (int i=0; i<4; i++) {
		if (arr[i]) {
			t = findTarget(arr,i,stop);
			if (t!=i) {
				if (!arr[t]) {
					arr[t]=arr[i];
				} else if (arr[t]==arr[i]) {
					arr[t]++;
					stop = t+1;
				}
				arr[i]=0;
				slide = true;
			}
		}
	}
	return slide;
}

void Turn(int game[4][4]) {
	for (int i=0; i<2; i++) {
		for (int j=i; j<4-i-1; j++) {
			int tmp = game[i][j];
			game[i][j] = game[j][4-i-1];
			game[j][4-i-1] = game[4-i-1][4-j-1];
			game[4-i-1][4-j-1] = game[4-j-1][i];
			game[4-j-1][i] = tmp;
		}
	}
}

bool Direction(int game[4][4], char c) {
  bool move;
  if(c=='u'){
    move = false;
    for (int i=0; i<4; i++) move |= slideArray(game[i]);
    return move;
  } else if(c=='d'){
    Turn(game);
    Turn(game);
    for (int i=0; i<4; i++) move |= slideArray(game[i]);
    Turn(game);
    Turn(game);
    return move;
  } else if(c=='l'){
    Turn(game);
    for (int i=0; i<4; i++) move |= slideArray(game[i]);
    Turn(game);
    Turn(game);
    Turn(game);
    return move;
  } else if(c=='r'){
    Turn(game);
    Turn(game);
    Turn(game);
    for (int i=0; i<4; i++) move |= slideArray(game[i]);
    Turn(game);
    return move;
  }
  return false;
}

bool findPair(int game[4][4]) {
	for (int i=0; i<4; i++) {
		for (int j=0; j<3; j++) {
			if (game[i][j]==game[i][j+1]) return true;
		}
	}
	return false;
}

bool isEmpty(int game[4][4]) {
  int count=0;
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (game[i][j]==0) {
				count++;
			}
		}
	}
	return (count>0) ? false : true;
}

bool gameOver(int game[4][4]) {
	bool over = true;
	if (!isEmpty(game)) return false;
	if (findPair(game)) return false;
	Turn(game);
	if (findPair(game)) over = false;
	Turn(game);
	Turn(game);
	Turn(game);
	return over;
}

void generateTile(int game[4][4]) {
  int i, j;
	int r, len=0;
	int n, list[4*4][2];

	for (i=0; i<4; i++) {
		for (j=0; j<4; j++) {
			if (game[i][j] == 0) {
				list[len][0]=i;
				list[len][1]=j;
				len++;
			}
		}
	}

	if (len) {
		r = rand()%len;
		i = list[r][0];
		j = list[r][1];
		n = (rand()%10)/9+1;
		game[i][j]=n;
	}
}

void coloring(int value, char* c) {
	int original[] = {8,255,1,255,2,255,3,255,4,255,5,255,6,255,7,255,9,0,10,0,11,0,12,0,13,0,14,0,255,0,255,0};
	int *schemes[] = {original};
	int *bg = schemes[0]+0;
	int *fg = schemes[0]+1;
	if (value > 0) {
    while (value--) {
		  if (bg+2<schemes[0]+sizeof(original)) bg+=2; fg+=2;
	  }
  }
	snprintf(c, 40,"\033[38;5;%d;48;5;%dm",*fg,*bg);
}

void setGame(int game[4][4]) {
	char color[40];
	printf("\033[H");

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			coloring(game[j][i], color);
			printf("%s",color);
			printf("       ");
			printf("%s","\033[m");
		}
		printf("\n");
		for (int j=0; j<4; j++) {
			coloring(game[j][i], color);
			printf("%s",color);
			if (game[j][i]!=0) {
				char s[8];
				snprintf(s,8,"%u",(int)1<<game[j][i]);
				int t = 7-strlen(s);
				printf("%*s%s%*s",t-t/2,"",s,t/2,"");
			} else {
				printf("       ");
			}
			printf("%s","\033[m");
		}
		printf("\n");
		for (int j=0; j<4; j++) {
			coloring(game[j][i], color);
			printf("%s",color);
			printf("       ");
			printf("%s","\033[m");
		}
		printf("\n");
	}
	printf("\n");
	printf("\033[A");
}

void startGame(int game[4][4]) {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			game[i][j]=0;
		}
	}
	generateTile(game);
	generateTile(game);
	setGame(game);
}

int main(int argc, char *argv[]) {
	int game[4][4];
	char c;
	bool success;

	printf("\033[?25l\033[2J");

	startGame(game);
	setBufferedInput(false);
	while (true) {
		c=getchar();
		if (c == -1){
			puts("\nKeyError");
			break;
		} 
		switch(c) {
			case 97:
        success = Direction(game, 'l');
        break;
			case 68:
				success = Direction(game, 'l');  
        break;
			case 100:
        success = Direction(game, 'r');
        break;
			case 67:
				success = Direction(game, 'r');
        break;
			case 119:
        success = Direction(game, 'u');
        break;
			case 65:
				success = Direction(game, 'u');
        break;
			case 115:
        success = Direction(game, 'd');
        break;
			case 66:
				success = Direction(game, 'd');
        break;
			default: success = false;
		}
		if (success) {
			setGame(game);
			generateTile(game);
			setGame(game);
			if (gameOver(game)) {
				printf("game over\n");
				break;
			}
		}
	}
	setBufferedInput(true);
	printf("\033[?25h\033[m");
	return 0;
}