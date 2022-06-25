 int temp = 1 + max (left, right);
    int ans = max (temp, 1 + left + right);
    res = max (res, ans);
    return temp;