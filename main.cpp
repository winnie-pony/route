#include <iostream>
#include "astar.h"
using namespace std;      //表示当前空间的所有变量和函数使用的多少C++标准库中的变量和函数

int main()
{
    //初始化地图，用二维矩阵代表地图，1表示障碍物，0表示可通
    vector<vector<int>> maze={
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,1,0,1,0,0,0,0,1},
        {1,0,0,1,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,1,1,1},
        {1,1,1,0,0,0,0,0,1,1,0,1},
        {1,1,0,1,0,0,0,0,0,0,0,1},
        {1,0,1,0,0,0,0,1,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}
    };
    Astar astar;                //实例化一个Astar类的对象-astar
    astar.InitAstar(maze);      //调用astar的初始化函数

    //设置起始和结束点
    Point start(1,1);           //按照maze中的矩阵显示，（1,1）是一个障碍物
    Point end(6,10);
    //A*算法找寻路径
    list<Point *> path=astar.GetPath(start,end,false);      //得到路径的信息
    //打印
    for(auto &p:path)
        cout<<'('<<p->x<<','<<p->y<<')'<<endl;

    system("pause");
    return 0;
}
