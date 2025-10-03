let mtrx = [[1, 2, 3, 4],
[4, 5, 6, 7],
[7, 8, 9, 10]];

let l = 0;
let t = 0;
let r = mtrx[0].length;
let b = mtrx.length;

let res = []

while (l < r && t < b) {
    for (let i = l; i < r; i++) {
        res.push(mtrx[t][i]);
    }
    t += 1;
    for (let i = t; i < b; i++) {
        res.push(mtrx[i][r - 1]);
    }
    r -= 1;

    if (t < b) {
        for (let i = r; i >= l; i--) {
            res.push(mtrx[b - 1][i]);
        }
        b -= 1;
    }
    if(l < r)
    for (let i = b - 1; i > t - 1; i--) {
        res.push(mtrx[i][l]);
    }
    l += 1;
}

console.log(res)