#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define rep(v,b,e) for(int v=b;v<=e;v++)
#define repq(v,b,e) for(int v=b;v<e;v++)
#define rrep(v,e,b) for(int v=b;v>=e;v--)
#define rrepq(v,e,b) for(int v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CAR 10
#define HORSE 1
#define ELEPHANT 2
#define GUARD 3
#define KING 4
#define SOILDER 5
#define DUCK 6
#define RED 8 
#define BLUE 9 

int chess[15][15];
int color[15][15];
map<int, string> duiyin = {
  {CAR, "car"}, {HORSE, "horse"}, {ELEPHANT, "elephant"}, 
  {GUARD, "guard"}, {KING, "captain"}, {SOILDER, "soldier"}, 
  {DUCK, "duck"}, {RED, "red"}, {BLUE, "blue"}
};

void init() {
  int firstline[10] = {CAR, HORSE, ELEPHANT, GUARD, KING, GUARD, ELEPHANT, HORSE, CAR};
  repq(i, 0, 9) {
    chess[0][i] = chess[9][i] = firstline[i];
    color[0][i] = RED;
    color[9][i] = BLUE;
  }
  rep(i, 0, 8) {
    if (i & 1) continue;
    chess[3][i] = chess[6][i] = SOILDER;
    color[3][i] = RED;
    color[6][i] = BLUE;
  }
  chess[2][0] = chess[2][8] = chess[7][8] = chess[7][0] = DUCK;
  color[2][0] = color[2][8] = RED;
  color[7][8] = color[7][0] = BLUE;
}

int turn = RED;
bool gameover = 0;
#define INVALID printf("Invalid command\n");

