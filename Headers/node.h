#ifndef NODE_H
#define NODE_H

class Node {
protected:
    int x_row, y_column;

public:
    Node();
    Node(int row, int col);

    void set_x_row(int i);
    int get_x_row();

    void set_y_column(int i);
    int get_y_column();

    void set_row_column(int row, int col);
};

#endif // NODE_H
