// Spiral Order Matrix II: https://www.interviewbit.com/problems/spiral-order-matrix-ii/
// Tags: #easy #scaler #M4DSA1 #array2 #additional
// Efficiency: Time Complexity O(n*m), Space Complexity O(1)

class Solution {
    spiralOrderMatrix(matrixSize: number): number[][] {
        let count = 1,
            center = Math.ceil((matrixSize - 1) / 2);
        let matrix: number[][] = Array.from(Array(matrixSize), () =>
            Array(matrixSize).fill(0)
        );

        for (let depth = 0; depth < center; depth++) {
            for (let i = 0 + depth; i < matrixSize - 1 - depth; i++)
                matrix[depth][i] = count++;

            for (let i = 0 + depth; i < matrixSize - 1 - depth; i++)
                matrix[i][matrixSize - depth - 1] = count++;

            for (let i = 0 + depth; i < matrixSize - 1 - depth; i++)
                matrix[matrixSize - depth - 1][matrixSize - i - 1] = count++;

            for (let i = 0 + depth; i < matrixSize - 1 - depth; i++)
                matrix[matrixSize - i - 1][depth] = count++;
        }

        if (matrixSize % 2 !== 0) matrix[center][center] = count;

        return matrix;
    }

    printMatrix(matrix: number[][]) {
        for (let i = 0; i < matrix.length; i++) {
            for (let j = 0; j < matrix[0].length; j++)
                process.stdout.write(`${matrix[i][j]} `);
            console.log("");
        }
    }
}

const solution = new Solution();
const matrix = solution.spiralOrderMatrix(5);
solution.printMatrix(matrix);
