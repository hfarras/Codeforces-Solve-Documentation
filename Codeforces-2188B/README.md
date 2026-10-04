# 2188B - Seats

Source : (https://codeforces.com/contest/2188/problem/B)

We are given a binary string $s$ of length $n$, where $s_i = 1$ indicates that the $i$-th seat is currently occupied by a student, and $s_i = 0$ indicates that it is currently free.

We want to calculate the minimum number of additional students that can be seated. Since no two students can sit adjacent to each other, if $s_i = 1$, then neither $s_{i-1}$ nor $s_{i+1}$ can be occupied. Therefore, we need to count the contiguous segments of available seats ($0$s) while excluding those adjacent to an already occupied seat ($1$).

To determine which $0$'s can actually be occupied, I used a boolean vector. If a position cannot be occupied, we mark it as false.

```cpp
vector<bool> v;
if(n <= 2) cout << 1 << "\n";
    else {
        for(int i = 0; i < n; i++) {
            if(i == 0 && (s[i] == '1' || s[i+1] == '1')) v.push_back(false);
            else if(i == n-1 && (s[i] == '1' || s[i-1] == '1')) v.push_back(false);
            else {
                if(s[i] == '1' || s[i+1] == '1' || s[i-1] == '1') v.push_back(false);
                else v.push_back(true);
            }
        }
```

After marking the valid positions, we calculate the lengths of the continuous segments of available seats (where v[j] == true):

```cpp
int cnt = 0;
    for(int j = 0; j <= n; j++) {
        if(j < n && v[j] == true) cnt++;
            else {
                if(cnt > 0) cout << cnt << "\n";
                cnt = 0;
            }
    }
    cout << "\n";

```

Now that we have the length of each available segment (cnt), we need to find the minimum number of students that can be seated in it.

Let's analyze the pattern based on the segment length:

- 1 `2` -> length 1 (minimum)
- 1 `2` 3 `4` -> length 2
- 1 `2` 3 4 `5` 6 -> length 2
- 1 `2` 3 4 `5` 6 7 `8` -> length 3
- 1 `2` 3 4 `5` 6 7 `8` 9 `10` -> length 4
- 1 `2` 3 4 `5` 6 7 `8` 9 10 `11` 12 -> lenght 4
- 1 `2` 3 4 `5` 6 7 `8` 9 10 `11` 12 13 `14` -> length 5
- 1 `2` 3 4 `5` 6 7 `8` 9 10 `11` 12 13 `14` 15 `16` -> length 6

The resulting sequence for the minimum students needed is: 1, 2, 2, 3, 4, 4, 5, 6, ...

Notice that for segment lengths such as 2, 8, and 14, if we add 1 and divide by 3, we get the exact minimum number of students. For the remaining cases, adding 3 or 5 before dividing by 3 (and subtracting 1) yields the correct result. This pattern holds true for odd lengths as well.

```cpp
if((cnt + 1) % 3 == 0) sum += (cnt+1)/3;
else if((cnt + 3) % 3 == 0) sum += (cnt+3)/3 -1;
else if((cnt + 5) % 3 == 0) sum += (cnt+5)/3 -1;
```
