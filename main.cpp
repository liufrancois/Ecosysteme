#include<cstdio>
#include<iostream>

using namespace std;


class cases{
    public:
    int herbe; // 0 = non / 1 = oui
    int sels = 0;
    int time_sels;
    cases(){
        (this)->herbe = 1;
        time_sels = 0;
    }
};

class annimal{
    public:
    char *name; // Loup / Mouton
    int age;
    int faim;
    int act;
    int sexe;

    int cood_x;
    int cood_y;

    annimal(){
        name = "";
        age = 0;
        faim = 0;
        act = 0;
        sexe = rand() % 2;
    }

    void create(char *N, int X, int Y){
        name = N;
        age = 0;
        faim = 0;
        act = 2;

        cood_x = X;
        cood_y = Y;
    }

    void create_n(char *N, int X, int Y){
        name = N;
        age = 0;
        faim = 0;
        act = 0;

        cood_x = X;
        cood_y = Y;
    }

    void remove(){
        name = "";
        age = 0;
        faim = 0;
    }

    void move(annimal t_A[100][100], int X, int Y){
        t_A[X][Y] = t_A[cood_x][cood_y];
        t_A[cood_x][cood_y].remove();
        t_A[cood_x][cood_y].cood_x = cood_x;
        t_A[cood_x][cood_y].cood_y = cood_y;
        t_A[X][Y].cood_x = X;
        t_A[X][Y].cood_y = Y;
        return;
    }

    void manger_Mouton(annimal t_A[100][100], int X, int Y){
        cout << "Loup (" << X << Y << ") à mangé un Mouton." << endl;
        t_A[X][Y] = t_A[cood_x][cood_y];
        t_A[cood_x][cood_y].remove();
        t_A[cood_x][cood_y].cood_x = cood_x;
        t_A[cood_x][cood_y].cood_y = cood_y;
        t_A[X][Y].cood_x = X;
        t_A[X][Y].cood_y = Y;
        t_A[X][Y].faim = 0;
        cout << "mangé " << X << Y << endl;
        return;
    }

    void manger_Herbe(annimal t_A[100][100], cases t_C[100][100]){
        t_C[cood_x][cood_y].herbe = 0;
        t_A[cood_x][cood_y].faim = 0;
        return;
    }

    void reproduction_loup(annimal tableau[100][100],int x, int y, int taille_x, int taille_y){
        if (tableau[cood_x+1][cood_y+1].name == "" && cood_x+1 != taille_x && cood_y+1 != taille_y){
            tableau[cood_x+1][cood_y+1].create("petit_loup", cood_x+1, cood_y+1);
        }
        else if (tableau[cood_x+1][cood_y].name == "" && cood_x+1 != taille_x){
            tableau[cood_x+1][cood_y].create("petit_loup", cood_x+1, cood_y);
        }
        else if (tableau[cood_x+1][cood_y-1].name == "" && cood_x+1 != taille_x && cood_y != 0){
            tableau[cood_x+1][cood_y-1].create("petit_loup", cood_x+1, cood_y-1);
        }
        else if (tableau[cood_x-1][cood_y].name == "" && cood_x != 0){
            tableau[cood_x-1][cood_y].create("petit_loup", cood_x-1, cood_y);
        }
        else if (tableau[cood_x-1][cood_y-1].name == "" && cood_x != 0 && cood_y != 0){
            tableau[cood_x-1][cood_y-1].create("petit_loup", cood_x-1, cood_y-1);
        }
        else if (tableau[cood_x][cood_y+1].name == "" && cood_y+1 != taille_y){
            tableau[cood_x][cood_y+1].create("petit_loup", cood_x, cood_y+1);
        }
        else if (tableau[cood_x][cood_y-1].name == "" && cood_y != 0){
            tableau[cood_x][cood_y-1].create("petit_loup", cood_x, cood_y-1);
        }
        else if (tableau[cood_x-1][cood_y+1].name == "" && cood_x != 0 && cood_y+1 != taille_y){
            tableau[cood_x-1][cood_y+1].create("petit_loup", cood_x-1, cood_y+1);
        }


        else if (tableau[x+1][y+1].name == "" && x+1 != taille_x && y+1 != taille_y){
            tableau[x+1][y+1].create("petit_loup", x+1, y+1);
        }
        else if (tableau[x+1][y].name == "" && x+1 != taille_x){
            tableau[x+1][y].create("petit_loup", x+1, y);
        }
        else if (tableau[x+1][y-1].name == "" && x+1 != taille_x && y != 0){
            tableau[x+1][y-1].create("petit_loup", x+1, -1);
        }
        else if (tableau[x-1][y].name == "" && x != 0){
            tableau[x-1][y].create("petit_loup", x-1, y);
        }
        else if (tableau[x-1][y-1].name == "" && x != 0 && y != 0){
            tableau[x-1][y-1].create("petit_loup", x-1, y-1);
        }
        else if (tableau[x][y+1].name == "" && y+1 != taille_y){
            tableau[x][y+1].create("petit_loup", x, y+1);
        }
        else if (tableau[x][y-1].name == "" && y != 0){
            tableau[x][y-1].create("petit_loup", x, y-1);
        }
        else if (tableau[x-1][y+1].name == "" && x != 0 && y+1 != taille_y){
            tableau[x-1][y+1].create("petit_loup", x-1, y+1);
        }
        cout << "creation petit_loup)" << x << y << endl; 
    }

