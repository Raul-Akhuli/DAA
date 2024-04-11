n = 5
p = [3, 3, 2, 5, 1]
w = [10, 15, 10, 12, 8]
W = 10
def knapsack():
    cur_w = W
    tot_v = 0
    maxi = 0
    used = [0] * 10
    while cur_w > 0:
        maxi = -1
        for i in range(n):
            if used[i] == 0 and (maxi == -1 or w[i]/p[i] > w[maxi]/p[maxi]):
                maxi = i
        used[maxi] = 1
        cur_w -= p[maxi]
        tot_v += w[maxi]
        if cur_w >= 0:
            print(f"Added object {maxi + 1} ({w[maxi]}, {p[maxi]}) completely in the bag. Space left: {cur_w}.")
        else:
            print(f"Added {int((1 + cur_w/p[maxi]) * 100)}% ({w[maxi]}, {p[maxi]}) of object {maxi + 1} in the bag.")
            tot_v -= w[maxi]
            tot_v += (1 + cur_w/p[maxi]) * w[maxi]
    print(f"Filled the bag with objects worth {tot_v:.2f}.")
knapsack()
