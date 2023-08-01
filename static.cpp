//静态成员和静态方法的使用，记录玩家数量，输出玩家数量
#include<iostream>
#include<vector>
using namespace std;

class Player{
    //默认情况下成员为private类型
    string playerName; //玩家姓名
    int attack; //攻击力
    int defense; //防御力
    int health=100; //生命值
    int maxHealth=100; //最大生命值

    public:
        static int playerNumber; //玩家数量
        static vector<string> playerList; //在线玩家列表
        //int publicNumber;

        //构造函数，玩家数量+1
        Player(int attackParam,int defenseParam,string nameParam){
            attack=attackParam;
            defense=defenseParam;
            playerName=nameParam;
            ++playerNumber;
            playerList.push_back(playerName);
        }

        static void printPlayerNum(){  //输出玩家数量
            cout<<"当前玩家数量为："<<playerNumber<<endl;
        }

        static void printPlayerList(){ //输出在线玩家名
            //遍历输出列表元素
            cout<<"玩家名称为：";
            for (int i;i < playerList.size();i++){
                cout<<playerList[i]<<' ';
            }
            cout<<endl;
        }

        void printPlayerAttr(){  //输出玩家属性
            cout<<"名称："<<playerName<<" 攻击力："<<attack<<" 防御力："<<defense<<"血量："<<health<<"\n"<<endl;
        } 

        //析构函数，玩家数-1
        ~Player(){
            --playerNumber;
        }

};

int Player::playerNumber=0;
vector<string> Player::playerList;
//int Player::publicNumber=0;  //非静态数据成员不能在其类的外部定义C/C++(246)

int main(){
    Player player1(50,50,"cjp");
    player1.printPlayerAttr();
    Player player2(20,20,"zyh");
    player2.printPlayerAttr();
    //cout<<player1.maxHealth<<endl;
    Player::printPlayerNum();
    Player::printPlayerList();
    system("pause");
    return 0;
}