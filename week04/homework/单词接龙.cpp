//
// Created by Administrator on 2020/11/15.
//

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    //存放单词
    unordered_set<string> words;
    //存放问过的节点
    unordered_set<string> visited;
    for (int i = 0; i < wordList.size(); ++i) {
        words.insert(wordList[i]);
    }
    //初始化
    int step = 1;
    visited.insert(beginWord);
    queue<string> visiting;
    visiting.push(beginWord);

    //如果队列不为空
    while (!visiting.empty()) {
        int length = visiting.size();
        for (int i = 0; i < length; ++i) {
            string dealStr = visiting.front();
            visiting.pop();
            //每个单词的长度
            for (int j = 0; j < dealStr.size(); ++j) {
                char temp = dealStr[j];
                //每个位置
                for (int k = 'a'; k <= 'z'; ++k) {
                    dealStr[j] = k;
                    //如果在单词列表中找到了，并且没有访问过，则进行处理
                    if (words.count(dealStr) && visited.count(dealStr)==0) {
                        //等于最后一个
                        if (dealStr == endWord) {
                            return step + 1;
                        }
                        //放到将要遍历的队列中
                        visiting.push(dealStr);
                        //放到已经访问过得队列
                        visited.insert(dealStr);
                    }
                }
                //改回来
                dealStr[j] = temp;
            }
        }
        step++;
    }
    return 0;

}