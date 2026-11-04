#pragma once
class minpl5
{

};
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<bits/stdc++.h>
//#include<graphics.h>
//#include"标头.h"
//using namespace std;
//#define MAX0 5000        //站台的多少
//#define MAX1 500         //路线的多少
//struct luxian0 {
//    string zhanming;
//    unsigned int x = 0;//与前一个站台的距离
//    unsigned int y = 0;//与后一个后一个站台的关系
//    luxian0* shang = nullptr, * next = nullptr;
//};                                       //记录路线中站台关系
//struct {
//    int hao;
//    luxian0* next;
//    luxian0* qi;
//}luxianhao[MAX1];                         //记录站台路线号
//struct zhantaim {
//    int hao;
//    zhantaim* next;
//};
//struct {
//    string zhanming;
//    zhantaim* luxian = nullptr;//下一个路线号
//    zhantaim* qi = nullptr;//记录有几个站经过此线
//}zhantai[MAX0];                          //记录站台的信息
//
//
//
//int  zhandianx = 0, luxiany = 0;
//// 修改结构体h以记录完整路径
//struct h {
//    vector<int> stations; // 存储路径上的站点序列
//    vector<int> routes;   // 存储路径上的路线序列
//    int totalDistance;    // 总距离
//    int transfers;        // 换乘次数
//};
//
//const char tt[3][10] = { "上一站","本站","下一站" };
//
//
//int kpl = 0;
//vector<h> allPaths; // 存储所有路径
//int minTransfers = INT_MAX; // 最小换乘次数
//
//int weizhi(string s, int i, int j) {//找到该站点的位置,保证其前面的都小于他，若有相等的则返回0；
//    //二分查找
//    if (i == j) {
//        if (s == zhantai[i].zhanming) {
//            return i;
//        }
//        else {
//            return s > zhantai[i].zhanming ? i + 1 : i - 1;
//        }
//    }
//    int mid = i + (j - i) / 2;
//    if (s > zhantai[mid].zhanming) {
//        return weizhi(s, mid + 1, j);
//    }
//    else if (s < zhantai[mid].zhanming) {
//        return weizhi(s, i, mid - 1);
//    }
//    else {
//        return mid;
//    }
//}
//
//void KMP(string s, int length) {//KMP算法查找站点
//    vector<int>next(length + 1);
//    int i = 0, j = 0;
//    next[0] = 0;
//    for (j = 1; j < length; j++) {
//        if (s[i] == s[j]) {
//            i++;
//            next[j] = i;
//        }
//        else {
//            while (i > 0 && s[i] != s[j]) {
//                i = next[i - 1];
//            }
//            if (s[i] == s[j]) {
//                i++;
//                next[j] = i;
//            }
//            else {
//                next[j] = i;
//            }
//        }
//    }
//    int z = 0;
//    for (i = 0; i <= zhandianx; i++) {
//        z = 0;
//        for (j = 0; j < zhantai[i].zhanming.length() && length <= zhantai[i].zhanming.length(); j++) {
//            if (zhantai[i].zhanming[j] == s[z]) {
//                z++;
//            }
//            else {
//                while (z > 0 && zhantai[i].zhanming[j] != s[z]) {
//                    z = next[z - 1];
//                }
//                if (zhantai[i].zhanming[j] == s[z]) {
//                    z++;
//                }
//            }
//            if (z == length) {
//                cout << zhantai[i].zhanming << endl;
//                break;
//            }
//        }
//    }
//}
//
//int luxianchazhao(int g, int i, int j) {
//    int left = i, right = j;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (luxianhao[mid].hao == g) {
//            return mid;
//        }
//        else if (luxianhao[mid].hao < g) {
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//}
//
//void zhandianjianli() {//建立站点
//    bool w = false;
//    string s;
//    initgraph(1000, 500, EX_SHOWCONSOLE);
//    setbkcolor(WHITE);
//    cleardevice();
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        cleardevice();
//        printf0(400, 100, 200, 100, "请输入站名", BLACK);
//        if (w) {// 相等则需返回
//            printf0(400, 300, 200, 100, "此站台名字重复，请重新输入!", RED);
//        }
//        if (button(400, 200, 200, 100, "") && Interval(clock())) {
//            if (zhandianx != 0) {
//                char x[100];
//                InputBox(x, sizeof(x), "站台建立", NULL);
//                s = (string)x;
//                int j = weizhi(s, 1, zhandianx);
//                if (s == zhantai[j].zhanming) {
//                    w = true;
//                }
//                else {
//                    w = false;
//                }
//                if (w) {// 相等则需返回
//                    continue;
//                }
//                int i;
//                // 将j及之后的元素后移一位
//                for (i = ++zhandianx; i >= j; i--) {
//                    zhantai[i].zhanming = zhantai[i - 1].zhanming;
//                    zhantai[i].luxian = zhantai[i - 1].luxian;
//                    zhantai[i].qi = zhantai[i - 1].qi;
//                }
//                // 插入新元素到j位置
//                zhantai[j].zhanming = s;
//                zhantai[j].qi = NULL;
//                zhantai[j].luxian = NULL;
//                break;
//            }
//            else {
//                char x[100];
//                InputBox(x, sizeof(x), NULL, NULL);
//                s = (string)x;
//                // 数组为空时直接插入第一个元素
//                ++zhandianx;
//                zhantai[zhandianx].zhanming = s;
//                zhantai[zhandianx].qi = NULL;
//                zhantai[zhandianx].luxian = NULL;
//                break;
//            }
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            msg.message = 0;
//            return;
//        }
//        EndBatchDraw();
//        msg.message = 0;
//    }
//}
//
//void zhandianshanchu(int i) {
//    zhantaim* q = zhantai[i].qi;
//    while (q != nullptr) {
//        int j = luxianchazhao(q->hao, 1, luxiany);
//        struct luxian0* sq = luxianhao[j].next;
//        while (sq->zhanming != zhantai[i].zhanming) {
//            sq = sq->next;
//        }
//        sq->shang->next = sq->next;
//        sq->shang->y = sq->x + sq->y;
//        sq->next->x = sq->shang->y;
//        delete(sq);
//        q = q->next;
//    }
//    for (int j = i; j < zhandianx; j++) {
//        zhantai[i].zhanming = zhantai[i + 1].zhanming;
//        zhantai[i].luxian = zhantai[i + 1].luxian;
//        zhantai[i].qi = zhantai[i + 1].qi;
//    }
//    --zhandianx;
//}
//
//void zhandiangaimin(int i, string s) {
//    zhantaim* q = zhantai[i].qi;
//    while (q != nullptr) {
//        int j = luxianchazhao(q->hao, 1, luxiany);
//        struct luxian0* sq = luxianhao[j].next;
//        while (sq->zhanming != zhantai[i].zhanming) {
//            sq = sq->next;
//        }
//        sq->zhanming = s;
//    }
//    zhantai[i].zhanming = s;
//}
//
//void zhandianxiugai() {
//    int i;
//    string s;
//    bool rr = false;
//    string ss;
//    int j;
//    bool panduan = false;
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        cleardevice();
//        printf0(400, 100, 200, 100, "请输入站名", BLACK);
//        if (rr == true) {
//            printf0(400, 300, 200, 50, "无此站台，请重新输入!", RED);
//        }
//        if (button(400, 200, 200, 100, "") && Interval(clock())) {
//            rr = false;
//            char x[100];
//            InputBox(x, 100, NULL, NULL);
//            s = (string)x;
//            KMP(s, s.length());
//            i = weizhi(s, 1, zhandianx);
//            if (s == zhantai[i].zhanming) {
//                initgraph(1000, 500, EX_DBLCLKS | EX_SHOWCONSOLE);
//                setbkcolor(WHITE);
//                cleardevice();
//                while (true) {
//                    if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//                    }
//                    BeginBatchDraw();
//                    cleardevice();
//                    if (button(400, 90, 200, 60, "站点删除") && Interval(clock())) {
//                        zhandianshanchu(i);
//                        break;
//                    }
//                    else if (button(400, 90 + 60, 200, 60, "站点改名") && Interval(clock())) {
//                        while (true)
//                        {
//                            if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//                            }
//                            BeginBatchDraw();
//                            cleardevice();
//                            printf0(400, 100, 200, 100, "请输入新站名", BLACK);
//                            if (button(400, 200, 200, 100, "") && Interval(clock())) {
//                                char x[100] = { "\0" };
//                                InputBox(x, 100, NULL, NULL);
//                                ss = (string)x;
//                                j = weizhi(ss, 1, zhandianx);
//                                if (ss == zhantai[j].zhanming) {// 相等则需返回
//                                    panduan = true;
//                                }
//                                else {
//                                    panduan = false;
//                                    zhandiangaimin(i, ss);
//                                    break;
//                                }
//                            }
//                            else if (fanhui()) {
//                                EndBatchDraw();
//                                msg.message = 0;
//                                break;
//                            }
//                            if (panduan) {// 相等则需返回
//                                printf0(400, 300, 200, 100, "此站台名字重复，请重新输入!", RED);
//                                msg.message = 0;
//                                EndBatchDraw();
//                                continue;
//                            }
//                            msg.message = 0;
//                            EndBatchDraw();
//                        }
//                        break;
//                    }
//                    else if (fanhui()) {
//                        EndBatchDraw();
//                        msg.message = 0;
//                        break;
//                    }
//                    EndBatchDraw();
//                    msg.message = 0;
//                }
//                break;
//            }
//            else {
//                rr = true;
//            }
//
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            msg.message = 0;
//            return;
//        }
//        EndBatchDraw();
//        msg.message = 0;
//    }
//}
//
//// 修改站点路线添加函数
//void shuruluxian(int n, int u) {
//    zhantaim* pa = new zhantaim;
//    pa->hao = n;
//    pa->next = nullptr;
//
//    // 添加到站点路线链表头部
//    if (zhantai[u].qi == nullptr) {
//        zhantai[u].qi = pa;
//        zhantai[u].luxian = pa;
//    }
//    else {
//        pa->next = zhantai[u].qi;
//        zhantai[u].qi = pa;
//    }
//}
//
//// 递归输入站点函数
//luxian0* shurudigui(luxian0* pa, int v) {
//    string s;
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//            // 处理消息
//        }
//        BeginBatchDraw();
//        cleardevice();
//
//        bool rr = false; // 每次循环重置错误状态
//
//        printf0(400, 100, 200, 50, "下一站名", BLACK);
//        printf0(400, 300, 200, 50, "与上一站的距离", BLACK);
//
//        if (button(400, 150, 200, 50, "") && Interval(clock())) {
//            char x[100];
//            InputBox(x, sizeof(x), "下一站名", "路线添加");
//            s = (string)x;
//
//            // 去除首尾空白
//            s.erase(0, s.find_first_not_of(" \n\r\t"));
//            s.erase(s.find_last_not_of(" \n\r\t") + 1);
//
//            if (s.empty() || s == "NULL") {
//                EndBatchDraw();
//                return pa;
//            }
//
//            int j = weizhi(s, 1, zhandianx);
//            if (s != zhantai[j].zhanming) {
//                rr = true;
//            }
//            else {
//                shuruluxian(v, j);
//                char distInput[20];
//                InputBox(distInput, sizeof(distInput), "与上一站的距离", "添加路线");
//                int n = zhuanhuan(distInput);
//                if (n < 0) {
//                    printf0(400, 200, 200, 50, "距离无效，请重新输入!", RED);
//                    EndBatchDraw();
//                    Sleep(1000); // 短暂显示错误
//                    continue;
//                }
//
//                luxian0* p = new luxian0;
//                p->zhanming = s;
//                p->shang = pa;
//                p->x = n;
//                p->y = 0;
//                p->next = nullptr;
//
//                if (pa) {
//                    pa->next = p;
//                    pa->y = n; // 上一站到这一站的距离
//                }
//
//                EndBatchDraw();
//                return shurudigui(p, v);
//            }
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            // 释放已创建的节点？注意：pa是由调用者创建的，不应在此释放
//            if (pa) {
//                pa->next = nullptr; // 标记结束
//            }
//            return pa;
//        }
//
//        if (rr) {
//            printf0(400, 200, 200, 50, "无此站台，请重新输入!", RED);
//        }
//
//        EndBatchDraw();
//    }
//}
//
//// 路线建立
//void luxianjianli() {
//    string s;
//    int n, j, u;
//    bool rr = false;
//
//    cleardevice();
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//            // 处理消息
//        }
//        BeginBatchDraw();
//        cleardevice();
//
//        rr = false; // 重置重复标志
//
//        printf0(400, 100, 200, 100, "请输入路线名", BLACK);
//
//        if (button(400, 200, 200, 100, "") && Interval(clock())) {
//            char x[20];
//            InputBox(x, sizeof(x), "请输入路线号", "路线建立");
//            n = zhuanhuan(x);
//
//            if (n <= 0) {
//                printf0(400, 300, 200, 100, "路线号必须为正整数", RED);
//                EndBatchDraw();
//                continue;
//            }
//
//            // 检查路线号是否已存在
//            bool duplicate = false;
//            for (int i = 1; i <= luxiany; i++) {
//                if (luxianhao[i].hao == n) {
//                    duplicate = true;
//                    break;
//                }
//            }
//
//            if (duplicate) {
//                rr = true;
//            }
//            else {
//                // 创建新路线头节点
//                luxian0* pa = new luxian0;
//                pa->shang = nullptr;
//                pa->x = 0;
//                pa->y = 0;
//                pa->next = nullptr;
//
//                // 在有序数组中插入新路线
//                int pos = 1;
//                while (pos <= luxiany && luxianhao[pos].hao < n) {
//                    pos++;
//                }
//
//                // 后移元素
//                for (int i = luxiany + 1; i > pos; i--) {
//                    luxianhao[i] = luxianhao[i - 1];
//                }
//
//                luxianhao[pos].hao = n;
//                luxianhao[pos].qi = pa;
//                luxianhao[pos].next = pa; // 初始时头尾相同
//                luxiany++;
//
//                // 输入起始站
//                while (true) {
//                    BeginBatchDraw();
//                    cleardevice();
//                    bool stationFound = false;
//                    printf0(400, 100, 200, 100, "起始站名", BLACK);
//
//                    if (button(400, 200, 200, 100, "") && Interval(clock())) {
//                        char stationName[100];
//                        InputBox(stationName, sizeof(stationName), "起始站名", "路线建立");
//                        s = (string)stationName;
//
//                        int stationIndex = weizhi(s, 1, zhandianx);
//                        if (s == zhantai[stationIndex].zhanming) {
//                            u = stationIndex;
//                            shuruluxian(n, u);
//                            pa->zhanming = s; // 设置起始站名
//
//                            // 递归输入后续站点
//                            luxian0* lastNode = shurudigui(pa, n);
//                            if (lastNode) {
//                                luxianhao[pos].next = lastNode; // 更新路线尾指针
//                            }
//
//                            // 打印路线验证
//                            cout << "路线 " << n << ": ";
//                            luxian0* current = luxianhao[pos].qi;
//                            while (current) {
//                                cout << current->zhanming << "(" << current->x << ") ";
//                                current = current->next;
//                            }
//                            cout << endl;
//
//                            EndBatchDraw();
//                            return;
//                        }
//                        else {
//                            printf0(400, 300, 200, 100, "无此站台，请重新输入!", RED);
//                        }
//                    }
//                    else if (fanhui()) {
//                        // 用户取消，删除新创建的路线
//                        for (int i = pos; i < luxiany; i++) {
//                            luxianhao[i] = luxianhao[i + 1];
//                        }
//                        luxiany--;
//                        delete pa;
//                        EndBatchDraw();
//                        return;
//                    }
//                    EndBatchDraw();
//                }
//            }
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            return;
//        }
//
//        if (rr) {
//            printf0(400, 300, 200, 100, "此路线名字重复，请重新输入!", RED);
//        }
//
//        EndBatchDraw();
//    }
//}
//
//// 路线删除
//void luxianshanchu(luxian0* p, int luxianming) {
//    if (p == nullptr) {
//        return;
//    }
//
//    // 先递归删除后续节点
//    luxianshanchu(p->next, luxianming);
//
//    int px = weizhi(p->zhanming, 1, zhandianx);
//    if (px < 1 || px > zhandianx) {
//        // 站点不存在，直接删除节点
//        delete p;
//        return;
//    }
//
//    // 从站点中删除路线引用
//    zhantaim* pa = zhantai[px].qi;
//    zhantaim* prev = nullptr;
//
//    while (pa != nullptr) {
//        if (pa->hao == luxianming) {
//            if (prev == nullptr) {
//                // 删除链表头节点
//                zhantai[px].qi = pa->next;
//                if (zhantai[px].luxian == pa) {
//                    zhantai[px].luxian = zhantai[px].qi;
//                }
//            }
//            else {
//                prev->next = pa->next;
//                if (zhantai[px].luxian == pa) {
//                    zhantai[px].luxian = prev;
//                }
//            }
//            delete pa;
//            break;
//        }
//        prev = pa;
//        pa = pa->next;
//    }
//
//    // 删除路线节点
//    delete p;
//}
//
//// 站点添加
//void luxiantianjia(luxian0* q, int n) {
//    char x[100];
//    string s;
//    // 获取站台名称
//    InputBox(x, sizeof(x), "添加站台", "请输入站台名称");
//    s = (string)x;
//    // 查找站台位置
//    int wwww = weizhi(s, 1, zhandianx);
//    // 确保找到有效站台
//    while (wwww < 1 || wwww > zhandianx || s != zhantai[wwww].zhanming) {
//        InputBox(x, sizeof(x), "添加站台", "无此站台\n请重新输入！");
//        s = (string)x;
//        wwww = weizhi(s, 1, zhandianx);
//    }
//    // 设置当前节点的站台名称
//    q->zhanming = s; // 关键修复：设置节点名称
//    // 添加路线引用到站点
//    shuruluxian(n, wwww);
//    // 设置与前一个站点的距离
//    if (q->shang != nullptr) {
//        while (true) {
//            InputBox(x, sizeof(x), "添加站台", "与上一站台的距离");
//            int distance = zhuanhuan(x);
//
//            if (distance >= 0) {
//                q->x = distance;
//                q->shang->y = distance;
//                break;
//            }
//
//            printf0(400, 300, 200, 50, "距离不能为负!", RED);
//            Sleep(1000);
//        }
//    }
//    // 设置与后一个站点的距离
//    if (q->next != nullptr) {
//        while (true) {
//            InputBox(x, sizeof(x), "添加站台", "与下一站台的距离");
//            int distance = zhuanhuan(x);
//
//            if (distance >= 0) {
//                q->y = distance;
//                q->next->x = distance;
//                break;
//            }
//            printf0(400, 300, 200, 50, "距离不能为负!", RED);
//            Sleep(1000);
//        }
//    }
//}
//
//// 路线修改函数
//void luxiangaizhan(luxian0* pa, int n) {
//    if (pa == nullptr) {
//        printf0(300, 300, 200, 50, "无效节点!", RED);
//        Sleep(1000);
//        return;
//    }
//    // 保存原始节点指针用于恢复
//    luxian0* originalPa = pa;
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        cleardevice();
//        // 显示当前节点信息
//        string pp[3];
//        bool hasPrev = (pa->shang != nullptr);
//        bool hasNext = (pa->next != nullptr);
//        pp[0] = hasPrev ? pa->shang->zhanming : "无上站";
//        pp[1] = pa->zhanming;
//        pp[2] = hasNext ? pa->next->zhanming : "无下站";
//        for (int i = 0; i < 3; i++) {
//            printf0(300 + i * 150, 100, 100, 50, tt[i], BLACK);
//            printf0(300 + i * 150, 150, 100, 50, pp[i].c_str(), RED);
//        }
//        // 显示操作按钮
//        if (button(400, 225, 100, 50, "删除当前站") && Interval(clock())) {
//            if (!hasPrev || !hasNext) {
//                printf0(500, 300, 200, 50, "首尾站不能删除!", RED);
//                EndBatchDraw();
//                Sleep(1000);
//                continue;
//            }
//            // 删除当前站点
//            luxian0* prev = pa->shang;
//            luxian0* next = pa->next;
//            prev->next = next;
//            next->shang = prev;
//            prev->y = pa->x + pa->y;
//            next->x = prev->y;
//            // 从站点中删除路线引用
//            int px = weizhi(pa->zhanming, 1, zhandianx);
//            if (px >= 1 && px <= zhandianx) {
//                zhantaim* p = zhantai[px].qi;
//                zhantaim* prev = nullptr;
//                while (p != nullptr) {
//                    if (p->hao == n) {
//                        if (prev == nullptr) {
//                            zhantai[px].qi = p->next;
//                        }
//                        else {
//                            prev->next = p->next;
//                        }
//                        delete p;
//                        break;
//                    }
//                    prev = p;
//                    p = p->next;
//                }
//            }
//            // 删除节点
//            delete pa;
//            pa = prev; // 移动到前一个站点
//            EndBatchDraw();
//            Sleep(500); // 短暂暂停
//            continue;
//        }
//        if (hasNext && button(550, 225, 100, 50, "下一站") && Interval(clock())) {
//            pa = pa->next;
//        }
//        if (hasPrev && button(250, 225, 100, 50, "上一站") && Interval(clock())) {
//            pa = pa->shang;
//        }
//        if (buttonziti(250, 300, 150, 50, "在上站添加", 20) && Interval(clock())) {
//            if (pa->shang == nullptr) {
//                printf0(500, 300, 200, 50, "首站前不能添加!", RED);
//                EndBatchDraw();
//                Sleep(1000);
//                continue;
//            }
//            luxian0* newStation = new luxian0;
//            newStation->next = pa;
//            newStation->shang = pa->shang;
//            pa->shang->next = newStation;
//            pa->shang = newStation;
//            luxiantianjia(newStation, n);
//        }
//        if (buttonziti(550, 300, 150, 50, "在下站添加", 20) && Interval(clock())) {
//            if (pa->next == nullptr) {
//                printf0(500, 300, 200, 50, "尾站后不能添加!", RED);
//                EndBatchDraw();
//                Sleep(1000);
//                continue;
//            }
//            luxian0* newStation = new luxian0;
//            newStation->next = pa->next;
//            newStation->shang = pa;
//            pa->next->shang = newStation;
//            pa->next = newStation;
//            luxiantianjia(newStation, n);
//        }
//        if (button(400, 375, 100, 50, "返回") || fanhui()) {
//            EndBatchDraw();
//            msg.message = 0;
//            return;
//        }
//        EndBatchDraw();
//    }
//}
//
//void luxianxiugai() {
//    /*if(luxiany==0){
//        while(true){
//            printf0(400, 300, 200, 100, "无路线", RED);
//        }
//    }*/
//    int n, j;
//    bool rr = false, yiyi = false;
//    initgraph(1000, 500, EX_DBLCLKS | EX_SHOWCONSOLE);
//    setbkcolor(WHITE);
//    cleardevice();
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        cleardevice();
//        printf0(400, 100, 200, 100, "请输入路线名", BLACK);
//        if (button(400, 200, 200, 100, "") && Interval(clock())) {
//            char x[100];
//            InputBox(x, sizeof(x), NULL, NULL);
//            n = zhuanhuan(x);
//            j = luxianchazhao(n, 1, luxiany);
//            if (n == luxianhao[j].hao) {
//                rr = true;
//                EndBatchDraw();
//                break;
//            }
//            else {
//                rr = true;
//            }
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            msg.message = 0;
//            return;
//        }
//        if (rr) {
//            printf0(400, 300, 200, 100, "无此路线，请重新输入!", RED);
//        }
//        EndBatchDraw();
//    }
//    int ff = true;
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        cleardevice();
//        if (button(400, 90 + 0 * 60, 200, 60, "路线删除") && Interval(clock())) {
//            luxianshanchu(luxianhao[j].qi, luxianhao[j].hao);
//            msg.message = 0;
//            for (int i = j; i < luxiany; i++) {
//                luxianhao[i].hao = luxianhao[i + 1].hao;
//                luxianhao[i].next = luxianhao[i + 1].next;
//            }
//            luxianhao[luxiany].hao = 0;
//            luxianhao[luxiany].next = nullptr;
//            luxiany--;
//            cout << "删除成功" << endl;
//            return;
//        }
//        /*else if (button(400, 90 + i * 60, 200, 60, "路线改名")) {
//            msg.message = 0;
//        }*/
//        else if (button(400, 90 + 2 * 60, 200, 60, "路线改站") && Interval(clock())) {
//            luxiangaizhan(luxianhao[j].qi, j);
//            msg.message = 0;
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            msg.message = 0;
//            break;
//        }
//        EndBatchDraw();
//    }
//}
//
//// 站点路线信息
//void displayzhandian() {
//    string stationName;
//    bool found = false;
//    bool foudd = false;
//    int stationIndex = -1;
//
//    // 获取站点名称
//    while (!found) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        cleardevice();
//
//        printf0(400, 100, 200, 50, "请输入站点名称", BLACK);
//
//        if (button(400, 200, 200, 100, "") && Interval(clock())) {
//            char input[100];
//            InputBox(input, sizeof(input), "站点查询", "请输入站点名称");
//            stationName = string(input);
//            KMP(stationName, stationName.size());
//            // 查找站点
//            stationIndex = weizhi(stationName, 1, zhandianx);
//            if (stationIndex >= 1 && stationIndex <= zhandianx &&
//                zhantai[stationIndex].zhanming == stationName) {
//                found = true;
//                foudd = false;
//            }
//            else {
//                foudd = true;
//            }
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            return;
//        }
//        if (foudd) {
//            printf0(400, 300, 200, 50, "未找到该站点!", RED);
//        }
//
//        EndBatchDraw();
//    }
//
//    // 获取站点关联的所有路线
//    vector<int> routes;
//    zhantaim* routeNode = zhantai[stationIndex].qi;
//    while (routeNode != nullptr) {
//        routes.push_back(routeNode->hao);
//        routeNode = routeNode->next;
//    }
//
//    // 如果没有关联路线
//    if (routes.empty()) {
//        initgraph(600, 300, EX_SHOWCONSOLE);
//        setbkcolor(WHITE);
//        cleardevice();
//
//        while (true) {
//            if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//                // 处理消息
//            }
//            BeginBatchDraw();
//            cleardevice();
//
//            printf0(200, 100, 200, 50, "该站点没有关联路线", RED);
//
//            if (fanhui()) {
//                EndBatchDraw();
//                closegraph();
//                return;
//            }
//
//            EndBatchDraw();
//        }
//    }
//
//    // 创建显示窗口
//    initgraph(800, 600, EX_SHOWCONSOLE);
//    setbkcolor(WHITE);
//    cleardevice();
//
//    int currentPage = 0;
//    const int routesPerPage = 5;
//    int totalPages = (routes.size() + routesPerPage - 1) / routesPerPage;
//
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//            // 处理消息
//        }
//        BeginBatchDraw();
//        cleardevice();
//
//        // 显示标题
//        settextcolor(BLACK);
//        settextstyle(24, 0, "微软雅黑");
//        char title[100];
//        sprintf(title, "站点: %s", stationName.c_str());
//        outtextxy(50, 20, title);
//
//        // 显示分页信息
//        sprintf(title, "第 %d/%d 页", currentPage + 1, totalPages);
//        outtextxy(650, 20, title);
//
//        // 显示路线
//        int startY = 70;
//        for (int i = 0; i < routesPerPage; i++) {
//            int routeIndex = currentPage * routesPerPage + i;
//            if (routeIndex >= routes.size()) break;
//
//            int routeId = routes[routeIndex];
//
//            // 查找路线
//            int routePos = luxianchazhao(routeId, 1, luxiany);
//            if (routePos < 1 || routePos > luxiany) continue;
//
//            // 显示路线号
//            settextcolor(BLUE);
//            settextstyle(20, 0, "微软雅黑");
//            char routeTitle[50];
//            sprintf(routeTitle, "路线 %d:", routeId);
//            outtextxy(50, startY, routeTitle);
//
//            // 显示路线上的所有站点
//            luxian0* current = luxianhao[routePos].qi;
//            int xPos = 150;
//            int yPos = startY;
//
//            while (current != nullptr) {
//                // 设置颜色：当前站点红色，其他黑色
//                if (current->zhanming == stationName) {
//                    settextcolor(RED);
//                }
//                else {
//                    settextcolor(BLACK);
//                }
//
//                // 显示站点名称
//                outtextxy(xPos, yPos, current->zhanming.c_str());
//
//                // 计算下一个位置
//                int textWidth = textwidth(current->zhanming.c_str()) + 10;
//                xPos += textWidth;
//
//                // 如果超出宽度，换行
//                if (xPos + textWidth > 750) {
//                    xPos = 150;
//                    yPos += 30;
//                }
//
//                // 添加箭头（如果不是最后一个）
//                if (current->next != nullptr) {
//                    settextcolor(BLACK);
//                    outtextxy(xPos, yPos, "->");
//                    xPos += 20;
//                }
//
//                current = current->next;
//            }
//
//            startY = yPos + 40;
//        }
//
//        // 显示翻页按钮
//        if (currentPage > 0 && button(50, 500, 100, 40, "上一页")) {
//            currentPage--;
//        }
//
//        if (currentPage < totalPages - 1 && button(650, 500, 100, 40, "下一页")) {
//            currentPage++;
//        }
//
//        // 返回按钮
//        if (fanhui()) {
//            initgraph(1000, 500, EX_SHOWCONSOLE);
//            EndBatchDraw();
//            msg.message = 0;
//
//            return;
//        }
//
//        EndBatchDraw();
//    }
//}
//
//// 显示路线所有站点
//void displayluxian() {
//    int routeId = -1;
//    bool found = false;
//    bool foudd = false;
//    int routeIndex = -1;
//    // 获取路线号
//    while (!found) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//            // 处理消息
//        }
//        BeginBatchDraw();
//        cleardevice();
//
//        printf0(400, 100, 200, 50, "请输入路线号", BLACK);
//
//        if (button(400, 200, 200, 100, "") && Interval(clock())) {
//            char input[100];
//            InputBox(input, sizeof(input), "路线查询", "请输入路线号");
//            routeId = zhuanhuan(input);
//
//            // 查找路线
//            if (routeId > 0) {
//                routeIndex = luxianchazhao(routeId, 1, luxiany);
//                if (routeIndex >= 1 && routeIndex <= luxiany &&
//                    luxianhao[routeIndex].hao == routeId) {
//                    found = true;
//                    foudd = false;
//                }
//                else {
//                    foudd = true;
//                }
//            }
//
//            if (foudd) {
//                printf0(400, 300, 200, 50, "未找到该路线!", RED);
//            }
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            msg.message = 0;
//            return;
//        }
//
//        EndBatchDraw();
//    }
//
//    // 创建显示窗口
//    initgraph(800, 600, EX_SHOWCONSOLE);
//    setbkcolor(WHITE);
//    cleardevice();
//
//    // 获取路线信息
//    luxian0* current = luxianhao[routeIndex].qi;
//    vector<string> stations;
//    int totalDistance = 0;
//
//    // 收集所有站点和距离
//    while (current != nullptr) {
//        stations.push_back(current->zhanming);
//        totalDistance += current->x;
//        current = current->next;
//    }
//
//    int currentPage = 0;
//    const int stationsPerPage = 15;
//    int totalPages = (stations.size() + stationsPerPage - 1) / stationsPerPage;
//
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//            // 处理消息
//        }
//        BeginBatchDraw();
//        cleardevice();
//
//        // 显示标题
//        settextcolor(BLUE);
//        settextstyle(24, 0, "微软雅黑");
//        char title[100];
//        sprintf(title, "路线 %d (总站点数: %d, 总距离: %d)",
//            routeId, stations.size(), totalDistance);
//        outtextxy(50, 20, title);
//
//        // 显示分页信息
//        settextcolor(BLACK);
//        sprintf(title, "第 %d/%d 页", currentPage + 1, totalPages);
//        outtextxy(650, 20, title);
//
//        // 显示站点
//        int startY = 70;
//        settextstyle(20, 0, "微软雅黑");
//
//        for (int i = 0; i < stationsPerPage; i++) {
//            int stationIndex = currentPage * stationsPerPage + i;
//            if (stationIndex >= stations.size()) break;
//
//            // 显示序号
//            settextcolor(BLACK);
//            char numText[10];
//            sprintf(numText, "%d.", stationIndex + 1);
//            outtextxy(50, startY, numText);
//
//            // 显示站点名称
//            outtextxy(100, startY, stations[stationIndex].c_str());
//
//            // 如果是首尾站特殊标记
//            if (stationIndex == 0) {
//                settextcolor(RED);
//                outtextxy(400, startY, "(起点站)");
//            }
//            else if (stationIndex == stations.size() - 1) {
//                settextcolor(RED);
//                outtextxy(400, startY, "(终点站)");
//            }
//
//            // 显示到下一站的距离（如果有）
//            if (stationIndex < stations.size() - 1) {
//                luxian0* node = luxianhao[routeIndex].qi;
//                for (int j = 0; j < stationIndex; j++) node = node->next;
//
//                char distText[50];
//                sprintf(distText, "-> %d米 ->", node->y);
//                settextcolor(DARKGRAY);
//                outtextxy(500, startY, distText);
//            }
//
//            startY += 30;
//        }
//
//        /*// 显示路线图
//        int graphY = 500;
//        int graphX = 50;
//        int graphWidth = 700;
//
//        // 绘制路线背景
//        setfillcolor(LIGHTGRAY);
//        fillroundrect(graphX, graphY, graphX + graphWidth, graphY + 30, 15, 15);
//
//        // 绘制站点标记
//        if (!stations.empty()) {
//            int stationWidth = graphWidth / (stations.size() > 1 ? stations.size() - 1 : 1);
//
//            for (int i = 0; i < stations.size(); i++) {
//                int xPos = graphX + i * stationWidth;
//
//                // 绘制站点标记
//                setfillcolor(i == 0 || i == stations.size() - 1 ? RED : BLUE);
//                fillcircle(xPos, graphY + 15, 8);
//
//                // 绘制连接线
//                if (i > 0) {
//                    setlinecolor(DARKGRAY);
//                    setlinestyle(PS_SOLID, 2);
//                    line(xPos - stationWidth, graphY + 15, xPos, graphY + 15);
//
//                    // 显示距离
//                    luxian0* prevNode = luxianhao[routeIndex].qi;
//                    for (int j = 0; j < i - 1; j++) prevNode = prevNode->next;
//
//                    char distText[20];
//                    sprintf(distText, "%d米", prevNode->y);
//                    settextcolor(DARKGRAY);
//                    settextstyle(12, 0, "微软雅黑");
//                    outtextxy(xPos - stationWidth / 2 - 20, graphY - 20, distText);
//                }
//            }
//        }*/
//
//        // 显示翻页按钮
//        if (currentPage > 0 && button(50, 450, 100, 40, "上一页")) {
//            currentPage--;
//        }
//
//        if (currentPage < totalPages - 1 && button(650, 450, 100, 40, "下一页")) {
//            currentPage++;
//        }
//
//        // 返回按钮
//        if (fanhui()) {
//            initgraph(1000, 500, EX_SHOWCONSOLE);
//            EndBatchDraw();
//            msg.message = 0;
//            return;
//        }
//
//        EndBatchDraw();
//    }
//}
//
//// DFS函数
//void dfs(int current, int target, bool visitedRoutes[], vector<int>& pathStations, vector<int>& pathRoutes, int distance, int currentRoute) {
//    // 添加当前站点到路径
//    pathStations.push_back(current);
//
//    // 如果到达目标站点
//    if (current == target) {
//        // 计算换乘次数
//        int transfers = 0;
//        for (int i = 1; i < pathRoutes.size(); i++) {
//            if (pathRoutes[i] != pathRoutes[i - 1]) {
//                transfers++;
//            }
//        }
//
//        // 保存路径
//        h newPath;
//        newPath.stations = pathStations;
//        newPath.routes = pathRoutes;
//        newPath.totalDistance = distance;
//        newPath.transfers = transfers;
//        allPaths.push_back(newPath);
//
//        // 更新最小换乘次数
//        if (transfers < minTransfers) {
//            minTransfers = transfers;
//        }
//
//        pathStations.pop_back();
//        return;
//    }
//
//    // 遍历当前站点的所有路线
//    zhantaim* routeNode = zhantai[current].qi;
//    while (routeNode != nullptr) {
//        int routeId = routeNode->hao;
//        int routeIdx = luxianchazhao(routeId, 1, luxiany);
//
//        // 如果路线未访问
//        if (!visitedRoutes[routeIdx]) {
//            visitedRoutes[routeIdx] = true;
//
//            // 获取路线结构
//            luxian0* route = luxianhao[routeIdx].qi;
//
//            // 查找当前站点在路线中的位置
//            luxian0* currentStationNode = route;
//            while (currentStationNode != nullptr &&
//                currentStationNode->zhanming != zhantai[current].zhanming) {
//                currentStationNode = currentStationNode->next;
//            }
//
//            if (currentStationNode != nullptr) {
//                // 尝试向前移动
//                luxian0* nextNode = currentStationNode->next;
//                while (nextNode != nullptr) {
//                    int nextStationIdx = weizhi(nextNode->zhanming, 1, zhandianx);
//
//                    // 递归探索下一个站点
//                    pathRoutes.push_back(routeId);
//                    dfs(nextStationIdx, target, visitedRoutes, pathStations, pathRoutes,
//                        distance + nextNode->x, routeId);
//                    pathRoutes.pop_back();
//
//                    nextNode = nextNode->next;
//                }
//
//                // 尝试向后移动
//                luxian0* prevNode = currentStationNode->shang;
//                while (prevNode != nullptr) {
//                    int prevStationIdx = weizhi(prevNode->zhanming, 1, zhandianx);
//
//                    // 递归探索上一个站点
//                    pathRoutes.push_back(routeId);
//                    dfs(prevStationIdx, target, visitedRoutes, pathStations, pathRoutes,
//                        distance + prevNode->y, routeId);
//                    pathRoutes.pop_back();
//
//                    prevNode = prevNode->shang;
//                }
//            }
//
//            visitedRoutes[routeIdx] = false;
//        }
//
//        routeNode = routeNode->next;
//    }
//
//    pathStations.pop_back();
//}
//
//// 比较函数：先按换乘次数，再按总距离
//bool comparePaths(const h& a, const h& b) {
//    if (a.transfers != b.transfers) {
//        return a.transfers < b.transfers;
//    }
//    return a.totalDistance < b.totalDistance;
//}
//
//// 路线查询函数
//void luxianchaxun() {
//    // 初始化变量
//    allPaths.clear();
//    minTransfers = INT_MAX;
//
//    string startStation, endStation;
//    int startIdx = -1, endIdx = -1;
//
//    // 获取起点站
//    initgraph(1000, 500, EX_DBLCLKS | EX_SHOWCONSOLE);
//    setbkcolor(WHITE);
//    cleardevice();
//    while (startIdx == -1) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        cleardevice();
//        printf0(400, 100, 200, 100, "请输入起点站", BLACK);
//
//        if (button(400, 200, 200, 100, "") && Interval(clock())) {
//            char input[100];
//            InputBox(input, sizeof(input), "起点站", "请输入起点站名称");
//            startStation = input;
//
//            // 查找站点
//            startIdx = weizhi(startStation, 1, zhandianx);
//            if (startIdx < 1 || startIdx > zhandianx ||
//                zhantai[startIdx].zhanming != startStation) {
//                printf0(400, 300, 200, 50, "未找到该站点!", RED);
//                startIdx = -1;
//            }
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            return;
//        }
//        EndBatchDraw();
//    }
//
//    // 获取终点站
//    cleardevice();
//    while (endIdx == -1) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        cleardevice();
//        printf0(400, 100, 200, 100, "请输入终点站", BLACK);
//
//        if (button(400, 200, 200, 100, "") && Interval(clock())) {
//            char input[100];
//            InputBox(input, sizeof(input), "终点站", "请输入终点站名称");
//            endStation = input;
//
//            // 查找站点
//            endIdx = weizhi(endStation, 1, zhandianx);
//            if (endIdx < 1 || endIdx > zhandianx ||
//                zhantai[endIdx].zhanming != endStation) {
//                printf0(400, 300, 200, 50, "未找到该站点!", RED);
//                endIdx = -1;
//            }
//        }
//        else if (fanhui()) {
//            EndBatchDraw();
//            return;
//        }
//        EndBatchDraw();
//    }
//
//    // 准备DFS
//    bool visitedRoutes[MAX1] = { false };
//    vector<int> pathStations;
//    vector<int> pathRoutes;
//
//    // 执行DFS
//    dfs(startIdx, endIdx, visitedRoutes, pathStations, pathRoutes, 0, -1);
//
//    // 如果没有找到路径
//    if (allPaths.empty()) {
//        cleardevice();
//        while (true) {
//            if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//            }
//            BeginBatchDraw();
//            cleardevice();
//            printf0(400, 200, 200, 100, "未找到可行路径!", RED);
//
//            if (fanhui()) {
//                EndBatchDraw();
//                return;
//            }
//            EndBatchDraw();
//        }
//    }
//
//    // 按最少换乘排序
//    sort(allPaths.begin(), allPaths.end(), comparePaths);
//
//    // 显示结果
//    int currentPage = 0;
//    const int pathsPerPage = 5;
//    int totalPages = (allPaths.size() + pathsPerPage - 1) / pathsPerPage;
//
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        cleardevice();
//
//        // 显示标题
//        settextcolor(BLACK);
//        settextstyle(24, 0, "微软雅黑");
//        char title[100];
//        sprintf(title, "从 %s 到 %s", startStation.c_str(), endStation.c_str());
//        outtextxy(50, 20, title);
//
//        // 显示分页信息
//        sprintf(title, "第 %d/%d 页", currentPage + 1, totalPages);
//        outtextxy(650, 20, title);
//
//        // 显示路径
//        int startY = 70;
//        for (int i = 0; i < pathsPerPage; i++) {
//            int pathIndex = currentPage * pathsPerPage + i;
//            if (pathIndex >= allPaths.size()) break;
//
//            const h& path = allPaths[pathIndex];
//
//            // 显示路径信息
//            settextstyle(16, 0, "微软雅黑");
//            char info[100];
//            sprintf(info, "路径 %d: 换乘 %d 次, 总距离 %d 米",
//                pathIndex + 1, path.transfers, path.totalDistance);
//            outtextxy(50, startY, info);
//
//            // 显示路径详情
//            startY += 30;
//            int xPos = 50;
//
//            for (int j = 0; j < path.stations.size(); j++) {
//                int stationIdx = path.stations[j];
//                string stationName = zhantai[stationIdx].zhanming;
//
//                // 显示站点名称
//                settextcolor(BLACK);
//                outtextxy(xPos, startY, stationName.c_str());
//                xPos += textwidth(stationName.c_str()) + 10;
//
//                // 如果不是最后一个站点，显示路线号和箭头
//                if (j < path.stations.size() - 1) {
//                    int routeId = path.routes[j];
//
//                    // 显示路线号
//                    char routeText[20];
//                    sprintf(routeText, "[%d]", routeId);
//                    settextcolor(BLUE);
//                    outtextxy(xPos, startY, routeText);
//                    xPos += textwidth(routeText) + 5;
//
//                    // 显示箭头
//                    settextcolor(BLACK);
//                    outtextxy(xPos, startY, "→");
//                    xPos += 20;
//                }
//
//                // 换行检查
//                if (xPos > 750) {
//                    xPos = 50;
//                    startY += 25;
//                }
//            }
//
//            startY += 40;
//        }
//
//        // 显示翻页按钮
//        if (currentPage > 0 && button(50, 500, 100, 40, "上一页")) {
//            currentPage--;
//        }
//
//        if (currentPage < totalPages - 1 && button(650, 500, 100, 40, "下一页")) {
//            currentPage++;
//        }
//
//        // 返回按钮
//        if (fanhui()) {
//            EndBatchDraw();
//            return;
//        }
//
//        EndBatchDraw();
//    }
//}
//
//void chaxun() {
//    void(*hanshu2[3])() = { displayzhandian, displayluxian ,luxianchaxun };
//    char chaozuo2[3][10] = { "站点查询","路线查询","路径查询" };
//    setbkcolor(WHITE);
//    cleardevice();
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        setbkcolor(WHITE);
//        BeginBatchDraw();
//        jiazai();
//        cleardevice();
//        for (int i = 0; i < 3; i++) {
//            if (button(400, 150 + i * 60, 200, 60, chaozuo2[i]) && Interval(clock())) {
//                hanshu2[i]();
//                msg.message = 0;
//            }
//            else if (fanhui()) {
//                msg.message = 0;
//                EndBatchDraw();
//                return;
//            }
//        }
//        EndBatchDraw();
//    }
//    return;
//}
//
//void xuanxiangdigui() {
//    void(*hanshu[5])() = { zhandianjianli ,zhandianxiugai,luxianjianli,luxianxiugai,chaxun };
//    setbkcolor(WHITE);
//    cleardevice();
//    while (true) {
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        jiazai();
//        cleardevice();
//        for (int i = 0; i < 5; i++) {
//            if (button(400, 90 + i * 60, 200, 60, chaozuo[i]) && Interval(clock())) {
//                hanshu[i]();
//                msg.message = 0;
//            }
//            else if (fanhui()) {
//                msg.message = 0;
//                EndBatchDraw();
//                return;
//            }
//        }
//        EndBatchDraw();
//    }
//    closegraph();
//    return;
//}
//
//
//// 添加文件保存功能
//void saveToFile() {
//    FILE* file = fopen("subway_data.txt", "wb");
//    if (!file) {
//        cout << "无法创建文件! 错误: " << strerror(errno) << endl;
//        return;
//    }
//
//    // 保存站点数量 (从1开始计数)
//    fwrite(&zhandianx, sizeof(int), 1, file);
//
//    // 保存每个站点信息
//    for (int i = 1; i <= zhandianx; i++) {
//        // 保存站点名称长度和内容
//        int nameLen = zhantai[i].zhanming.length();
//        fwrite(&nameLen, sizeof(int), 1, file);
//        fwrite(zhantai[i].zhanming.c_str(), sizeof(char), nameLen, file);
//
//        // 保存站点关联的路线数量
//        int routeCount = 0;
//        zhantaim* p = zhantai[i].qi;
//        while (p) {
//            routeCount++;
//            p = p->next;
//        }
//        fwrite(&routeCount, sizeof(int), 1, file);
//
//        // 保存关联的路线号
//        p = zhantai[i].qi;
//        while (p) {
//            fwrite(&p->hao, sizeof(int), 1, file);
//            p = p->next;
//        }
//    }
//
//    // 保存路线数量 (从1开始计数)
//    fwrite(&luxiany, sizeof(int), 1, file);
//
//    // 保存每条路线
//    for (int i = 1; i <= luxiany; i++) {
//        // 保存路线号
//        fwrite(&luxianhao[i].hao, sizeof(int), 1, file);
//
//        // 计算路线中的站点数量
//        int stationCount = 0;
//        luxian0* p = luxianhao[i].qi;
//        while (p) {
//            stationCount++;
//            p = p->next;
//        }
//        fwrite(&stationCount, sizeof(int), 1, file);
//
//        // 保存路线中的每个站点及其关系
//        p = luxianhao[i].qi;
//        int index = 0;
//        while (p) {
//            // 保存站点名称长度和内容
//            int nameLen = p->zhanming.length();
//            fwrite(&nameLen, sizeof(int), 1, file);
//            fwrite(p->zhanming.c_str(), sizeof(char), nameLen, file);
//
//            // 保存距离信息
//            fwrite(&p->x, sizeof(unsigned int), 1, file);
//            fwrite(&p->y, sizeof(unsigned int), 1, file);
//
//            // 保存节点位置标识 (首节点/中间节点/尾节点)
//            int nodeType = 0;
//            if (p == luxianhao[i].qi) nodeType = 1; // 首节点
//            if (p == luxianhao[i].next) nodeType = 2; // 尾节点
//
//            fwrite(&nodeType, sizeof(int), 1, file);
//
//            p = p->next;
//            index++;
//        }
//    }
//
//    fclose(file);
//    cout << "数据保存成功! 站点数: " << zhandianx << ", 路线数: " << luxiany << endl;
//}
//
//// 清除现有数据
//void clearExistingData() {
//    // 清除站点数据
//    for (int i = 1; i <= zhandianx; i++) {
//        zhantaim* p = zhantai[i].qi;
//        while (p) {
//            zhantaim* temp = p;
//            p = p->next;
//            delete temp;
//        }
//        zhantai[i].qi = nullptr;
//        zhantai[i].luxian = nullptr;
//    }
//    zhandianx = 0;
//
//    // 清除路线数据
//    for (int i = 1; i <= luxiany; i++) {
//        luxian0* p = luxianhao[i].qi;
//        while (p) {
//            luxian0* temp = p;
//            p = p->next;
//            delete temp;
//        }
//        luxianhao[i].qi = nullptr;
//        luxianhao[i].next = nullptr;
//    }
//    luxiany = 0;
//}
//
//// 添加文件加载功能
//void loadFromFile() {
//    clearExistingData(); // 清除现有数据
//    FILE* file = fopen("subway_data.txt", "rb");
//    if (!file) {
//        cout << "无法打开文件! 错误: " << strerror(errno) << endl;
//        return;
//    }
//    // 加载站点数量
//    if (fread(&zhandianx, sizeof(int), 1, file) != 1) {
//        cout << "读取站点数量失败!" << endl;
//        fclose(file);
//        return;
//    }
//    // 加载每个站点
//    for (int i = 1; i <= zhandianx; i++) {
//        // 读取站点名称长度
//        int nameLen;
//        if (fread(&nameLen, sizeof(int), 1, file) != 1) {
//            cout << "读取站点[" << i << "]名称长度失败!" << endl;
//            fclose(file);
//            return;
//        }
//        // 读取站点名称
//        string tempName(nameLen, '\0');
//        if (fread(&tempName[0], sizeof(char), nameLen, file) != nameLen) {
//            cout << "读取站点[" << i << "]名称内容失败! 期望长度: " << nameLen << endl;
//            fclose(file);
//            return;
//        }
//        zhantai[i].zhanming = tempName;
//        // 初始化路线链表
//        zhantai[i].qi = nullptr;
//        zhantai[i].luxian = nullptr;
//        // 读取关联路线数量
//        int routeCount;
//        if (fread(&routeCount, sizeof(int), 1, file) != 1) {
//            cout << "读取站点[" << tempName << "]关联路线数量失败!" << endl;
//            fclose(file);
//            return;
//        }
//        // 读取关联的路线号并重建链表
//        zhantaim* prevNode = nullptr;
//        for (int j = 0; j < routeCount; j++) {
//            int routeNum;
//            if (fread(&routeNum, sizeof(int), 1, file) != 1) {
//                cout << "读取站点[" << tempName << "]的路线号失败!" << endl;
//                fclose(file);
//                return;
//            }
//            zhantaim* newNode = new zhantaim;
//            newNode->hao = routeNum;
//            newNode->next = nullptr;
//
//            if (!zhantai[i].qi) {
//                zhantai[i].qi = newNode;
//            }
//            else {
//                prevNode->next = newNode;
//            }
//            prevNode = newNode;
//        }
//        zhantai[i].luxian = prevNode;  // 设置链表尾指针
//    }
//
//    // 加载路线数量
//    if (fread(&luxiany, sizeof(int), 1, file) != 1) {
//        cout << "读取路线数量失败!" << endl;
//        fclose(file);
//        return;
//    }
//    // 加载每条路线
//    for (int i = 1; i <= luxiany; i++) {
//        // 读取路线号
//        if (fread(&luxianhao[i].hao, sizeof(int), 1, file) != 1) {
//            cout << "读取路线[" << i << "]号失败!" << endl;
//            fclose(file);
//            return;
//        }
//
//        // 读取站点数量
//        int stationCount;
//        if (fread(&stationCount, sizeof(int), 1, file) != 1) {
//            cout << "读取路线[" << luxianhao[i].hao << "]站点数量失败!" << endl;
//            fclose(file);
//            return;
//        }
//        // 加载路线中的站点并重建双向链表
//        luxianhao[i].qi = nullptr;
//        luxianhao[i].next = nullptr;
//        luxian0* prevNode = nullptr;
//        for (int j = 0; j < stationCount; j++) {
//            luxian0* newNode = new luxian0;
//            // 初始化新节点
//            newNode->shang = nullptr;
//            newNode->next = nullptr;
//            newNode->x = 0;
//            newNode->y = 0;
//            // 读取站点名称长度
//            int nameLen;
//            if (fread(&nameLen, sizeof(int), 1, file) != 1) {
//                cout << "读取路线[" << luxianhao[i].hao << "]站点名称长度失败!" << endl;
//                delete newNode;
//                fclose(file);
//                return;
//            }
//            // 读取站点名称
//            string tempName(nameLen, '\0');
//            if (fread(&tempName[0], sizeof(char), nameLen, file) != nameLen) {
//                cout << "读取路线[" << luxianhao[i].hao << "]站点名称内容失败! 期望长度: " << nameLen << endl;
//                delete newNode;
//                fclose(file);
//                return;
//            }
//            newNode->zhanming = tempName;
//            // 读取距离信息
//            if (fread(&newNode->x, sizeof(unsigned int), 1, file) != 1 ||
//                fread(&newNode->y, sizeof(unsigned int), 1, file) != 1) {
//                cout << "读取路线[" << luxianhao[i].hao << "]距离信息失败!" << endl;
//                delete newNode;
//                fclose(file);
//                return;
//            }
//            // 关键修复：必须读取节点类型标识
//            int nodeType = 0;
//            if (fread(&nodeType, sizeof(int), 1, file) != 1) {
//                cout << "读取路线[" << luxianhao[i].hao << "]节点类型失败!" << endl;
//                delete newNode;
//                fclose(file);
//                return;
//            }
//            // 重建双向链表关系
//            newNode->shang = prevNode;
//            if (prevNode) {
//                prevNode->next = newNode;
//            }
//            else {
//                luxianhao[i].qi = newNode; // 首节点
//            }
//            prevNode = newNode;
//            // 如果是最后一个节点，设为路线终点
//            if (j == stationCount - 1) {
//                luxianhao[i].next = newNode;
//            }
//        }
//    }
//
//    fclose(file);
//    cout << "数据加载成功! 站点数: " << zhandianx << ", 路线数: " << luxiany << endl;
//
//    // 验证数据结构完整性
//    for (int i = 1; i <= luxiany; i++) {
//        luxian0* current = luxianhao[i].qi;
//        luxian0* prev = nullptr;
//        int nodeCount = 0;
//
//        while (current) {
//            nodeCount++;
//            // 验证双向链表关系
//            if (current->shang != prev) {
//                cout << "警告: 路线[" << luxianhao[i].hao << "]节点[" << current->zhanming
//                    << "]的前向指针不正确!" << endl;
//            }
//
//            if (prev && prev->next != current) {
//                cout << "警告: 路线[" << luxianhao[i].hao << "]节点[" << prev->zhanming
//                    << "]的后向指针不正确!" << endl;
//            }
//
//            prev = current;
//            current = current->next;
//        }
//
//        // 验证路线节点数量
//        if (nodeCount == 0) {
//            cout << "警告: 路线[" << luxianhao[i].hao << "]没有站点!" << endl;
//        }
//        else if (luxianhao[i].next != prev) {
//            cout << "警告: 路线[" << luxianhao[i].hao << "]尾指针不正确!" << endl;
//        }
//    }
//}
//
//void schema() {
//    initgraph(1000, 500, EX_DBLCLKS | EX_SHOWCONSOLE);
//    void(*hanshu0[2])() = { xuanxiangdigui, chaxun };
//    setbkcolor(WHITE);
//    cleardevice();
//    while (true) {
//        setbkcolor(WHITE);
//        if (peekmessage(&msg, EX_MOUSE | EX_KEY)) {
//        }
//        BeginBatchDraw();
//        jiazai();
//        cleardevice();
//        if (button(400, 150, 200, 60, "管理模式") && Interval(clock())) {
//            msg.message = 0;
//            char input[100];
//            char mima[] = "123456";
//            InputBox(input, sizeof(input), "管理密码", "请输入密码");
//            if (!strcmp(input, mima)) {
//                hanshu0[0]();
//                saveToFile();
//            }
//            else {
//                InputBox(input, 256, "密码错误", "提示", "密码错误，请不要填写", 300, 0, false);
//            }
//        }
//        else if (button(400, 150 + 60, 200, 60, "游客模式") && Interval(clock())) {
//            msg.message = 0;
//            hanshu0[1]();
//        }
//        else if (fanhui()) {
//            msg.message = 0;
//            EndBatchDraw();
//            closegraph();
//            return;
//        }
//        EndBatchDraw();
//    }
//    closegraph();
//    return;
//}
//int main() {
//    loadFromFile();
//    cout << "站台:" << endl;
//    for (int i = 1; i <= zhandianx; i++) {
//        cout << zhantai[i].zhanming << " ";
//    }
//    cout << endl;
//    cout << "路线:" << endl;
//    for (int i = 1; i <= luxiany; i++) {
//        cout << luxianhao[i].hao << endl;
//        luxian0* pa = luxianhao[i].qi;
//        while (luxianhao[i].next != pa && pa != nullptr) {
//            cout << pa->zhanming << " ";
//            pa = pa->next;
//        }
//        if (pa != nullptr) {
//            cout << pa->zhanming << endl;
//        }
//    }
//    schema();
//    saveToFile();
//    return 0;
//}
//
//
