#pragma once

#include <cmath>
#include <stack>
#include <string>

namespace util {
using namespace std;
    double s2d(string s)
    {
        int i, f = 0;
        char a;
        double ce = 0, fr = 0, pw = 1.0;
        for (i = 0; i < s.size(); i++) {
            a = s[i];
            if (a == '.')
                f = 1;
            else if (f == 0)
                ce = ce * 10.0 + (double)(a - '0');
            else {
                fr = fr * 10.0 + (double)(a - '0');
                pw = pw * 10.0;
            }
        }
        return ce + fr / pw;
    }

    int isIn(char a, string s)
    {
        int i, n = s.size();
        for (i = 0; i < n; i++)
            if (s[i] == a)
                return i;
        return -1;
    }

    string* parse(string formula)
    {
        int n = formula.size();
        string* res = new string[n + 1];
        string tmp;
        char a;
        int i, ptr;

        ptr = 0;
        tmp = "";

        for (i = 0; i <= n; i++)
            res[i] = "";

        for (i = 0; i < n; i++) {
            a = formula[i];
            if (isIn(a, "+-*/^()") >= 0) {
                if (tmp.size() > 0)
                    res[ptr++] = tmp;
                res[ptr++] = string(1, a);
                tmp = "";
            }

            else {
                tmp = tmp + string(1, a);
            }
        }
        if (tmp.size() > 0)
            res[ptr++] = tmp;
        return res;
    }

    int prty(char op)
    {
        switch (op) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':

            return 3;
        default:
            return -1;
        }
    }

    double exec(char op, double a1, double a2)
    {
        double r;
        switch (op) {
        case '+':
            r = a1 + a2;
            return r;
        case '-':
            r = a1 - a2;
            return r;
        case '*':
            r = a1 * a2;
            return r;
        case '/':
            r = a1 / a2;
            return r;
        case '^':
            r = pow(a1, a2);
            return r;
        }
    }

    double eval(string formula)
    {
        stack<double> s1;
        stack<char> s2;

        size_t pos;
        while ((pos = formula.find(" ")) != std::string::npos) {
            formula.replace(pos, 1, "");
        }

        int i, ilex = 0, p1, p2;
        double v, a1, a2, r;
        string curr;

        string* lex = parse(formula);

        while (lex[ilex] != "") {
            curr = lex[ilex++];
            if (curr[0] >= '0' && curr[0] <= '9') {
                v = s2d(curr);
                s1.push(v);
            } else {
                if ((curr[0] == '(') || s2.empty()) {
                    s2.push(curr[0]);
                } else {
                    if (curr[0] == ')') {
                        while (1) {
                            if (s2.top() == '(') {
                                s2.pop();
                                break;
                            }
                            a2 = s1.top();
                            s1.pop();
                            a1 = s1.top();
                            s1.pop();
                            r = exec(s2.top(), a1, a2);
                            s1.push(r);
                            s2.pop();
                        }
                    } else {
                        p1 = prty(s2.top());
                        p2 = prty(curr[0]);

                        if (p2 > p1) {
                            s2.push(curr[0]);
                        } else {
                            a2 = s1.top();
                            s1.pop();
                            a1 = s1.top();
                            s1.pop();
                            r = exec(s2.top(), a1, a2);
                            s1.push(r);
                            s2.pop();
                            s2.push(curr[0]);
                        }
                    }
                }
            }
        }

        while (1) {
            if (s2.empty())
                break;
            a2 = s1.top();
            s1.pop();
            a1 = s1.top();
            s1.pop();
            r = exec(s2.top(), a1, a2);
            s1.push(r);
            s2.pop();
        }

        delete[] lex;

        return s1.top();
    }
}