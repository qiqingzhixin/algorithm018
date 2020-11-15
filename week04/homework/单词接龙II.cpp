//
// Created by Administrator on 2020/11/15.
//

/**
 * 对单词接龙1 的一种改进，
 * 用队列记录不是最后单词而是数组。访问单词有之前的访问边做标记换成一层做完一起做标记
 * @param beginWord
 * @param endWord
 * @param wordList
 * @return
 */
vector <vector<string>> findLadders(string beginWord, string endWord, vector <string> &wordList) {
    unordered_set <string> words;
    for (int i = 0; i < wordList.size(); ++i) {
        words.insert(wordList[i]);
    }
    unordered_set <string> visited;
    queue <vector<string>> que;
    visited.insert(beginWord);
    que.push({beginWord});
    bool flag = true;
    while (flag && !que.empty()) {
        int length = que.size();
        vector <string> tempVisited;
        for (int i = 0; i < length; ++i) {
            vector <string> list = que.front();
            que.pop();
            string dealStr = list.back();
            for (int j = 0; j < dealStr.size(); ++j) {
                char tempChar = dealStr[j];
                for (int k = 'a'; k <= 'z'; ++k) {
                    dealStr[j] = k;
                    if (words.count(dealStr) && visited.count(dealStr) == 0) {
                        list.push_back(dealStr);
                        que.push(list);
                        list.pop_back();
                        tempVisited.push_back(dealStr);
                        if (dealStr == endWord) {
                            flag = false;
                        }
                    }
                }
                dealStr[j] = tempChar;
            }
        }
        //这里存放用到的单词
        for (int l = 0; l < tempVisited.size(); ++l) {
            visited.insert(tempVisited[l]);
        }
    }
    vector <vector<string>> result;
    while (!que.empty()) {
        vector <string> item = que.front();
        que.pop();
        if (item.back() == endWord) {
            result.push_back(item);
        }
    }
    return result;
}