    void reproduction_mouton(annimal tableau[100][100],int x, int y, int taille_x, int taille_y){
        if (tableau[cood_x+1][cood_y+1].name == "" && cood_x+1 != taille_x && cood_y+1 != taille_y){
            tableau[cood_x+1][cood_y+1].create("petit_mouton", cood_x+1, cood_y+1);
        }
        else if (tableau[cood_x+1][cood_y].name == "" && cood_x+1 != taille_x){
            tableau[cood_x+1][cood_y].create("petit_mouton", cood_x+1, cood_y);
        }
        else if (tableau[cood_x+1][cood_y-1].name == "" && cood_x+1 != taille_x && cood_y != 0){
            tableau[cood_x+1][cood_y-1].create("petit_mouton", cood_x+1, cood_y-1);
        }
        else if (tableau[cood_x-1][cood_y].name == "" && cood_x != 0){
            tableau[cood_x-1][cood_y].create("petit_mouton", cood_x-1, cood_y);
        }
        else if (tableau[cood_x-1][cood_y-1].name == "" && cood_x != 0 && cood_y != 0){
            tableau[cood_x-1][cood_y-1].create("petit_mouton", cood_x-1, cood_y-1);
        }
        else if (tableau[cood_x][cood_y+1].name == "" && cood_y+1 != taille_y){
            tableau[cood_x][cood_y+1].create("petit_mouton", cood_x, cood_y+1);
        }
        else if (tableau[cood_x][cood_y-1].name == "" && cood_y != 0){
            tableau[cood_x][cood_y-1].create("petit_mouton", cood_x, cood_y-1);
        }
        else if (tableau[cood_x-1][cood_y+1].name == "" && cood_x != 0 && cood_y+1 != taille_y){
            tableau[cood_x-1][cood_y+1].create("petit_mouton", cood_x-1, cood_y+1);
        }


        else if (tableau[x+1][y+1].name == "" && x+1 != taille_x && y+1 != taille_y){
            tableau[x+1][y+1].create("petit_mouton", x+1, y+1);
        }
        else if (tableau[x+1][y].name == "" && x+1 != taille_x){
            tableau[x+1][y].create("petit_mouton", x+1, y);
        }
        else if (tableau[x+1][y-1].name == "" && x+1 != taille_x && y != 0){
            tableau[x+1][y-1].create("petit_mouton", x+1, -1);
        }
        else if (tableau[x-1][y].name == "" && x != 0){
            tableau[x-1][y].create("petit_mouton", x-1, y);
        }
        else if (tableau[x-1][y-1].name == "" && x != 0 && y != 0){
            tableau[x-1][y-1].create("petit_mouton", x-1, y-1);
        }
        else if (tableau[x][y+1].name == "" && y+1 != taille_y){
            tableau[x][y+1].create("petit_mouton", x, y+1);
        }
        else if (tableau[x][y-1].name == "" && y != 0){
            tableau[x][y-1].create("petit_mouton", x, y-1);
        }
        else if (tableau[x-1][y+1].name == "" && x != 0 && y+1 != taille_y){
            tableau[x-1][y+1].create("petit_mouton", x-1, y+1);
        }
        
    }




