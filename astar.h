//在头文件中，声明了一个表示点的结构图，定义了一个表示A*算法的类
#pragma once
/*
//A*算法对象类
*/
#include <vector>      //vector表示向量，相当于一个动态的数组，当程序员无法知道自己需要的数组的规模多大时，用其来解决问题可以达到最大节约空间的目的
#include <list>        //list相当于数据结构中的双向链表，内存空间不连续，但是可以随意存取和删除数据

const int kCost1=10; //垂直移动一格代价为10
const int kCost2=14; //斜方向移动一格代价为14

struct Point
{
    int x,y; //点坐标，这里为了方便按照C++的数组来计算，x代表横排，y代表竖列
    int F,G,H; //F=G+H，其中F表示总代价，G表示当前代价，H表示启发式函数计算出的代价
    Point *parent; //parent的坐标，这里没有用指针，从而简化代码，这里是生成了一个结构体类型的指针？
    Point(int _x,int _y):x(_x),y(_y),F(0),G(0),H(0),parent(NULL)  //变量初始化
    {
    }
};


class Astar
{
public:
    void InitAstar(std::vector<std::vector<int>> &_maze);
    std::list<Point *> GetPath(Point &startPoint,Point &endPoint,bool isIgnoreCorner);

private:
    Point *findPath(Point &startPoint,Point &endPoint,bool isIgnoreCorner);
    std::vector<Point *> getSurroundPoints(const Point *point,bool isIgnoreCorner) const;
    bool isCanreach(const Point *point,const Point *target,bool isIgnoreCorner) const; //判断某点是否可以用于下一步判断
    Point *isInList(const std::list<Point *> &list,const Point *point) const; //判断开启/关闭列表中是否包含某点
    Point *getLeastFpoint(); //从开启列表中返回F值最小的节点
    //计算FGH值
    int calcG(Point *temp_start,Point *point);          //计算G的值，参数为开始节点和当前节点
    int calcH(Point *point,Point *end);                 //计算H的值，参数为当前节点和目标节点
    int calcF(Point *point);                            //计算当前点的F值
private:
    std::vector<std::vector<int>> maze;
    std::list<Point *> openList;  //开启列表，表示生成一个openlist表，表中的每一个元素都是一个point结构体，存在x,y,f,g,h和parent？
    std::list<Point *> closeList; //关闭列表
};