void solve() {
  int fromx, tox, fromy, toy;
  cin >> fromx >> fromy >> tox >> toy;
  if (gameover) {
    INVALID; return;
  }
  if (!chess[fromx][fromy]) {
    INVALID; return;
  }
  if (color[fromx][fromy] != turn) {
    INVALID; return;
  }
  if (color[tox][toy] == turn) {
    INVALID; return;
  }
  int ordinal = chess[tox][toy], ordinalcolor = color[tox][toy];
  if (chess[fromx][fromy] == CAR) {
    if (abs(fromy - toy) == 0) {
      repq(i, fromx + 1, tox) {
        if (chess[i][toy]) {
          INVALID; return;
        }
      }
    } else if (abs(fromx - tox) == 0) {
      repq(i, fromy + 1, toy) {
        if (chess[tox][i]) {
          INVALID; return;
        }
      }
    } else {
      INVALID; return;
    }
    cout << duiyin[turn] << ' ' << duiyin[CAR] << ';';
    chess[fromx][fromy] = 0;
    chess[tox][toy] = CAR;
    color[tox][toy] = turn;
    color[fromx][fromy] = 0;
    if (ordinal && abs(ordinalcolor - turn) == 1) {
      cout << duiyin[ordinalcolor] << ' ' << duiyin[ordinal] << ';';
      if (ordinal == KING) {
        cout << "no;yes\n";
        gameover = 1;
        goto lastturn;
      }
    } else {
      cout << "NA;";
    }
    repq(x, 0, 10) {
      if (chess[tox][x] == KING || chess[x][toy] == KING) {
        cout << "yes;no;\n";
        goto lastturn;
      } 
    }
    cout << "no;no\n";
    goto lastturn;
  }
  if (chess[fromx][fromy] == GUARD) {
    if (abs(fromx - tox) == 1  && abs(fromy - toy) == 1) {
      cout << duiyin[turn] << ' ' << duiyin[GUARD] << ';';
    } else {
      INVALID; return;
    }
    chess[fromx][fromy] = 0;
    chess[tox][toy] = GUARD;
    color[tox][toy] = turn;
    color[fromx][fromy] = 0;
    if (ordinal && abs(ordinalcolor - turn) == 1) {
      cout << duiyin[ordinalcolor] << ' ' << duiyin[ordinal] << ';';
      if (ordinal == KING) {
        cout << "no;yes\n";
        gameover = 1;
        goto lastturn;
      }
    } else {
      cout << "NA;";
    }
    int dxy[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    repq(i, 0, 4) {
      int dx = dxy[i][0] + tox;
      int dy = dxy[i][1] + toy;
      if (dx < 0 || dx > 9 || dy < 0 || dy > 8) continue;
      if (chess[dx][dy] == KING && abs(color[dx][dy] - turn) == 1) {
        cout << "yes;no\n";
        goto lastturn;
      }
    }
    cout << "no;no\n";
    goto lastturn;
  }
  if (chess[fromx][fromy] == HORSE) {
    if (abs(fromx - tox) == 2 && abs(fromy - toy) == 1) {
      int sx = (fromx - tox) / 2;
      int sy = (fromy - toy);
      sx = -sx, sy = -sy;
      if (chess[sx + fromx][fromy]) {
        INVALID; return;
      }
    } else if (abs(fromx - tox) == 1 && abs(fromy - toy) == 2) {
      int sx = (fromx - tox);
      int sy = (fromy - toy) / 2;
      sx = -sx, sy = -sy;
      if (chess[fromx][sy + fromy]) {
        INVALID; return;
      }
    } else {
      INVALID; return;
    }
    cout << duiyin[color[fromx][fromy]] << ' ' << duiyin[HORSE] << ';';
    chess[fromx][fromy] = 0;
    chess[tox][toy] = HORSE;
    color[tox][toy] = turn;
    color[fromx][fromy] = 0;
    if (ordinal && abs(ordinalcolor - turn) == 1) {
      cout << duiyin[ordinalcolor] << ' ' << duiyin[ordinal] << ';';
      if (ordinal == KING) {
        cout << "no;yes\n";
        gameover = 1;
        goto lastturn;
      }
    } else {
      cout << "NA;";
    }
    int dxy[4][2] = {{2, 1}, {1, 2}, {-1, -2}, {-2, -1}};
    repq(i, 0, 4) {
      int dx = dxy[i][0] + tox;
      int dy = dxy[i][1] + toy;
      if (dx < 0 || dx > 9 || dy < 0 || dy > 8) continue;
      if (chess[dx][dy] == KING && abs(color[dx][dy] - turn) == 1) {
        cout << "yes;no\n";
        goto lastturn;
      }
    }
    cout << "no;no\n";
    goto lastturn;
  }
  if (chess[fromx][fromy] == SOILDER) {
    if (abs(fromx - tox) <= 1 && abs(fromy - toy) <= 1) {
      cout << duiyin[color[fromx][fromy]] << ' ' << duiyin[SOILDER] << ';';
    } else {
      INVALID;
      return;
    }
    chess[tox][toy] = SOILDER;
    chess[fromx][fromy] = 0;
    color[tox][toy] = turn;
    color[fromx][fromy] = 0;
    if (ordinal && abs(ordinalcolor - turn) == 1) {
      cout << duiyin[ordinalcolor] << ' ' << duiyin[ordinal] << ';';
      if (ordinal == KING) {
        cout << "no;yes\n";
        gameover = 1;
        goto lastturn;
      }
    } else {
      cout << "NA;";
    }
    int dxy[8][2] = {{0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, 0}, {0, -1}};
    repq(i, 0, 8) {
      int dx = dxy[i][0] + tox;
      int dy = dxy[i][1] + toy;
      if (dx < 0 || dx > 9 || dy < 0 || dy > 8) continue;
      if (chess[dx][dy] == KING && abs(color[dx][dy] - turn) == 1) {
        cout << "yes;no\n";
        goto lastturn;
      }
    }
    cout << "no;no\n";
  }
  if (chess[fromx][fromy] == ELEPHANT) {
    if (abs(fromx - tox) == 2 && abs(fromy - toy) == 2) {
      int sx = (fromx - tox) / 2, sy = (fromy - toy) / 2;
      if (chess[fromx + sx][fromy + sy]) {
        INVALID;
        return;
      }
    } else {
      INVALID; return;
    }
    chess[tox][toy] = ELEPHANT;
    chess[fromx][fromy] = 0;
    color[tox][toy] = turn;
    color[fromx][fromy] = 0;
    if (ordinal && abs(ordinalcolor - turn) == 1) {
      cout << duiyin[ordinalcolor] << ' ' << duiyin[ordinal] << ';';
      if (ordinal == KING) {
        cout << "no;yes\n";
        gameover = 1;
        goto lastturn;
      }
    } else {
      cout << "NA;";
    }
    int dxy[4][2] = {{2, 2}, {-2, 2}, {2, -2}, {-2, -2}};
    repq(i, 0, 4) {
      int dx = dxy[i][0] + tox;
      int dy = dxy[i][1] + toy;
      if (dx < 0 || dx > 9 || dy < 0 || dy > 8) continue;
      if (chess[dx][dy] == KING && abs(color[dx][dy] - turn) == 1) {
        cout << "yes;no\n";
        goto lastturn;
      }
    }
    cout << "no;no\n";
  }
  if (chess[fromx][fromy] == DUCK) {
    if (abs(fromx - tox) == 3 && abs(fromy - toy) == 2) {
      int sx = (fromx - tox) / 3, sy = (fromy - toy) / 2;
      sx = -sx, sy = -sy;
      if (chess[fromx + sx * 2][fromy + sy] || chess[fromx + sx][fromy]) {
        INVALID;
        return;
      }
    } else if (abs(fromx - tox) == 2 && abs(fromy - toy) == 3) {
      int sx = (fromx - tox) / 2, sy = (fromy - toy) / 3;
      sx = -sx, sy = -sy;
      if (chess[fromx + sx][fromy + sy * 2] || chess[fromx][fromy + sy]) {
        INVALID;
        return;
      }
    } else {
      INVALID;
      return;
    }
    cout << duiyin[turn] << ' ' << duiyin[DUCK] << ';';
    chess[tox][toy] = DUCK;
    chess[fromx][fromy] = 0;
    color[tox][toy] = turn;
    color[fromx][fromy] = 0;
    if (ordinal && abs(ordinalcolor - turn) == 1) {
      cout << duiyin[ordinalcolor] << ' ' << duiyin[ordinal] << ';';
      if (ordinal == KING) {
        cout << "no;yes\n";
        gameover = 1;
        goto lastturn;
      }
    } else {
      cout << "NA;";
    }
    int dxy[4][2] = {{3, 2}, {-3, 2}, {3, -2}, {-3, -2}};
    repq(i, 0, 4) {
      int dx = dxy[i][0] + tox;
      int dy = dxy[i][1] + toy;
      if (dx < 0 || dx > 9 || dy < 0 || dy > 8) continue;
      if (chess[dx][dy] == KING && abs(color[dx][dy] - turn) == 1) {
        cout << "yes;no\n";
        goto lastturn;
      }
    }
    cout << "no;no\n";
    goto lastturn;
  }
  if (chess[fromx][fromy] == KING) {
    if (abs(fromx - tox) + abs(fromy - toy) > 1) {
      INVALID;
      return;
    }
    cout << duiyin[turn] << ' ' << duiyin[KING] << ';';
    chess[tox][toy] = KING;
    chess[fromx][fromy] = 0;
    color[tox][toy] = turn;
    color[fromx][fromy] = 0;
    if (ordinal && abs(ordinalcolor - turn) == 1) {
      cout << duiyin[ordinalcolor] << ' ' << duiyin[ordinal] << ';';
      if (ordinal == KING) {
        cout << "no;yes\n";
        gameover = 1;
        goto lastturn;
      }
    } else {
      cout << "NA;";
    }
    int dxy[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    repq(i, 0, 4) {
      int dx = dxy[i][0] + tox;
      int dy = dxy[i][1] + toy;
      if (dx < 0 || dx > 9 || dy < 0 || dy > 8) continue;
      if (chess[dx][dy] && abs(color[dx][dy] - turn) == 1) {
        cout << "yes;no\n";
        goto lastturn;
      }
    }
    cout << "no;no\n";
    goto lastturn;
  }
  lastturn:;
  if (turn == RED) turn = BLUE;
  else turn = RED;
}

main() {
  init();
	int t; cin >> t; while (t--) solve();
  
	return 0;
}