    void action(annimal tableau[100][100],cases t_C[100][100], int taille_x, int taille_y){
        if (tableau[cood_x][cood_y].act != 0){
            return;
        }

        if (tableau[cood_x][cood_y].name == "Loup"){
            //possibilité
            int nb = 0;

            int num[50];


            int action[50][2] = {
                {cood_x, cood_y},
                {cood_x+1, cood_y+1},
                {cood_x+1, cood_y},
                {cood_x+1, cood_y-1},
                {cood_x-1, cood_y},
                {cood_x-1, cood_y-1},
                {cood_x, cood_y+1},
                {cood_x, cood_y-1},
                {cood_x-1, cood_y+1},
                {cood_x+1, cood_y+1},
                {cood_x+1, cood_y},
                {cood_x+1, cood_y-1},
                {cood_x-1, cood_y},
                {cood_x-1, cood_y-1},
                {cood_x, cood_y+1},
                {cood_x, cood_y-1},
                {cood_x-1, cood_y+1},
                {cood_x+1, cood_y+1},
                {cood_x+1, cood_y},
                {cood_x+1, cood_y-1},
                {cood_x-1, cood_y},
                {cood_x-1, cood_y-1},
                {cood_x, cood_y+1},
                {cood_x, cood_y-1},
                {cood_x-1, cood_y+1}
            };

            //rester
            num[nb] = 0;
            nb++;

            if (tableau[cood_x+1][cood_y+1].name == "" && cood_x+1 != taille_x && cood_y+1 != taille_y){
                num[nb] = 1;
                nb++;
            }
            if (tableau[cood_x+1][cood_y].name == "" && cood_x+1 != taille_x){
                num[nb] = 2;
                nb++;
            }
            if (tableau[cood_x+1][cood_y-1].name == "" && cood_x+1 != taille_x && cood_y != 0){
                num[nb] = 3;
                nb++;
            }
            if (tableau[cood_x-1][cood_y].name == "" && cood_x != 0){
                num[nb] = 4;
                nb++;
            }
            if (tableau[cood_x-1][cood_y-1].name == "" && cood_x != 0 && cood_y != 0){
                num[nb] = 5;
                nb++;
            }
            if (tableau[cood_x][cood_y+1].name == "" && cood_y+1 != taille_y){
                num[nb] = 6;
                nb++;
            }
            if (tableau[cood_x][cood_y-1].name == "" && cood_y != 0){
                num[nb] = 7;
                nb++;
            }
            if (tableau[cood_x-1][cood_y+1].name == "" && cood_x != 0 && cood_y+1 != taille_y){
                num[nb] = 8;
                nb++;
            }

            //Manger

            if (tableau[cood_x+1][cood_y+1].name == "Mouton" && cood_x+1 != taille_x && cood_y+1 != taille_y){
                num[nb] = 9;
                nb++;
                num[nb] = 9;
                nb++;
            }
            if (tableau[cood_x+1][cood_y].name == "Mouton" && cood_x+1 != taille_x){
                num[nb] = 10;
                nb++;
                num[nb] = 10;
                nb++;
            }
            if (tableau[cood_x+1][cood_y-1].name == "Mouton" && cood_x+1 != taille_x && cood_y != 0){
                num[nb] = 11;
                nb++;
                num[nb] = 11;
                nb++;
            }
            if (tableau[cood_x-1][cood_y].name == "Mouton" && cood_x != 0){
                num[nb] = 12;
                nb++;
                num[nb] = 12;
                nb++;
            }
            if (tableau[cood_x-1][cood_y-1].name == "Mouton" && cood_x != 0 && cood_y != 0){
                num[nb] = 13;
                nb++;
                num[nb] = 13;
                nb++;
            }
            if (tableau[cood_x][cood_y+1].name == "Mouton" && cood_y+1 != taille_y){
                num[nb] = 14;
                nb++;
                num[nb] = 14;
                nb++;
            }
            if (tableau[cood_x][cood_y-1].name == "Mouton" && cood_y != 0){
                num[nb] = 15;
                nb++;
                num[nb] = 15;
                nb++;
            }
            if (tableau[cood_x-1][cood_y+1].name == "Mouton" && cood_x != 0 && cood_y+1 != taille_y){
                num[nb] = 16;
                nb++;
                num[nb] = 16;
                nb++;
            }

            //reproduction


            if (tableau[cood_x+1][cood_y+1].name == "Loup" && tableau[cood_x][cood_y].sexe != tableau[cood_x+1][cood_y+1].sexe && cood_x+1 != taille_x && cood_y+1 != taille_y){
                num[nb] = 17;
                nb++;
                num[nb] = 17;
                nb++;
            }
            if (tableau[cood_x+1][cood_y].name == "Loup" && tableau[cood_x][cood_y].sexe != tableau[cood_x+1][cood_y].sexe && cood_x+1 != taille_x){
                num[nb] = 18;
                nb++;
                num[nb] = 18;
                nb++;
            }
            if (tableau[cood_x+1][cood_y-1].name == "Loup" && tableau[cood_x][cood_y].sexe != tableau[cood_x+1][cood_y-1].sexe && cood_x+1 != taille_x && cood_y != 0){
                num[nb] = 19;
                nb++;
                num[nb] = 19;
                nb++;
            }
            if (tableau[cood_x-1][cood_y].name == "Loup" && tableau[cood_x][cood_y].sexe != tableau[cood_x-1][cood_y].sexe && cood_x != 0){
                num[nb] = 20;
                nb++;
                num[nb] = 20;
                nb++;
            }
            if (tableau[cood_x-1][cood_y-1].name == "Loup" && tableau[cood_x][cood_y].sexe != tableau[cood_x-1][cood_y-1].sexe && cood_x != 0 && cood_y != 0){
                num[nb] = 21;
                nb++;
                num[nb] = 21;
                nb++;
            }
            if (tableau[cood_x][cood_y+1].name == "Loup" && tableau[cood_x][cood_y].sexe != tableau[cood_x][cood_y+1].sexe && cood_y+1 != taille_y){
                num[nb] = 22;
                nb++;
                num[nb] = 22;
                nb++;
            }
            if (tableau[cood_x][cood_y-1].name == "Loup" && tableau[cood_x][cood_y].sexe != tableau[cood_x][cood_y-1].sexe && cood_y != 0){
                num[nb] = 23;
                nb++;
                num[nb] = 23;
                nb++;
            }
            if (tableau[cood_x-1][cood_y+1].name == "Loup" && tableau[cood_x][cood_y].sexe != tableau[cood_x-1][cood_y+1].sexe && cood_x != 0 && cood_y+1 != taille_y){
                num[nb] = 24;
                nb++;
                num[nb] = 24;
                nb++;
            }

            int R = rand() % nb;

            if (num[R] == 0){
                tableau[cood_x][cood_y].act = 1;
                return;
            }
            else if (num[R] <= 8){
                tableau[cood_x][cood_y].move(tableau, action[num[R]][0], action[num[R]][1]);
                tableau[cood_x][cood_y].act = 1;
                tableau[action[num[R]][0]][action[num[R]][1]].act = 1;
            }
            else if (num[R] > 8 && num[R] <= 16){
                tableau[cood_x][cood_y].manger_Mouton(tableau, action[num[R]][0], action[num[R]][1]);
                tableau[cood_x][cood_y].act = 1;
                tableau[action[num[R]][0]][action[num[R]][1]].act = 1;
            }
            else{
                tableau[cood_x][cood_y].reproduction_loup(tableau, action[num[R]][0], action[num[R]][1], taille_x, taille_y);
                tableau[cood_x][cood_y].act = 2;
                tableau[action[num[R]][0]][action[num[R]][1]].act = 2;
            }
        }

        if (tableau[cood_x][cood_y].name == "Mouton"){
            //possibilité
            int nb = 0;
            int num[50];

            int action[20][2] = {
                {cood_x, cood_y},
                {cood_x+1, cood_y+1},
                {cood_x+1, cood_y},
                {cood_x+1, cood_y-1},
                {cood_x-1, cood_y},
                {cood_x-1, cood_y-1},
                {cood_x, cood_y+1},
                {cood_x, cood_y-1},
                {cood_x-1, cood_y+1},
                {cood_x, cood_y},
                {cood_x+1, cood_y+1},
                {cood_x+1, cood_y},
                {cood_x+1, cood_y-1},
                {cood_x-1, cood_y},
                {cood_x-1, cood_y-1},
                {cood_x, cood_y+1},
                {cood_x, cood_y-1},
                {cood_x-1, cood_y+1}
            };

            //rester
            num[nb] = 0;
            nb++;
            
            if (tableau[cood_x+1][cood_y+1].name == "" && cood_x+1 != taille_x && cood_y+1 != taille_y){
                num[nb] = 1;
                nb++;
            }
            if (tableau[cood_x+1][cood_y].name == "" && cood_x+1 != taille_x){
                num[nb] = 2;
                nb++;
            }
            if (tableau[cood_x+1][cood_y-1].name == "" && cood_x+1 != taille_x && cood_y != 0){
                num[nb] = 3;
                nb++;
            }
            if (tableau[cood_x-1][cood_y].name == "" && cood_x != 0){
                num[nb] = 4;
                nb++;
            }
            if (tableau[cood_x-1][cood_y-1].name == "" && cood_x != 0 && cood_y != 0){
                num[nb] = 5;
                nb++;
            }
            if (tableau[cood_x][cood_y+1].name == "" && cood_y+1 != taille_y){
                num[nb] = 6;
                nb++;
            }
            if (tableau[cood_x][cood_y-1].name == "" && cood_y != 0){
                num[nb] = 7;
                nb++;
            }
            if (tableau[cood_x-1][cood_y+1].name == "" && cood_x != 0 && cood_y+1 != taille_y){
                num[nb] = 8;
                nb++;
            }

            //Manger
            if (t_C[cood_x][cood_y].herbe == 1){
                num[nb] = 9;
                nb++;
                num[nb] = 9;
                nb++;
                num[nb] = 9;
                nb++;
            }

            //reproduction
            if (tableau[cood_x+1][cood_y+1].name == "Mouton" && tableau[cood_x][cood_y].sexe != tableau[cood_x+1][cood_y+1].sexe && cood_x+1 != taille_x && cood_y+1 != taille_y){
                num[nb] = 10;
                nb++;
                num[nb] = 10;
                nb++;
            }
            if (tableau[cood_x+1][cood_y].name == "Mouton" && tableau[cood_x][cood_y].sexe != tableau[cood_x+1][cood_y].sexe && cood_x+1 != taille_x){
                num[nb] = 11;
                nb++;
                num[nb] = 11;
                nb++;
            }
            if (tableau[cood_x+1][cood_y-1].name == "Mouton" && tableau[cood_x][cood_y].sexe != tableau[cood_x+1][cood_y-1].sexe && cood_x+1 != taille_x && cood_y != 0){
                num[nb] = 12;
                nb++;
                num[nb] = 12;
                nb++;
            }
            if (tableau[cood_x-1][cood_y].name == "Mouton" && tableau[cood_x][cood_y].sexe != tableau[cood_x-1][cood_y].sexe && cood_x != 0){
                num[nb] = 13;
                nb++;
                num[nb] = 13;
                nb++;
            }
            if (tableau[cood_x-1][cood_y-1].name == "Mouton" && tableau[cood_x][cood_y].sexe != tableau[cood_x-1][cood_y-1].sexe && cood_x != 0 && cood_y != 0){
                num[nb] = 14;
                nb++;
                num[nb] = 14;
                nb++;
            }
            if (tableau[cood_x][cood_y+1].name == "Mouton" && tableau[cood_x][cood_y].sexe != tableau[cood_x][cood_y+1].sexe && cood_y+1 != taille_y){
                num[nb] = 15;
                nb++;
                num[nb] = 15;
                nb++;
            }
            if (tableau[cood_x][cood_y-1].name == "Mouton" && tableau[cood_x][cood_y].sexe != tableau[cood_x][cood_y-1].sexe && cood_y != 0){
                num[nb] = 16;
                nb++;
                num[nb] = 16;
                nb++;
            }
            if (tableau[cood_x-1][cood_y+1].name == "Mouton" && tableau[cood_x][cood_y].sexe != tableau[cood_x-1][cood_y+1].sexe && cood_x != 0 && cood_y+1 != taille_y){
                num[nb] = 17;
                nb++;
                num[nb] = 17;
                nb++;
            }

            int R = rand() % nb;
            if (num[R] == 0){
                tableau[cood_x][cood_y].act=1;
                return;
            }
            else if (num[R] <= 8){
                tableau[cood_x][cood_y].move(tableau, action[num[R]][0], action[num[R]][1]);
                tableau[cood_x][cood_y].act=1;
            }
            else if (num[R] == 9){
                tableau[cood_x][cood_y].manger_Herbe(tableau, t_C);
                tableau[cood_x][cood_y].act=1;
            }
            else{
                tableau[cood_x][cood_y].reproduction_mouton(tableau, action[num[R]][0], action[num[R]][1], taille_x, taille_y);
                tableau[cood_x][cood_y].act=2;
            }
        }
    }

