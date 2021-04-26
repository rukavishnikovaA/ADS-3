// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <stack>
std::string infx2pstfx(std::string inf) {
    std::map<char, int> priority = { {'(', 0}, {')', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3} };
    std::string res, t;
    std::stack<char> stack;
    for (auto& chr : inf) {
        if (chr >= '0' && chr <= '9') {
            t += chr;
        } else if (chr == '(' || chr == '+' ||
            chr == '-' || chr == '*' || chr == '/') {
            if (t.length()) {
                res += t;
                res += ' ';
                t = "";
            }
            if (!stack.empty()) {
                if (chr == '(') {
                    stack.push(chr);
                } else if (priority[chr] > priority[stack.top()]) {
                    stack.push(chr);
                } else {
                    res += stack.top();
                    stack.pop();
                    stack.push(chr);
                    res += ' ';
                }
            } else {
                stack.push(chr);
            }
        } else if (chr == ')') {
            if (t.length()) {
                res += t;
                res += ' ';
                t = "";
            }
            if (!stack.empty()) {
                while (stack.top() != '(') {
                    res += stack.top();
                    stack.pop();
                    res += ' ';
                }
                stack.pop();
            }
        }
    }
    if (t.length()) {
        res += t;
        res += ' ';
   }
    for (unsigned int i = stack.size(); i > 0; i--) {
        res += stack.top();
        res += ' ';
        stack.pop();
    }
    res.erase(res.end() - 1, res.end());
    return res;
  return std::string("");
}

int eval(std::string pst) {
    unsigned int x = 0, y = 0;
    std::stack<unsigned int> stack;
    unsigned int t = 0;
    for (unsigned int i = 0; i < pst.length() + 1; i++) {
        if (pst[i] >= '0' && pst[i] <= '9') {
            t *= 10;
            t += pst[i] - '0';
        } else if (pst[i] == ' ') {
            stack.push(t);
            t = 0;
        } else {
            x = stack.top();
            stack.pop();
            y = stack.top();
            stack.pop();
            if (pst[i] == '+') {
                stack.push(y + x);
            } else if (pst[i] == '-') {
                stack.push(y - x);
            } else if (pst[i] == '*') {
                stack.push(y * x);
            } else {
                stack.push(y / x);
            }
            i++;
        }
    }
    return stack.top();
}
  return 0;
}
