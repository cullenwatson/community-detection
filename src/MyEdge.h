

#ifndef INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_MYEDGE_H
#define INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_MYEDGE_H
class MyEdge {
    pair<int, int> pair1;
    mutable int qty = 1;

public:
    MyEdge(int x, int y) {
        pair1.first = x;
        pair1.second = y;

    }
    void setX(int _x){pair1.first = _x;}
    void setY(int _y){pair1.second = _y;}

    bool operator<(const MyEdge &s) const {
        return pair1 < s.pair1;
    }

    bool operator==(const MyEdge &s) const {
        return pair1 == s.pair1;
    }

    void incQty() const { qty++; }
    int getQty() const {return qty;}
    int getX() const {return pair1.first;}
    int getY() const {return pair1.second;}
};
#endif //INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_MYEDGE_H
