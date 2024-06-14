#include <iostream>
#include <conio.h> 
using namespace std;

class Enemy{
public:
    void Update();
    void approach();
    void shoot();
    void retreat();

    static void (Enemy::* table[])();

private:
    int index = 0;
};

void Enemy::approach(){
    cout << "�G�̐ڋ߁I" << endl;
}

void Enemy::shoot(){
    cout << "�G�̍U���I" << endl;
}

void Enemy::retreat(){
    cout << "�G�̌�ށI" << endl;
}


void Enemy::Update(){


    (this->*table[index])();


    while (true){

        if (_kbhit()){
            char key = _getch();
            if (key == ' '){
                index = (index + 1) % 3; 
                break;
            }
        }
    }
}

void (Enemy::* Enemy::table[])() ={
    &Enemy::approach,
    &Enemy::shoot,
    &Enemy::retreat
};

int main(){
    Enemy my;
    while (true){
        my.Update();
    }

    return 0;
}