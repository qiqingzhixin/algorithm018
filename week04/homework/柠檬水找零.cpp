//
// Created by Administrator on 2020/11/15.
//

bool lemonadeChange(vector<int> &bills) {
    int bill[2] = {0, 0};
    for (int i = 0; i < bills.size(); ++i) {
        switch (bills[i]) {
            case 5:
                bill[0]++;
                break;
            case 10:
                if (bill[0] > 0) {
                    bill[1]++;
                    bill[0]--;
                } else {
                    return false;
                }
                break;
            case 20:
                if (bill[0] > 0 && bill[1] > 0) {
                    bill[2]++;
                    bill[1]--;
                    bill[0]--;
                } else if (bill[0] > 2) {
                    bill[0] = bill[0] - 3;
                } else {
                    return false;
                }
                break;
        }
    }
    return true;
}