//
// Created by Administrator on 2020/10/24.
//

//猜谜语
string getHint(string secret, string guess) {
    int table[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int x = 0, y = 0;
    for (int i = 0; i < secret.size(); ++i) {
        if (secret[i] == guess[i]) {
            x++;
            guess[i] = 'a';
            continue;
        }

        table[secret[i] - '0']++;
    }
    for (int j = 0; j < guess.size(); ++j) {
        if (guess[j] == 'a') {
            continue;
        }
        if (table[guess[j] - '0'] == 0) {
            continue;
        }
        table[guess[j] - '0']--;
        y++;
    }
    return to_string(x) + "A" + to_string(y) + "B";
}