    void MAJ_action(annimal tableau[100][100], cases t_C[100][100], int taille_x, int taille_y){
        for (int x = 0; x != taille_x; x++){
            for (int y = 0; y != taille_y; y++){
                tableau[x][y].act--;
                
                if (t_C[x][y].sels == 1 && t_C[x][y].time_sels == 1){
                    t_C[x][y].herbe = 1;
                    t_C[x][y].sels = 0;
                    t_C[x][y].time_sels = 0;
                }

                if (tableau[x][y].name != ""){
                    tableau[x][y].faim++;
                    tableau[x][y].age++;

                    if (tableau[x][y].name == "petit_loup" && tableau[x][y].act == 0){
                        tableau[x][y].name = "Loup";
                        tableau[x][y].age = 0;
                        tableau[x][y].faim = 0;
                        cout << "Naissance Loup " << x << y << endl;
                    }
                    if (tableau[x][y].name == "petit_mouton" && tableau[x][y].act == 0){
                        tableau[x][y].name = "Mouton";
                        tableau[x][y].age = 0;
                        tableau[x][y].faim = 0;
                        cout << "Naissance Mouton" << x << y << endl;
                    }
                    
                    if (tableau[x][y].name == "Mouton" && tableau[x][y].faim == 5){
                        tableau[x][y].remove();
                        t_C[x][y].sels = 1;
                        t_C[x][y].time_sels = 1;
                        cout << "Mouton est mort de faim" << x << y << endl;
                    }
                    if (tableau[x][y].name == "Loup" && tableau[x][y].faim == 10){
                        tableau[x][y].remove();
                        t_C[x][y].sels = 1;
                        t_C[x][y].time_sels = 1;
                        cout << "Loup est mort de faim" << x << y << endl;
                    }
                    if (tableau[x][y].name == "Mouton" && tableau[x][y].age == 50){
                        tableau[x][y].remove();
                        t_C[x][y].sels = 1;
                        t_C[x][y].time_sels = 1;
                        cout << "Mouton est mort de vieillesse" << x << y << endl;
                    }
                    if (tableau[x][y].name == "Loup" && tableau[x][y].age == 60){
                        tableau[x][y].remove();
                        t_C[x][y].sels = 1;
                        t_C[x][y].time_sels = 1;
                        cout << "Loup est mort de vieillesse" << x << y << endl;
                    }
                }
            }
        }
        return;
    }

