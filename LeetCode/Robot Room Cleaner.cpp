  /**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

#define pii pair<int, int>
#define fi first
#define se second

const int D = 0;
const int L = 1;
const int U = 2;
const int R = 3;

class Solution {
public:
    int dir = U;
    map<pii, bool> visit;
    
    void change_dir(int d, Robot& robot) {
        if (dir < d) {
            for (int i = 0; i < d - dir; ++i) robot.turnRight();
        } else if (dir > d) {
            for (int i = 0; i < dir - d; ++i) robot.turnLeft();
        }
        dir = d;
    }
    
    void clear(pii pos, Robot& robot) {
        if (visit[pos]) return;
        robot.clean();
        visit[pos] = true;
        for (int i = 0; i < 4; ++i) {
            int previous_dir = dir;
            if (i == 0) {
                change_dir(D, robot);
                if (robot.move()) {
                    clear({ pos.fi, pos.se - 1 }, robot);
                    change_dir(U, robot);
                    robot.move();
                    change_dir(previous_dir, robot);
                } else {
                    change_dir(previous_dir, robot);
                }
            } else if (i == 1) {
                change_dir(L, robot);
                if (robot.move()) {
                    clear({ pos.fi - 1, pos.se }, robot);
                    change_dir(R, robot);
                    robot.move();
                    change_dir(previous_dir, robot);
                } else {
                    change_dir(previous_dir, robot);
                }
            } else if (i == 2) {
                change_dir(U, robot);
                if (robot.move()) {
                    clear({ pos.fi, pos.se + 1 }, robot);
                    change_dir(D, robot);
                    robot.move();
                    change_dir(previous_dir, robot);
                } else {
                    change_dir(previous_dir, robot);
                }
            } else {
                change_dir(R, robot);
                if (robot.move()) {
                    clear({ pos.fi + 1, pos.se }, robot);
                    change_dir(L, robot);
                    robot.move();
                    change_dir(previous_dir, robot);
                } else {
                    change_dir(previous_dir, robot);
                }
            }
        }
    }
    
    void cleanRoom(Robot& robot) {
        clear({0, 0}, robot);
    }
};

// Another solution written on 09/08/2021
class Solution {
public:
    map<pair<int, int>, bool> visit;
    
    int di[4] = { -1, 0, 1, 0 };
    int dj[4] = { 0, 1, 0, -1 };
    
    bool is_visit(int i, int j) {
        auto it = visit.find({i, j});
        return !(it == visit.end());
    }
    
    void f(Robot& robot, int i, int j, int dir) {
        if (!is_visit(i, j)) {
            visit[{i, j}] = true;
            robot.clean();
        }
        int curr_dir = dir;
        for (int k = 0; k < 4; ++k) {
            robot.turnRight();
            curr_dir = (curr_dir + 1) % 4;
            int ii = i + di[curr_dir], jj = j + dj[curr_dir];
            if (!is_visit(ii, jj) && robot.move()) {
                f(robot, ii, jj, curr_dir);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
        }
    }
    
    void cleanRoom(Robot& robot) {
        f(robot, 0, 0, 0);
    }
};
