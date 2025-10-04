let mtrx = [[1, 2, 3, 4],
[4, 5, 6, 7],
[7, 8, 9, 10],
[10,11,12,13]];

let res = [];

let top = 0;
let bottom = mtrx.length;
let left = 0;
let right = mtrx[0].length;

while (top < bottom && left < right) {
    for (let i = left; i < right; i++) {
        res.push(mtrx[top][i]);
    }
    top += 1;

    for (let i = top; i < bottom; i++) {
        res.push(mtrx[i][right - 1]);
    }
    right -= 1;

    if (top < bottom) {

        for (let i = right - 1; i >= left; i--) {
            res.push(mtrx[bottom - 1][i]);
        }
        bottom -= 1;

    }

    if (left < right) {
        for (let i = bottom - 1; i >= top; i--) {
            res.push(mtrx[i][left]);
        }
        left += 1;
    }
}

console.log(res)