    int verif_fin(annimal tableau[100][100], int taille_x, int taille_y){
        for (int x = 0; x != taille_x; x++){
            for (int y = 0; y != taille_y; y++){
                if (tableau[x][y].name != ""){
                    return 1;
                }
            }
        }
        return 0;
    } 
};

class plateau{
    public:
    int taille_x;
    int taille_y;
    cases tableau[100][100];
    annimal t_A[100][100];    
    
    plateau(int m, int n, int loup, int mouton){
        taille_x = m;
        taille_y = n;
        for (int x = 0; x != m; x++){
            for (int y = 0; y != n; y++){
                tableau[x][y] = cases();
                t_A[x][y] = annimal();
            }
        }
        while (loup != 0){
            int R1 = rand() % taille_x;
            int R2 = rand() % taille_y;
            if (t_A[R1][R2].name == ""){
                t_A[R1][R2].create_n("Loup", R1, R2);
                loup--;
            }
        }
        while (mouton != 0){
            int R1 = rand() % taille_x;
            int R2 = rand() % taille_y;
            if (t_A[R1][R2].name == ""){
                t_A[R1][R2].create_n("Mouton", R1, R2);
                mouton--;
            }
        }
    }

    void en_vie(){
        int loup = 0;
        int mouton = 0;
        for (int x = 0; x != taille_x; x++){
            for (int y = 0; y != taille_y; y++){
                if (t_A[x][y].name == "Loup"){
                    loup++;
                }
                if (t_A[x][y].name == "Mouton"){
                    mouton++;
                }
            }
        }
        cout << "Loup :" << loup << " et Mouton: " << mouton << endl;
        return;
    }

    void affichage(){
        for(int x = 0; x != taille_x; x++){
            printf("| ");
            for(int y = 0; y != taille_y; y++){
                if (t_A[x][y].name == "Loup"){
                    printf("L");
                }
                else if (t_A[x][y].name == "Mouton"){
                    printf("M");
                }
                else if (tableau[x][y].sels == 1){
                    printf("S");
                }
                else if (tableau[x][y].herbe == 1){
                    printf("=");
                }
                else{
                    printf(" ");
                }
                printf(" | ");
            }
            printf("\n");
            for(int k = 0; k != taille_y; k++){
                printf("----");
            }
            printf("\n");
        }
    }   
};



int main(void){
    plateau eco = plateau(10, 10, 20, 20);
    int tour = 0;
    eco.en_vie();
    eco.affichage();
    printf("\n");

    while (eco.t_A[0][0].verif_fin(eco.t_A, eco.taille_x, eco.taille_y)){
        for (int x = 0; x != eco.taille_x; x++){
            for (int y = 0; y != eco.taille_y; y++){
                eco.t_A[x][y].action(eco.t_A, eco.tableau, eco.taille_x, eco.taille_y);
            }
        }
        cout << "tour: " << tour << endl;
        eco.en_vie();
        eco.affichage();
        printf("\n");
        eco.t_A[0][0].MAJ_action(eco.t_A, eco.tableau, eco.taille_x, eco.taille_y);
        tour++;
        //if (tour == 50){
        //    break;
        //}
    }
    eco.en_vie();
    eco.affichage();
    printf("\n");
    return 0;
}